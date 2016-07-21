#if !defined(NGA)
#define NGA
#include "ga.h"
//---------------------------------------------------------------------------
//
//      Niched GA for sharing genotypes
//
//---------------------------------------------------------------------------
template <class Genotype>
class TNichedGA : public TGeneticAlgorithm<Genotype>
{protected:
        float* nicheCount;
        float nicheRadius;
        void setNiches();
        void selection();
        void mating();
        void replacement();
        virtual void setRadius(){;}
        virtual void cross(Genotype& ,Genotype& ){;}
        virtual void mutate(Genotype& ){;}
        virtual void fitness(Genotype& g){;}
 public:
	TNichedGA(TGAParameters p){params=p; init();}
 	TNichedGA(){;}
        ~TNichedGA(){;}
};
//---------------------------------------------------------------------------
template <typename Genotype> void TNichedGA<Genotype> :: setNiches()
{ int n=pop.size();
  nicheCount=new float[n];
  setRadius();
  for(int i=0;i<n;i++)
     { nicheCount[i]=0.0;
       for(int j=0;j<n;j++)
           { float gamma=pop[i].distance(pop[j]);
             if(gamma<nicheRadius)
               nicheCount[i]+=1-(gamma/nicheRadius);
           }
     }
}
//---------------------------------------------------------------------------
template <typename Genotype> void TNichedGA<Genotype>::selection()
{//select parents for mating by roulette wheel selection method
 setNiches();
 pop.RouletteWheelSelection();
}
//---------------------------------------------------------------------------
template <typename Genotype> void TNichedGA<Genotype>::mating()
{ //(1)cross each pair of parents and produce offspring
  //(2)mutate each offspring
  int size=pop.size();
  for(int i=0;i<size;i=i+2)
    {  if(frand()<params.Pcross)
          cross(pop[size+i], pop[size+i+1]);
       mutate(pop[size+i]);
       mutate(pop[size+i+1]);
    }
}
//---------------------------------------------------------------------------
template <typename Genotype> void TNichedGA<Genotype>:: replacement()
{//replace parents by offspring using tournament replacement method
 pop.TounamentReplacement();
}
//---------------------------------------------------------------------------
//
//      Pareto GA with niching for Multiobjective optimization
//
//---------------------------------------------------------------------------
template <class Genotype>
class TParetoGA : public TNichedGA<Genotype>
{private:
        int objCount;
 protected:
        int* rank;
        void setRank();
        int dominate(Genotype ,Genotype ); // g1>g2 , g1 dominate g2
        void init(){ rank=new int[params.popSize];}
        virtual float* objective(Genotype){;}
        virtual void cross(Genotype& ,Genotype& ){;}
        virtual void mutate(Genotype& ){;}
        virtual void fitness(Genotype& g){;}
 public:
	TParetoGA(TGAParameters p){params=p; init();}
 	TParetoGA(){;}
        ~TParetoGA(){;}
};
//---------------------------------------------------------------------------
template <typename Genotype> int TParetoGA<Genotype>:: dominate(Genotype g1,Genotype g2)
{ int dmt=1;
  for(int i=0;i<objCount;i++)
     if(objective(g1)[i]<objective(g1)[i])
       { dmt=0; break;
       }
  return dmt;
}
//---------------------------------------------------------------------------
template <typename Genotype> void TParetoGA<Genotype>:: setRank()
{ int rnk=1; int size=pop.size();
  int effSize=size;
  for(int i=0;i<size;i++)
     { rank[i]=0;
       eff[i]=pop[i];
     }
  while(effSize)
       { for(int i=0;i<size;i++)
             if(!rank[i])
                { rank[i]=rnk;
                  for(int j=0;j<size;j++)
                     if(!rank[j])
                       if(dominate(pop[j],pop[i]))
                           { rank[i]=0;
                             break;
                           }
                  if(rank[i]) effSize--;
                }//end of for(i)
         rnk++;
       }//end of while
}
//---------------------------------------------------------------------------
#endif
