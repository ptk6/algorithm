#include <iostream>
using namespace std;

int main() {
	int n,i,num[10],sm=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
	    cin>>num[i];
	}
		for(i=0;i<n;i++)
	{
		sm=num[i]%10;
		cout<<sm;
	    num[i]=num[i]/10;
	    cout<<num[i]<<endl;
	    
	}
	
	return 0;
}

