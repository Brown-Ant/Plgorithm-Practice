#include <iostream>
using namespace std;
int knapsack(int num,int capacity,int weight[],int value[]){//使用动态规划求解0-1背包问题
    /*
    @parameters:
    @num:物品数量，整数类型
    @capacity:背包容量，整数类型
    @weight:各个物品的重量，数组类型
    @value:各个物品的价值，数组类型
    */
    int space,sub_cap,total_value[num+1][capacity+1];
    for(int i=0;i<=num;i++)for(int j=0;j<=capacity;j++)total_value[i][j]=0;//初始化记忆表格
    for(sub_cap=1;sub_cap<=capacity;sub_cap++){
        for(space=1;space<=num;space++){
            if(sub_cap>=weight[space-1]){//判断是否能不能装下
                //能装下，判断装了以后是不是背包的价值更大了
                total_value[space][sub_cap]=max(total_value[space-1][sub_cap],total_value[space-1][sub_cap-weight[space-1]]+value[space-1]);
            }else{
                //装不下的话背包价值还是没有装之前的价值
                total_value[space][sub_cap]=total_value[space-1][sub_cap];
            }
        }
    }
    return total_value[num][capacity];
}
int main(){
    int num=7,capacity=15,weight[]={2,3,5,7,1,4,1};
    int value[]={10, 5, 15, 7, 6, 18, 3};
    cout<<knapsack(num,capacity,weight,value)<<endl;
    return 0;
}
