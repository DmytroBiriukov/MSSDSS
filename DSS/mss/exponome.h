
//---------------------------------------------------------------------------
//   class TExponome by Dmitrij Birjukov
//---------------------------------------------------------------------------

#if !defined(EXPONOME)
#define EXPONOME
#include <math.h>

using namespace std;

class TExponome
{ private:
        double* a;
        double* b;
        int d;
        void reset(int );
  public:
        void simplify();
        void integral();
        void diff();
        void integral(const TExponome&);
        void diff(const TExponome&);
        double value(double);
        int deg(){return d;}
        double geta(int i){return a[i];}
        double getb(int i){return b[i];}
//
        double& operator () (int index)
                {return a[index];
                }
        double& operator [] (int index)
                {return b[index];
                }
        void seta(double v, int i){a[i]=v;}
        void setb(double v, int i){b[i]=v;}
        void init(double*, double*, int);
        void init(int n);
        void operator=(const TExponome&);
        TExponome& operator=(TExponome& );
        TExponome& operator=(double);
        friend TExponome& operator* (const TExponome&, const TExponome&);
        friend TExponome& operator+ (const TExponome&, const TExponome&);
        friend TExponome& operator- (const TExponome&, const TExponome&);
        TExponome& operator*=(TExponome&);
        TExponome& operator*=(double);
        TExponome& operator+=(TExponome&);
        TExponome& operator-=(TExponome&);
        friend TExponome& operator* (TExponome&, double);
        friend TExponome& operator* (double m, TExponome& p) { return p*m;}
        friend TExponome& operator+ (TExponome&, double);
        friend TExponome& operator+ (double m, TExponome& p){ return p+m;}
        ostream& exponome2TeX(ostream&);
        ostream& exponome2MatLab(ostream&);        
        friend ostream& operator<<(ostream&, const TExponome&);
        friend istream& operator>>(istream&, TExponome&);
        TExponome(){ d=0;}
        TExponome(int);
        TExponome(double a1)
              {d=1; a=new double[d]; b=new double[d];
               a[0]=a1; b[0]=0.0;
              }
        ~TExponome();
};
//---------------------------------------------------------------------------
TExponome::TExponome(int n)
{ d=n;
  if(d){
  a=new double[d];
  b=new double[d];
  for(int i=0;i<d;i++) a[i]=b[i]=0.0;
  }
}
//---------------------------------------------------------------------------
TExponome::~TExponome()
{// if(d)
 // { delete[] a; delete[] b;}
}
//---------------------------------------------------------------------------
double TExponome::value(double t)
{ double value=0.0;
  for(int i=0;i<d;i++)  value+=exp(b[i]*t)*a[i];
  return value;
}
//---------------------------------------------------------------------------
void TExponome::init(int n)
{ if(d) {delete[] a;   delete[] b;}
 d=n;
  if(d) {a=new double[d];    b=new double[d];
  for(int i=0;i<d;i++) a[i]=b[i]=0.0;   }
}
//---------------------------------------------------------------------------
void TExponome::simplify()
{
 for(int i=0;i<d;i++)
   for(int k=i+1;k<d;k++)
     { if(b[i]==b[k])
         { a[i]+=a[k];
           a[k]=a[d-1];
           b[k]=b[d-1];
           a[d-1]=0.0;
           d--;
         }
     }

 for(int i=0;i<d;i++)
    if(a[i]==0.0)
      { a[i]=a[d-1];
        b[i]=b[d-1];
        d--;
      }
 reset(d);
}
//---------------------------------------------------------------------------
void TExponome::reset(int n)
{
  if(n){ double* t=new double[n];
              double* x=new double[n];
              if(d<n)
                {for(int i=0;i<d;i++) { t[i]=a[i]; x[i]=b[i];}
                 for(int i=d;i<n;i++) t[i]=x[i]=0.0;
                } else  for(int i=0;i<n;i++) { t[i]=a[i]; x[i]=b[i];}
              init(n);
              for(int i=0;i<d;i++) { a[i]=t[i]; b[i]=x[i];}
              delete[] t;  delete[] x;
            }
       else { init(n);}

}
//---------------------------------------------------------------------------
void TExponome::init(double* c, double* x, int n)
{ this->init(n);
  for(int i=0;i<n;i++) { a[i]=c[i]; b[i]=x[i];}
}
//---------------------------------------------------------------------------
void TExponome::operator= (const TExponome& p)
{ int n=p.deg();
  if(d!=n)
    {if(d) {delete [] a; delete [] b;}
     d=n;
     a=new double[d]; b=new double[d];
    }
  for(int i=0;i<d;i++) { a[i]=p.geta(i); b[i]=p.getb(i);}
}
//---------------------------------------------------------------------------

