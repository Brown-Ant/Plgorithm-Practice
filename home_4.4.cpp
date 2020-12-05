#include <stdio.h>
#include <queue>
using namespace std;
#define MAXN 21 //最多的集装箱数
//问题表示
int n=5;
int W=10;
int w[]={0,5,2,6,4,3}; //集装箱重量,不计下标 0 的元素
//求解结果表示
int bestw=0; //存放最大重量,全局变量
int bestx[MAXN]; //存放最优解,全局变量
int Count=1; //搜索空间中结点数累计,全局变量
typedef struct {
    int no; //结点编号
    int i; //当前结点在解空间中的层次
    int w; //当前结点的总重量
    int x[MAXN]; //当前结点包含的解向量
    int ub; //上界
} NodeType;
struct Cmp //队列中关系比较函数
{
    bool operator()(const NodeType &s,const NodeType &t)
    {
        return (s.ub<t.ub) || (s.ub==t.ub && s.x[0]>t.x[0]); //ub 越大越优先,当 ub 相同时 x[0]越小越优先
    }
};
void bound(NodeType &e) //计算分枝结点 e 的上界
{
    int i=e.i+1;
    int r=0; //r 为剩余集装箱的重量
    while (i<=n)
    {
        r+=w[i];
        i++;
    }
    e.ub=e.w+r;
}
void Loading() //求装载问题的最优解
{
    NodeType e,e1,e2; //定义 3 个结点
    priority_queue<NodeType,vector<NodeType>,Cmp > qu; //定义一个优先队列 qu
    e.no=Count++; //设置结点编号
    e.i=0; //根结点置初值,其层次计为 0
    e.w=0;
    for (int j=0; j<=n; j++) //初始化根结点的解向量
        e.x[j]=0;
    bound(e); //求根结点的上界
    qu.push(e); //根结点进队
    while (!qu.empty()) //队不空循环
    {
        e=qu.top();
        qu.pop(); //出队结点 e 作为当前结点
        if (e.i==n) //e 是一个叶子结点
        {
            if ((e.w>bestw) || (e.w==bestw && e.x[0]<bestx[0])) //比较找最优解
            {
                bestw=e.w; //更新 bestw
                for (int j=0;j<=e.i;j++)
                    bestx[j]=e.x[j]; //复制解向量 e.x->bestx
            }
        }else //e 不是叶子结点
        {
            if (e.w+w[e.i+1]<=W) //检查左孩子结点
            {
                e1.no=Count++; //设置结点编号
                e1.i=e.i+1; //建立左孩子结点
                e1.w=e.w+w[e1.i];
                for (int j=0; j<=e.i; j++)
                    e1.x[j]=e.x[j]; //复制解向量 e.x->e1.x
                e1.x[e1.i]=1; //选择集装箱 i
                e1.x[0]++; //装入集装箱数增 1
                bound(e1); //求左孩子结点的上界
                qu.push(e1); //左孩子结点进队
            }
            e2.no=Count++; //设置结点编号
            e2.i=e.i+1; //建立右孩子结点
            e2.w=e.w;
            for (int j=0; j<=e.i; j++) //复制解向量 e.x->e2.x
                e2.x[j]=e.x[j];
            e2.x[e2.i]=0; //不选择集装箱 i
            bound(e2); //求右孩子结点的上界
            if (e2.ub>bestw) //若右孩子结点可行,则进队,否则被剪枝
                qu.push(e2);
        }
    }
}
void disparr(int x[],int len) //输出一个解向量
{
    for (int i=1;i<=len;i++)
        printf("%2d",x[i]);
}
void dispLoading() //输出最优解
{
    printf(" X=[");
    disparr(bestx,n);
    printf("],装入总价值为%d\n",bestw);
}
int main()
{
    Loading();
    printf("求解结果:\n");
    dispLoading(); //输出最优解
}
