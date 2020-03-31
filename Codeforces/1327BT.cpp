#include <cstdio>
#include <algorithm>
#define maxn 100010
using namespace std;
int x[maxn],vis[maxn];
int main(){
	int t,n,k,i,j,v,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)x[i]=0,vis[i]=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			for(j=1;j<=k;j++){
				scanf("%d",&v);
				if(x[i]==0&&vis[v]==0)x[i]=v,vis[v]=1;
			}
		}
		a=0,b=0;
		for(i=1;i<=n;i++)
			if(x[i]==0){
				a=i;
				break;
			}
		for(i=1;i<=n;i++)
			if(vis[i]==0){
				b=i;
				break;
			}
		if(a==0&&b==0){
			printf("OPTIMAL\n");
		}else{
			printf("IMPROVE\n");
			printf("%d %d\n",a,b);
		}
	}
	return 0;
}