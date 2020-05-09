#include <bits/stdc++.h>
using namespace std;
const static int N = 4e6 + 6;
long long pos[N];
const long long mod = 998244353, root = 3;
inline long long pow(long long a, long long b) {
    long long ans = 1;
    for (; b; a = a * a % mod, b >>= 1) if (b & 1) ans = ans * a % mod;
    return ans;
}
inline void exgcd(const long long a, const long long b, long long &g,long long &x, long long &y) {
    if (!b) g = a, x = 1, y = 0;
    else exgcd(b, a % b, g, y, x), y -= x * (a / b);
}
inline long long inv(long long a) {
    long long g, x, y;
    exgcd(a, mod, g, x, y);
    return (x % mod + mod) % mod;
}

void init(const int &n) {
    for (int i = 0,j=0; i < n; ++i) {
        pos[i]=j;for (int l = n >> 1; (j ^= l) < l; l >>= 1);
    }
}

void transform(long long *a, const int &n, bool inverse) {
    for (int i = 0; i < n; ++i) if (i > pos[i]) swap(a[i], a[pos[i]]);

    for (int l = 2; l <= n; l <<= 1) {
        int m = l / 2;long long omega=pow(inverse ? inv(root):root,(mod-1)/l);
        for (long long *p = a; p != a + n; p += l) {
            long long x=1;
            for (int i = 0; i < m; ++i,x = x * omega % mod) {
                long long t = x* p[m + i] %mod;
                p[m + i] = (p[i] - t + mod )%mod;(p[i] += t)%=mod;
            }
        }
    }
}

void dft(long long *a, const int &n) {
    transform(a, n, 0); 
}
void idft(long long *a, const int &n) {
    const long long INV = inv(n);
    transform(a, n, 1);
    for (int i = 0; i < n; i++) a[i] = a[i] * INV % mod;
}
const int maxn=4e6+6;
long long a[maxn],b[maxn],c[maxn];
int main(){
    int n,m,tem;cin>>n>>m;
    for(int i=0;i<=n;i++) scanf("%lld",a+i);
    for(int i=0;i<=m;i++) scanf("%lld",b+i);
    int cnt=1;while(cnt<=(n+m)) cnt<<=1;

    init(cnt);dft(a,cnt);dft(b,cnt);
    for(int i=0;i<cnt;i++) c[i]=a[i]*b[i];
    idft(c,cnt);

    for(int i=0;i<=n+m;i++) printf("%lld ",c[i]);cout<<"\n";
}