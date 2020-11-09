#include <iostream>
using namespace std;

int main() {
  float sm1=0,sm2=0,sm3=0;
  int ar[]={12,-3,-43,0,34,2};
  
    while(ar[6]>=1)
    {
      sm1++;
    }
    while(ar[6]<0)
    {
      sm2++;
    }
    while(ar[6]==0)
    {
      sm3++;
    }

  cout<<sm1/6<<endl<<sm2/6<<endl<<sm3/6;

return 0;
}