TExponome& TExponome::operator= (TExponome& p)
{ int n=p.deg();
  if(d!=n)
    {if(d) {delete [] a; delete [] b;}
     d=n;
     a=new double[d]; b=new double[d];
    }
  for(int i=0;i<d;i++) { a[i]=p.geta(i); b[i]=p.getb(i);}
  return *this;
}
void TExponome::integral(const TExponome& p)
{ int n=p.deg();
  if(d!=n)
    {if(d) {delete [] a; delete [] b;}
     d=n;
     a=new double[d]; b=new double[d];
    }
  for(int i=0;i<d;i++)
  { a[i]=p.geta(i)/p.getb(i);
    b[i]=p.getb(i);
  }
}
void TExponome::integral()
{ for(int i=0;i<d;i++) a[i]/=b[i];
}
void TExponome::diff()
{ for(int i=0;i<d;i++) a[i]*=b[i];
}
void TExponome::diff(const TExponome& p)
{ int n=p.deg();
  if(d!=n)
    {if(d) {delete [] a; delete [] b;}
     d=n;
     a=new double[d]; b=new double[d];
    }
  for(int i=0;i<d;i++)
  { a[i]=p.geta(i)*p.getb(i);
    b[i]=p.getb(i);
  }
}
//---------------------------------------------------------------------------
TExponome& operator* (const TExponome& p1, const TExponome& p2)
{ int n1=p1.deg();
  int n2=p2.deg();
  int n=n1*n2;
  TExponome* t=new TExponome(n);
  double s;
  double c;
  for(int j=0;j<n1;j++)
  for(int k=0;k<n2;k++)
     { s=c=0.0;
       s=p1.geta(j)*p2.geta(k);
       c=p1.getb(j)+p2.getb(k);
       t->seta(s,n2*j+k);
       t->setb(c,n2*j+k);
     }
  t->simplify();
  return *t;
}
//---------------------------------------------------------------------------
TExponome& TExponome::operator= (double a1)
{ /*if(d>0){  d=1; a[0]=a1; b[0]=0.0;}
          else {d=1; a=new double[d]; b=new double[d];
               a[0]=a1; b[0]=0.0;}
  return *this;*/
  if(d!=1)
    {if(d) {delete [] a; delete [] b;}
     d=1;
     a=new double[1]; b=new double[1];
    }
  a[0]=a1; b[0]=0.0;
  return *this;
}
//---------------------------------------------------------------------------
TExponome& operator+ (const TExponome& p1, const TExponome& p2)
{ int n1=p1.deg();
  int n2=p2.deg();
  int n=n1+n2;
  TExponome* t=new TExponome(n);
  for(int j=0;j<n1;j++) { t->seta(p1.geta(j),j); t->setb(p1.getb(j),j);}
  for(int k=0;k<n2;k++) { t->seta(p2.geta(k),n1+k); t->setb(p2.getb(k),n1+k);}
  t->simplify();
  return *t;
}
//---------------------------------------------------------------------------
TExponome& operator- (const TExponome& p1, const TExponome& p2)
{ int n1=p1.deg();
  int n2=p2.deg();
  int n=n1+n2;
  TExponome* t=new TExponome(n);
  for(int j=0;j<n1;j++) { t->seta(p1.geta(j),j); t->setb(p1.getb(j),j);}
  for(int k=0;k<n2;k++) { t->seta((-1.0)*p2.geta(k),n1+k); t->setb(p2.getb(k),n1+k);}
  t->simplify();
  return *t;
}
//---------------------------------------------------------------------------
TExponome& TExponome::operator+= (TExponome& p)
{ int n=p.deg();
  int tn=d;
  this->reset(n+d);
  for(int i=0;i<n;i++) { a[tn+i]=p.geta(i); b[tn+i]=p.getb(i);}
  this->simplify();
  return *this;
}
//---------------------------------------------------------------------------
TExponome& TExponome::operator-= (TExponome& p)
{ int n=p.deg();
  int tn=d;
  this->reset(n+d);
  for(int i=0;i<n;i++) { a[tn+i]=(-1.0)*p.geta(i); b[tn+i]=p.getb(i);}
  this->simplify();
  return *this;
}
//---------------------------------------------------------------------------
TExponome& TExponome::operator*= (TExponome& p)
{ int n=p.deg();
  TExponome* t=new TExponome(n*d);
  double s;
  double c;
  for(int j=0;j<n;j++)
  for(int k=0;k<d;k++)
     { s=c=0.0;
       s=p.geta(j)*a[k];
       c=p.getb(j)+b[k];
       t->seta(s,d*j+k);
       t->setb(c,d*j+k);
     }
  this->init(d*n);
  for(int i=0;i<d;i++) { a[i]=t->geta(i); b[i]=t->getb(i);}
  this->simplify();
  return *this;
}
//---------------------------------------------------------------------------
TExponome& TExponome::operator*= (double m)
{ for(int i=0;i<d;i++) a[i]*=m;
  return *this;
}
//---------------------------------------------------------------------------
TExponome& operator* (TExponome& p, double m)
{ int n=p.deg();
  TExponome* t=new TExponome(n);
  for(int i=0;i<n;i++) { t->seta(m*p.geta(i),i); t->setb(p.getb(i),i);}
  return *t;
}
//---------------------------------------------------------------------------
TExponome& operator+ (TExponome& p, double m)
{ int n=p.deg();
  TExponome* t=new TExponome(n+1);
  for(int i=0;i<n;i++) { t->seta(p.geta(i),i); t->setb(p.getb(i),i);}
  t->seta(m,n); t->setb(0.0,n);
  return *t;
}
//---------------------------------------------------------------------------
ostream& operator<<(ostream& stream, const TExponome& p)
{ int n=p.deg();
  stream<<n;
  for(int i=0; i<n;i++)
     { stream<<" "; stream<<p.geta(i);
       stream<<" "; stream<<p.getb(i);
     }
  return stream;
}

