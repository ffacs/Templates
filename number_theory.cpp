#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
const int mod=1e9+7;

inline void exgcd(ll a,ll b,ll &g,ll &x,ll &y) { //a*x+b*y=gcd(a,b)
    if (!b) g=a,x=1,y=0;
    else exgcd(b,a%b,g,y,x),y-=x*(a/b);
}
inline ll inv(ll a) {
   ll g,x,y;
    exgcd(a,mod,g,x,y);
    return (x%mod+mod)%mod; //the minimum non-negative interger solution of x
}

inline ll fastpow(ll a,ll b) {
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
	return ans;
}
ll fac[maxn]={1},ifac[maxn],inv[maxn]={0,1};
inline ll C(ll n,ll m) {
	return fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
inline ll A(ll n,ll m) {
	return fac[n]*ifac[n-m]%mod;
}
inline void init() { //calculate the inversion ,factorial and inversion of factorial
	for(int i=2;i<maxn;++i) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
	ifac[maxn-1]=fastpow(fac[maxn-1],mod-2);
	for(int i=maxn-2;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}


int prim[maxn],pcnt,mu[maxn],mpf[maxn];	
//prim is the primer set
//pcnt is the size of prim
//mu[i] is mu(i)
//mpf[i] is the minimum primer factor of i
void get_mu() { //
    mu[1]=1;
    for(int i=2;i<maxn;i++) {
        if(!mpf[i]) {prim[++pcnt]=i;mu[i]=-1;mpf[i]=i;}
        for(int j=1;j<=pcnt&&prim[j]*i<maxn;j++) {
            mu[i*prim[j]]=-mu[i];mpf[i*prim[j]]=prim[j];
            if(i%prim[j]==0) {
                mu[i*prim[j]]=0;
                break;
            }
        }
    }
}

ll lucas(ll n,ll m){ // mod should be a primer
    if(m==0) return  1;
    return lucas(n/mod,m/mod,mod)*C(n%mod,m%mod,mod)%mod;
}

ll mathSqrt(ll n) {
	for(ll l=1,r;l<=n;l=r+1) {
		r=min(n,n/(n/l));
		// there n/l ~ n/r are the same
	}
}

int phi(int n){ // calculate n`s phi
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) ans-=ans/i;
        while (n%i==0) n/=i;
    }
    if(n!=1) ans-=ans/n;
    return ans;
}

int main() {
	init();get_mu();
    return 0;
}