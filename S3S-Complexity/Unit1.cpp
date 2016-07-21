#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <alloc.h>
#include<iostream>
#include<fstream>
//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

float mpow(float x, unsigned short m)
{ if(m>1) return x*mpow(x, m-1);
     else return x;
}

long long Cnk(unsigned int n, unsigned int k)
{ double d;
  if(k>n/2) k=n-k;     
  d=1;
  for(int i=0; i<k; i++)
    d*=(double)(n-i)/(double)(i+1);
  return d;
}

void printfRozb(int p, int* x, int k, long double &v)
{
 int r=0;      //number of stings in configuration
 int n=0;      //number of elements in configuration n=x[0]+x[1]+x[2]+...+x[r-1]
 int t=1;      //number of same lenght strings
 long tt=1;    //  A(t)=fact(t)
 long long M=1;
 long ttt=1;
 for(int i=0;i<p;i++)
 {
   if(x[i])
   {
     if(i<p-1 && x[i]==x[i+1])
       { t++;
         tt*=t;
       }else
       { printf("[%d]",x[i]);
         if(t>1)
         { printf("(x%d)",t);
           long long d1=Cnk(x[i]+k-1,k-1);    // d=|V[i]| variants of string [i]
           //double d=mpow(Cnk(x[i]+k-1,k-1),t)/tt;    // d=|V[i]| variants of string [i]
           double d=mpow(Cnk(x[i]+k-1,k-1),t);    // d=|V[i]| variants of string [i]
          // printf(" |V%d|=(%ld^%d)/%d! =%-4.4f",i,d1,t,t,d);
           printf(" |V%d|=%-4.0f",i,d);
           M*=d;
         }else
         { long long d=Cnk(x[i]+k-1,k-1);    // d=|V[i]| variants of string [i]
           printf(" |V%d|=%ld  ",i,d);
           M*=d;
         }
         t=tt=1;
       }
     n+=x[i];
     r++;
   }
 }
 printf("\n |V|=f(n,k,r)=f(%d,%d,%d)=%d \n\n",n,k,r,M/ttt);
 v+=M;
 }

int main(int argc, char* argv[])
{
  argc=2;
  argv[1]="data1.dat";
  argv[2]="test1.m";
  if(argc>1)
   {using namespace std;
    ifstream in_stream;   in_stream.open(argv[1]);
    ofstream out_stream;  out_stream.open(argv[2]);
    if(in_stream.fail() || out_stream.fail())
    { cout<<"\n Input or output stream can't be open";
      exit(1);
    }
  int n;      //no. of elements
  int K;      //no. of types/versions
  long long m;
  int* x;
  //printf("\n Input n=");
  //scanf("%d",&n);
  //printf("\n Input k=");
  //scanf("%d",&K);
  //printf("\n");
  int n1, n0;      //no. of elements
  int K1, K0;
  in_stream>>n0; in_stream>>n1;
  in_stream>>K0;  in_stream>>K1;
  long double** Vc;
  Vc=new long double*[n1-n0+1];
  for(int n=n0;n<=n1;n++)
   { Vc[n-n0]=new long double[K1-K0+1];
     for(int K=K0;K<=K1;K++)
     {
       cout<<"\n n="<<n<<" k="<<K<<"\n";
       x=(int*)calloc(n,sizeof(int));
       x[0]=n;
       long double V=0;
       printfRozb(n, x, K, V);
        //rozbNo(0, n, n, m, x,n);
       int k,t,i,s;
       k=i=0;
       RA:    t=x[k]-1;  s=t+i-k+1;
         for(i=k;i<n;i++)
         { if(s>t)
           { x[i]=t;
             s-=t;
           }else
           { x[i]=s;
             break;
           }
         }
         printfRozb(n, x, K, V);
         for(k=i;k>=0;--k)
         if(x[k]>1) goto RA;
      free(x);
      printf("\n |V|=%d",V);
      Vc[n-n0][K-K0]=V;
      //getch();
     }
    }
   //out_stream.setf(ios::scientific);
   out_stream.setf(ios::fixed);
   out_stream.setf(ios::showpoint);
   out_stream.precision(0);
   out_stream<<"y=[";
   for(int n=n0;n<=n1;n++) out_stream<<n<<", ";
   out_stream<<"]\nx=[";
   for(int K=K0;K<=K1;K++) out_stream<<K<<", ";
   out_stream<<"]\nz=[";
   for(int n=0;n<n1-n0+1;n++)
   {
     for(int K=0;K<K1-K0+1;K++) out_stream<<Vc[n][K]<<" ";
     out_stream<<";\n";
   }
   out_stream<<"]\nmesh(x,y,z)\n%surf(x,y,z)";
  }
  getch();
  return 0;
}
//---------------------------------------------------------------------------
/*
void rozbNo(int p, int max, int n, long long &m, int* x, int c)
{
 if(n)
 { for(int i=(max<n)? max:n; i>0; i--)
   { int* tmp; tmp=(int*)calloc(c, sizeof(int));
     for(int j=0;j<c;j++) tmp[j]=x[j];
     tmp[p]=i;
     rozbNo(p+1, i, n-i, m, x,c);
     free(tmp);
   }
 }
 else
 { m++;
//   printfRozb(p-1, x);
 }
}
*/