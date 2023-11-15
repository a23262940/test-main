#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int a,c=0;
    //vector<string> b1;
    string b;
    while(true){
        while(cin >>a){
            if(a==1 || a==0){
                cout << "n incorrect\n";
            }else if(a==-1){
                return 0;
            }else if(a<-1){
                continue;
            }
            else{
                break;
            }
        }
        while(cin>>b){
            bool flag1  = false;
            for (int i = 0; i < b.size();i++){
                bool flag  = false;
                if (b[i] == 'R')
                {
                    c = a - 1;
                    for (int i = 0; i < a; i++)
                    {
                        for (int j = 0; j < a - c; j++)
                        {
                            cout << "*";
                        }
                        cout << "\n";
                        c--;
                    }
                    flag1 = true;
                    flag = true;
                }
                else if (b[i] == 'L')
                {
                    c = 0;
                    for (int i = a; i > 0; i--)
                    {
                        for (int j = 0; j < a - c; j++)
                        {
                            cout << "*";
                        }
                        cout << "\n";
                        c++;
                    }
                    flag1 = true;
                    flag = true;
                }else{
                    flag = true;
                    cout << "D incorrect\n";
                }
            if(flag)
                break;
        }
        if(flag1)
                break;
        } 
    }
}