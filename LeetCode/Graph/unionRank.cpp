#include<iostream>

using namespace std;

class UnionRank
{
private:
    int *root;
    int *rank;
    int size;
public:
    UnionRank(int n)
    {
        root = new int[n];
        rank = new int[n];
        this->size = n;
        for(int i = 0; i<n;i++){
        	root[i] = i;
        	rank[i] = 1;
        }
    }

    int Find(int x){
    	while(root[x]!=x){
    		x = root[x];
    	}

    	return x;
    }	

    void UnionSet(int x,int y){
    	int rootX = Find(x);
    	int rootY = Find(y);

    	if(rootX!=rootY){
    		// check for the height of tree rootx and rooty carrying 
    		if(rank[rootX]>rank[rootY]){
    			root[rootY] = rootX;
    		}else if(rank[rootX] < rank[rootY]){
    			root[rootX] = rootY;
    		}else{
    			root[rootY] = rootX;
    			rank[rootX] += 1;	// we will add rootY Node in rootX
    		}
    	}
    }
    bool connected(int x,int y){
    	return root[x]==root[y];
    }

};
int main()
{

 	
    UnionRank uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.UnionSet(1, 2);
    uf.UnionSet(2, 5);
    uf.UnionSet(5, 6);
    uf.UnionSet(6, 7);
    uf.UnionSet(3, 8);
    uf.UnionSet(8, 9);
    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.UnionSet(9, 4);
    cout << uf.connected(4, 9) << endl;  // true

}