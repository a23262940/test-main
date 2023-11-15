#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void c_recur(int k, int n, int m, vector < int > list,vector < int > list1);

int main() {
    while(true) {
        int m, n,d;
        cin >> m >> n;
        if(m<=0 || n<=0 || m<n){
            break;
        }
        vector < int > list;
        vector < int > list1;
        for (int i = 0;i<m;i++){
                cin >> d;
                list.push_back(d);
        }
        sort(list.begin(),list.end());
        for (int i = 0; i <= (m - n) && n > 0; ++i) {
            c_recur(i + 1, n - 1, m, list,list1);
        }
    }
    return 0;
}

void c_recur(int k, int n, int m, vector < int > list,vector < int > list1) {
    list1.push_back(list[k-1]);
    for (int i = k; i <= (m - n) && n > 0; ++i) {
        c_recur(i + 1, n - 1, m, list,list1);
    }
    if (n == 0) {
        sort(list1.begin(), list1.end());
        for (int i = 0; i < list1.size(); ++i)
        {
            cout << list1[i] << ' ';
        }
        cout << endl;
    }
}