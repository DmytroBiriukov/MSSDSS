
//---------------------------------------------------------------------------
//   class TExpolynome by Dmitrij Birjukov
//---------------------------------------------------------------------------

#if !defined(EXPOLYNOME)
#define EXPOLYNOME
#include <math.h>
#include"polynome.h"

using namespace std;

class TExpolynome
{ private:
        TPolynome* a;
        double* b;
        int d;
        void reset(int );
  public:
        double c(int j, int k){return a[j].operator[](k);}
        void simplify();
        void integral();
        void diff();
        void inverse();
        double value(double);
        int deg(){return d;}
        TPolynome& geta(int i){return a[i];}
        double getb(int i){return b[i];}
        TPolynome& operator () (int index)
                {return a[index];
                }
        double& operator [] (int index)
                {return b[index];
                }
        void seta(TPolynome &v, int i){ a[i]=v;} //?????
        void setb(double v, int i){b[i]=v;}
        void init(TPolynome*, double*, int);
        init(int, int*, double**, double*);
        void init(int n);
        void operator=(const TExpolynome&);
        TExpolynome& operator=(TExpolynome& );
        TExpolynome& operator=(TPolynome&);
        friend TExpolynome& operator* (const TExpolynome&, const TExpolynome&);
        friend TExpolynome& operator+ (const TExpolynome&, const TExpolynome&);
        friend TExpolynome& operator- (const TExpolynome&, const TExpolynome&);

        TExpolynome& operator*=(TExpolynome&);
        TExpolynome& operator*=(TPolynome&);
        TExpolynome& operator*=(double);
        TExpolynome& operator+=(TExpolynome&);
        TExpolynome& operator+=(double);
        TExpolynome& operator-=(TExpolynome&);
        friend TExpolynome& operator* (TExpolynome&, TPolynome&);
        friend TExpolynome& operator* (TPolynome& m, TExpolynome& p) { return p*m;}
        friend TExpolynome& operator+ (TExpolynome&, TPolynome&);
        friend TExpolynome& operator+ (TPolynome& m, TExpolynome& p){ return p+m;}
        //ostream&
        void expolynome2TeX(ostream&);
        void expolynome2stream(ostream&);
        ostream& expolynome2MatLab(ostream&);
        friend ostream& operator<<(ostream&, const TExpolynome&);

        friend istream& operator>>(istream&, TExpolynome&);
        TExpolynome(){ d=0;}
        TExpolynome(int);
        TExpolynome(int, int*, double**, double*);
        TExpolynome(double a1)
              {d=1; a=new TPolynome[d]; b=new double[d];
               a[0]=a1; b[0]=0.0;
              }
        TExpolynome(istream& );
        ~TExpolynome(){;}
};
//---------------------------------------------------------------------------
TExpolynome::TExpolynome(int n, int* pn, double** pc, double* ac)
{ d=n;
  if(d)
  { a=new TPolynome[d];
    for(int i=0;i<d;i++)
    { a[i].init(pc[i],pn[i]);
    }
    b=new double[d];
    for(int i=0;i<d;i++) b[i]=ac[i];
  }
}
TExpolynome::init(int n, int* pn, double** pc, double* ac)
{ this->init(n);
  for(int i=0;i<d;i++)
  { a[i].init(pc[i],pn[i]);
    b[i]=ac[i];
  }

}
void TExpolynome::inverse()
{ for(int i=0;i<d;i++) b[i]*=(-1.0);
}
TExpolynome::TExpolynome(int n)
{ d=n;
  if(d)
  { a=new TPolynome[d];
    b=new double[d];
    for(int i=0;i<d;i++) b[i]=0.0;
  }
}
//---------------------------------------------------------------------------
double TExpolynome::value(double t)
{ double value=0.0;
  for(int i=0;i<d;i++)
    if(t!=0.0) value+=exp(b[i]*t)*a[i].value(t);
    else value+=a[i].operator[](0);
  return value;
}
//---------------------------------------------------------------------------
void TExpolynome::init(int n)
{ if(d) {delete[] a;   delete[] b;}
  d=n;
  if(d)
  { a=new TPolynome[d];
    b=new double[d];
    for(int i=0;i<d;i++) { b[i]=0.0; a[i]=0.0;}
  }
}
//---------------------------------------------------------------------------
void TExpolynome::simplify()
{int n=deg();
 for(int i=0;i<n-1;i++)
   for(int k=i+1;k<n;k++)
     { if(b[i]==b[k])
         { a[i]+=a[k];
           n--;
           a[k]=a[n];
           b[k]=b[n];
           k--;
//           cout<<"\n b[i]="<<b[i]<<"==b[k]="<<b[k];
         }
     }
 for(int i=0;i<n;i++)
    if(! a[i].isVal())
      { n--;
        a[i]=a[n];
        b[i]=b[n];
        i--;
      }
 if(n!=deg()) reset(n);
}
//---------------------------------------------------------------------------
bool equalOne(const TExpolynome& exp)
{ exp.simplify();
  if(exp.deg()==1 && exp.geta(0).isConst() && exp.geta(0).operator [](0)== 1.0)
  { return true;
  }
  return false;
}

