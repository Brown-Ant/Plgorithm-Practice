//
// Created by ant on 2020/10/18.
//
#include<iostream>
using namespace std;
int Partition(int a[],int p,int r);
int main(){
    int a[] = {2,8,7,1,3,5,6,4};
    for(int i:a){
        cout << i << " ";
    }
    cout << endl;
    //传入数组，最小下标，最大下标。
    Partition(a,0,7);
    for(int i:a){
        cout << i << " ";
    }

}
/**
 * 将传进来的数组的最后一位假设为分界值
 * 先从左往右进行比较，设立两个下标。
 * 第一个下标j是为了从左往右遍历。最大为r-1。第二个下标i是为了记录已知的小于分界值的值的最大下标。
 * 数组从左往右遍历，当遇到小于等于分界值的数，下标i++，然后把当前的值交换到已知的小于分界值的元素的最右边。
 * 一便遍历完后，最后把分界值与已知的小于分界值的右边的元素交换，这个时候分界值左边全是小于它的元素，右边全是大于它的元素。不过都是无序的。
 * @param a
 * @param p
 * @param r
 * @return
 */
int Partition(int a[],int p,int r){
    int i = p-1;
    int j = p;
    int x = a[r];//假设最后一位是分界值
    int t;//接收数组的临时变量
    for(;j<r;j++){
        if(a[j]<=x){
            i++;
            t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    }
    t = a[i+1];
    a[i+1] = a[r];
    a[r] = t;
    return i+1;
}
