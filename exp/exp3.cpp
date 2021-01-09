

#include<iostream>
#include<algorithm>
using namespace std;
// 商店结构体
struct store{
    int x;
    int y;
};
int main(){
    store a[10];
    int n;// 商店数量
    int m;
    cout<< "输入二维矩阵化街道的长度："<<endl;
    cin>>m;
    // 由商店围成的几何图形上下左右边,随着商店的增加可能会不断变化
    int xmin=m,xmax=0,ymin=m,ymax=0;
    cout<<"输入商店数量："<<endl;
    cin>>n;
    cout<<"开始进行输入商店坐标："<<endl;
    // 输入各个商店的坐标
    for(int i=0;i<n;i++){
        cout<<"输入商店"<< i+1 <<"坐标："<<endl;
        cin>>a[i].x>>a[i].y;
        if(a[i].x<xmin)
            xmin=a[i].x;
        if(a[i].y<ymin)
            ymin=a[i].y;
        if(a[i].x>xmax)
            xmax=a[i].x;
        if(a[i].x>ymax)
            ymax=a[i].y;
    }

    int xsum=100,ysum=100;// 假设仓库位置最边坐标
    int storageX,storageY;// 仓库实际坐标
    // 计算商店横坐标
    for(int i=xmin;i<=xmax;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            // 计算绝对值
            sum+=abs(a[j].x-i);
        }
        if(sum<xsum){//如果当前i轴距离各商店横向距离总和比上一个i-1轴小则替换
            xsum=sum;
            storageX=i;
        }
    }
    // 计算商店纵坐标
    for(int i=ymin;i<=ymax;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            // 计算绝对值
            sum+=abs(a[j].y-i);
        }
        if(sum<ysum){//如果当前i轴距离各商店纵向距离总和比上一个i-1轴小则替换
            ysum=sum;
            storageY=i;
        }
    }
    cout<<"最佳仓库位置："<<endl;
    cout<<"("<<storageX<<','<<storageY<<")"<<endl;
    cout<<"总路程:"<<endl;
    cout<<xsum+ysum<<endl;
    return 0;
}
