#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<math>

#include"numerics.h"
//using namespace std;

int main(int argc, char* argv[])
{
/*
   TPolynome a(7), b(7), c(7);
   TMatrix L(3,3);
   L(0,0)=-0.75; L(0,1)=0.45; L(0,2)=0.30;
   L(1,0)=0.55; L(1,1)=-0.80; L(1,2)=0.25;
   L(2,0)=0.60; L(2,1)=0.25; L(2,2)=-0.85;
   TVector po(3);
   po[2]=0.925; po[1]=0.055; po[0]=0.020;

   TLinearDiffEqSys ds(L, po, 7);
   for(int k=0;k<3;k++)
      { a.init(ds.aprox(k), 8);
        cout<<endl<<"ds.aprox(p"<<k<<"(t), t)= "<<a<<endl;
      }
*/
  /*
   double* t=new double[n];
   t[0]=h;
   for(int i=0;i<n;i++) t[i+1]=t[i]+h;
   double sum=0.0;
   for(int k=0;k<3;k++)
      sl[k]=new double[n];
   for(int i=0;i<n-1;i++)
      { sum=0.0;
        cout<<endl<<"#"<<i+1;
        double w[3];
        for(int k=0;k<3;k++)
          { sl[k][i]=ds.point(i+1)[k];
            sum+=sl[k][i];
          }
        for(int k=0;k<3;k++)
          { w[k]=sl[k][i]/sum;
            sl[k][i]=(1-sum)*w[k];
            cout<<" p"<<k<<"["<<i<<"]="<<sl[k][i];
          }
        for(int k=0;k<3;k++)
          { sum+=sl[k][i];
            for(int i=0;i<n-1;i++)
                sl[k][i]-=po[k];
          }
        cout<<"  sum="<<sum;
      }

   a.LSM_aprox(sl[0], t, n-1);
   cout<<endl<<"a.LSM_aprox(p0(t), t, n)= "<<a<<endl;
   a^=1; a+=po[0];
   b.LSM_aprox(sl[1], t, n-1);
   cout<<endl<<"b.LSM_aprox(p1(t), t, n)= "<<b<<endl;
   b^=1; b+=po[1];
   c.LSM_aprox(sl[2], t, n-1);
   cout<<endl<<"c.LSM_aprox(p2(t), t, n)= "<<c<<endl;
   c^=1; c+=po[2];

   cout<<endl<<"a.LSM_aprox(p0(t), t, n)= "<<a<<endl;
   cout<<endl<<"b.LSM_aprox(p1(t), t, n)= "<<b<<endl;
   cout<<endl<<"c.LSM_aprox(p2(t), t, n)= "<<c<<endl;
   getch();

   for(int i=0;i<4;i++)
      {cout<<endl<<"p("<<t[i]<<")="<<sl[0][i]<<" , P("<<t[i]<<")="<<a.value(t[i]);
       cout<<endl<<"p("<<t[i]<<")-P("<<t[i]<<")="<<sl[0][i]-a.value(t[i]);
      }
*/
/* 
//Test of TExponome operations and simplyfing
*/
   TExponome a,b, c;
   int a_n=4; int b_n=3;
   double a_c[] = { 3.1, 4.4, 5.6, 3.2 };
   double a_s[] = { 3.1, 4.4, 5.6, 3.2 };
   double b_c[] = { 3.1, 4.4, 5.6 };
   double b_s[] = { 3.1, 4.4, 5.6 };
   a.init(a_c, a_s, a_n);
   b.init(b_c, b_s, b_n);
   cout<<"A="<<a;
   cout<<"\nB="<<b;
   c=a+b;
   cout<<"\nC=A+B=\n"<<c;
   getch();
   c=a*b;
   cout<<"\nC=A*B=\n"<<c;
   c.simplify();
   cout<<"\nsimplified C\n"<<c;

   return getch();
}
//---------------------------------------------------------------------------














