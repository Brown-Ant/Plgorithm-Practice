#include <iostream>
#include <cstdlib>
using namespace std;
long Binomial(int,int);
int main()
{
    int n,k;
    cout<<"输入 n:";
    cin>>n;
    cout<<"输入 k:";
    cin>>k;
    cout<<"\nC("<<n<<","<<k<<")="<<Binomial(n,k)<<endl;
    return 0;
}
int min(int n,int m)
{
    return (n>m)?m:n;
}
long Binomial(int n,int k)
{
    if (n<k||n<0||k<0)
    {
        cout<<"数据为： \n";
        return -1;
    }
    else
    {
        int** a=new int*[n+1];
        if (a==0)
        {
            cout<<"不能分配\n";
            return -2;
        }
        int i,j;
        for (i=0;i<=n;i++)
        {
            a[i]=new int[k+1];
            if (a[i]==0)
            {
                cout<<"不能分配\n";
                return -3;
            }
        }
        for (i=0;i<=n;i++)
        {
            for (j=0;j<=min(i,k);j++)
                if (j==0||j==i)
                    a[i][j]=1;
                else
                    a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
        int temp=a[n][k];
        for (i=0;i<=n;i++)
            delete [] a[i];
        delete [] a;
        return temp;
    }
}