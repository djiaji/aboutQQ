#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1919810;
const int maxn = 1005;
struct node{int from,to,val;bool operator<(const node& n)const{return val<n.val;}}a[N];
int n,m,cnt,ans,fa[N];
int find(int x){return (fa[x]==x?x:find(fa[x]));}
void merge(int x,int y){fa[find(x)]=find(y);}
bool same(int x,int y){return find(x)==find(y);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		a[i] = {x,y,t};
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;++i){
		if(same(a[i].from,a[i].to))continue;
			ans = max(ans,a[i].val);
		merge(a[i].from,a[i].to);
		if(++cnt==n-1)break;
	}
	if(cnt<n-1)puts("-1");
	else printf("%d",ans);
	return 0;
}
