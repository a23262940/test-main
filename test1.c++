#include<iostream>
#include<string>
using namespace std;
string getcoffeine(string a){
    string coffeine;
    const string map = {
        'coffee' : '95 mg',
        'Redbull' : '147 mg',
        'Tea' : '11 mg',
        'Soda' : '21mg'
    };
    coffeine = coffeine ? map[a] : 'Not found';
    return coffeine;
}

int main(){
    string a;
    cin >> a;
    cout << getcoffeine(a);
}