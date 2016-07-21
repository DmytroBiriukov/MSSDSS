#if !defined(SGA)
#define SGA
#include "ga.h"

template <class Genotype>
class TSimpleGA : public TGeneticAlgorithm<Genotype>
{protected:
        void selection();
        void mating();
        void replacement();
        virtual void cross(Genotype& ,Genotype& );
        virtual void mutate(Genotype& );
        void uniformcross(Genotype& ,Genotype& );
 public:
	TSimpleGA(TGAParameters p){params=p; init();}
 	TSimpleGA(){;}
        ~TSimpleGA(){;}
};
//---------------------------------------------------------------------------
template <typename Genotype> void TSimpleGA<Genotype>::mating()
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
template <typename Genotype> void TSimpleGA<Genotype>:: replacement()
{//replace parents by offspring using tournament replacement method
 pop.TounamentReplacement();
}
//---------------------------------------------------------------------------
template <typename Genotype> void TSimpleGA<Genotype>::selection()
{//select parents for mating by roulette wheel selection method
 pop.RouletteWheelSelection();
}
//---------------------------------------------------------------------------
template <typename Genotype>
void TSimpleGA<Genotype>:: cross(Genotype& genome1,Genotype& genome2)
{  int count=genome1.count();
   int crosspoint=frand()*(count-1);
   Genotype tmp=Genotype(count);
   tmp=genome1;
   for(int i=0;i<crosspoint;i++)
       genome1.encode(i,genome2[i]);
   for(int i=crosspoint;i<count;i++)
       genome2.encode(i,tmp[i]);
}
//---------------------------------------------------------------------------
template <typename Genotype> void TSimpleGA<Genotype>::
uniformcross(Genotype& genome1,Genotype& genome2)
{  Genotype tmp=Genotype(genome1);
   for(i=0;i<genome1.count();i++)
      if(frand()<0.5)
      { genome1.encode(i,genome2[i]);
        genome2.encode(i,tmp[i]);
      }
}
//---------------------------------------------------------------------------
template <typename Genotype> void TSimpleGA<Genotype>:: mutate(Genotype& genome)
{
 for(int i=0;i<params.genCount;i++)
    if(frand()<params.Pmut) genome.swap(i);
}
//---------------------------------------------------------------------------
#endif
