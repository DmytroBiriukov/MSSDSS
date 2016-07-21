/*------------------------------------------------------------------------------
        This source is developed by Dmitrij Birjukov to support
        State Transition Graph processing for multi-state
        complex-structured systems
------------------------------------------------------------------------------*/
#if !defined(STG)
#define STG
//#include <iostream>
#define VCL_IOSTREAM
#include <dstring.h>
#include"sys.h"
#include"expolynome.h"
/*------------------------------------------------------------------------------
        TSTGNode class developed to represent node of state transition graph
------------------------------------------------------------------------------*/
template <class T>
class TSTGNode
{private:
        unsigned short isEst;
        double* intensity;
        double* outensity;
        int xPos;
        int yPos;
        T po;
        int prevCnt;
        TSTGNode<T>** prev;
        T* node;
	int nextCnt;
        TSTGNode<T>** next;
        int index;
 public:
        int GetX(){return xPos;}
        void SetX(int x){xPos=x;}
        int GetY(){return yPos;}
        void SetY(int y){yPos=y;}
        T& GetPo(){return po;}
        TSTGNode()
                { node=new T;
                  isEst=0;
                }
        int GetIndex(){return index;}
        void SetIndex(int i){index=i;}
        int GetPrevCount()
                {return prevCnt;
                }
        int GetNextCount()
                {return nextCnt;
                }
        void SetInNode(int index, TSTGNode<T>* n)
		{ prev[index]=n;
		}
        void SetOutNode(int index, TSTGNode<T>* n)
		{ next[index]=n;
		}
        T& GetNode()
                {return *node;
                }
        TSTGNode<T>* GetInNode(int index)
                {return prev[index];
                }
        TSTGNode<T>* GetOutNode(int index)
                {return next[index];
                }
        virtual void Set(int pc, int nc, T* np)
                { prevCnt=pc;
		  prev=new TSTGNode<T>*[prevCnt];
		  nextCnt=nc;
		  next=new TSTGNode<T>*[nextCnt];
                  node=new T();
		  *node=*np;
                  intensity=new double[prevCnt];
                  outensity=new double[nextCnt];
                  isEst=0;
                }
        void setIntens(double* intens, double* outens);
        double& intens(int i)
                { return intensity[i];
                }
        double& outens(int i)
                { return outensity[i];
                }
        unsigned short  IsEsted()
                { return isEst;
                }
        void  IsEsted(unsigned short ie)
                { isEst=ie;
                }
};
template <class T>
void TSTGNode<T>::setIntens(double* intens, double* outens)
{ for(int i=0; i<prevCnt; i++) intensity[i]=intens[i];
  for(int i=0; i<nextCnt; i++) outensity[i]=outens[i];
}
/*------------------------------------------------------------------------------
        class TSTGraph developed to represent state transition graph
------------------------------------------------------------------------------*/
template <class T> class TSTGraph
{private:
        TSTGNode<T>* state;
        T* prfunction;
        int stateCnt;
        unsigned short isEval;
 public:
        TSTGNode<T>& GetNode(int index){return state[index];}
        int stateCount(){return  stateCnt;}
        void stateCount(int n){stateCnt=n;}
        void eval();
        void eval(int);
        T& PrF(int i){return prfunction[i];}
        void scanf(istream& ins);
        void printf(ostream& stream);
        TSTGNode<T>& operator [] (int index)
                {return state[index];
                }
	TSTGraph(){stateCnt=0; isEval=0;}
        TSTGraph(istream& ins){scanf(ins);}
 	void init(int n);
        //friend istream& operator>>(istream& stream, TSTGraph<T>&);
        //friend void operator>>(istream& stream, TSTGraph<T>&);
	~TSTGraph();
};

template <class T> void TSTGraph<T> ::init(int n)
{ stateCnt=n;
  state=new TSTGNode<T>[n];
  prfunction=new T[n];
}

