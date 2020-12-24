#include<stdio.h>
#define MAXN 20					
#define MAXW 100
 int n=7,W=15;
 int w[MAXN]={2, 3, 5, 7, 1, 4, 1};
 int v[MAXN]={10, 5, 15, 7, 6, 18, 3};
 int dp[1][MAXW];
 int max(int a,int b){
 	return a>b?a:b;
 }
 void Knap(){
 	int i,r;
 	int c=0;
 	for(int i=0;i<=1;i++)
 	dp[i][0]=0;
 	for(int r=0;r<=W;r++)
 	dp[0][r]=0;
 	for(int i=1;i<=n;i++){
 		c=1-c;
 		for(int r=1;r<=W;r++){
 			if(r<w[i])  dp[c][r]=dp[1-c][r];
 			else
 			dp[c][r]=max(dp[1-c][r],dp[1-c][r-w[i]]+v[i]);
		 }
	 }
 }
 int main(){
 	Knap();
	printf("总价值=%d\n",max(dp[0][W],dp[1][W]));
 	return 0;
 }