void TExpolynome::reset(int n)
{
  if(n && n!=d)
  { TPolynome* t=new TPolynome[n];
    double* x=new double[n];
    if(d<n)
    { for(int i=0;i<d;i++) { t[i]=a[i]; x[i]=b[i];}
      for(int i=d;i<n;i++) {t[i]=0.0; x[i]=0.0;}
    }else  for(int i=0;i<n;i++) { t[i]=a[i]; x[i]=b[i];}
    this->init(t,x,n);
    delete[] t;  delete[] x;
  }else this->init(n);
}
//---------------------------------------------------------------------------
void TExpolynome::init(TPolynome* c, double* x, int n)
{ this->init(n);
  for(int i=0;i<n;i++) { a[i]=c[i]; b[i]=x[i];}
}
//---------------------------------------------------------------------------
void TExpolynome::operator= (const TExpolynome& p)
{ int n=p.deg();
  if(d!=n)
    {if(d) {delete [] a; delete [] b;}
     d=n;
     a=new TPolynome[d]; b=new double[d];
    }
  for(int i=0;i<d;i++) { a[i]=p.geta(i); b[i]=p.getb(i);}
}
//---------------------------------------------------------------------------
TExpolynome& TExpolynome::operator= (TExpolynome& p)
{ int n=p.deg();
  if(d!=n)
    {if(d) {delete [] a; delete [] b;}
     d=n;
     a=new TPolynome[d]; b=new double[d];
    }
  for(int i=0;i<d;i++) { a[i]=p.geta(i); b[i]=p.getb(i);}
  return *this;
}
//---------------------------------------------------------------------------
void TExpolynome::integral()
{
  for(int i=0; i< this->deg(); i++)
  { if(b[i]!=0.0)
    { int m=a[i].deg();
      double* d=new double [m];

      for(int k=0; k<m; k++)
      { d[k]=0.0;
        double s=c(i,k)/b[i];
        for(int j=1; j<=k+1; j++)
        {
          if( (j+2)%2 ) d[k-j+1]+=s;
          else d[k-j+1]-=s;
          if(b[j]!=0.0)
          s*=((double)(k-j+1))/b[j];
        }
      }
      for(int k=0; k<m; k++) a[i].operator[](k)=d[k];
      delete d;
    }else
    { a[i].integral();
    }
  }
  this->simplify();
}
//---------------------------------------------------------------------------
void TExpolynome::diff()
{
  for(int i=0;i<d;i++)
  { int m=a[i].deg();
    double* a1=new double[m];
    double* a2=new double[m];
    for(int j=0;j<m;j++) a1[j]=b[i]*a[i].operator[](j);
    for(int j=0;j<m-1;j++) a2[j]=(j+1)*a[i].operator[](j+1);
    for(int j=0;j<m;j++) a[i].operator[](j)=a1[j]+a2[j];
  }
}
//---------------------------------------------------------------------------
TExpolynome& operator* (const TExpolynome& p1, const TExpolynome& p2)
{ int n1=p1.deg();
  int n2=p2.deg();
  TExpolynome* t=new TExpolynome(n1*n2);
  for(int j=0;j<n1;j++)
  for(int k=0;k<n2;k++)
     {
       t->seta(p1.geta(j)*p2.geta(k),n2*j+k);
       t->setb(p1.getb(j)+p2.getb(k),n2*j+k);
     }
  t->simplify();
  return *t;
}
//---------------------------------------------------------------------------
TExpolynome& TExpolynome::operator= (TPolynome& a1)
{
  if(d!=1)
    {if(d) {delete [] a; delete [] b;}
     d=1;
     a=new TPolynome[1]; b=new double[1];
    }
  a[0]=a1; b[0]=0.0;
  return *this;
}
//---------------------------------------------------------------------------
TExpolynome& operator+ (const TExpolynome& p1, const TExpolynome& p2)
{ int n1=p1.deg();
  int n2=p2.deg();
  TExpolynome* t=new TExpolynome(n1+n2);
  for(int j=0;j<n1;j++) { t->seta(p1.geta(j),j); t->setb(p1.getb(j),j);}
  for(int k=0;k<n2;k++) { t->seta(p2.geta(k),n1+k); t->setb(p2.getb(k),n1+k);}
  t->simplify();
  return *t;
}
//---------------------------------------------------------------------------
TExpolynome& operator- (const TExpolynome& p1, const TExpolynome& p2)
{ int n1=p1.deg();
  int n2=p2.deg();
  TExpolynome* t=new TExpolynome(n1+n2);
  for(int j=0;j<n1;j++) { t->seta(p1.geta(j),j); t->setb(p1.getb(j),j);}
  for(int k=0;k<n2;k++) { t->seta((-1.0)*p2.geta(k),n1+k); t->setb(p2.getb(k),n1+k);}
  t->simplify();
  return *t;
}
//---------------------------------------------------------------------------
TExpolynome& TExpolynome::operator+= (TExpolynome& p)
{ int n=p.deg();
  int tn=d;
  this->reset(n+d);
  for(int i=0;i<n;i++) { a[tn+i]=p.geta(i); b[tn+i]=p.getb(i);}
  this->simplify();
  return *this;
}
//---------------------------------------------------------------------------
TExpolynome& TExpolynome::operator+=(double p)
{ this->reset(d+1);
  a[d-1]=p;
  b[d-1]=0.0;
  //cout<<"\n oper +=   ";
  //this->expolynome2TeX(cout);
  //this->simplify();
  //cout<<"\n after simplify   ";
  //this->expolynome2TeX(cout);
  this->simplify();
  return *this;
}
//---------------------------------------------------------------------------
TExpolynome& TExpolynome::operator-= (TExpolynome& p)
{ int n=p.deg();
  int tn=d;
  this->reset(n+d);
  for(int i=0;i<n;i++) { a[tn+i]=(-1.0)*p.geta(i); b[tn+i]=p.getb(i);}
  this->simplify();
  return *this;
}
//---------------------------------------------------------------------------
TExpolynome& TExpolynome::operator*= (TExpolynome& p)
{ int n=p.deg();
  TExpolynome* t=new TExpolynome(n*d);
  for(int j=0;j<n;j++)
  for(int k=0;k<d;k++)
     { t->seta(p.geta(j)*a[k],d*j+k);
       t->setb(p.getb(j)+b[k],d*j+k);
     }
  this->init(d*n);
  for(int i=0;i<d;i++) { a[i]=t->geta(i); b[i]=t->getb(i);}
  this->simplify();
  delete t;
  return *this;
}
//---------------------------------------------------------------------------
TExpolynome& TExpolynome::operator*= (TPolynome& m)
{ for(int i=0;i<d;i++) a[i]*=m;
  this->simplify();
  return *this;
}
//---------------------------------------------------------------------------
TExpolynome& TExpolynome::operator*= (double m)
{ for(int i=0;i<d;i++) a[i]*=m;
  this->simplify();
  return *this;
}
//---------------------------------------------------------------------------
TExpolynome& operator* (TExpolynome& p, double m)
{ int n=p.deg();
  TExpolynome* t=new TExpolynome(n);
  for(int i=0;i<n;i++) { t->seta(p.geta(i)*m,i); t->setb(p.getb(i),i);}
  t->simplify();
  return *t;
}
//---------------------------------------------------------------------------
TExpolynome& operator+ (TExpolynome& p, double m)
{ int n=p.deg();
  TExpolynome* t=new TExpolynome(n+1);
  for(int i=0;i<n;i++) { t->seta(p.geta(i),i); t->setb(p.getb(i),i);}
  t->seta(m,n); t->setb(0.0,n);
  t->simplify();
  return *t;
}
//---------------------------------------------------------------------------
ostream& operator<<(ostream& stream, const TExpolynome& p)
{ int n=p.deg();
  stream<<n;
  for(int i=0; i<n; i++)
     { stream<<"\n"; stream<<p.geta(i);
       stream<<"\n"; stream<<p.getb(i);
     }
  return stream;
}