template <class T> TSTGraph<T>::~TSTGraph()
{ if(stateCnt){delete[] state; delete[] prfunction;}
}

template <class T> void TSTGraph<T> ::eval()
{ if(!isEval)
  { for(int i=0;i<stateCnt;i++)
    { if(state[i].GetNextCount()==0)
      { eval(i);

      }
    }
    isEval=1;
  }
}

template <class T> void TSTGraph<T> ::eval(int idx)
{
  for(int i=0; i<state[idx].GetPrevCount();i++)
  { int idx1=state[idx].GetInNode(i)->GetIndex();
    int isEst1=state[idx1].IsEsted();
    if(! isEst1) eval(idx1);
  }
  int isEst=state[idx].IsEsted();
  double to=0.0;

  using namespace std;
  ofstream out_stream;
  out_stream.open("result1.txt",1);
  if( out_stream.fail())     ShowMessage("out stream failed!");

  if(! isEst)
  { out_stream<<"\n\n Processing state node No."<<idx;
    double Co=prfunction[idx].value(0.0);

    int nnn[1]={1};
    double** ddd1=new double*[1]; ddd1[0]=new double[1]; ddd1[0][0]=1.0;
    double** ddd0=new double*[1]; ddd0[0]=new double[1]; ddd0[0][0]=0.0;
    double dd[1]={0.0};

    if(state[idx].GetNextCount()>0)
    { double a=0.0;
      for(int k=0;k<state[idx].GetNextCount();k++) a+=state[idx].outens(k);

      if(state[idx].GetPrevCount()>0)
      { out_stream<<"\n case 2";
        T tmp0;
        dd[0]=a;
        tmp0.init(1,nnn,ddd1,dd);
//        double tmp00=(-1.0)*tmp0.value(0.0);
//        tmp0+=tmp00;

        T tmp3;
        T tmp2;
        dd[0]=0.0;
        tmp2.init(1,nnn,ddd0,dd);
        for(int k=0; k<state[idx].GetPrevCount();k++)
        { tmp3.init(1,nnn,ddd0,dd);
          tmp3=state[idx].GetInNode(k)->GetNode();
          tmp3*=state[idx].GetInNode(k)->outens(k);
          tmp3*=tmp0;
          tmp2+=tmp3;
        }
        out_stream<<"\n before integr "; tmp2.expolynome2MatLab(out_stream);
        tmp2.integral();
        out_stream<<"\n after integr "; tmp2.expolynome2MatLab(out_stream);
        double Int_to=tmp2.value(0.0);
        tmp2+=(-1.0)*Int_to;
        out_stream<<"\n Int_to="<<Int_to;
        tmp2+=Co;
        out_stream<<"\t Co="<<Co<<"\t  Co + tmp2 = "; tmp2.expolynome2MatLab(out_stream);
        dd[0]=-a;
        ddd1[0][0]=exp(a*to);
        tmp0.init(1,nnn,ddd1,dd);
        tmp2*=tmp0;
        state[idx].GetNode()=tmp2;
      }else
      { out_stream<<"\n case 1";
        dd[0]=-a;
        ddd1[0][0]=exp(a*to);        
        state[idx].GetNode().init(1,nnn,ddd1,dd);
        state[idx].GetNode()*=Co;
      }

    }else
    { // (3)
      out_stream<<"\n case 3";
      T tmp2;
      dd[0]=0.0;
      tmp2.init(1,nnn,ddd0,dd);
      if(state[idx].GetPrevCount()>0)
      {  for(int k=0; k<state[idx].GetPrevCount();k++)
           tmp2+=(state[idx].GetInNode(k)->GetNode()*state[idx].GetInNode(k)->outens(k));
         tmp2.integral();
         double Int_to=Co-tmp2.value(0.0);
         tmp2+=Int_to;
      }
      state[idx].GetNode()=tmp2;
    }

    state[idx].IsEsted(1);

    out_stream<<"\n\n nonstat state "<<idx<<"prob = ";
    state[idx].GetNode().expolynome2MatLab(out_stream);

  }
     out_stream.close();
}
/*
template <class T>
//istream& operator>>(istream& stream, TSTGraph<T>& gph)
void operator>>(istream& stream, TSTGraph<T>& gph)
{ int n;
  stream>>n;
  gph.init(n);
  for(int i=0;i<n;i++)
	{T fl;
         int out, in;   int x, y;
	 stream>>in; stream>>out;
         stream>>x; stream>>y;
         stream>>fl;
         gph.GetStateNode(i).SetIndex(i);
         gph.GetStateNode(i).Set(in,out, &fl);
         gph.GetStateNode(i).SetX(x);
         gph.GetStateNode(i).SetY(y);
	}
  for(int i=0;i<n;i++)
  { int inarcs=gph.GetStateNode(i).GetPrevCount();
    for(int j=0;j<inarcs;j++)
	{int t;
	 stream>>t;
         gph.GetStateNode(i).SetInNode(j,&gph.GetStateNode(t));
         double fl;
         stream>>fl;
         gph.GetStateNode(i).intens(j)=fl;
	}
    int outarcs=state[i].GetNextCount();
    for(int j=0;j<outarcs;j++)
	{int t;
	 stream>>t;
         gph.GetStateNode(i).SetOutNode(j, &gph.GetStateNode(t));
         double fl;
         stream>>fl;
         gph.GetStateNode(i).outens(j)=fl;
	}
   }
 //return stream;
}
*/
template <class T>  void TSTGraph<T> ::scanf(istream& stream)
{ int n;
  using namespace std;
  stream>>n;
  stateCnt=n;
  state=new TSTGNode<T>[n];
  prfunction=new T[n];
  for(int i=0;i<n;i++)
	{T fl;
         int out, in;   int x, y;
	 stream>>in; stream>>out;
         stream>>x; stream>>y;
         stream>>fl;
         prfunction[i]=fl;
         state[i].Set(in,out, &prfunction[i]);
         state[i].SetIndex(i);
         state[i].SetX(x);  state[i].SetY(y);
	}
  for(int i=0;i<n;i++)
  { int inarcs=state[i].GetPrevCount();
    for(int j=0;j<inarcs;j++)
	{int t;
	 stream>>t;
         state[i].SetInNode(j, &state[t]);
         double fl;
         stream>>fl;
         state[i].intens(j)=fl;
	}
    int outarcs=state[i].GetNextCount();
    for(int j=0;j<outarcs;j++)
	{int t;
	 stream>>t;
         state[i].SetOutNode(j, &state[t]);
         double fl;
         stream>>fl;
         state[i].outens(j)=fl;
	}
  }
  stream>>isEval;
  if(isEval)
  { for(int i=0;i<n;i++)
	{ T fl;
          stream>>fl;
          state[i].GetNode()=fl;
        }
  }

}

