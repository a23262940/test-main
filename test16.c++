#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,num;
    string a;
    vector<string> a1,out;
    while(true){
        cin >> n;
        if(n<1){
            break;
        }
        for(int i=0; i<n; i++){
            cin >> a;
            if(a[0]>='A' && a[0]<='Z'){
               num =a[0] - 'A';
               out.push_back(to_string(num+48));
               a1.push_back(to_string(num+48));
            }else if(a[0]>='a'&&a[0]<='z'){
                num =a[0] - 'a';
                out.push_back(to_string(num+48));
                a1.push_back(to_string(num+48));
            }
            a1.push_back(a);
        }
        sort(out.begin(), out.end());
        cout << "Sorted list: "<<endl;
        for (int i = 0 ; i <n;i++){
            for (int j = 0; j < a1.size();j+=2){
                if (out[i] == a1[j]){
                    cout <<"Name "<<i+1<< ": " <<a1[j+1] << "\n";
                }
            }
        }
        a1.clear();
        out.clear();
    }
}