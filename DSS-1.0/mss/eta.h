/*------------------------------------------------------------------------------
        This source is developed by Dmitrij Birjukov to support
        Event Tree Analisys technique for multi-state
        complex-structured systems
------------------------------------------------------------------------------*/
#if !defined(ETA)
#define ETA
#include"sys.h"
using namespace std;
/*------------------------------------------------------------------------------
        class TETANode represents the node of fault tree
------------------------------------------------------------------------------*/
template <class T> class TETANode : public TNode<T>
{private:
        unsigned short isEst;
        T value;
        T (*f)(TETANode<T>* );
 public:
        unsigned short& IsEstimated()
                {return isEst;
                }
        void evaluate()
                {value=f(this);
                 isEst=1;
                }
        T& GetValue()
                {return value;
                }
        void set(T (*ff)(TETANode<T>*))
                {f=ff;
                }
        void setValue(T val)
                {value=val;
                 isEst=1;
                }
        TETANode(T val)
                {value=val;
                 isEst=1;
                }
        TETANode(T (*ff)(TETANode<T>*))
                {f=ff;
                }
};
/*------------------------------------------------------------------------------
        Functions that describe logics-to-probability transforms
        on logical level of Fault Tree
------------------------------------------------------------------------------*/
template <class T> T logical_and(TETANode<T> * node)
{ T tmp;
  for(int i=0;i<node->GetNextCount();i++)
     tmp=tmp+node->GetOutNode(i)->GetValue();
  return tmp;
}
template <class T> T logical_or(TETANode<T> * node)
{ T tmp; tmp=1.0;
  for(int i=0;i<node->GetNextCount();i++)
     tmp=tmp*node->GetOutNode(i)->GetValue();
  return tmp;
}
template <class T> T logical_inverse(TETANode<T> * node)
{ T tmp; tmp=1.0;
  tmp=tmp-node->GetValue();
  return tmp;
}
template <class T> T logical_nor(TETANode<T> * node)
{ return node->GetValue();
}
//------------------------------------------------------------------------------
template <class T> struct LConnectFunctions
{ T (*(lf[4]))(TETANode<T> *);
  LConnectFunctions()
  { lf={logical_or, logical_and, logical_inverse, logical_nor};
  }
};
/*------------------------------------------------------------------------------
        Functions that describe logics-to-probability transforms
        on initial level of Event Tree Analisys
------------------------------------------------------------------------------*/
template <class T> T equalto(TNode<T> * node, int state)
{return node->comp->getPr(state);
}
template <class T> T lessthen(TNode<T> * node, int state)
{T tmp;
 for(int i=0;i<state;i++)
   tmp=tmp+node->comp->getPr(i);
 return tmp;
}
template <class T> T morethen(TNode<T> * node, int state)
{T tmp;
 for(int i=state;i<node->comp->stateCount();i++)
   tmp=tmp+node->comp->getPr(i);
 return tmp;
}
template <class T> T notlessthen(TNode<T> * node, int state)
{return (morethen(node, state)+node->comp->getPr(state) );
}
template <class T> T notmorethen(TNode<T> * node, int state)
{return (lessthen(node, state)+node->comp->getPr(state) );
}
template <class T> T inverse(TNode<T> * node, int state)
{T tmp; tmp=1.0;
 return (tmp-node->comp->getPr(i));
}
//------------------------------------------------------------------------------
template <class T> struct LInitFunctions
{ T (*(l2pf[6]))(TNode<T> *, int);
  LInitFunctions()
  { l2pf={equalto, inverse, lessthen, morethen, notlessthen, notmorethen};
  }
};
#endif


