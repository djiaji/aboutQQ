#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2005;
int n,c,ans,__dist_array[N];
struct point_t{
	int x,y;
};
point_t points[N];
int __dist_function(int x,int y){
	return (points[x].x-points[y].x)*(points[x].x-points[y].x)+(points[x].y-points[y].y)*(points[x].y-points[y].y);
}
class dis_base{
public:
	int operator()(int x,int y){
		return __dist_function(x,y);
	}
	int& operator[](int x){
		return __dist_array[x];
	}
}dis;
bool vis[N];
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&points[i].x,&points[i].y);
	memset(__dist_array,0x3f3f3f3f,sizeof(__dist_array));
	dis[1] = 0;
	int x = 1;
	goto label;
	while(true){
		x = 0;
		for(int i=1;i<=n;++i)
			if(!vis[i]&&dis[i]<dis[x]&&dis[i]&&dis[i]>=c)
				x = i;
		if(x==0)break;
		label:
		vis[x] = 1;
		ans += dis[x];
		for(int i=1;i<=n;++i)
			if(!vis[i]&&dis[i]>dis(i,x)&&dis(i,x)>=c)
				dis[i] = dis(i,x);
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])
			return 0*printf("-1");
	printf("%d",ans);
	return 0;
}
