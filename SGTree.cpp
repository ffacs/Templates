#include<bits/stdc++.h>
using namespace std;
struct SGtree{
    #define MAXN 100005
    int tree[MAXN<<2],val[MAXN],tag[MAXN<<2];
    void pushup(int p){
        tree[p]=tree[p<<1]+tree[p<<1|1];
    }
    void pushdown(int p){
    }
    void build(int l,int r,int p){
        if(l==r){tree[p]=val[l];return;}
        int mid=(l+r)>>1;build(l,mid,p<<1);build(mid+1,r,p<<1|1);
        pushup(p);
    }
    void update(int l,int r,int nl,int nr,int p,int k){
        if(nl>=l&&nr<=r){;return;}
        int mid=nl+nr>>1;pushdown(p);
        if(l<=mid) update(l,r,nl,mid,p<<1,k);
        if(r>mid) update(l,r,mid+1,nr,p<<1|1,k);
        pushup(p);
    }
    int query(int l,int r,int nl,int nr,int p){
        if(nl>=l&&nr<=r){ return 0;}
        int mid=nl+nr>>1,ans=0;
        if(l<=mid) ans+=query(l,r,nl,mid,p<<1);
        if(r>mid) ans+=query(l,r,mid+1,nr,p<<1|1);
        return ans;
    }
}tree;