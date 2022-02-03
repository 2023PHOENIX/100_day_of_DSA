#include<iostream>

using namespace std;

int main(){
	int n;	cin>>n;
	int xxor = 0;
	int sum = 0;
	for(int i = 0; i<n;i++){
		xxor ^= (i + 1);
	}
	int v[n];
	for(int i = 0; i<n;i++){
		cin>>v[i];

		xxor ^= v[i];
		sum+=v[i];
	}


	// xxor = missing ^ repeating 
	int a = 0,b = 0;
	int rmsb = (xxor &  -xxor);

	for(int i = 0; i<n;i++){
		if((rmsb & v[i]) == 0){
			a ^= v[i];
		}else{
			b ^= v[i];
		}
	}
	for(int i = 1; i<=n;i++){
		if((rmsb & i)==0){
			a ^= i;
		}else{
			b ^= i;
		}
	}

	int nsum = (n*(n + 1))/2;

	if(nsum == sum - a + b){
		cout<<"Missing Number -> "<<b<<endl;
		cout<<"Repeating Number -> "<<a<<endl;
	}else{
		cout<<"Missing Number -> "<<a<<endl;
		cout<<"Repeating Number -> "<<b<<endl;
	}
}