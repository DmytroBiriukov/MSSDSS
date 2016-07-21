/*------------------------------------------------------------------------------
        This source is developed by Dmitrij Birjukov
        to support various optimization methods of
        discrete optimization in complex systems
------------------------------------------------------------------------------*/
#if !defined(SYS)
#define SYS
//------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include <string.h>
#include <math>
#include <algorithm>
#include <values.h>

using namespace std;
/*------------------------------------------------------------------------------
        TNode class developed to organize oriented graf configuration
------------------------------------------------------------------------------*/
template <class T> class TNode
{protected:
        int prevCnt;
        TNode<T>* prev;
        T* node;
	int nextCnt;
        TNode<T>* next;
        int index;
 public:
        friend ostream& operator<< (ostream &outs, const TNode<T>& node);
        friend istream& operator>> (istream &ins, TNode<T>& node);
        int GetIndex(){return index;}
        void SetIndex(int i){index=i;}
        int GetPrevCount()
                {return prevCnt;
                }
        int GetNextCount()
                {return nextCnt;
                }
        void SetInNode(int index, TNode<T>* n)
		{ prev[index]=*n;
		}
        void SetOutNode(int index, TNode<T>* n)
		{ next[index]=*n;
		}
        T& GetNode()
                {return *node;
                }
        TNode<T>& GetInNode(int index)
                {return prev[index];
                }
        TNode<T>& GetOutNode(int index)
                {return next[index];
                }
        TNode()
                { node=new T;
                }
        virtual void Set(int pc, int nc, T *np)
                { prevCnt=pc;
		  prev=new TNode<T>[prevCnt];
		  nextCnt=nc;
		  next=new TNode<T>[nextCnt];
		  node=np;
                }
};

template <class T>
ostream& operator << (ostream &outs, const TNode<T>& node)
{outs<<node;
 return outs;
}
template <class T>
istream& operator>> (istream &ins, TNode<T>& node)
{
 ins>>node;
 return ins;
}
/*        ~TNode()
                {delete[] next;
                 delete[] prev;
                }
*/
#endif


