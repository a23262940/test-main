#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int a[100], i, z = 0, j = 0, n = 0;
  ifstream A("6.txt");
  while (A>>a[z])
    z++;
  cout << z;

  
  return 0;
}