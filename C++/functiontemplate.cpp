#include <iostream>
using namespace std;

 template <class T>
  T maxim (T a , T b)     //this function can be written instead of below two function
  {
      return a>b?a:b;
  }
  
//  int max (int x ,int  y)
//   {
//       return x>y?x:y; //if x greater than y return x otherwise return y
//   }
//   float max (float x ,float y)
//   {
//       x>y?x:y;  //if x greater than y return x otherwise return y
//   }
main (){
    cout<<maxim( 10 , 5) <<endl;
    cout<<maxim( 10.5f ,15.5f) <<endl;

    return 0;
}
