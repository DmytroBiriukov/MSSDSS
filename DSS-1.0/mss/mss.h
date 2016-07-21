/*------------------------------------------------------------------------------
        This source is developed by Dmitrij Birjukov
        to support various optimization methods of
        discrete optimization in complex systems
------------------------------------------------------------------------------*/
#if !defined(MSS)
#define MSS
#include"sys.h"
#include"eta.h"
#include"stg.h"
enum TSystemType {MSSHE=0, MMSS, MBSS, S3S};
/*------------------------------------------------------------------------------
  System types are:
  - MSSHE (Multi-state system with heterogenious elements);
  - MMSS (Monotone multi-state system);
  - MBSS (Monotone binary-state system);
  - S3S (Three-state system / System with two faile modes).
------------------------------------------------------------------------------*/
struct TDrawParams
{ int height;
  int width;
  int Xscale;
  int Yscale;
  int n;
};
/*------------------------------------------------------------------------------
        TMSComponent class developed to contain subsystem characteristics
------------------------------------------------------------------------------*/
template <class T> class TMSComponent
{private:
	int stateCnt;
        T* Pr;              //internal state probabilities
	T* statePr;         //output state probabilities
	int IsEst;
        int index;
        TSTGraph<T> STGraph;
 public:

	int stateCount()
			{ return stateCnt;
			}
	void stateCount(int cnt)
 			{stateCnt=cnt;
			 statePr= new T[stateCnt];
                         Pr= new T[stateCnt];
			}
	T getStatePr(int state)
			{ return statePr[state];
			}
  	T getPr(int state)
			{ return Pr[state];
			}
	void stateProbability(int state, T pr)
			{ Pr[state]=pr;
			}
	void setStatePr(int state, T pr)
			{ statePr[state]=pr;
			}
	int IsEstimated()
			{ return IsEst;
			}
	int IsEsted()
			{ return IsEst;
			}
        void IsEstimated(int est)
                        { IsEst=est;
                        }
        int GetIndex(){return index;}
        void SetIndex(int i){index=i;}
	void EstimateStateProbabilities(int (*LOperator)(TMSComponent<T> *));
        ostream& graphics(ostream& (*f)(ostream&, TDrawParams, const TMSComponent<T>&),ostream&, TDrawParams, const TMSComponent<T>&);
	TMSComponent<T>& operator = (TMSComponent<T>&);
        friend ostream& operator<<(ostream& outs, const TMSComponent<T>& comp);
//        friend istream& operator>>(istream& ins, TMSComponent<T>& comp);
//        istream& scanf(istream& ins);
        void scanf(istream& ins);
	TMSComponent()
			{IsEst=0;
			 stateCnt=0;
			}
	TMSComponent(int sc)
			{IsEst=0;
			 stateCnt=sc;
			 statePr= new T[stateCnt];
                         Pr= new T[stateCnt];
                         STGraph.init(stateCnt);
			}
       ~TMSComponent();
};
template <class T>
void TMSComponent<T>::EstimateStateProbabilities(int (*LOperator)(TMSComponent<T>*))
{ if(LOperator(this)) IsEst=1;
  else  IsEst=0;
}
//---------------------------------------------------------------------------
template <class T>
ostream& TMSComponent<T>::graphics(ostream& (*f)(ostream&, TDrawParams, const TMSComponent<T>&),ostream& stream, TDrawParams p, const TMSComponent<T>& c)
{
 return f(stream,p, comp);
}

