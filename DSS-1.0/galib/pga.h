#if !defined(PGA)
#define PGA
#include "ga.h"
//---------------------------------------------------------------------------
template <class GeneticAlgorithm>
class TParallelGA
{ private:
        int demeCount;
        GeneticAlgorithm* gaDeme;
  public:
        void execute();
        TParallelGA(int dcnt, TGAParameters p);
};
//---------------------------------------------------------------------------
template <typename GeneticAlgorithm>
TParallelGA<GeneticAlgorithm>:: TParallelGA(int dcnt,TGAParameters p)
{ demeCount=dcnt;
  gaDeme=new GeneticAlgorithm[demeCount];
  for(int i=0;i<demeCount;i++) gaDeme=GeneticAlgorithm(p);
}
//---------------------------------------------------------------------------
template <typename GeneticAlgorithm>
void TParallelGA<GeneticAlgorithm>:: execute()
{ for(int i=0;i<demeCount;i++) gaDeme[i].evaluate();
}
//---------------------------------------------------------------------------
#endif
