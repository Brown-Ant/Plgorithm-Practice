//
// Created by ant on 2020/9/30.
//
#include <vector>
#include <string>
#include <iostream> //cout
using namespace std;
struct student{
    int height;
    string sex;
};
//按照身高排序
int cmpn1(student a,student b)
{
    return a.height>b.height;
}
int main(){
    int n;
    cout << "输入学生个数：" << endl;
    cin >> n;
    vector<student> stu(n);
    vector<student>::iterator it;//定义迭代器
    for(int i=0;i<n;i++){
        int s = rand()%2;//0是male，1是female
        if(s == 0){
            stu[i].sex = "male";
            stu[i].height = 160+(rand()%20+1);
        }else{
            stu[i].sex = "female";
            stu[i].height = 150+(rand()%20+1);
        }
    }
    sort(stu.begin(), stu.end(),cmpn1);//调用cmpn1进行从大到小排序
    cout << "输出按身高倒序结果：" << endl;
    for(it = stu.begin();it!=stu.end();it++){
        cout <<"("<<it->height<<","<<it->sex<<")" <<endl;
    }

}
