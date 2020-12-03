//
// Created by ant on 2020/10/21.
//
#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int> vec,int low,int mid,int heigh)
int main(){
    //声明vector变量
    vector <int> vec = {6,1,7,9,4,2,5,2,0,3,11,20};
    cout << "vec length: "<< vec.size() << endl;


}
/**
 * 两路归并排序
 * 使用分治法分解数组，分解最小后。进行排序然后再归并。通过递归的方式，使最后一次的归并和排序之后得到有序的数组。
 * 排序思路：一个无序数组，由两段组成。把后半段的元素通过比较，插入到前半段。最后得到排序好的数组。
 * 这里要求实现降序，所以大的在前面,小的往后放。但是如果遇到大的直接替换的话会出现后面比较
 */

/**
 *
 * @param vec
 * @param low 最小下标
 * @param min 中间位置下标
 * @param heigh 最大下标
 */
 void Merge(vector<int> vec,int low,int mid,int heigh){
     while(low < heigh && mid <= heigh){
        if(vec[low]<vec[mid]){

        }else{

        }
     }
 }
 void MergeSort(){

 }
