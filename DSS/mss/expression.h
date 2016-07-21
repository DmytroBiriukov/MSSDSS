
//---------------------------------------------------------------------------
//   class TExpression by Dmitrij Birjukov
//---------------------------------------------------------------------------

#if !defined(EXPRESSION)
#define EXPRESSION
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

class TExpression
{ private:
            ;
  public:
	char* exn;
        TExpression& operator=(TExpression&);
        TExpression& operator=(TExpression );
        TExpression& operator=(double);
        friend TExpression& operator* (TExpression&, TExpression&);
        friend TExpression& operator+ (TExpression&, TExpression&);
        TExpression& operator*=(TExpression&);
        TExpression& operator*=(double);
        TExpression& operator+=(TExpression&);
        friend TExpression& operator* (TExpression&, double);
        friend TExpression& operator* (double m, TExpression& p) { return p*m;}
        friend TExpression& operator+ (TExpression&, double);
        friend TExpression& operator+ (double m, TExpression& p){ return p+m;}
        friend ostream& operator<<(ostream&, TExpression&);
        friend istream& operator>>(istream&, TExpression&);
        TExpression(){ exn="";}
        TExpression(char*);
        ~TExpression();
};
//---------------------------------------------------------------------------
TExpression::TExpression(char* str)
{ strcpy(exn,str);
}
//---------------------------------------------------------------------------
TExpression::~TExpression()
{
}
//---------------------------------------------------------------------------
TExpression& TExpression::operator= (TExpression& str)
{
  strcpy(exn,str->exn);
  return *this;
}
//---------------------------------------------------------------------------
TExpression& TExpression::operator= (TExpression str)
{
  strcpy(exn,str->exn);
  return *this;
}
//---------------------------------------------------------------------------
TExpression& operator* (TExpression& str1, TExpression& str2)
{ char* leftbracket="(";
  char* rightbracket=")";
  char* multsign="*";

  TExpression* t=new TExpression(leftbracket);
  strcat(t->exn,str1);
  strcat(t->exn,rightbracket);
  strcat(t->exn,multsign);
  strcat(t->exn,leftbracket);
  strcat(t->exn,str2);
  strcat(t->exn,rightbracket);
  return *t;
}
//---------------------------------------------------------------------------
TExpression& TExpression::operator= (double p)
{ if(d!=1)
    {delete [] a;  delete [] b;
     d=1;
     a=new double[d];
     b=new double[d];
    }
  a[0]=p;
  b[0]=0.0;
  return *this;
}
//---------------------------------------------------------------------------
TExpression& operator+ (TExpression& p1, TExpression& p2)
{ int n1=p1.deg();
  int n2=p2.deg();
  int n=n1+n2;
  TExpression* t=new TExpression(n);
  for(int j=0;j<n1;j++) { t->seta(p1.geta(j),j); t->setb(p1.getb(j),j);}
  for(int k=0;k<n2;k++) { t->seta(p2.geta(k),n1+k); t->setb(p2.getb(k),n1+k);}
  return *t;
}
//---------------------------------------------------------------------------
TExpression& TExpression::operator+= (TExpression& p)
{ int n=p.deg();
  int tn=d;
  this->reset(n+d);
  for(int i=0;i<n;i++) { a[tn+i]=p.geta(i); b[tn+i]=p.getb(i);}
  return *this;
}
//---------------------------------------------------------------------------
TExpression& TExpression::operator*= (TExpression& p)
{ int n=p.deg();
  TExpression* t=new TExpression(n*d);
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
  this->reset(d*n);
  for(int i=0;i<d;i++) { a[i]=t->geta(i); b[i]=t->getb(i);}
  return *this;
}
//---------------------------------------------------------------------------
TExpression& TExpression::operator*= (double m)
{ for(int i=0;i<d;i++) a[i]*=m;
  return *this;
}
//---------------------------------------------------------------------------
TExpression& operator* (TExpression& p, double m)
{ int n=p.deg();
  TExpression* t=new TExpression(n);
  for(int i=0;i<n;i++) { t->seta(m*p.geta(i),i); t->setb(p.getb(i),i);}
  return *t;
}
//---------------------------------------------------------------------------
TExpression& operator+ (TExpression& p, double m)
{ int n=p.deg();
  TExpression* t=new TExpression(n+1);
  for(int i=0;i<n;i++) { t->seta(p.geta(i),i); t->setb(p.getb(i),i);}
  t->seta(m,n); t->setb(0.0,n);
  return *t;
}
//---------------------------------------------------------------------------
ostream& operator<<(ostream& stream, TExpression& p)
{
 stream.setf(ios::fixed);
 stream.setf(ios::showpoint);
 stream.precision(4);
 stream<<p.deg();
 for(int i=0; i<p.deg();i++)
     { stream<<p.geta(i);
       stream<<p.getb(i);
     }
 return stream;
}

istream& operator>>(istream& stream, TExpression& p)
{int t;
 stream>>t;
 p.reset(t);
 cout<<" deg()="<<p.deg();
 for(int i=0; i<p.deg();i++)
     { double tf;
       stream>>tf;
       p.seta(tf,i);
       stream>>tf;
       p.setb(tf,i);
     }
 return stream;
}

#endif
