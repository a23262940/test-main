#include <iostream>
#include <vector>
using namespace std;

void truangle(int n){
    int i, j;
    for(i=0; i<n; i++){
        for (j = 0; j < (n - 1 - i);j++){
            cout << " ";
        }
        for (j = 0; j < 2 * i + 1;j++){
            if(j==0 || j==2*i)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    for (i = 0; i < n - 1;i++){
        for (j = 0; j < i + 1;j++){
            cout << " ";
        }
        for (j = 0; j < 2 * (n - 1) - (1 + 2 * i);j++){
            if(j==0 || j==2*(n-i-2))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void aa(int n){
    int i, j;
    if(n<=2){
        for (i = 1; i <= n; i++)
        {
            if (i == 1 || i == n)
            {
                for (j = 0; j < n; j++)
                {
                    cout << "*";
                }
                cout << "\n";
            }
            else
            {
                cout << "*";
                for (j = 1; j <= n - 2; j++)
                {
                    cout << " ";
                }
                cout << "*\n";
            }
        }
    }else{
        for (i = 0; i < n % 2;i++){
            
        }
    }
}

int main()
{
    while (true){
        int a,b,c,e,i;
        vector<int> d;
        cin >> a;
        if (a <= 0)
            break;
        for (i = 0; i < a;i++){
            cin >> b >> c;
            d.push_back(b),d.push_back(c);
        }
        for (e = 0; e < d.size();e+=2){
            if(d[e]==1){
                truangle(d[e + 1]);
            }else if(d[e]==2){
                if(d[e+1]==2)
                    aa(d[e + 1]+1);
                else
                    aa(d[e + 1]);
            }
        }
    }
    return 0;
}