#include <iostream>
#include <cmath>
using namespace std;

int len = 0,n =0 ,sum = 0,*step;
void printSum() {
    for (int i = 0; i < len; i++)cout <<step[i]<<" ";
        cout <<endl;
    }
void compute(int stair) {
    if (stair < 0) return;
    if (stair == 0) {
        printSum();
        sum++;
        return;
    }
    for (int i = 1; i <= 2; i++) {
        step[len] = i;
        len++;
        compute(stair - i);
        len--;
    }
}
int main(){
    int n;
    while(true){
        cin >> n;
        if(n==0){
            break;
        }
        step = new int[n];
        compute(n);
        cout << sum << endl;
        len = 0, sum = 0;
    }
}