#include <iostream>
#include <queue>
using namespace std;
// 地图（二维矩阵）0表示可通行，-1表示有障碍物被锁定。
int grid[7][7] = {
        { 0, 0,-1,-1, 0, 0, 0},
        { 0, 0, 0,-1, 0, 0, 0},
        { 0, 0, 0, 0,-1, 0, 0},
        { 0, 0, 0,-1,-1, 0, 0},
        {-1, 0, 0, 0,-1, 0, 0},
        {-1,-1,-1, 0, 0, 0, 0},
        {-1,-1,-1, 0, 0, 0, 0},
};
int m=7, n=7;//二维矩阵横纵长度
// 节点实体
struct Position
{
    int row;
    int col;
};
// 地图格式化输出
void Show()
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            if(grid[i][j]>=0 && grid[i][j]<10){
                cout<<"  "<<grid[i][j];
            }else{
                cout<<" "<<grid[i][j];
            }
            cout<<"";
        cout<<endl;
    }
}
// 计算从起点位置start到目标位置finish的最短路径
bool SearchPath(Position start,Position finish,int &PathLen,Position *&path)
{
    // 判断起点与终点是否重合
    if((start.row==finish.row) && (start.col==finish.col))
    {
        PathLen=0;
        cout<<"起点与终点是否重合！"<<endl;
        return true;
    }
    //初始化相对位移
    Position offset[4];
    offset[0].row=0;
    offset[0].col=1;//右
    offset[1].row=1;
    offset[1].col=0;//下
    offset[2].row=0;
    offset[2].col=-1;//左
    offset[3].row=-1;
    offset[3].col=0;//上
    // 声明当前活结点和下一活结点实例
    Position here,next;
    here.row=start.row;
    here.col=start.col;
    grid[start.row][start.col]=1;
    queue<Position> Queue;// 队列先进先出
    do
    {
        for(int i=0; i<4; i++)
        {
            next.row=here.row + offset[i].row;
            next.col=here.col + offset[i].col;
            //能走且没有越界
            if(grid[next.row][next.col]==0&&next.row!=-1 && next.col!=-1 )
            {
                grid[next.row][next.col]=grid[here.row][here.col]+1;
                if((next.row==finish.row) &&(next.col==finish.col)) break; //到达终点，路径提前搜索完成
                Queue.push(next);
            }
        }
        // 中断do while循环，到达终点，路径提前搜索完成
        if((next.row==finish.row)&&(next.col==finish.col)) break;//完成布线
        // 活结点队列传入空结点，已经越过边界。无法到达终点
        if(Queue.empty()) return false;
        // 取队首
        here = Queue.front();
        // 出队
        Queue.pop();
    }while(true);
    // 得到最短路径
    PathLen = grid[finish.row][finish.col];
    path = new Position[PathLen];
    // 从目标位置finish开始向起始位置回溯，并存储路径经过的活结点坐标。
    here=finish;
    for(int j=PathLen-1; j>=0; j--)
    {
        // 当前获取当前活结点坐标
        path[j]=here;
        // 四周寻找上一个活结点
        for(int i=0; i<4; i++)
        {
            next.row=here.row+offset[i].row;
            next.col=here.col+offset[i].col;
            if(grid[next.row][next.col]==j)
            {
                break;
            }
        }
        here=next;//向前移动
    }
    return PathLen;
}
int main()
{
    // 声明起点和终点
    Position start;
    Position finish;
    // 设置起点和终点
    start.row=2;
    start.col=1;
    finish.row=3;
    finish.col=5;
    // 查看起点和终点
    cout<<"起点坐标：("<<start.col<<" "<<start.row<<")"<<endl;
    cout<<"终点坐标：("<<finish.row<<" "<<finish.col<<")"<<endl;
    // 设置距离（其他活结点与起点的距离）
    int PathLen=0;
    // 获取起点到终点的某一条最短路径
    Position *path;
    cout<<"原地图"<<endl;
    Show();
    // 进行路径搜索
    SearchPath(start,finish,PathLen,path);
    cout<<"标注活结点与起点之间距离之后的地图"<<endl;
    Show();
    cout<<"起点到终点的某一条最短路径"<<endl;
    for(int i=0; i<PathLen; i++)
    {
        cout<<"("<<path[i].row<<" "<<path[i].col<<")"<<endl;
    }
    return 0;
}
