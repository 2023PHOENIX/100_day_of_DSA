#include<iostream>


using namespace std;

class UnionCompression{
    int *root;
    int *rank;
    int size;
public:
    UnionCompression(int n){
        this->size = n;
        root = new int[n];
        rank = new int[n];
        for(int i = 0; i<n;i++){
            root[i] = i;
            rank[i] = 1;
        }
    }

    //  O(n) converted to O(H);
    int find(int x){
        if(x==root[x]){
        	return x;
        }

        int p = find(root[x]);

        root[x] = p;
        return p;
    }

    // O(N) => rank by union convert to O(H).
    void Union(int x,int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX==rootY)return;


        if(rank[rootX] > rank[rootY]){
        	root[rootY] = rootX;
        }else if(rank[rootX] < rank[rootY]){
        	root[rootX] = rootY;
        }else{
        	root[rootY] = rootX;
        	rank[rootX] += 1; 
        }
    }
    // O(N)
    bool connected(int x,int y){
        return find(x)==find(y);
    }
};

int main(){

    UnionCompression uf(10);
    uf.Union(1, 2);
    uf.Union(2, 5);
    uf.Union(5, 6);
    uf.Union(6, 7);
    uf.Union(3, 8);
    uf.Union(8, 9);
    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.Union(9, 4);
    cout << uf.connected(4, 9) << endl;  // true
}