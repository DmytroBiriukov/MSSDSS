
//---------------------------------------------------------------------------
//   class TDiffEqSys and TLinearDiffEqSys by Dmitrij Birjukov
//---------------------------------------------------------------------------

#if !defined(DYNAMICS)
#define DYNAMICS

#include "matrix.h"

class TDiffEqSys
{ private:
        double** a;
        int n;
  public:
        TDiffEqSys(double h, TVector& (*f)(TVector& x, TVector& t));
};
//---------------------------------------------------------------------------
TDiffEqSys::TDiffEqSys(double h, TVector& (*f)(TVector& x, TVector& t))
{//  method Runge-Kutt
 //  x[i+1]=x[i]+(1/6)sum(k[j])
 //  dx/dt = f(x,t)
 /*
 TVector k1(n), k2(n), k3(n), k4(n);
 TVector a(n);
 for(int i=0;i<m;i++)
     { k1=(h/6)*((*f)(x,t));
       k2=(h/6)*((*f)(x+(h/2),t+(k1/2)));
       k3=(h/6)*((*f)(x+(h/2),t+(k2/2)));
       k4=(h/6)*((*f)(x+h,t+k3));
       a[i+1]=a[i]+k1+k2+k3+k4;
     }
 */
}
//---------------------------------------------------------------------------
class TLinearDiffEqSys
{ private:
        double** a;
        int n;
  public:
        double* aprox(int i){ return &a[i][0];}
        TLinearDiffEqSys(){;}
        TLinearDiffEqSys(TMatrix&, TVector&, int);
        ~TLinearDiffEqSys();
};
//---------------------------------------------------------------------------
TLinearDiffEqSys::TLinearDiffEqSys(TMatrix& A, TVector& po, int q)
{ // x(t)=exp(A*t)*x(to)
  n=po.argCount();
  a=new double*[n];
  for(int i=0;i<n;i++)
      a[i]=new double[q+1];
  TMatrix Q(n,n); Q.normalize();
  double h; h=1.0;
  for(int k=0;k<q+1; k++)
     { if(k) h*=k;
       TVector v(n);
       v=(1/h)*Q*po;
       Q*=A;
       for(int i=0;i<n;i++)
          a[i][k]=v[i];
     }
}
//---------------------------------------------------------------------------
TLinearDiffEqSys::~TLinearDiffEqSys()
{ for(int i=0;i<n;i++) delete[] a[i];
  delete[] a;
}
//---------------------------------------------------------------------------
#endif

