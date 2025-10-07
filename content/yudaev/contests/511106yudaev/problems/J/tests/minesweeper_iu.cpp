#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std; 
int a[1000][1000];
int main (){
	int n,m,x,y,res=0,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0; i<k; i++){
		scanf("%d %d",&x,&y);
		a[x][y]=-1;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i][j]!=-1){
			if(a[i][j+1]==-1)res++;
			if(a[i][j-1]==-1)res++;
			if(a[i+1][j]==-1)res++;
			if(a[i-1][j]==-1)res++;
			if(a[i-1][j-1]==-1)res++;
			if(a[i+1][j+1]==-1)res++;
			if(a[i-1][j+1]==-1)res++;
			if(a[i+1][j-1]==-1)res++;
			a[i][j]=res;
			res=0;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i][j]==-1)printf("* ");
			else printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}