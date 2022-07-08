#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1919810;
int n,m,s,lg[N],dep[N],fa[N][21];
vector<int> g[N];
void dfs(int p,int f){
	dep[p] = dep[f] + 1;
	fa[p][0] = f;
	for(int i=1;i<=lg[dep[p]];++i)
		fa[p][i] = fa[fa[p][i-1]][i-1];
	for(int x:g[p])if(x!=f)dfs(x,p);
}
int LCA(int a,int b){
	if(dep[a]>dep[b])swap(a,b);
	while(dep[a]!=dep[b])b=fa[b][lg[dep[b]-dep[a]]];
	if(a==b)return a;
	for(int i=lg[dep[a]];i>=0;--i)
		if(fa[a][i]!=fa[b][i])
			a = fa[a][i], b = fa[b][i];
	return fa[a][0];
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;i!=n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(s,0);
	for(int i=1;i<=m;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",LCA(a,b));
	}
	return 0;
}