void TExpolynome::expolynome2stream(ostream& stream)
{ int n=this->deg();
  stream<<n;
  for(int i=0; i<n; i++)
     { stream<<"\n"; stream<<this->geta(i);
       stream<<"\n"; stream<<this->getb(i);
     }

}

//ostream&
void TExpolynome::expolynome2TeX(ostream& stream)
{ //int prec=4;
// stream.setf(ios::scientific);
// stream.setf(ios::fixed);
// stream.setf(ios::showpoint);
// stream.precision(prec);
 int n=deg();
 int m=0;
 for(int i=0; i<n;i++)
     { if(i) stream<<"+";
       if(a[i].isVal())
       { if(! a[i].isConst())
         { stream<<"\\lgroup ";
           a[i].polynome2TeX(stream);
           stream<<" \\rgroup";
           if(getb(i)!=0.0) stream<<"\\cdot";
         }else a[i].polynome2TeX(stream);
       if(getb(i)!=0.0)
       { double b=getb(i); int pw=0;
         while(fabs(b)<1.0){b*=10.0; pw++;}
         if(pw) stream<<"\\exp("<<b<<"\\cdot 10^"<<pw<<"t)";
         else
         stream<<"\\exp("<<getb(i)<<"\\cdot t)";
       }
       m++;
       }else stream<<" NULL ";
     }
  if(!n)stream<<" n==0 !!! ";   
// return stream;
}

ostream& TExpolynome::expolynome2MatLab(ostream& stream)
{int n=deg();
 int m=0;
 for(int i=0; i<n;i++)
     {
//cutting very long formulae
       if(m && m%5==0) stream<<"\n";
       if(i) stream<<"+";
       if(n>1)
       { stream<<"("; geta(i).polynome2MatLab(stream); stream<<")";
       }else     geta(i).polynome2MatLab(stream);

       if(getb(i)!=0.0) stream<<".*exp("<<getb(i)<<"*t)";
       m++;
     }
 return stream;
}

istream& operator>>(istream& stream, TExpolynome& p)
{int t;
 stream>>t;
 p.init(t);
 for(int i=0; i<t;i++)
     { TPolynome tp(stream);
       double tf;
       p.seta(tp,i);
       stream>>tf;
       p.setb(tf,i);
     }
 return stream;
}

TExpolynome::TExpolynome(istream& stream)
{int t;
 stream>>t;
 this->init(t);
 for(int i=0; i<t;i++)
     { TPolynome tp(stream);
       this->seta(tp,i);
       double tf;
       stream>>tf;
       this->setb(tf,i);
     }
}

#endif
