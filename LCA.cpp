#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct EDGE{
	int v,nex;
}edge[maxn*2];
int head[maxn],ecnt;
inline void add_edge(int u,int v) {
	edge[++ecnt]={v,head[u]};head[u]=ecnt;
	edge[++ecnt]={u,head[v]};head[v]=ecnt;
}
int anc[maxn][20],dep[maxn];
void dfs(int u,int fa) {
	anc[u][0]=fa;dep[u]=dep[fa]+1;
	for(int i=1;(1<<i)<dep[u];i++) anc[u][i]=anc[anc[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].nex) {
		int v=edge[i].v;if(fa^v) dfs(v,u);
	}
}
inline int lca(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=19;i>=0;i--) if(dep[u]-(1<<i)>=dep[v]) u=anc[u][i];
	for(int i=19;i>=0;i--) if(anc[u]!=anc[v]) u=anc[u],v=anc[v];
	return u==v?u:anc[u][0];
}
