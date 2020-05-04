#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
struct NODE{
    int a,b,c,cnt;
}a[maxn],b[maxn];
int tree[maxn*2];
inline void update(register int x,register int d){for(register int i=x;i<2*maxn;tree[i]+=d,i+=i&-i);}
inline int query(register int x){register int ans=0;for(register int i=x;i;ans+=tree[i],i-=i&-i); return ans;}
bool cmp(NODE a,NODE b){
    return a.a==b.a?a.b==b.b?a.c<b.c:a.b<b.b:a.a<b.a;
}
void CDQ(register int l,register int r){
    if(l==r) return;
    register int mid=l+r>>1,nl=l,nr=mid+1;CDQ(l,mid);CDQ(mid+1,r);
    for(register int i=l;i<=r;i++){
        if((nl<=mid&&a[nl].b<=a[nr].b)||(nr>r)) update(a[nl].c,1),b[i]=a[nl++];
        else a[nr].cnt+=query(a[nr].c),b[i]=a[nr++];
    }
    for(register int i=l;i<=mid;i++) update(a[i].c,-1);
    for(register int i=l;i<=r;i++) a[i]=b[i];
}
inline bool same(NODE a,NODE b){
    return a.a==b.a&&a.b==b.b&&a.c==b.c;
}
int cnt[2*maxn];
int main() {
    register int n,k,now=0;cin>>n>>k;
    for(register int i=1;i<=n;i++) {scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);}
    sort(a+1,a+1+n,cmp);
    for(register int i=n-1;i>=1;i--){
        if(same(a[i],a[i+1])) {now++;a[i].cnt+=now;}
        else now=0;
    }
    CDQ(1,n);
    for(register  int i=1;i<=n;i++) cnt[a[i].cnt]++;
    for(register int i=0;i<n;i++)  printf("%d\n",cnt[i]);
    return 0;
}