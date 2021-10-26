#include <iostream>

using namespace std;
int & fun(int &a)
{
cout<<a<<endl;
return a;
}
int main()
{
int x=10;
fun(x)=25;
cout<<x<<endl;
return 0;
}
