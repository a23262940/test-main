#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a, b,c[]={2000,1000,500,200,100,50,20,10,5,1},flag=0;
    while(true){
        cin >> a >> b;
        if(a ==-1 || b==-1){
            break;
        }
        if(a>b){
            cout << "not enough\n";
        }else if(a==b){
            cout << "ok\n";
        }else{
            a -= b;
            a = 0 - a;
            cout << a << " ";
            for(int i=0; i<10; i++){
                if(a>=c[i]){
                    while(true){
                        b = a - c[i];
                        flag++;
                        if(b-c[i]<0){
                            break;
                        }else{
                            a = b;
                        }
                    }
                    a = b;
                    cout << c[i] << "*" << flag << " ";
                    flag = 0;
                }
            }
            cout << "\n";
        }
    }
}