#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    int T,M;
    while(cin>>T>>M)
    {
        int t[1001],v[101];
        int m[101][1001];
        memset(m,0,sizeof(m));
        for(int i=1;i<=M;i++)
        {
            cin>>t[i]>>v[i];
        }
        for(int i=1;i<=M;i++)
        {
            for(int j=1;j<=T;j++)
            {
                if(j<t[i]) m[i][j]=m[i-1][j];
                else
                {
                    if(m[i-1][j]>m[i-1][j-t[i]]+v[i])
                        m[i][j]=m[i-1][j];
                    else m[i][j]=m[i-1][j-t[i]]+v[i];
                }
            }
        }
        cout<<"最优解： "<<m[M][T]<<endl;
    }
    return 0;
}
