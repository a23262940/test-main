#include <iostream>
using namespace std;
int main()
{
    int i, j, size = 13;
    /*
    for (i = 1; i <= size;i++){
        for (j = 0; j <= size - i;j++)
            cout << " ";
        for (j = 1; j <= 2*i-1 ;j++)
            if(j==1 || j==i*2-1)
                cout << "*";
            else
                cout << " ";
        cout << "\n";
    }
    for (i = 1;i<=size*2+1;i++)
        cout << '*';
    cout << "\n";
    for (i = size; i > 0;i--){
        for (j = 0; j <= size - i;j++)
            cout << " ";
        for (j = 1; j <= 2 * i - 1;j++)
            if(j==1 || j==i*2-1)
                cout << "*";
            else
                cout << " ";
        cout << "\n";
    }*/
    for (i = size; i >= 0; i--)
    {
        for (j = 0; j <= size - i; j++)
            cout << " ";
        for (j = 1; j <= 2 * i - 1; j++)
            if (j == 1 || j == i * 2 - 1)
                cout << "*";
            else
                cout << " ";
        cout << "\n";
        if (size / 2 + 1 == i){
            j = i;
            break;
        }
    }
    for (i = 0; i <= size * 2 + 1; i++)
    {
       if(i>j && i<size/2+size){
            cout << "*";
       }
        else
            cout << " ";
        //cout << "\n";
    }
}
