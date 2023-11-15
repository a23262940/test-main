#include <iostream>
#include <fstream>
using namespace std;
int main(void) {
    int x, y;
    double sum = 0,z=1;
    fstream fp("d.txt");
    fp >> x >> y;
    for (int i = 1;i <= y;i++) {
        z = z*x/i;
        sum += z;
    }
    cout << x << endl << y << endl << "Ans=" << int(sum) << endl;
    fp.close();
    return 0;
}