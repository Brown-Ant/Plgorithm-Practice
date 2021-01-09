#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int s=0;
    int jump=0;
    int current=0;
    // 输入
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    for(int i=0;i<n;++i){
        s=max(s,i+arr[i]);
        if(current == i){
            jump ++;
            current = s;
        }
    }
    // 如果无法到达输出-1
    if( current >= n ){
        cout << "最少需要的次数："<< jump <<endl;
    }else{
        cout << "-1" <<endl;
    }
    return 0;
}