//
// Created by ant on 2020/10/14.
//
/**
 * 快速排序实现
 */
#include <iostream>
using namespace std;

int Partition(int a[],int p,int r);
void QuickSort(int a[],int p,int r);
int main(){
    int a[] = {6,5,7,9,8,11,24,1,3,14};
    int r = (sizeof(a)/sizeof(a[0]))-1;//sizeof(a)/sizeof(a[0])返回数组的length，r是数组的最大下标。
    int p = 0;//数组排序的起始位
    QuickSort(a,p,r);
    for(int i:a){
        cout<<i<<" ";//不换行输出
    }
}
/**
 * 快速排序算法，分治思路递归实现
 * @param a
 */
void QuickSort(int a[],int p,int r){
    if(p<r){//递归循环的截止条件
        int q = Partition(a,p,r);//传入数组的该部分数组的第一位下标为p，假设该元素是分界值进行第一次快速排序
        //在得到数组该部分的分界值的基础上，利用分治法再分别对分出的部分进行排序
        QuickSort(a,p,q-1);
        QuickSort(a,q+1,r);
    }
}
/**
 * Partition快速排序算法
 * 传入参数是一个数组和这个数组需要排序的部分数组的最小下标p和最大下标r
 * 假设传入数组的第一位为分界值
 * 在一个循环里
 * 先从左往右遍历判断是否有大于分界值的数，有的话停止遍历。
 * 然后从右往左遍历判断是否有小于等于分界值的数，有的话停止遍历。
 * 设置退出循环的条件，如果大于分界值的数的下标大于等于那个小于分界值的数的下标。
 * 如果当前没有退出循环的话，交换上面遍历得到的大于分界值的数的和小于等于分界值的数的位置
 * 继续循环
 * 如果循环结束
 * 分界值和最后得到的小于等于分界值的数交换位置
 * 返回新的分界值的下标
 * @return
 */
int Partition(int a[],int p,int r){
    int i = p;
    int j = r+1;//假设一个数组之外的下标。方便运算。
    int t;//接收数组的临时变量
    int x = a[p];//假设分界值
    while(true){
        while(a[++i] <= x && i<r);//从左往右遍历，遇到小于等于分界值的数则继续循环。当前数是大于分界值的数则退出循环。
        while(a[--j] > x);//从右往左遍历，遇到大于分界值的数则继续循环。当前数是小于等于分界值的数则退出循环。
        if(i>=j)break;//完成了一次完成的遍历
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}