#include<queue>
#include<cstdio>
#include<vector>
#include<bitset>
#include<iostream>
const int N = 10005;
using namespace std;
int n,m,ans;
bool can[N],mention[N];
class main{
private:
	bool vis[N];
	void flush(){
		for(int i=1;i<=n;++i)
			if(!in[i]&&!vis[i])
				q.push(i),vis[i]=1;
	}
public:
	vector<int> g[N];
	int in[N];
	bitset<N> dp[N];
	queue<int> q;
	void init(int x,int y){
		g[x].push_back(y);
		++in[y];
		dp[x][y] = 1;
	}
	void toposort(){
		flush();
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int x:g[u]){
				dp[x] |= dp[u];
				--in[x];
			}cout<<u<<' ';for(int i=1;i<=n;++i)cout<<dp[u][i];puts("");
			flush();
		}
	}
}g1,g2;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		mention[x] = 1;
		mention[y] = 1;
		g1.init(x,y);
		g2.init(y,x);
	}
	g1.toposort();
	g2.toposort();
	for(int i=1;i<=n;++i)
		if((int)g1.dp[i].count()>n/2||(int)g2.dp[i].count()>n/2)can[i]=1;
	for(int i=1;i<=n;++i)
		if(can[i]&&mention[i])++ans;
	printf("%d",ans);
	return 0;
}
