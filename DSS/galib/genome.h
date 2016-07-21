#if !defined(GENOME)
#define GENOME

#include<math.h>

template <typename T> class TGenome
{protected:
        T* gen;
        int _count;
        double _fitness;
 public:
        double fitness(){return _fitness;}
        void fitness(double fts){ _fitness=fts;}
        int count(){return _count;}
        virtual void decode(int k, T& vrb){vrb=gen[k];}
        virtual void encode(int k, T vrb){gen[k]=vrb;}
        virtual float distance(TGenome g){;}
        T& operator[](int k){return gen[k];}
        TGenome& operator=(TGenome g);
        TGenome& operator<<(TGenome& g);
        int operator!=(TGenome& g);
        virtual void swap(int ){;}
        TGenome(int cnt){ _count=cnt; gen=new T[cnt];}
        TGenome(){;}
        ~TGenome(){;}
};
//---------------------------------------------------------------------------
template <typename T> TGenome<T>& TGenome<T>::operator=(TGenome g)
{ if( _count < g.count())
    { _count=g.count();
      gen=new T[_count];
    }
  for(int i=0;i< _count;i++) encode(i,g[i]);
  _fitness=g.fitness();
  return *this;
}
template <typename T> TGenome<T>& TGenome<T>::operator<<(TGenome& g)
{ for(int i=0;i< _count;i++)
     { T temp; decode(i,temp); encode(i,g[i]); g.encode(i,temp);
     }
  double temp; temp=fitness(); fitness(g.fitness()); g.fitness(temp);
  return *this;
}
template <typename T> int TGenome<T>:: operator!=(TGenome& g)
{ int eq=0;
  for(int i=0;i< _count;i++)
      if (g[i]!=gen[i])
         { eq=1; break;
         }
  return eq;
}
//---------------------------------------------------------------------------
typedef TGenome<unsigned> TNumGenome;
typedef TGenome<int> TIntGenome;
//---------------------------------------------------------------------------
class TBitGenome : public TGenome<bool>
{ public:
        void GrayDecode(int k0, int k1, unsigned& vrb){;}// Gray decode
        void GrayEncode(int k0, int k1, unsigned vrb){;}// Gray encode
        int distance(TBitGenome );// Hamming distance
        void swap(int );
        TBitGenome(int cnt){ _count=cnt; gen=new bool[cnt];}
        TBitGenome(){;}
        ~TBitGenome(){;}
};
//---------------------------------------------------------------------------
int TBitGenome ::distance(TBitGenome g)// Hamming distance
{int dist=0;
  for(int i=0;i< _count; i++)
     if(gen[i]!= g.gen[i]) dist++;
 return dist;
}
//---------------------------------------------------------------------------
void TBitGenome :: swap(int i)
{if(gen[i]) encode(i,0);
   else encode(i,1);
}
//---------------------------------------------------------------------------
class TRealGenome : public TGenome<float>
{ public:
        float distance(TRealGenome );// Euclidian distance
        TRealGenome(int cnt){ _count=cnt; gen=new float[cnt];}
        TRealGenome(){;}
        ~TRealGenome(){;}
};
//---------------------------------------------------------------------------
float TRealGenome ::distance(TRealGenome g)// Euclidian distance
{float dist=0.0;
  for(int i=0;i< _count; i++)
     dist+=pow((gen[i]-g.gen[i]),2.0);
 return sqrt(dist);
}
//---------------------------------------------------------------------------
#endif

