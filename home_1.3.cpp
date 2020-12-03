//
// Created by ant on 2020/10/10.
//
#include  <iostream>
using namespace std;
int getLength(char ch [] ,int i);

int main(){
    char str [10];
    cout << "输入长度不超过10个字符的字符串" << endl;
    cin >> str;
    int i = 0;
    cout <<  "字符串长度:"<< getLength(str,i) << endl;
}
int getLength(char ch [],int i){
    if(ch[i] == '\0'){
        return i;
    }else{
        i++;
        return getLength(ch,i);
    }
}
