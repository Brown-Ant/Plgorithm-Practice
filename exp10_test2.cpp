#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int n;
int dp[100][100];
int pre[100][100];
int ans=0;
int search(){ //求解最小路径和 ans
    int i,j;
    dp[0][0]=a[0][0];
    for(i=1;i<n;i++){ //考虑第 1 列的边界
        dp[i][0]=dp[i-1][0]+a[i][0];
        pre[i][0]=i-1;
    }
    for(i=1;i<n;i++){ //考虑对角线的边界
        dp[i][i]=a[i][i]+dp[i-1][i-1];
        pre[i][i]=i-1;
    }
    for(i=2;i<n;i++){ //考虑其他有两条达到路径的结点
        for(j=1;j<i;j++){
            if(dp[i-1][j-1]<dp[i-1][j]){
                pre[i][j]=j-1;
                dp[i][j]=a[i][j]+dp[i-1][j-1];
            }   
            else{
                pre[i][j]=j;
                dp[i][j]=a[i][j]+dp[i-1][j];
            }
        }
    }
    ans=dp[n-1][0];
    int k=0;
    for(j=1;j<n;j++){ //求出最小 ans 和对应的列号 k
        if(ans>dp[n-1][j]){
            ans=dp[n-1][j];
            k=j;
        }
    }
    return k;
}
void Dispath(int k) //输出最小和路径
{
    int i = n - 1;
    vector<int> path;//存放逆路径向量 path
    while (i >= 0) //从(n-1,k)结点反推求出反向路径
    {
        path.push_back(a[i][k]);
        k = pre[i][k]; //最小路径在前一行中的列号
        i--; //在前一行寻找
    }
    vector<int>::reverse_iterator it; //定义反向迭代器
    for (it = path.rbegin(); it != path.rend(); ++it)
        cout << *it << " "; // 反向输出构成正向路径
    }
int main(){
    int k;
    memset(pre,0,sizeof(pre));
    memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            scanf("%d",&a[i][j]);
            k=search();Dispath(k);
            printf("最小路径和为： ");
            printf("%d\n",ans);
    return 0;
}