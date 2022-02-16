#include<iostream>

using namespace std;

// quick find set
class UnionFind
{
private:
    int *root;
    int size;
public:
    UnionFind(int size)
    {
    	this->size = size;
        root = new int[size];
        for(int i = 0; i < size; i++)
        {
            root[i] = i;
        }
    }

    int find(int x)
    {
        return root[x];
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY){
        	// update all the value of rootY with rootX
        	for(int i = 0; i<size;i++){
        		if(root[i]==rootY){
        			root[i]==rootX;
        		}
        	}
        }
    }
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

    void display(){
    	for(int i = 0; i< 10;i++){
    		cout<<i<<"->" << root[i]<<endl;
    	}
    }

};

int main()
{

    UnionFind uf(10);

    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);
    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    uf.unionSet(9, 4);
    cout << uf.connected(4, 9) << endl;  // true
    uf.display();
}