template <class T>  void TSTGraph<T> ::printf(ostream& stream)
{ int n=stateCnt;
  stream.setf(ios::fixed);
  stream.setf(ios::showpoint);
  stream<<n<<"\n";
  for(int i=0;i<n;i++)
  { stream<<state[i].GetPrevCount(); stream<<" ";
    stream<<state[i].GetNextCount(); stream<<"\n";
    stream<<state[i].GetX(); stream<<" "; stream<<state[i].GetY(); stream<<"\n";
//    stream<<state[i].GetNode();  stream<<"\n";
    stream<<prfunction[i];  stream<<"\n";
  }
  for(int i=0;i<n;i++, stream<<"\n")
  { int inarcs=state[i].GetPrevCount();
    for(int j=0;j<inarcs;j++, stream<<" ")
	{stream<<state[i].GetInNode(j)->GetIndex();
         stream<<" "; stream<<state[i].intens(j);
	}
    int outarcs=state[i].GetNextCount();
    for(int j=0;j<outarcs;j++, stream<<" ")
	{stream<<state[i].GetOutNode(j)->GetIndex();
         stream<<" "; stream<<state[i].outens(j);
	}
  }
  stream<<"\n"<<isEval;
  if(isEval)
  { for(int i=0;i<stateCnt;i++)
	{ stream<<"\n";
          stream<<state[i].GetNode();
        }
  }

}
/*------------------------------------------------------------------------------
this code was used to organize
STG windowed grafics
------------------------------------------------------------------------------*/
#define rds 15
#define ard 15
#define PicHeight 200
#define PicWidth 400

