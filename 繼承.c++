#include <iostream>
#include <string.h>
using namespace std;
class score
{
private:
   int chin;
    int eng;
public:
   score(int c,int e)
    {
       chin=c;
       eng=e;
    }
   int getc()
    {
     return chin;
    }
   int gete()
    {
     return eng;
    }
  int sum(){return chin+eng;}
};
class student:public score
{
 private:
    char name[10];
    int stu_no;
   public:
    student(char*n,int s,int c,int e): score(c,e)
        {
            strcpy(name,n);
            stu_no=s;
        }
    char *getn(){ return name;}
    int gets(){return stu_no;}
};
int main()
{
 int s1,c1,e1;
   char na[10];
   for(int i=0;i<10;i++)
    {
     cin >> na[i];
    }
   cin >> s1 >> c1 >>e1;
   student k(na, s1,c1,e1);
   cout << "name:" << k.getn() << endl;
   cout <<"stuno:"<< k.gets() << endl;
   cout <<"chin:"<< k.getc() << endl;
   cout << "eng:" <<k.gete() << endl;
   cout << "sum:"<< k.sum() << endl;
 return 0;
}