template <class T>
TMSComponent<T>::~TMSComponent()
{  if(stateCnt)
        {delete[] statePr;
         delete[] Pr;
        }
}
template <class T>
TMSComponent<T>& TMSComponent<T>:: operator = (TMSComponent<T>& component)
{  if(stateCount())
     { delete statePr[];
       delete Pr[];
     }
   stateCount(component.stateCount());
   for(int i=0;i<stateCount();i++)
      Pr[i]=component.getPr(i);
   if(component.IsEstimated())
      {for(int i=0;i<stateCount();i++)
          statePr[i]=component.getStatePr(i);
       IsEst=1;
      }
   return *this;
}
template <class T> ostream& operator<<(ostream& stream, const TMSComponent<T>& c)
{int i=c.GetIndex();
 stream<<"\n\n Component No."<<i<<".";
 int m=c.stateCount();
 stream<<" State number is $m_"<<i<<"="<<m<<"$.";
 for(int s=0; s<m; s++) stream<<"\n\n $p^{("<<s+1<<")}_"<<i<<"(t)="<<c.getPr(s)<<"$";
 for(int s=0; s<m; s++) stream<<"\n\n $\\pi^{("<<s+1<<")}_"<<i<<"(t)="<<c.getStatePr(s)<<"$";
 return stream;
}
//template <class T> istream& operator>>(istream& stream, TMSComponent<T>& component)
//template <class T> istream& TMSComponent<T> ::scanf(istream& stream)
template <class T> void TMSComponent<T> ::scanf(istream& stream)
{ int k;
  stream>>k;
  this->stateCount(k);
  STGraph.init(stateCnt);
// are nonstationar. prob.s given ?
// k > 0 - true   k==0 - othervice
  stream>>k;
  if(k)
    {  for(int j=0;j<stateCnt;j++)
         { TExpolynome t; stream>>t;
           stateProbability(j,t);
         }

    }else
    {
     STGraph.scanf(stream);
     STGraph.eval();
//     cout<<"\n scanf TMSComponent ";
     for(int j=0;j<stateCnt;j++)
        { stateProbability(j,STGraph.PrF(j));
    //      cout<<"\n State "<<j<<" Pr="<<getPr(j);
        }
    }
// return stream;
}
/*------------------------------------------------------------------------------
        TStructureNode class developed to organize system
        configuration like graph
------------------------------------------------------------------------------*/
template <class T>
class TStructureNode : public TNode< TMSComponent<T> >

{public:
        TStructureNode() : TNode< TMSComponent<T> >()
                {;
                }
};
/*------------------------------------------------------------------------------
        TMSSystem class developed to contain system characteristics
------------------------------------------------------------------------------*/
template <class T> class TMSSystem
{private:
    	float* statePerformanceLevel;
        T systemPerformanceDemand;
	int componentCnt;
        int stateCnt;
        TMSComponent<T>* component;
        TStructureNode<T>* node;
        ifstream in_stream;
        ofstream out_stream;
        void print(ostream&, int);
        unsigned short systemType;
 public:
        int ComponentCount()
                {return componentCnt;
                }
        int stateCount()
                {return  stateCnt;
                }
        void stateCount(int n)
                {stateCnt=n;
                }
	T ExpectedPerformance();
        void eval(){EvaluateProbabilities(&node[componentCnt-1]);}
        void EvaluateProbabilities(TNode<TMSComponent<T> >*);
//        friend istream& operator>>(istream& ins, TMSSystem<T>& mss);
//        istream& scanf(istream& ins);
        void scanf(istream& ins);
        void printf(ostream&);
        TStructureNode<T>& operator [] (int index)
                {return node[index];
                }
        TMSComponent<T>& operator () (int index)
                {return component[index];
                }
	TMSSystem()
		{;
		}
	~TMSSystem();
	TMSSystem(istream& ins)
		{ scanf(ins);
		}
};
template <class T> TMSSystem<T> ::~TMSSystem()
{if(componentCnt)
   { delete[] component;
     delete[] node;
   }
}
template <class T> void TMSSystem<T> ::print(ostream& stream, int i)
{
 stream<<"\n\n Component #$"<<i<<"$.";
 int m=component[i].stateCount();
 stream<<" State number is $m_"<<i<<"="<<m<<"$.";
 for(int s=0; s<m; s++) stream<<"\n $p^{("<<s+1<<")}_"<<i<<"(t)="<<component[i].getPr(s)<<"$";
 for(int s=0; s<m; s++) stream<<"\n $\\pi^{("<<s+1<<")}_"<<i<<"(t)="<<component[i].getStatePr(s)<<"$";
}

