#include<iostream>
#include<vector>

using namespace std;

class QuickUnion{
	// quick union is : find-> O(N)
private: 
	int *root;
	int size;
public:
	QuickUnion(int sz){
		this->size = sz;
		root = new int[sz];
	}
	// O(N) complexity
	void find(int x){

		while(root[x]!=x){
			x = root[x];
		}

		return x;
	}

	void Union(int a,int b){

		rootX = Union(a);
		rootY = Union(b);

		if(rootX!=rootY){
			root[rootY] = rootX;
		}

	}

	bool connected(a,b){
		return find(a)==find(b);
	}

};

int main(){


}