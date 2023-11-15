#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string a,d;
    vector<string> b,c;
    int f,g[3];
    while(true){
        bool ok = false,ok1=false;
        for (int i = 0; i < 3;i++){
            cin >> a;
            if(a == "-1Joker")
                return 0;
            b.push_back(a);
        }
        for(int i = 0; i < 3;i++){
            if(b[i][0]=='S'){
                ok1=true;
            }else if(b[i][0]=='H'){
                ok1=true;
            }else if(b[i][0]=='D'){
                ok1=true;
            }else if(b[i][0]=='C'){
                ok1=true;
            }else{
                cout << "ERROR\n";
                ok1 = false;
                b.clear();
                c.clear();
                break;
            }
        }
        if(ok1){
            for (int i = 0; i < b.size(); i++)
            {
                d = b[i];
                d.erase(0, 1);
                f = stoi(d);
                if (f >= 1 && f <= 13)
                {
                    c.push_back(b[i]);
                }
                else
                {
                    cout << "ERROR\n";
                    b.clear();
                    c.clear();
                    break;
                }
            }
            if(!c.empty()){
                for (int i = 0; i < 3; i++){
                    d=c[i];
                    d.erase(0, 1);
                    g[i] = stoi(d);
                }
                ok = ((g[0] == g[1]-1 && g[0]==g[2]-2) || (g[0] == g[1]-2 && g[0]==g[2]-1) || (g[0]-1 == g[1] && g[0]-1==g[2]-2) || (g[0]-1 == g[1]-2 && g[0]-1==g[2]) || (g[0]-2 == g[1] && g[0]-2==g[2]-1) || (g[0]-2 == g[1]-1 && g[0]-2==g[2]));
                if ((c[0][0] == c[1][0] && c[0][0] == c[2][0] && c[1][0] == c[2][0])){
                    if(ok){
                        cout << "同花順\n";
                    }else{
                        cout << "同花\n";
                    }
                }
                else if (c[0][1] == c[1][1] && c[1][1] == c[2][1] && c[0][1] == c[2][1])
                {
                    cout << "三條\n";
                }
                else if ((c[0][1] == c[1][1] || c[0][1] == c[2][1] || c[1][1] == c[2][1]) && c[0][0] != c[1][0] && c[0][0] != c[2][0] && c[1][0] != c[2][0])
                {
                    cout << "對子\n";
                }
                else if (ok)
                {
                    cout << "順子\n";
                }else{
                    cout << "散牌\n";
                }
            }
            b.clear();
            c.clear();
        }
    }
}