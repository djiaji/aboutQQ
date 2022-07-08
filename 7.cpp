#pragma GCC optimize(3)
#include<queue>
#include<cstdio>
#include<vector>
#include<bitset>
#include<iostream>
const int N = 10005;
using namespace std;
int n,m,k;
bitset<N> dp[N];
vector<int> g[N];
int in[N];
bool vis[N];
void toposort(){
	queue<int> q;
	for(int i=1;i<=n;++i)if(!in[i])q.push(i),vis[i]=1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int x:g[u]){
			dp[x] |= dp[u];
			--in[x];
		}//cout<<u<<' ';for(int i=1;i<=n;++i)cout<<dp[u][i];puts("");
		for(int i=1;i<=n;++i)if(!in[i]&&!vis[i])q.push(i),vis[i]=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)dp[i][i]=1;
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		g[y].push_back(x);
		++in[x];
	}
	toposort();
	scanf("%d",&k);
	for(int i=1;i<=k;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(dp[x][y])puts("Y");
		else puts("N");
	}
	return 0;
}
