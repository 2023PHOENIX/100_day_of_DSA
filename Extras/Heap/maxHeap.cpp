#include<iostream>
#include<climits>

using namespace std;


class MaxHeap{
	int *maxheap;
	int actualSize;
	int heapSize;

public:
	MaxHeap(int size){
		this->heapSize = size;
		maxheap = new int[heapSize + 1];
		maxheap[0] = 0;
	}

	// insert the node;
	void add(int element){

		actualSize++;
		if(actualSize > heapSize){
			cout<<"too many element"<<endl;
			actualSize--;
			return;
		}


		maxheap[actualSize] = element;

		int index = actualSize;

		int parent = index/2;

		while(index > 1 and maxheap[index] > maxheap[parent]){
			// swap
			int temp = maxheap[index];
			maxheap[index] = maxheap[parent];
			maxheap[parent] = temp;


			index = parent;
			parent = index/2;
		} 
	}

	void display(){
		for(int i =1; i<=actualSize ; i++){
			cout<<maxheap[i]<<", ";
		}
	}
};

int main(){
	MaxHeap M(3);
	M.add(10);
	M.add(20);
	M.add(12);
	M.display();
}