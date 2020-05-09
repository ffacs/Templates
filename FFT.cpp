#include <bits/stdc++.h>
using namespace std;
struct Complex{
    double r,i;
    Complex(double r,double i):r(r),i(i){}
    inline void real ( const double& x )  {  r = x ;  }
	inline double real ( )  {  return r ;  }
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
	inline Complex conj ()  {
		return Complex ( r, -i ) ;
	}
};

const static int N=4e6+5;
#define PI 3.14159265354
int pos[N];
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
const int maxn=4e6+6;
Complex a[maxn],b[maxn],c[maxn];
int main(){
    int n,m,tem;cin>>n>>m;
    for(int i=0;i<=n;i++) scanf("%d",&tem),a[i].r=tem;
    for(int i=0;i<=m;i++) scanf("%d",&tem),b[i].r=tem;
    int cnt=1;while(cnt<=(n+m)) cnt<<=1;

    init(cnt);dft(a,cnt);dft(b,cnt);
    for(int i=0;i<cnt;i++) c[i]=a[i]*b[i];
    idft(c,cnt);
    for(int i=0;i<=n+m;i++) printf("%d ",int(c[i].r+1e-2));cout<<"\n";
}