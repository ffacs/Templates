#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll p=998244353;
const ll inv2=499122177;
const int rank=20;
int A[1<<rank],B[1<<rank],a[1<<rank],b[1<<rank],n,tot;
void init(){
    for(int i=0;i<(1<<n);++i){
        a[i]=A[i];b[i]=B[i];
    }
}
void Or(int *f){
    for(int bs=2;bs<=tot;bs<<=1){
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j)
                f[i+j+g]=(f[i+j]+f[i+j+g])%p;
    }
}
void iOr(int *f){
    for(int bs=tot;bs>=2;bs>>=1){
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j)
                f[i+j+g]=(f[i+j+g]+p-f[i+j])%p;
    }
}
void And(int *f){
    for(int bs=2;bs<=tot;bs<<=1){
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j)
                f[i+j]=(f[i+j]+f[i+j+g])%p;
    }
}
void iAnd(int *f){
    for(int bs=tot;bs>=2;bs>>=1){
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j)
                f[i+j]=(f[i+j]+p-f[i+j+g])%p;
    }
}
void Xor(int *f){
    for(int bs=2;bs<=tot;bs<<=1){
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j){
                int t0=(f[i+j]+f[i+j+g])%p,t1=(f[i+j]+p-f[i+j+g])%p;
                f[i+j]=t0;f[i+j+g]=t1;
            }
    }
}
void iXor(int *f){
    for(int bs=tot;bs>=2;bs>>=1){
        int g=(bs>>1);
        for(int i=0;i<tot;i+=bs)
            for(int j=0;j<g;++j){
                int t0=inv2*(f[i+j]+f[i+j+g])%p,t1=inv2*(f[i+j]+p-f[i+j+g])%p;
                f[i+j]=t0;f[i+j+g]=t1;
            }
    }
}
int main(){
	scanf("%d",&n);tot=(1<<n); //总共 2 ^n 个，若不足则需补齐
    for(int i=0;i<tot;++i) scanf("%d",A+i);
    for(int i=0;i<tot;++i) scanf("%d",B+i);
    init();Or(a);Or(b);
    for(int i=0;i<tot;++i) a[i]=(long long)a[i]*b[i]%p;
    iOr(a);
    for(int i=0;i<tot;++i) printf("%d ",a[i]);
    return 0;
}