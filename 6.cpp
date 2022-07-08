#include<cstdio>
#include<vector>
#include<climits>
#include<cstring>
#include<algorithm>
const int N = 114514;
const int homo = 1919810;
struct edge{int from,to,val;bool operator<(const edge& n)const{return val>n.val;}}a[homo];
struct node{int to,val;};
using namespace std;
vector<node> g[N];
int n,m,cnt,q,fa[N],dep[N],fat[N][21],st[N][21],lg[N];
int find(int x){return (x==fa[x]?x:(fa[x]=find(fa[x])));}
void merge(int x,int y){fa[find(x)]=find(y);}
void dfs(int p,int f,int val){
	dep[p] = dep[f] + 1;
	fat[p][0] = f;
	st[p][0] = val;
	for(int i=1;i<=lg[dep[p]];++i)fat[p][i]=fat[fat[p][i-1]][i-1],st[p][i]=min(st[p][i-1],st[fat[p][i-1]][i-1]);
	for(node x:g[p])if(x.to!=f)dfs(x.to,p,x.val);
}
int LCA(int a,int b){
	if(find(a)!=find(b))return -1;
	if(dep[a]>dep[b])swap(a,b);
	int ans = INT_MAX;
	while(dep[a]!=dep[b])ans=min(ans,st[b][lg[dep[b]-dep[a]]]),b=fat[b][lg[dep[b]-dep[a]]];
	if(a==b)return ans;
	for(int i=lg[dep[a]];i>=0;--i)
		if(fat[a][i]!=fat[b][i])
			ans=min(ans,min(st[a][i],st[b][i])),a=fat[a][i],b=fat[b][i];
	return min(ans,min(st[a][0],st[b][0]));
}
int main(){
	memset(st,0x3f3f3f3f,sizeof(st));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].val);
	sort(a+1,a+m+1);
	for(int i=1;i<=m;++i){
		if(find(a[i].from)!=find(a[i].to)){
			merge(a[i].from,a[i].to);
			g[a[i].from].push_back({a[i].to,a[i].val});
			g[a[i].to].push_back({a[i].from,a[i].val});
			if(++cnt==n-1)break;
		}
	}
	dfs(1,0,INT_MAX);
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",LCA(x,y));
	}
	return 0;
}