struct TTexRatio
{float b[13];//only low bounds are needed, 'cos  hight_bound[i]==low_bound[i+1]
 int a[12];  //only x arguments are needed, 'cos y[i]==x[11-i]
} TeXRatio={{0.0 , 0.15 , 0.3 , 0.4 , 0.6 , 0.7 , 1.0 , 1.4 , 1.7 , 2.5 , 3.5 , 5 , 200},
{0, 1, 1, 1, 2, 3, 4, 3, 2, 3, 4, 1}};

int texRatioIndex(float rat)
{int ind;
 for(int i=0;i<12;i++)
    if((rat>=TeXRatio.b[i])&&(rat<TeXRatio.b[i+1]))
      {ind=i; break;
      }
 return ind;
}

double round(double x)
{double r=floor(x);
 return (r+0.5>x)? r+1.0 : r;
}

int sign(double a)
{ if(!a) return 0;
    else if(a>0) return 1; else return -1;
}
//---------------------------------------------------------------------------
template <class T>
struct Node
{ T data;
  Node *link;
  Node(T data_value, Node *link_value):data(data_value), link(link_value){};
};
//---------------------------------------------------------------------------
template <class T>
class TmyDeque
{ private:
        Node<T> *fst;
        Node<T> *lst;
        unsigned int count;
 public:
        Node<T>* GetNode(unsigned int index);
        unsigned int GetCount(){return count;}
        T& operator [] (unsigned int index)
        {return (GetNode(index)->data);
        }
        Node<T>* operator ()(unsigned int index)
        {return GetNode(index);
        }
        void InsertNode(T& data);
        TmyDeque()
        { count=0;
        }
        ~TmyDeque(){ free();}
        void free();
};
//---------------------------------------------------------------------------
template <class T>
void TmyDeque<T>:: free()
{
while(fst!=NULL)
  {  Node<T> *node;
     node=fst;
     delete node;
     fst=fst->link;
  }
  count=0;
}
//---------------------------------------------------------------------------
template <class T>
void TmyDeque<T>::InsertNode(T& data)
{ if(fst!=NULL)
    {lst->link=new Node<T>(data, NULL);
     lst=lst->link;
    }else
    {fst=new Node<T>(data, NULL);
     lst=fst;
    }
 count++;
}
//---------------------------------------------------------------------------
template <class T>
Node<T>* TmyDeque<T>::GetNode(unsigned int index)
{ Node<T>* ptr;
  for(ptr=fst; index && ptr; index--) ptr=ptr->link;
  return ptr;
}
//---------------------------------------------------------------------------
struct TVertex
{unsigned int state;
 int x;
 int y;
 double pr;
 double pr0;
 char* description;
 TVertex(unsigned int state_v, double pr0_v, char* d_v, int x0, int y0)
        { state=state_v; pr0=pr0_v; description="";
          strcpy(description, d_v); x=x0; y=y0;
        }
 TVertex(){;}        
};
//---------------------------------------------------------------------------
struct TTransition
{unsigned int vout;
 unsigned int vin;
 double lambda;
 int dx;
 int dy;
 TTransition(unsigned int vo, unsigned int vi, double l)
                : vout(vo), vin(vi), lambda(l){};
 TTransition(){;}                
};
//---------------------------------------------------------------------------
void DrawArrow(int x0, int y0, int x1, int y1, void (*move)(int x, int y), void (*line)(int x, int y))
{
      double alpha, beta, gamma, delta;
      double a;
      int dX, dY;
      int x2, y2;
      dX=x1-x0; dY=y1-y0;
      alpha=M_PI/8;
      beta=atan(dX/dY);
      gamma=M_PI_2- beta-alpha;
      delta= beta-alpha;
      move(x0,y0);
      line(x1,y1);
      move(x1,y1);
      x2=x1- a*sin(delta);
      y2=y1+ a*cos(delta);
      line(x2,y2);
      x2=x1- a*cos(gamma);
      y2=y1+ a*sin(gamma);
      line(x2,y2);
}
//---------------------------------------------------------------------------
void Drawing2STGraph(TmyDeque<TVertex>* vertexDeque, TmyDeque<TTransition>* arrowDeque,
TSTGraph<TExpolynome>* stgraph)
{
// component state number
unsigned int m=vertexDeque->GetCount();// StringGrid2->RowCount;
// transition number
unsigned int p=arrowDeque->GetCount();
stgraph->init(m);
int* pc=new int[m];
int* nc=new int[m];
for(unsigned int i=0;i<m;i++)
   { pc[i]=nc[i]=0;
     int x=vertexDeque->GetNode(i)->data.x;
     int y=vertexDeque->GetNode(i)->data.y;
     stgraph->GetNode(i).SetX(x);
     stgraph->GetNode(i).SetY(y);
   }
for(int i=0;i<p;i++)
   { /* //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     */
     pc[arrowDeque->GetNode(i)->data.vin]++;
     nc[arrowDeque->GetNode(i)->data.vout]++;
   }
for(int i=0;i<m;i++)
   {
     stgraph->GetNode(i).SetIndex(i);
     stgraph->GetNode(i).Set(pc[i], nc[i], new TExpolynome( vertexDeque->GetNode(i)->data.pr0 ) );
//-----------------------------------------------------------------
     stgraph->PrF(i)=TExpolynome( vertexDeque->GetNode(i)->data.pr0 );
//-----------------------------------------------------------------
   }

for(unsigned int i=0;i<m;i++)
   {
     double* intens=new double[pc[i]];
     double* outens=new double[nc[i]];
     int k, l; k=l=0;
     for(int j=0;j<p;j++)
        { if(arrowDeque->GetNode(j)->data.vin==i)
          { intens[k]=arrowDeque->GetNode(j)->data.lambda;
            stgraph->GetNode(i).SetInNode(k, &stgraph->GetNode(arrowDeque->GetNode(j)->data.vout));
            k++;
          }
          if(arrowDeque->GetNode(j)->data.vout==i)
          { outens[l]=arrowDeque->GetNode(j)->data.lambda;
            stgraph->GetNode(i).SetOutNode(l, &stgraph->GetNode(arrowDeque->GetNode(j)->data.vin));
            l++;
          }
        }
     stgraph->GetNode(i).setIntens(intens, outens);
     delete[] intens; delete[] outens;
   }
}
//---------------------------------------------------------------------------
void STGraph2Drawing(TmyDeque<TVertex>* vertexDeque, TmyDeque<TTransition>* arrowDeque,
TSTGraph<TExpolynome>* stgraph)
{ // component state number
  unsigned int m=stgraph->stateCount();
  for(unsigned int i=0;i<m;i++)
  {int x=stgraph->GetNode(i).GetX();
   int y=stgraph->GetNode(i).GetY();
   double l=stgraph->GetNode(i).GetNode().value(0.0);
   vertexDeque->InsertNode(TVertex(i, l, "", x, y));
    // transition number
    unsigned int p=stgraph->GetNode(i).GetPrevCount();
    for(int j=0;j<p;j++)
    { int vo=stgraph->GetNode(i).GetInNode(j)->GetIndex();
      double l=stgraph->GetNode(i).intens(j);
      arrowDeque->InsertNode(TTransition(i, vo, l));
    }
  }
}
//---------------------------------------------------------------------------
#endif














