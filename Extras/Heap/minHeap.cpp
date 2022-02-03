#include<iostream>
#include<climits>
using namespace std;


class MinHeap {
	int * minHeap;
	int actualSize = 0;
	int heapSize;

public:
	// constructor
	MinHeap(int heapSize) {
		this->heapSize = heapSize;
		minHeap = new int[heapSize + 1];
		// better to track index
		minHeap[0] = 0;
	}

	void add(int element) {
		actualSize++;

		if (heapSize < actualSize) {
			cout << "memory overflow" << endl;
			actualSize--;
			return;
		}

		// put it on last index
		minHeap[actualSize] = element;

		int index = actualSize;


		// acess the parent
		int parent = index / 2;


		while (minHeap[index] < minHeap[parent] && index > 1) {
			int temp = minHeap[index];
			minHeap[index] = minHeap[parent];
			minHeap[parent] = temp;
			index = parent;
			parent = index / 2;
		}


	}
	int peek() {
		return minHeap[1];
	}

	int pop() {
		if(actualSize < 1){
			cout<<"not enought element";
			return INT_MAX;
		}
		// peak element 
		int removed = minHeap[1];
		minHeap[1] = minHeap[actualSize];

		// decrease the size;
		actualSize--;

		int index = 1;

		while(index <= (actualSize / 2)){

			int leftChild = 2*index;
			int rightChild = 2*index + 1;

			if(minHeap[index] > minHeap[leftChild] or minHeap[index] > minHeap[rightChild]){
				if(minHeap[leftChild] < minHeap[rightChild]){
					int temp = minHeap[leftChild];
					minHeap[leftChild] = minHeap[index];
					minHeap[index] = temp;
					index = leftChild;
				}else{
					int temp = minHeap[rightChild];
					minHeap[rightChild] = minHeap[index];
					minHeap[index] = minHeap[rightChild];
					index = rightChild;
				}
			}else{
				break;
			}
		}

		return removed;

	}
	int size(){
		return actualSize;
	}

	void display(){
		for(int i =1; i<=actualSize;i++){
			cout<<minHeap[i]<<", ";
		}
	}


};

int main(){
	MinHeap MH(4);
	MH.add(23);
	MH.add(25);
	MH.add(11);
	MH.add(10);

	MH.display();

}