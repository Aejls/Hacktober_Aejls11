#include <iostream>
using namespace std;

int sum ( int x ,int y , int z)
{
     return x+y+z;
}
int sum ( int x ,int y)
{
    return x + y;
}
float sum ( float x , float y)
{
    return x + y ;

}
int main (){
    cout<<sum(10,20,30)<<endl;
    cout<<sum(10 ,15)<<endl;
    cout<<sum( 10.5f ,15.5f)<<endl;
    return 0;
}
