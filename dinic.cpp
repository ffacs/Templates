#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+4;
const int maxm=1e5+5;
struct EDGE{
	int t,nex;
	ll w;
}edge[maxm<<1];
int head[maxn],ecnt;
inline void addedge(int u,int v,int w){
	edge[++ecnt]={v,head[u],w};head[u]=ecnt;
}
int S,T,N,M;
const int INF=0x7fffffff;
int degree[maxn];
inline bool bfs(){
	queue<int> Q;
	Q.push(S);
	for(int i=1;i<=N;i++) degree[i]=0;degree[S]=1;
	while (!Q.empty()){
		int x=Q.front();Q.pop();
		for(int i=head[x];i;i=edge[i].nex){
			int v=edge[i].t;
			if(edge[i].w&&!degree[v]){
				degree[v]=degree[x]+1;
				Q.push(v);
			}
		}
	}
	return degree[T];
}
ll dfs(int now,ll flow){
	if(now==T||!flow) return flow;
	ll ans=0;
	for(int i=head[now];i;i=edge[i].nex){
		int v=edge[i].t,low;
		if(degree[now]+1==degree[v]&&edge[i].w){
			low=dfs(v,min(flow,edge[i].w));
			edge[i].w-=low;edge[((i-1)^1)+1].w+=low;
			flow-=low;ans+=low;
		}
	}
	if(ans==0) degree[now]=0;
	return ans;
}
inline ll dinic(){
	ll ans=0,d;
	while (bfs()) while (d=dfs(S,INF)) ans+=d;
	return ans;
}
int main(){
	cin>>N>>M>>S>>T; //N V,M E,S 源,T 汇,需初始 N,S,T 
	int u,v,w;
	for(int i=1;i<=M;i++){
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);addedge(v,u,0); //对于有向边，正向容量w,反向0，双向边则正反容量都为w
	}
	cout<<dinic()<<endl;
	return 0;
}