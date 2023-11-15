#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int a,b;
    double d,sum;
    while(true){
        string str;
        vector<string> tmp;
        cin >> a >> b;
        if( a <= 0 || b <=0 )
            break;
        for( int i=0; i<a; i++ ){
            cin >> str;
            tmp.push_back(str);
        }
        vector<double> v[b];
        for( int i=0; i<b; i++ ){
            for( int j=0; j<a; j++ ){
                cin >> d;
                v[i].push_back(d);
            }
        }
        cout << "s\t";
        for( int i=0; i<a; i++ ){
            cout << tmp[i]<<"\t";
        }
        cout << "avg\n";
        for( int i=0; i<b; i++ ){
            cout << i + 1 << "\t";
            sum = 0;
            for( int j=0; j<a; j++ ){
                sum += v[i][j];
                cout << v[i][j] << "\t";
            }
            printf("%.2f",sum/=v[i].size());
            cout << endl;
        }
        cout << "aa\t";
        for( int i=0; i<a; i++){
            sum = 0;
            for( int j=0; j<b; j++){
                sum += v[j][i];
            }
            printf("%.2f\t", sum /= b);
        }
        cout << endl;
    }

    return 0;
}