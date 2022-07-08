#include<cmath>
#include<cstdio>
#include<numeric>
#include<climits>
#include<algorithm>
const int N = 1919810;
const int maxn = 505;
struct node{int from,to,val;bool operator<(const node& n)const{return val<n.val;}}a[N];
struct point{double x,y;}points[maxn];
double dist(int x,int y){
	return sqrt((points[x].x-points[y].x)*(points[x].x-points[y].x)+(points[x].y-points[y].y)*(points[x].y-points[y].y));
}
double dis[maxn],edge[maxn];
bool vis[maxn];
int s,p,cnt;
using namespace std;
int main(){
	scanf("%d%d",&s,&p);
	for(int i=1;i<=p;++i)scanf("%lf%lf",&points[i].x,&points[i].y);//for(int i=1;i<=p;++i)printf("%lf ",dist(i,4));
	fill(dis,dis+p+1,INT_MAX>>1);
	dis[1] = 0;
	while(true){
		int x=0;
		for(int i=1;i<=p;++i){
			if(!vis[i]){
				if(dis[i]<dis[x])x=i;
			}
		}
		if(x==0)break;
		vis[x] = 1;
		edge[++cnt] = dis[x];
		for(int i=1;i<=p;++i)if(!vis[i])dis[i]=min(dis[i],dist(x,i));
	}
	sort(edge+1,edge+p+1);
	printf("%.2lf",edge[p-s+1]);
	return 0;
}
