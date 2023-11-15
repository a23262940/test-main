#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int i, j, t, len,a, b, c;
    cin >> a >> b >> c;
    int d[a];
    len = a;
    for (i = 0; i < a;i++)
        d[i] = i + 1;
    i = c-1;
    while(a>1){
        i = (i + b - 1) % a;
        t = d[i];
        for (j = i; j < a - 1;j++){
            d[j] = d[j + 1];
        }
        d[j] = t;
        a--;
    }
    reverse(d,d+len);
    for (i = 0; i <len; i++){
        cout << d[i] << " ";
    }
}