#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct MATRIX{
    #define MAXN 105
    int mod=1e9+7;
    ll data[MAXN][MAXN],n;
    MATRIX(int siz){this->n=siz;for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)data[i][j]=0;}
    MATRIX operator*(const MATRIX& b){
        MATRIX ans(n);
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++){
            (ans.data[i][j]+=data[i][k]*b.data[k][j]%mod)%=mod;
        }
        return ans;
    }
    MATRIX(const MATRIX& b){
        this->n=b.n;
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=n;j++) 
                data[i][j]=b.data[i][j];
    }
    MATRIX& operator=(const MATRIX& b){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) data[i][j]=b.data[i][j];
        return *this;
    }
    MATRIX operator+(const MATRIX& b){
        MATRIX ans(n);
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) (ans.data[i][j]+=data[i][j]+b.data[i][j])%=mod;
    }
    MATRIX& operator*=(const MATRIX& b){
        return *this=*this*b;
    }
    MATRIX& operator+=(const MATRIX& b){
        return *this=*this+b;
    }
    MATRIX fpow(ll b){
        MATRIX ans(n),a(*this);
        for(int i=1;i<=n;i++) ans.data[i][i]=1;
        for(;b;b>>=1,a=a*a) {
            if(b&1) ans=ans*a;
        }return ans;
    }
    #undef MAXN
};
int main() {
    return 0;
}