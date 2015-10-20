#include <iostream>
#include <cstdio>
void f1(void);
void f2(int m);
using namespace std;
int m =10 ,n =5, a[10]={10,15,20};

int main()
{

   int  i;
   for(i =0;i<7;i++)
       f1();
       f2(1);
       cout<<a[m]<<" "<<a[n]<<endl;


}

void f1(void)
{
    static int n = 3;

    a[n] = a[n-1] +a[n-2]+ a[n-3];
    n++;
}
void f2(int m)
{
    for(;m<3;m+=2)
    {
        int m;
        {
            for(m =1;m<4;m++)
                cout<<a[m++]<<" ";
        }
    }

}
