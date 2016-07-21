//---------------------------------------------------------------------------
#ifndef gathreadH
#define gathreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "ga.h"
//---------------------------------------------------------------------------
template <class Genotype> class TGAThread : public TThread  , TGeneticAlgorithm<Genotype>
{protected:
        void __fastcall Execute();
        TGAParameters params;
        virtual void replacement(){;}
        virtual void init(){;}
        virtual int selection(){;}
        virtual void cross(Genotype& g1,Genotype& g2){;}
        virtual void mutate(Genotype& g){;}
        virtual void fitness(Genotype& g){;}
 public:
        __fastcall TGAThread(bool CreateSuspended, TGAParameters p){params=p; init();}
};
//---------------------------------------------------------------------------
template <class Genotype>  void __fastcall TGAThread<Genotype>::Execute()
{ while(!Terminated)
  {  if(stat.generation<params.generations)
        Synchronize(evaluate());
  }
}
//---------------------------------------------------------------------------
#endif
