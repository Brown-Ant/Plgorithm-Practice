//
// Created by ant on 2020/10/14.
//
#include <iostream>
using namespace std;
void arrayPrint(int n,int i,int j,int num,int floor);
int arr[50][50];

int main(){
    int n;
    cin >> n;
    int floor = (n+1)/2;
    arrayPrint(n,0,0,1,floor);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
/**
 * 输出螺旋矩阵
 * 螺旋矩阵就是不同层次的矩阵组合起来的。
 * 每一个层次的矩阵都是从左上角开始，顺时针方向数字由小到大，分为4段。
 * 每一个层次都是矩阵。但是需要进行奇数矩阵的判断，最后一层是个单独的数。
 * 层次越往里左上角的数值越大。
 * i 行，j列
 */
void arrayPrint(int n,int i,int j,int num,int floor){
    int i_n = i,j_n = j;
    if(!floor){
        return;
    }
    if((n & 1) ==1 && floor==1){
        arr[i][j] = num;
        return;
    }else{
        for(int k;k<4;k++){
            if(k==0){
                for(;j_n<n-1+j;j_n++){
                    arr[i_n][j_n] = num++;
                }
            }else if(k == 1){
                for(;i_n<n-1+i;i_n++){
                    arr[i_n][j_n] = num++;
                }
            }else if(k == 2){
                for(;j_n>j;j_n--){
                    arr[i_n][j_n] = num++;
                }
            }else if(k == 3){
                for(;i_n>i;i_n--){
                    arr[i_n][j_n] = num++;
                }
            }
        }
        arrayPrint(n-2,++i,++j,num,--floor);
    }

}