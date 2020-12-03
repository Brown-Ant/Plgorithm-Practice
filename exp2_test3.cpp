//
// Created by ant on 2020/10/6.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
using namespace std;

int n;
int queenpos[100];
void nqueen (int k);
int main()
{
    cin >> n;
    nqueen(0);
    return 0;
}

void nqueen (int k) {
    int i;
    if( k == n )
    {
        for(i = 0 ; i < n ; i++)
        {
            cout<<"("<<i+1<<"," << queenpos[i] + 1<<")" << "  ";
        }
        cout << endl;
        return ;
    }

    for(i = 0; i < n ; i++)
    {
        int j;
        for(j = 0 ; j < k; j++) {
            if( queenpos[j] == i || abs(queenpos[j] - i) == abs(k-j)) {
                break;                }
        }

        if(j == k)
        {
            queenpos[k] = i;
            nqueen(k+1);
        }
    }
}

