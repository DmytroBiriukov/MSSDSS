/*------------------------------------------------------------------------------
        This source is developed by Dmitrij Birjukov
        to support various optimization methods of
        discrete optimization in complex systems
------------------------------------------------------------------------------*/
#if !defined(UTILS)
#define UTILS
#include"mss.h"

long Cnk(unsigned int n, unsigned int k)
{ unsigned int d=1;
  if(k > n/2) k=n-k;
  for(unsigned int i=0;i<k;i++)
  { d*=(n-i);
    d/=(i+1);
  }
  return d;
}
//  n! / k!
long frat(unsigned int n, unsigned int k)
{ unsigned int d=1;
  for(unsigned int i=n; i>k && i>1; i++) d*=i;
  return d;
}

enum TVertexAction{vaDrawing, vaMoving};
enum TDrawingTool{dtEllipse, dtLine, dtSquare, dtArrow, dtRound};
//---------------------------------------------------------------------------
struct TAnchor
{ unsigned int X;
  unsigned int Y;
  unsigned int X1;
  unsigned int Y1;
  unsigned int k;          //index of object in array
  TDrawingTool type;       //type of object
  
};
//------------------------------------------------------------------------------
// Monotone structure-function
template <class T> int MonotoneSF(TNode<TMSComponent<T> > *node)
{int allest=1;
 cout<<" MonotoneSF #"<<node->GetIndex();
 int stateCount=node->GetNode().stateCount();
 int inputCount=node->GetPrevCount();
 if(inputCount)
   {for(int i=0; i<inputCount;i++)
      if(! node->GetInNode(i).GetNode().IsEstimated())
        {allest=0;
         break;
        }
    if(allest)
      {  T** pi;
         pi=new T*[inputCount];
         for(int i=0; i<inputCount;i++)
            { pi[i]=new T[stateCount];
              for(int s=0;s<stateCount;s++)
                 pi[i][s]=node->GetInNode(i).GetNode().getStatePr(s);
            }
         T* p1=new T[inputCount];
         T* p2=new T[inputCount];
         T p11; T p22;
         for(int i=0; i<inputCount;i++){ p1[i]=0.0; p2[i]=0.0;}
         for(int s=0;s<stateCount;s++)
            { for(int i=0; i<inputCount;i++)
                 { p1[i]+=pi[i][s];
                   if(s) p2[i]+=pi[i][s-1];
                  }

              p11=1.0; p22=1.0;
              for(int i=0; i<inputCount;i++) { p11*=p1[i]; p22*=p2[i];}
              T p3; p3=p11-p22;
              node->GetNode().setStatePr(s,p3);
            }
         T* p4=new T[stateCount];
         T* p5=new T[stateCount];
         T* p6=new T[stateCount];
         for(int s=0; s<stateCount; s++)
            p4[s]=node->GetNode().getStatePr(s);
         for(int s=0; s<stateCount; s++) p5[s]=p4[s];

         for(int s=1; s<stateCount; s++)
            p5[stateCount-s-1]+=p5[stateCount-s];
         p6[stateCount-1]=0.0;
         for(int s=1; s<stateCount; s++)
            p6[stateCount-s-1]=p6[stateCount-s]+node->GetNode().getPr(stateCount-s);
         for(int s=0; s<stateCount; s++)
            { T r; r=node->GetNode().getPr(s)*p5[s]+p6[s]*p4[s];
              node->GetNode().setStatePr(s,r);
            }
         node->GetNode().IsEstimated(1);
       }
   }
   else
   {for(int j=0;j<stateCount;j++)
      node->GetNode().setStatePr(j,node->GetNode().getPr(j));
    node->GetNode().IsEstimated(1);
   }
 return allest;
}
//------------------------------------------------------------------------------
// Binary-state structure function
template <class T> int BinarySystemSF(TNode<TMSComponent<T> > *node)
{ int allest=1;
  cout<<" Binary-state system SF #"<<node->GetIndex();
  int inputCount=node->GetPrevCount();
  if(inputCount)
   {for(int i=0; i<inputCount;i++)
      if(! node->GetInNode(i).GetNode().IsEstimated())
        {allest=0;
         break;
        }
      if(allest)
      {
         T** pi;
         pi=new T*[inputCount];
         for(int i=0; i<inputCount;i++)
            { pi[i]=new T[2];
              for(int s=0;s<2t;s++)
                 pi[i][s]=node->GetInNode(i).GetNode().getStatePr(s);
            }
         T p; p=1.0;
         for(int i=0; i<inputCount;i++) p*=pi[i][0];
         T p0; p0=1.0; p0*=p; p0*=node->GetNode().getPr(1); p0+=node->GetNode().getPr(0);
         T p1; p1=1.0; p1-=p; p1*=node->GetNode().getPr(1);
         node->GetNode().setStatePr(0,p0);
         node->GetNode().setStatePr(1,p1);
      }
   }else
   {for(int j=0;j<2;j++)
      node->GetNode().setStatePr(j,node->GetNode().getPr(j));
    node->GetNode().IsEstimated(1);
   }
  return allest;
}
//------------------------------------------------------------------------------
// 3SS structure function
template <class T> int ThreeStateSystemSF(TNode<TMSComponent<T> > *node)
{int allest=1;
 cout<<" 3SS SF #"<<node->GetIndex();
 int stateCount=node->GetNode().stateCount();
 int inputCount=node->GetPrevCount();
 if(inputCount)
   {for(int i=0; i<inputCount;i++)
      if(! node->GetInNode(i).GetNode().IsEstimated())
        {allest=0;
         break;
        }
      if(allest)
        {
         T** pi;
         pi=new T*[inputCount];
         for(int i=0; i<inputCount;i++)
            { pi[i]=new T[stateCount];
              for(int s=0;s<stateCount;s++)
                 pi[i][s]=node->GetInNode(i).GetNode().getStatePr(s);
            }
         T* p1=new T[inputCount];
         T* p2=new T[inputCount];
         T* p0=new T[stateCount];
         T p11; T p22;
         for(int i=0; i<inputCount;i++){ p1[i]=0.0; p2[i]=0.0;}
         for(int s=0;s<stateCount;s++)
            { for(int i=0; i<inputCount;i++)
                 { p1[i]+=pi[i][s];
                   if(s) p2[i]+=pi[i][s-1];
                 }
              p11=1.0; p22=1.0;
              for(int i=0; i<inputCount;i++) { p11*=p1[i]; p22*=p2[i];}
              p0[s]=p11-p22;
            }
         p11=1.0;
         p22=1.0;
         for(int i=0; i<inputCount;i++) p22*=(p11-pi[i][1]);

node->GetNode().setStatePr(0,p0[0]*(node->GetNode().getPr(1)+node->GetNode().getPr(2))+node->GetNode().getPr(0));
node->GetNode().setStatePr(1,p0[1]*(p11-p22));
node->GetNode().setStatePr(2,p11-(node->GetNode().getStatePr(0)+node->GetNode().getStatePr(0)));
         node->GetNode().IsEstimated(1);
        }
   }
   else
   {for(int j=0;j<stateCount;j++)
      node->GetNode().setStatePr(j,node->GetNode().getPr(j));
    node->GetNode().IsEstimated(1);
   }
 return allest;
}
//------------------------------------------------------------------------------
template<class T> class TSwitchSystem
{private:
        TMSComponent<T>* comp;
        bool isEval;
        unsigned short m; //number of states
        unsigned short mo; //number of 'failure' states
// failure state located in the begining of states' array
        unsigned short k; //number of allowed comp versions
        unsigned short lambda; //number of redundant comps
        unsigned short* kappa; //design vector - selected versions of comps
        unsigned short l; //number of technical characteristics
        float** c; //coef for technical characteristic l of comp version k
        float* a;  //total supply of resource type l
        T** rho;
	T* q;
	T* p;
        T* pi;
        T IntInversed(T , T );
  public:
        TSwitchSystem(){;}
        TSwitchSystem(istream& stream){scanf(stream);}
        ~TSwitchSystem(){;}
        void scanf(istream&);
        void printf(ostream&);
        unsigned int getLambda(){return lambda;}
        void eval(unsigned short, unsigned short*);
        void link2Component(TMSComponent<T>* c){comp=c;}
        void setPr();
	void settings(unsigned short& m1, unsigned short& mo1, unsigned short& k1){m1=m; mo1=mo; k1=k;}
	float supply(unsigned int i){return a[i];}
        T& Pi(int position)
                {return pi[position];
                }
        T& P(int state)
                {return p[state];
                }
        T& Rho (int index, int state)
                {return rho[index][state];
                }
        unsigned short stateCount(){ return m;}
        unsigned short versionCount(){ return k;}
};
//------------------------------------------------------------------------------
template<class T> void TSwitchSystem<T>::scanf(istream& stream)
{ isEval=false;
  stream>>m;
  stream>>mo;
  stream>>k;
  stream>>l;
  rho=new T*[k];
  p=new T[m];
  q=new T[k];
  c=new float*[k];
  for(unsigned short i=0;i<k;i++)
  {  rho[i]=new T[m];
     for(unsigned short j=0;j<m;j++)
     { stream>>rho[i][j];
     }

     for(unsigned short j=0;j<mo;j++) q[i]+=rho[i][j];

     q[i]*=(-1.0);
     q[i]+=1.0;
     q[i].simplify();
/**/
//     for(unsigned short j=mo;j<m;j++) q[i]+=rho[i][j];
//     q[i].simplify();
     if(l) c[i]=new float[l];
     for(unsigned short j=0;j<l;j++) stream>>c[i][j];
  }
}
//------------------------------------------------------------------------------
template<class T> void TSwitchSystem<T>::printf(ostream& stream)
{
  stream<<m<<"\n";
  stream<<mo<<"\n";
  stream<<k<<"\n";
  stream<<l<<"\n";
  for(unsigned short i=0;i<k;i++)
  {  for(unsigned short j=0;j<m;j++) stream<<rho[i][j]<<" ";
     stream<<"\n";
     for(unsigned short j=0;j<l;j++) stream<<c[i][j]<<" ";
     stream<<"\n";
  }
  stream<<"\n";
  for(unsigned short i=0;i<=lambda;i++)
  { stream<<"\rho_"<<i+1<<"(t)=";
    pi[i].expolynome2TeX(stream);
    stream<<"\n";
  }
  stream<<"\n";
  for(unsigned short i=0;i<m;i++)
  { stream<<"\p_"<<i+1<<"(t)=";
    p[i].expolynome2TeX(stream);
    stream<<"\n";
  }
}
//------------------------------------------------------------------------------
template<class T> T TSwitchSystem<T>::IntInversed(T f1, T f2)
{ T tmp;
  AnsiString str=ExtractFilePath(Application->ExeName)+"/data/debug.log";
  using namespace std;
  ofstream stream; stream.open(str.c_str(), 3);
  if(! stream.fail())
  { f2.diff(); f2.simplify();
    stream<<"\n\n f1      = "; f1.expolynome2MatLab(stream);
    stream<<"\n diff f2 = "; f2.expolynome2MatLab(stream);
    unsigned int n2=f2.deg();
    unsigned int n1=f1.deg();
    tmp.init(n1*n2+n2);
    for(unsigned int i=0; i<n2; i++)
    { for(unsigned int l=0; l<n1; l++)
      { unsigned int n3=f1.geta(l).deg()+f2.geta(i).deg();
        TPolynome tp_ub(n3);
        TPolynome tp_lb(n3);
        unsigned int n4j=f1.geta(l).deg();
        unsigned int n4k=f2.geta(i).deg();

        stream<<"\n ["<<i<<","<<l<<"] betta coefs ["<<f2.getb(i)<<","<<f1.getb(l)<<"]\n";
/*        for(unsigned int j=0;  j<n4j;  j++)
          for(unsigned int k=0;  k<n4k;  k++)
          { double aij=f1.geta(l).operator[](j);
            double alk=f2.geta(i).operator[](k);
            stream<<"\n aij["<<l<<","<<j<<"]="<<aij<<" alk["<<i<<","<<k<<"]="<<alk;
          }
*/
        if( f2.getb(i) == f1.getb(l) )
        { /*---  case b)    */
          for(unsigned int j=0;  j<n4j;  j++)
            for(unsigned int k=0;  k<n4k;  k++)
            { double aij=f1.geta(l).operator[](j);
              double alk=f2.geta(i).operator[](k);
              for(unsigned int s=0; s<=j ; s++)
                tp_ub[k+j+1]+= ( aij*alk*Cnk(j,s) / (double)(k+j-s+1) );
            }
          stream<<"\n ==  ub ["<<i<<","<<l<<"]";
          tp_ub.polynome2MatLab(stream);
        }else
        { /*---  case a)    */
          double aprod=1.0;
          for(int s=1; s<n3; s++)
          { aprod*=(1.0 / ( f2.getb(i)-f1.getb(l) ) );
            double msign=(-1.0);
            if(s % 2) msign=1.0;
            double innerprod=aprod*msign;
            for(int j=0;  j<n4j;  j++)
             for(int k=0;  k<n4k;  k++)
             { double aij=f1.geta(l).operator[](j);
               double alk=f2.geta(i).operator[](k);
               double ad;
/*---  low bound - 0  */
               if( (s-k-1 > 0) && (j+k-s+1 > 0) )
               { ad=aij*alk*Cnk(s-1, s-k-1)*frat(k,1)*frat(j, j-s+k+1);
                 if(s-k-1 % 2) ad*=(-1.0);
                 tp_lb[j-s+k+1]+=(ad*innerprod);
                 stream<<"\n !=  lb ["<<i<<","<<l<<"]";
                 tp_lb.polynome2MatLab(stream);

               }
/*---  upper bound - t  */
               if( k+j-s+1 > 0 )
               { ad=aij*alk*Cnk(s-1, j)*frat(k,k+j-s+1)*frat(j, 1);
                 if(j % 2) ad*=(-1.0);
                 tp_ub[k+j-s+1]+=(ad*innerprod);
                 stream<<"\n !=  ub ["<<i<<","<<l<<"] k="<<k<<" j="<<j<<" s="<<s<<" k+j-s+1  ="<<(k+j-s+1)<<" \n  ";
                 tp_ub.polynome2MatLab(stream);

               }
             }
          }
        }
        tmp.setb(f1.getb(l),n1*i+l);
        tmp.seta(tp_ub,n1*i+l);
        tmp.setb(f2.getb(i),n1*n2+i);
        tmp.seta(tp_lb,n1*n2+i);
//        tmp.simplify();
        stream<<"\n after "<<n1*i+l<<" was set";
        tmp.expolynome2MatLab(stream);
      }
    }
    stream<<"\n as is\n";
    tmp.expolynome2MatLab(stream);
    tmp.simplify();
    stream<<"\n\n ***** finally simplified \n";
    tmp.expolynome2MatLab(stream);
    stream.close();
  }
  return tmp;
}
//------------------------------------------------------------------------------
template<class T> void TSwitchSystem<T>::eval(unsigned short v, unsigned short* w)
{ if(isEval)
  { delete[] pi;
    delete[] kappa;
  }

  AnsiString str=ExtractFilePath(Application->ExeName)+"/data/debug2.log";
  using namespace std;
  ofstream stream;
  stream.open(str.c_str(), 0);
  if(! stream.fail())
  {

  lambda=v;
  stream<<"\n$ n_i^{*}="<<lambda<<" $";
  pi=new T[lambda+1];
  kappa=new unsigned short[lambda];
  for(unsigned short i=0;i<lambda;i++)
  { kappa[i]=w[i];
    stream<<"\n$ q["<<i<<"]=";
    q[kappa[i]].expolynome2MatLab(stream);
    stream<<" $";
  }
  pi[0]=q[kappa[0]];
/*  pi[0]*=(-1.0);
  pi[0]+=1.0;
  pi[0].simplify();
*/
  stream<<"\n pi["<<0<<"]=";
  pi[0].expolynome2MatLab(stream);

  for(unsigned short j=0;j<lambda;j++)
  { pi[j+1]=IntInversed( q[kappa[j]], pi[j] );
    stream<<"\n pi["<<j+1<<"]=";
    pi[j+1].expolynome2MatLab(stream);
  }

  for(unsigned short s=0;s<mo;s++)
  { p[s]=pi[lambda];
    stream<<"\n p["<<s<<"]=";
    p[s].expolynome2MatLab(stream);
  }

  for(unsigned short s=mo;s<m;s++)
  { T tmp1;
    for(unsigned short i=0;i<lambda;i++)
    { tmp1=IntInversed(rho[kappa[i]][s],pi[i]);
      p[s]+=tmp1;
    }
    stream<<"\n p["<<s<<"]=";
    p[s].expolynome2TeX(stream);
  }

  /*
  for(unsigned short j=0;j<l;j++)
  { a[j]=0.0;
     for(unsigned short i=0;i<lambda;i++)  a[j]+=c[kappa[i]][j];
  }
  */

    stream.close();
  }


  isEval=true;
}
//------------------------------------------------------------------------------
template<class T> void TSwitchSystem<T>::setPr()
{  for(unsigned short i=0; i<m ;i++)
   comp->stateProbability(i, *p);
}
//------------------------------------------------------------------------------
struct biIndex
{ int i;
  double j;
};
int biIndexCmp(const void* a, const void* b)
{ biIndex* x=(biIndex*)a;
  biIndex* y=(biIndex*)b;
  if(x->j > y->j) return 1; else return 0;
}
template <class T>
ostream& exponomicDraw2TeX(ostream& stream, TDrawParams p,const TMSComponent<T>& comp)
{
 int left_margin=20;
 int right_margin=10;
 int bottom_margin=10;
 int top_margin=10;

 stream<<"\n \\begin{picture}("<<p.width+80<<","<<p.height+bottom_margin+top_margin<<")";
 stream<<"\n\t \\put("<<left_margin<<",10){\\vector(1,0){"<<p.width+30<<"} }";
 stream<<"\n\t \\put("<<left_margin<<",10){\\vector(0,1){"<<p.height+10<<"} }";
 stream<<"\n\t \\put("<<p.width+50<<",15){$t$}";
 const int n=comp.stateCount();
 struct biIndex* arrayLegend=new biIndex[n];

 int h=p.width/p.n;
 int h2=p.height/5;
 int dlt=p.Xscale/p.n; int mrk=0;      int shift=-4; long int deg=1;
 stream<<"\\multiput("<<left_margin<<","<<bottom_margin<<")("<<h<<",0){"<<p.n+1<<"}{\\line(0,1){2}}";
 stream<<"\\multiput("<<left_margin<<","<<bottom_margin+h2<<")(0,"<<h2<<"){5}{\\line(1,0){2}}";
 for(int i=0;i<5;i++)
    {float Ytxt=0.2*(i+1);
     stream<<"\\put(5,"<<8+h2*(i+1)<<"){"<<Ytxt<<"}";
    }
 for(int i=0;i<p.n+1;i++)
    {
     while(mrk/deg) {deg*=10; shift-=2;}
     stream<<"\n\t \\put("<<left_margin+shift+i*h<<",0){"<<mrk<<"}";
     if(i<p.n)
       {
        for(int s=0;s<n;s++)
           {int point_a=bottom_margin+p.height*comp.getStatePr(s).value(i*dlt);
            int point_b=bottom_margin+p.height*comp.getStatePr(s).value((i+1)*dlt);
            int point_c=bottom_margin+p.height*comp.getStatePr(s).value(i*dlt+dlt/2);
            //point_c=  (point_a+point_b)/2;
            stream<<"\n\t \\qbezier("<<left_margin+i*h<<","<< point_a<<")";
            stream<<"("<<left_margin+i*h+h/2<<","<<point_c<<")";
            stream<<"("<<left_margin+(i+1)*h<<","<<point_b<<")";
           }
       }else
       { for(int s=0;s<n;s++)
           {
             arrayLegend[s].i=s;
             arrayLegend[s].j=comp.getStatePr(s).value(p.Xscale);
           }
         for(int s=0;s<n;s++)
            for(int j=s+1;j<n;j++)
               if(arrayLegend[s].j>arrayLegend[j].j)
                 {  double tmp=arrayLegend[s].j;
                    arrayLegend[s].j=arrayLegend[j].j;
                    arrayLegend[j].j=tmp;
                    int tmpi=arrayLegend[s].i;
                    arrayLegend[s].i=arrayLegend[j].i;
                    arrayLegend[j].i=tmpi;
                 }
         for(int s=0;s<n;s++)
           {
//             stream<<"\n\t \\put("<<p.width+50<<","<<18*s+30<<"){$\\rho_{"<<comp.GetIndex()<<"}^{("<<arrayLegend[s].i+1<<")}(t)$}";
             stream<<"\n\t \\put("<<p.width+50<<","<<18*s+30<<"){$ p_{i}^{("<<arrayLegend[s].i+1<<")}(t)$}";
             int pa=left_margin+p.width;
             int pb=bottom_margin+p.height*comp.getStatePr(arrayLegend[s].i).value(p.Xscale);
             stream<<"\n\t \\qbezier[16]("<<p.width+45<<","<<18*s+32<<")("<<(p.width+45+pa+2)/2<<","<<(pb+18*s+32)/2<<")("<<pa+2<<","<<pb<<")";
           }
       }
     mrk+=dlt;

    }
 stream<<"\n \\end{picture} \n";
 return stream;
}
/*------------------------------------------------------------------------------
   This function loads prob characteristics of
   different design variants of systems components
   T[i][k][s] = Pr{ comp[i] type[k] state[s] }
   TExponome class should be used instead T.
------------------------------------------------------------------------------*/
template <class T> void LoadVariants(fstream& stream, T*** v)
{ int n, m, k;
  stream>>n;
  v=new T**[n];
  cout<<"n="<<n;
  for(int i=0;i<n;i++)
     { stream>>k;  stream>>m;
       cout<<"  k["<<i+1<<"]="<<k; cout<<" m["<<i+1<<"]="<<m;
       v[i]=new T*[k];
       for(int j=0;j<k;j++)
          { v[i][j]=new T[m];
           for(int h=0;h<m;h++)
              {stream>>v[i][j][h];
               cout<<v[i][j][h];
              }
          }
     }
}
//------------------------------------------------------------------------------
#endif