ostream& TExponome::exponome2TeX(ostream& stream)
{ //int prec=4;
// stream.setf(ios::scientific);
// stream.setf(ios::fixed);
// stream.setf(ios::showpoint);
// stream.precision(prec);
 int n=deg();
 int m=0;
 for(int i=0; i<n;i++)
     {
//cutting very long formulae
       if(m && m%3==0)
         { if(geta(i)>0.0) stream<<"+$\n$"; else stream<<"-$\n$";
         }
       if(i && geta(i)>0) stream<<"+";
       if(geta(i)!=1.0 && geta(i)!=-1.0) stream<<geta(i)<<"\\cdot";
       if(geta(i)==-1.0) stream<<"-";
       if(getb(i)!=0.0) stream<<"\\exp("<<getb(i)<<"\\cdot t)";
       m++;
     }
 return stream;
}

ostream& TExponome::exponome2MatLab(ostream& stream)
{int n=deg();
 int m=0;
 for(int i=0; i<n;i++)
     {
//cutting very long formulae
       if(m && m%5==0) stream<<"\n";
       if(i && geta(i)>0) stream<<"+";
       if(geta(i)!=1.0) stream<<geta(i)<<"*";
       if(getb(i)!=0.0) stream<<"exp("<<getb(i)<<"*t)";
       m++;
     }
 return stream;
}

istream& operator>>(istream& stream, TExponome& p)
{int t;
 stream>>t;
 p.init(t);
 for(int i=0; i<t;i++)
     { double tf;
       stream>>tf;
       p.seta(tf,i);
       stream>>tf;
       p.setb(tf,i);
     }
 return stream;
}

#endif
