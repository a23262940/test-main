#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void outnum(vector<int> v){
    for(int i = 0; i < v.size();++i){
        cout << v[i];
    }
    cout << endl;
}
int main(){
    while(true){
        int n;
        vector<int> v;
        cin >> n;
        if(n == 0){
            break;
        }else{
        for(int i=1; i<=n; i++){
            v.push_back(i);
        }
        outnum(v);
        while(next_permutation(v.begin(), v.end())){
            outnum(v);
        }
        }
    }
}