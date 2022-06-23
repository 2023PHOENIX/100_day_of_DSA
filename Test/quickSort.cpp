#include<iostream>
#include<vector>

using namespace std;

void partition(vector<int> &v,int lo,int hi,int pivot){

	int i = lo,j= lo;

	while(i<=hi){
		if(pivot >= v[i]){
			swap(v[i],v[j]);
			j++;
		}
		i++;
	}

	// pivot index is j - 1;
	return j - 1;
}

int main(){


	int n;	cin>>n;
	vector<int> v(n);
	for(int &x : v)cin>>x;

	quickSort(v,0,v.size() -1);
}