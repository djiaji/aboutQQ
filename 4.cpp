#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1919810;
int n,m,st[N][22],lg[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;++i)scanf("%d",&st[i][0]);
	for(int k=1;k<=ceil(log2(n));++k)
	for(int i=1;i<=n;++i)
		st[i][k] = max(st[i][k-1],st[i+(1<<(k-1))][k-1]);
	for(int i=1;i<=m;++i){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",max(st[l][lg[r-l+1]],st[r-(1<<(lg[r-l+1]))+1][lg[r-l+1]]));
	}
	return 0;
}
