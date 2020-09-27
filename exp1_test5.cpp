//
// Created by ant on 2020/9/27.
//
#include <iostream> //cout
#include <vector> //vector
#include <algorithm> //sort()
#include <ctime> //clock()
#include <iomanip> //fixed,setprecision();
#include <cstdlib> //rand()
using namespace std;
void average_time_sort(int n);

int main(){
    int n [6]= {100,1000,10000,100000,1000000,10000000};
    //包含6个元素的数组
    for(int i=0; i<6; i++){
        average_time_sort(n[i]);
    }
}
void average_time_sort(int n) {
    vector<int> vec(n);//申请包含n个元素的数组
    double sum = 0.0;
    for (int j = 0; j < 100; j++) {
        for (int i = 0; i < n; i++) { //为数组赋值
            vec[i] = rand() % n + 1; //赋值为随机数，vec[i]取值范围为[1,n]
        }
        clock_t start_time = clock(); //开始定时
        sort(vec.begin(), vec.end()); //对数组赋值
        clock_t elpased_time = clock() - start_time; //计算耗时
        sum+=elpased_time;
    }
    sum = sum/100;  //计算平均值
    cout << fixed << setprecision(6); //设置输出小数点精度
    cout << "Time avg：" << double(sum) / CLOCKS_PER_SEC << endl;
}

