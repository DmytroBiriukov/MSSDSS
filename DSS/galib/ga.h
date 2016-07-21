#if !defined(GA)
#define GA

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

#include"genome.h"
#define frand() ((float)rand()/(RAND_MAX+1.0))
//---------------------------------------------------------------------------
struct TGAParameters
{ int popSize;
  int genCount;
  float Pcross;
  float Pmut;
};
struct TGAStatistics
{ double best;
  double average;
  double cv;
  double convergence;
  int solution;
};
//---------------------------------------------------------------------------
template <class Genotype> class Population
{private:
        int _size;
        Genotype* genome;
        double* selectPoint;
 public:
        void RouletteWheelSelection();
        void TounamentSelection();
        void SimpleReplacement();
        void TounamentReplacement();
        void ElitistReplacement();
        void recombinate();
        int size(){return _size;}
        Genotype& operator[](int k){return genome[k];}
        void init(int size,int count);
        Population(){;}
        ~Population(){;}
};
//---------------------------------------------------------------------------
template <class Genotype>
void Population<Genotype>::init(int size,int count)
{ _size=size;
  genome= new Genotype[2*size];
  selectPoint= new double[size];
  for(int i=0;i<2*size;i++) genome[i]= Genotype(count);
}
//---------------------------------------------------------------------------
template <class Genotype> void Population<Genotype>:: TounamentSelection()
{ int temp1, temp2;
  for(int i=0;i< _size; i++)
     { temp1=_size*frand();
       temp2=_size*frand();
       if(genome[temp1].fitness()>genome[temp2].fitness())
          genome[_size+i]=genome[temp1];
          else genome[_size+i]=genome[temp2];
     }
}
template <class Genotype> void Population<Genotype>:: RouletteWheelSelection()
{ int i;
  double temp=0.0;
  for(i=0;i< _size; i++)
     {selectPoint[i]=temp+genome[i].fitness();
      temp=selectPoint[i];
     }
  for(i=0;i< _size; i++)
     { temp=frand()*selectPoint[_size-1];
       for(int j=0;j< _size;j++)
          if(selectPoint[i]>temp)
            {genome[_size+i]=genome[i];
             break;
            }
     }
}
//---------------------------------------------------------------------------
template <class Genotype> void Population<Genotype>:: SimpleReplacement()
{ for(int i=0;i< _size; i++)
      genome[i]=genome[_size+i];
}
template <class Genotype> void Population<Genotype>:: TounamentReplacement()
{ for(int i=0;i< _size; i++)
      if(genome[i].fitness()<genome[_size+i].fitness())
         genome[i]=genome[_size+i];
}
template <class Genotype> void Population<Genotype>:: ElitistReplacement()
{int index;
 for(int i=0;i< _size; i++)
     { for(int j=i;j< _size*2;j++)
          {index=j;
           if(genome[j]>genome[index])index=j;
          }
       genome[i]<<genome[index];
     }
}
//---------------------------------------------------------------------------
template <class Genotype> void Population<Genotype>::recombinate()
{
  for(int i=0;i< _size;i++)
     for(int j=0;j< genome[i].count();j++)
        if(genome[i][j]==genome[i+1][j])
           genome[_size+i].encode(j,genome[i][j]);
}
//---------------------------------------------------------------------------
template <class Genotype> class TGeneticAlgorithm
{protected:
        Population<Genotype> pop;
        TGAParameters params;
        void init();
        virtual void selection(){;}
        virtual void mating(){;}
        virtual void replacement(){;}
        virtual void cross(Genotype& g1,Genotype& g2){;}
        virtual void mutate(Genotype& g){;}
        virtual void fitness(Genotype& g){;}
 public:
        void evaluate();
        void statistics(TGAStatistics& stat);
        Genotype genome(int k){return pop[k];}
	TGeneticAlgorithm(TGAParameters p){params=p; init();}
        TGeneticAlgorithm(){;}
        ~TGeneticAlgorithm(){;}
};
//---------------------------------------------------------------------------
template <typename Genotype>
void TGeneticAlgorithm<Genotype>::init()
{//(1) initialize population
 //(2) set fitness values
 //(3) set statistics
  pop.init(params.popSize,params.genCount);
  int size=pop.size();
  for(int k=0;k<size;k++) fitness(pop[k]);
 }
//---------------------------------------------------------------------------
template <typename Genotype>
void TGeneticAlgorithm<Genotype>::evaluate()
{ //(1)use selection operator
  selection();
  //(2)use mating method
  mating();
  //(3)set fitness values for each offspring
  int size=pop.size();
  for(int k=0;k<size;k++) fitness(pop[size+k]);
  //(4)use replacement operator
  replacement();
}
//---------------------------------------------------------------------------
template <typename Genotype>
void TGeneticAlgorithm<Genotype>:: statistics(TGAStatistics& stat)
{ int size=pop.size();
  stat.average=0.0; stat.best=0.0; stat.solution=0;
  for(int k=0;k<size;k++)
     {stat.average+=pop[k].fitness();
      if (pop[k].fitness() > stat.best)
         { stat.best=pop[k].fitness();
           stat.solution=k;
         }
     }
  stat.average=stat.average/size;
  stat.cv=0.0;
  for(int k=0;k<size;k++)
      stat.cv+=pow((pop[k].fitness()-stat.average),2.0);
  stat.cv=sqrt(stat.cv)/(sqrt(size)*stat.average);
}
//---------------------------------------------------------------------------
#endif
