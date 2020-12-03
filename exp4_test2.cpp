#include <iostream>
#include <algorithm>;
using namespace std;
int main() {
    int n = 3;
    int A[3] = { 1,2,3 };
    int B[3] = { 3,2,4 };
    int i = 0, j = 0;
    sort(A, A + n);
    sort(B, B + n);
    int count = 0;
    while (i < 3 && j < 3) {
        if (A[i] <= B[j]) {
            count++;
            i++;
            j++;
        }
        else {
            j++;
        }
    }
    cout << count;
}