template <class T> void TMSSystem<T> ::printf(ostream& stream)
{
 stream<<1<<endl;
 int n=this->stateCount();
 stream<<n<<endl;
 for(int i=0;i<n;i++) stream<<statePerformanceLevel[i]<<" ";
 stream<<endl;
 stream<<systemPerformanceDemand;
 stream<<endl;
 n=this->ComponentCount();
 stream<<n<<endl;

 for(int i=0;i<n;i++)
 {
   int m=this->component[i].stateCount();
   stream<<m<<endl;
   stream<<1<<endl;
   for(int j=0;j<m;j++)
   {  stream<<this->component[i].getPr(j);
      stream<<endl;
   }
   int inarcCnt=this->node[i].GetPrevCount();
   int outarcCnt=this->node[i].GetNextCount();
   stream<<inarcCnt<<" "<<outarcCnt<<endl;
 }
 for(int i=0;i<n;i++)
 { int inarcCnt=this->node[i].GetPrevCount();
   int outarcCnt=this->node[i].GetNextCount();
   for(int j=0;j<inarcCnt;j++)
   stream<<this->node[i].GetInNode(j).GetIndex()<<" ";
   for(int j=0;j<outarcCnt;j++)
   stream<<this->node[i].GetOutNode(j).GetIndex()<<" ";
 }
 stream<<endl;


}
//---------------------------------------------------------------------------
//template <class T> istream& operator>>(istream& stream, TMSSystem<T>& mss)
//template <class T> istream& TMSSystem<T> ::scanf(istream& stream)
template <class T> void TMSSystem<T> ::scanf(istream& stream)
{ int i,j,n;

// Read system type
  stream>>systemType;

// Read system's state number
  stream>>n;
  stateCount(n);
//1
//  cout<<"\n State number="<<stateCount()<<"\t";
// Read states' performance levels
  statePerformanceLevel=new float[n];
  for(i=0;i<n;i++)
      { stream>>statePerformanceLevel[i];
//2
//        cout<<"\t U["<<i+1<<"]="<<statePerformanceLevel[i];
      }
// Read system's performance demands
  stream>>systemPerformanceDemand;
//3
//  cout<<"\nSystem Performance Demand w(t)="<<systemPerformanceDemand<<"\n";

// Read component count
  stream>>n;

//  ShowMessage("Componets number is "+IntToStr(n)+" ");

  componentCnt=n;
  component=new TMSComponent<T>[n];
  node=new TStructureNode<T>[n];
  for(i=0;i<n;i++)
    { node[i].SetIndex(i);
      component[i].SetIndex(i);
    }
  for(i=0;i<n;i++)
  { component[i].scanf(stream);
//4
//    cout<<"\n Component No."<<component[i].GetIndex();
//    cout<<"\n States number="<<component[i].stateCount();
/*
    for(int j=0;j<component[i].stateCount();j++)
        cout<<"\n Pr["<<j<<"]="<<component[i].getPr(j);
*/
    int inarcs;
    int outarcs;
    stream>>inarcs;
    stream>>outarcs;
//    ShowMessage("Componet #"+IntToStr(i)+" outs ="+IntToStr(outarcs)+" and ins="+IntToStr(inarcs));
    node[i].Set(inarcs, outarcs, &component[i]);
//5
//    getch();
  }
  n=componentCnt;
  for(int i=0;i<n;i++)
  { int inarcs=node[i].GetPrevCount();
//6
//  cout<<"\n component #"<<i<<" have"<<node[i].GetPrevCount()<<" inputs";
//  cout<<" and "<<node[i].GetNextCount()<<" outputs";
//    cout<<"\n Ioi={";
    for(int j=0;j<inarcs;j++)
	{int t;
	 stream>>t;
         node[i].SetInNode(j,&node[t]);
//         cout<<t;
	}
//    cout<<"}\n";
    int outarcs=node[i].GetNextCount();
    for(int j=0;j<outarcs;j++)
	{int t;
	 stream>>t;
         node[i].SetOutNode(j, &node[t]);
	}
   }
//  return stream;
   ShowMessage("System properties were sucessfuly read");
}
//---------------------------------------------------------------------------
template <class T> void TMSSystem<T> :: EvaluateProbabilities(TNode<TMSComponent<T> >* node)
{ cout<<"\n operating in node #"<<node->GetIndex();

  for(int i=0; i<node->GetPrevCount();i++)
    { int idx=node->GetInNode(i).GetIndex();
      int isEst=component[idx].IsEsted();
      if(! isEst)
      {
        EvaluateProbabilities(&node->GetInNode(i));
      }
    }
  int isEst=component[node->GetIndex()].IsEsted();
  if(! isEst)
     { if(MonotoneSF(node))
       //if(ThreeStateSystemSF(node))
       print(cout, node->GetIndex());
//       getch();
     }
}
//---------------------------------------------------------------------------
template <class T>
T TMSSystem<T> ::ExpectedPerformance()
{ T performance;
  for(int i=0;i<stateCount();i++)
    performance=performance+statePerformanceLevel[i]*component[ComponentCount()-1].getStatePr(i);
 return performance;
}
/*------------------------------------------------------------------------------
        Class TMSEventTreeSet represents the set
        of fault trees for multi-state component
------------------------------------------------------------------------------*/
template <class T> class TMSEventTreeSet
{private:
        TETANode<T>** node;
        TNode<TMSComponent<T> >* comp;
 public:
        TMSEventTreeSet();
        TMSEventTreeSet(TNode<TMSComponent<T> >* c){comp=c};
        ~TMSEventTreeSet();
        friend ostream& operator<<(ostream& , TMSEventTreeSet& );
        friend istream& operator>>(istream& , TMSEventTreeSet& );
};
template <class T> TMSEventTreeSet<T>::TMSEventTreeSet()
{ // here should be detalizated
}
template <class T> TMSEventTreeSet<T>::~TMSEventTreeSet()
{ // here should be detalizated
}
template <class T> ostream& operator<<(ostream& stream, TMSEventTreeSet<T>& s)
{ stream.setf(ios::fixed);
  stream.setf(ios::showpoint);
  stream.precision(4);
// here should be detalizated
  return stream;
}
template <class T> istream& operator>>(istream& stream, TMSEventTreeSet<T>& s)
{
 LConnectFunctions<T> LCF;
 LInitFunctions<T> LIF;
 int k; //number of states
 stream>>k;
// create ET nodes set
 s.node=new TETANode<T>[k];
//
 for(int i=0;i<k;i++)
 { int n; //number of nodes in ET for state i
   stream>>n;
   s.node[i]=new TETANode<T>[n];
// for each node in ET set connections and properties
   for(int j=0;j<n; j++)
   { int h;  //out nodes number
     int g;  //out node index
     stream>>h;
     s.node[i][j].setOutNodeCount(h);
     for(int t=0;t<h;t++)
     { stream>>g;
       s.node[i][j].SetOutNode(t,&s.node[i][g]);
       //set parent node
       s.node[i][g].SetInNode(0,&s.node[i][j]);
     }
     // set logical function
     stream>>h; //get logical connection type
     //
     if(h==0) //initial node
     { int fi;
       int st;
       stream>>fi;  //get initial data
       stream>>st;
       s.node[i][j].setValue(LIF.l2pf[fi](comp,st));
     } else
     { stream>>g;
       s.node[i][j].set(LCF.lf[g]);
     }
   }
 }
 return stream;
}
/*------------------------------------------------------------------------------
        Function that makes recursive enumeration
        of nodes with their evaluation, therefore
        head node consists probability of state
------------------------------------------------------------------------------*/
template <class T>  BackThroughtETANodes(TETANode<T>* node)
{ int n=node->GetArgCount();
  for(int i=0; i<n;i++)
     BackThroughtNodes(node->GetOutNode(i));
  if(!IsEstimated())
     node->evaluate();
}
//------------------------------------------------------------------------------
#endif
