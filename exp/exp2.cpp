#include <iostream>
using namespace std;
int main()
{
    int number;
    string str;
    // 输入n和str
    cin>>number;
    cin>>str;
    int l = str.length();
    // 设立最小字典集用于判断
    string max ="AAAAA";
    string tep;
    for(int v=l-1;v>=0;v--)
        for(int w=l-1;w>=0;w--)
            for(int x=l-1;x>=0;x--)
                for(int y=l-1;y>=0;y--)
                    for(int z=l-1;z>=0;z--)
                    {
                        if(v!=w&&v!=x&&v!=y&&v!=z&&w!=x&&w!=y&&w!=z&&x!=y&&x!=z&&y!=z)
                        {
                            int a=str[v]-64;
                            int b=str[w]-64;
                            int c=str[x]-64;
                            int d=str[y]-64;
                            int e=str[z]-64;
                            if((a-b*b+c*c*c-d*d*d*d+e*e*e*e*e)==number)
                            {
                                tep  = str[v];
                                tep  += str[w];
                                tep  += str[x];
                                tep  += str[y];
                                tep  += str[z];
                                if(tep>max)
                                    max = tep;
                            }
                        }
                    }
    // 如果得到的最大字典集等于设置的最小字典集，则输出no solution
    if(max=="AAAAA"){
        cout<<"no solution"<<endl;
    }else{
        cout<<max<<endl;
    }
    return 0;
}
