// #include<iostream>
// #include<unordered_map>

// using namespace std;

// int main(){

// 	int n;	cin>>n;
// 	unordered_map<int,bool> ump;

// 	for(int i = 0; i<n;i++){
// 		int d;	cin>>d;
// 		ump[d] = true;
// 	}

// 	for(pair<int,bool> p : ump){
// 		if(ump.find(p.first-1) != ump.end()){
// 			ump[p.first] = false;
// 		}
// 	}

// 	int min_value = 0;
// 	int l = 0;

// 	for(pair<int,bool> p : ump){
// 		if(p.second == true){
// 			int val = p.first;
// 			int c = 1;

// 			while(ump.find(val + c) != ump.end()){
// 				c++;
// 			}
// 			// cout<<val <<" , "<<c<<endl;
// 			if(l <= c){
// 				l = c;
// 				min_value = p.first;
// 			}
// 		}
// 	}

// 	for(int i = 0 ; ump.find(min_value + i) != ump.end()  ; i++){
// 		cout<<min_value + i<<endl;
// 	}
// }

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<list>
using namespace std;

int main(){

	int n;	cin>>n;

	unordered_map<int,int> ump;
	int v[n];
	for(int i = 0; i<n;i++){
		cin>>v[i];
		ump[v[i]]++;
	}

	int mex_ele = 0;
	int cnt = 0;
	for(auto x : ump){
		ump[x.first] += ump[x.first - 1]; 
		if(ump[x.first] > cnt){
			cnt = ump[x.first];
			mex_ele = x.first;
		}
	}

	while(ump[mex_ele] != 0){
		mex_ele--;
	}

	// cout<<mex_ele<<endl;
	for(int i = 1; ump.find(mex_ele + i)!=ump.end(); i++){
		cout<<mex_ele + i<<endl;
	}


	


	
}