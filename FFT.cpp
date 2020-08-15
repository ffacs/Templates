#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Complex{
    double r,i;
    Complex(double r,double i):r(r),i(i){}
    Complex(){}
    inline Complex operator + ( const Complex& rhs )  const  {
        return Complex ( r + rhs.r, i + rhs.i ) ;
    }
    inline Complex operator - ( const Complex& rhs )  const  {
        return Complex ( r - rhs.r, i - rhs.i ) ;
    }
    inline Complex operator * ( const Complex& rhs )  const  {
        return Complex ( r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r ) ;
    }
    inline void operator /= ( const double& x )   {
        r /= x, i /= x ;
    }
    inline void operator *= ( const Complex& rhs )   {
        *this = Complex ( r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r ) ;
    }
    inline void operator += ( const Complex& rhs )   {
        r += rhs.r, i += rhs.i ;
    }
};

const int maxn=4e6+6;
#define PI 3.14159265354
int pos[maxn];
void init ( const int& n )  {
    for ( int i = 0 ,j=0; i < n ; ++ i )  {
        pos[i]=j;for (int l = n >> 1; (j ^= l) < l; l >>= 1);
    }
}

void transform ( Complex *a, const int& n, bool inverse ) {
    for ( int i = 0; i < n ; ++ i ){
        if (i > pos[i]) std ::swap(a[i], a[pos[i]]);
    }

    for ( int l = 2 ; l <= n ; l <<= 1 )  {
        int m = l / 2;Complex omega={cos(2*PI/l),inverse?-sin(2*PI/l):sin(2*PI/l)};
        for ( Complex *p = a ; p != a + n ; p += l )  {
            Complex x={1,0};
            for ( int i = 0 ; i < m ; ++ i ,x *= omega)  {
                Complex t = x  * p [m + i] ;
                p [m + i] = p [i] - t ;p [i] += t ;
            }
        }
    }
}

void dft ( Complex *a, const int& n )  {
    transform ( a, n, 0 ) ;
}

void idft ( Complex *a, const int& n )  {
    transform ( a, n, 1) ;
    for ( int i = 0 ; i < n ; ++ i ) a [i] /= n ;
}
Complex A[maxn],B[maxn],C[maxn];
void FFT(int n,int m) {// len(A),len(B)
    int cnt=1;while(cnt<=(n+m)) cnt<<=1;
    init(cnt);dft(A,cnt);dft(B,cnt);
    for(int i=0;i<cnt;i++) C[i]=A[i]*B[i];
    idft(C,cnt);
    for(int i=0;i<=n+m;i++) C[i].r=ll(C[i].r+0.01);
}
int main(){
    int n,m,tem;cin>>n>>m;
    for(int i=0;i<=n;i++) scanf("%d",&tem),A[i].r=tem;
    for(int i=0;i<=m;i++) scanf("%d",&tem),B[i].r=tem;
    FFT(n,m);
    for(int i=0;i<=n+m;i++) printf("%lld ",ll(C[i].r));cout<<"\n";
}