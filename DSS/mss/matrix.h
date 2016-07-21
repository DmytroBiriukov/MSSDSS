
//---------------------------------------------------------------------------
//   class TMatrix and TVector by Dmitrij Birjukov
//---------------------------------------------------------------------------

#if !defined(MATRIX)
#define MATRIX

class TVector
{ private:
        int count;
        double* arg;
        void reset(int);
  public:
        int argCount(){ return count;}
        double& operator[](int i){ return arg[i];}
        friend istream& operator>>(istream&, TVector&);
        friend ostream& operator<<(ostream&, TVector&);
        friend TVector& operator* (TVector&, double);
        friend TVector& operator* (double, TVector&);
        TVector& operator= (TVector& );
        double operator* (TVector );
        operator double*(){ return &arg[0];}
	void init(double*,int);
        TVector(){ count=0;}
        TVector(int);
        ~TVector(){ if(count) delete[] arg;}
};
//---------------------------------------------------------------------------
TVector::TVector(int n)
{ count=n;
  arg=new double[n];
  for(int i=0;i<n;i++) arg[i]=0.0;
}
//---------------------------------------------------------------------------
TVector& TVector:: operator= (TVector& a)
{ int n=a.argCount();
  if(n!=count) this->reset(n);
  for(int i=0;i<count;i++) arg[i]=a[i];
  return *this;
}
//---------------------------------------------------------------------------
double TVector:: operator* (TVector a)
{ double mult=0.0;
  for(int i=0;i<count;i++) mult+=arg[i]*a[i];
  return mult;
}
//---------------------------------------------------------------------------
void TVector:: init(double* a,int n)
{ if(n!=count)  this->reset(n);
  for(int i=0;i<count;i++) arg[i]=a[i];
}
//---------------------------------------------------------------------------
void TVector:: reset(int n)
{ double* t;
  t=new double[n];
  if(n>count)
    { for(int i=0;i<count;i++) t[i]=arg[i];
      for(int i=count;i<n;i++) t[i]=0.0;
    } else
      for(int i=0;i<n;i++) t[i]=arg[i];
  if(count) delete[] arg;
  count=n;
  arg=new double[count];
  for(int i=0;i<count;i++) arg[i]=t[i];
  delete[] t;
}
//---------------------------------------------------------------------------
ostream& operator<<(ostream& stream, TVector& v)
{ stream.setf(ios::fixed);
  stream.setf(ios::showpoint);
  stream.precision(4);
  for(int i=0;i<v.argCount();i++) stream<<" ["<<i<<"]="<<v[i];
  return stream;
}
//---------------------------------------------------------------------------
istream& operator>>(istream& stream, TVector& v)
{ for(int i=0;i<v.argCount();i++) stream>>v[i];
  return stream;
}
//---------------------------------------------------------------------------
TVector& operator* (TVector& a, double m)
{ int n=a.argCount();
  TVector* c=new TVector(n);
  for(int i=0;i<n;i++) c->operator[](i)=m*a[i];
  return *c;
}
//---------------------------------------------------------------------------
TVector& operator* (double m, TVector& a)
{ return a*m;
}
//---------------------------------------------------------------------------
class TMatrix
{ private:
        int row;
        int col;
        double** arg;
        void reset(int,int);
  public:
        int row_count(){ return row;}
        int col_count(){ return col;}
        double* get_row(int i){ return arg[i];}
        friend TMatrix& operator+ (TMatrix&, TMatrix&);
        friend TMatrix& operator* (TMatrix&, TMatrix&);
        friend TVector& operator* (TMatrix&, TVector&);
        friend TVector& operator* (TVector&, TMatrix&);
        friend TMatrix& operator* (TMatrix&, double);
        friend TMatrix& operator* (double t, TMatrix& A){ return A*t;}
        friend ostream& operator<<(ostream&, TMatrix&);
        friend istream& operator>>(istream&, TMatrix&);
        TMatrix& operator+= (TMatrix&);
        TMatrix& operator*= (double);
        TMatrix& operator*= (TMatrix&);
        TMatrix& operator= (TMatrix&);
        TVector& operator[] (int);
        double& operator() (int i, int j){ return arg[i][j];}
        void normalize();
	void init(double**,int,int);
        TMatrix(){ row=col=0;}
        TMatrix(int,int);
        ~TMatrix();
};
//---------------------------------------------------------------------------
TMatrix::TMatrix(int r, int c)
{ row=r;
  col=c;
  arg=new double*[row];
  for(int i=0;i< row;i++) arg[i]=new double[col];
  for(int i=0;i< row;i++)
     for(int j=0;j< col;j++) arg[i][j]=0.0;
}
//---------------------------------------------------------------------------
TMatrix:: ~TMatrix()
{ for(int i=0;i<row;i++) delete[] arg[i];
  if(row) delete[] arg;
}
//---------------------------------------------------------------------------
TMatrix& operator+ (TMatrix& A, TMatrix& B)
{ int n=(A.row_count()>B.row_count())? A.row_count() : B.row_count();
  int m=(A.col_count()>B.col_count())? A.col_count() : B.col_count();
  TMatrix* T=new TMatrix(n,m);
  for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
        T->operator ()(i,j)=A(i,j)+B(i,j);
  return *T;
}
//---------------------------------------------------------------------------
TMatrix& operator* (TMatrix& A, TMatrix& B)
{ int m=(A.col_count()>B.row_count())? A.col_count() : B.row_count();
  int n=(A.row_count()>B.col_count())? A.row_count() : B.col_count();
  TMatrix* T=new TMatrix(n,m);
  for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
        {double b=0.0;
         for(int k=0;k<n;k++) b+=A(k,i)*B(j,k);
         T->operator ()(i,j)=b;
        }
  return *T;
}
//---------------------------------------------------------------------------
TVector& operator* (TMatrix& A, TVector& b)
{ int n=(b.argCount() < A.row_count())? b.argCount() : A.row_count();
  int m=(b.argCount() < A.col_count())? b.argCount() : A.col_count();
  TVector* c=new TVector(n);
  for(int i=0; i<n; i++)
     { double s=0.0;
       for(int j=0; j<m; j++) s+=A(i,j)*b[j];
       c->operator[] (i)=s;
     }
  return *c;
}
//---------------------------------------------------------------------------
TVector& operator* (TVector& b, TMatrix& A)
{ return A*b;
}
//---------------------------------------------------------------------------
TMatrix& TMatrix:: operator= (TMatrix& A)
{ this->reset(A.row_count(), A.col_count());
  for(int i=0;i< row;i++)
     for(int j=0;j< col;j++) arg[i][j]=A(i,j);
  return *this;
}
//---------------------------------------------------------------------------
void TMatrix::reset(int m, int n)
{ double** t; t=new double*[m];
  for(int i=0;i<m; i++) t[i]=new double[n];
  int k=(m>row)? row: m;
  int l=(n>col)? col: n;
  for(int i=0;i<k;i++)
     for(int j=0;j<l;j++) t[i][j]=arg[i][j];
  for(int i=k;i<m;i++)
     for(int j=l;j<n;j++) t[i][j]=0.0;
  for(int i=0;i<row;i++) delete[] arg[i];
  if(row) delete[] arg;
  row=m;
  col=n;
  arg=new double*[row];
  for(int i=0;i<row; i++) arg[i]=new double[col];
  for(int i=0;i<row;i++)
     for(int j=0;j<col;j++) arg[i][j]=t[i][j];
  for(int i=0;i<m;i++) delete[] t[i];
  delete[] t;
}
//---------------------------------------------------------------------------
TMatrix& TMatrix:: operator+= (TMatrix& A)
{ this->reset(A.row_count(), A.col_count());
  for(int i=0;i< row;i++)
     for(int j=0;j< col;j++) arg[i][j]+=A(i,j);
   return *this;
}
//---------------------------------------------------------------------------
TMatrix& TMatrix:: operator*= (double t)
{ for(int i=0;i< row;i++)
   for(int j=0;j< col;j++) arg[i][j]*=t;
   return *this;
}
//---------------------------------------------------------------------------
TMatrix& operator* (TMatrix& A, double t)
{ int m=A.row_count();
  int n=A.col_count();
  TMatrix* T=new TMatrix(n,n);
  for(int i=0;i< m;i++)
   for(int j=0;j< n;j++)
      T->operator()(i,j)=A(i,j)*t;
  return *T;
}
//---------------------------------------------------------------------------
TMatrix& TMatrix:: operator*= (TMatrix& A)
{ int m=(A.col_count()>row)? A.col_count() : row;
  int n=(A.row_count()>col)? A.row_count() : col;
  TMatrix T(n,m);
  for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
        {double b=0.0;
         for(int k=0;k<n;k++) b+=arg[j][k]*A(k,i);
         T(i,j)=b;
        }
  this->reset(m, n);
  for(int i=0;i< n;i++)
     for(int j=0;j<m;j++) arg[i][j]=T(i,j);
  return *this;
}

ostream& operator<<(ostream& stream, TMatrix& A)
{ stream.setf(ios::fixed);
  stream.setf(ios::showpoint);
  stream.precision(4);
  for(int i=0;i<A.row_count();i++)
     for(int j=0;j<A.col_count();j++)
        stream<<" ["<<i<<"]["<<j<<"]="<<A(i,j);
  return stream;
}

istream& operator>>(istream& stream, TMatrix& A)
{
  for(int i=0;i<A.row_count();i++)
     for(int j=0;j<A.col_count();j++)
        stream>>A(i,j);
  return stream;

}

void TMatrix:: normalize()
{ for(int i=0;i<row;i++)
     for(int j=0;j<col;j++)
        if(i==j) arg[i][j]=1.0;
          else arg[i][j]=0.0;
}

void TMatrix:: init(double** a,int r,int c)
{ this->reset(r,c);
  for(int i=0;i<row;i++)
     for(int j=0;j<col;j++)  arg[i][j]=a[i][j];
}

//---------------------------------------------------------------------------
#endif
