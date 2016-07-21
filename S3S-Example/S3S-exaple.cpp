#include<iostream>
#include<stdlib.h>
#include "../dss/mss/mss.h"

using namespace std;

long Cnk(unsigned int n, unsigned int k)
{ unsigned int d=1;
  if(k > n/2) k=n-k;
  for(unsigned int i=0;i<k;i++)
  { d*=(n-i);
    d/=(i+1);
  }
  return d;
}

int main(int argc, char *argv[])
{
  unsigned int n;
  cout<<"\nInput n=";
  cin>>n;
  unsigned int sn=(unsigned int)pow(n, 0.5)+1;

  unsigned int** path_comp;
  path_comp=new unsigned int*[sn];

  unsigned int* path_mask=new unsigned int [Cnk(n,sn)];
  unsigned int subset_num=1;
  subset_num<<=n;

  unsigned int path_index=0;
  for(unsigned int i=1;i<subset_num;i++)
  { unsigned int ones_num=0;
    unsigned int tmp=i;
    while(tmp)
    { if(tmp%2) ones_num++;
      tmp/=2;
    }
    if(ones_num == sn)
    { path_mask[path_index]=i;
      path_index++;
    }
  }

  for(unsigned int i=0;i<sn;i++)
  { path_comp[i]=new unsigned int[sn];
    unsigned int the_path=path_mask[(unsigned int)(path_index*((double)rand()/(double)RAND_MAX))];
    unsigned int k=0;
    for(unsigned int j=0;j<n && the_path;j++)
    { if(the_path%2)
      { path_comp[i][k]=j;
        k++;
      }
      the_path/=2;
    }
  /*
    cout<<"\n path #"<<i+1 <<"\n";
    for(unsigned int j=0;j<sn;j++)
    { cout<<path_comp[i][j]<<"  ";
    }
  */
  }

  double lambda31[] ={0.00025, 0.000275};
  double lambda32[] ={0.00015, 0.000125};
  double to = 500;
  double po[2][3] ={ {0.1, 0.2, 0.7},{0.1, 0.2, 0.7} };
  TExpolynome p[2][3];

  TPolynome* c_p_13=new TPolynome(1);
  double* c_c_p_13=new double[1];
  c_c_p_13[0]=po[0][2];
  c_p_13->init(c_c_p_13,1);
  double* d_p_13=new double [1];

  d_p_13[0]=(lambda31[0] +lambda32[0])* (to-1);
  p[0][2].init(c_p_13, d_p_13, 1);

  d_p_13[0]=(lambda31[1] +lambda32[1])* (to-1);
  p[1][2].init(c_p_13, d_p_13, 1);

  p[0][1]=p[0][2];
  p[0][1] *= (-lambda32[0] / (lambda31[0] +lambda32[0]) );
  p[0][1] += po[0][1]+(lambda32[0] / (lambda31[0] +lambda32[0]) ) * po[0][2] ;

  p[0][0]=p[0][2];
  p[0][0] *= (-lambda31[0] / (lambda31[0] +lambda32[0]) );
  p[0][0] += po[0][0]+(lambda31[0] / (lambda31[0] +lambda32[0]) ) * po[0][2];

  p[1][1]=p[1][2];
  p[1][1] *= (-lambda32[1] / (lambda31[1] +lambda32[1]) );
  p[1][1] += po[1][1]+(lambda32[1] / (lambda31[1] +lambda32[1]) ) * po[1][2] ;

  p[1][0]=p[1][2];
  p[1][0] *= (-lambda31[1] / (lambda31[1] +lambda32[1]) );
  p[1][0] += po[1][0]+(lambda31[1] / (lambda31[1] +lambda32[1]) ) * po[1][2];
/*
  p[0][2].expolynome2TeX(cout);
  cout<<"\n";
  p[0][2].expolynome2MatLab(cout);
  cout<<"\n";
  p[0][1].expolynome2TeX(cout);
  cout<<"\n";
  p[0][1].expolynome2MatLab(cout);
  cout<<"\n";
  p[0][0].expolynome2TeX(cout);
  cout<<"\n";
  p[0][0].expolynome2MatLab(cout);
  cout<<"\n";

  p[1][2].expolynome2TeX(cout);
  cout<<"\n";
  p[1][2].expolynome2MatLab(cout);
  cout<<"\n";
  p[1][1].expolynome2TeX(cout);
  cout<<"\n";
  p[1][1].expolynome2MatLab(cout);
  cout<<"\n";
  p[1][0].expolynome2TeX(cout);
  cout<<"\n";
  p[1][0].expolynome2MatLab(cout);
  cout<<"\n\n";
*/




  system("PAUSE");
  return 0;
}
