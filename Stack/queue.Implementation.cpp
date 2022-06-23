#include<iostream>

using namespace std;

class Queue{
    private:
        int *arr;
        int arrSize;
        int queueSize;
        int front = 0;
        int back = 0;
    public:
    Queue(int n){
        arr = new int[n];
        for (int i = 0; i < n;i++){
            arr[i] = 0;
        }
            this->arrSize = n;
        queueSize = 0;
        front = 0;
        back = 0;
    }

    void push(int val){
        if(queueSize >= arrSize){
            cout << "overflow" << endl;
            return;
        }

        arr[back++] = val;
        queueSize++;
        back = (back) % arrSize;
    }
    int pop(){
        if(queueSize == 0){
            cout << "underflow" << endl;
            return -1;
        }
        int x = arr[front];
        arr[front++] = 0;
        queueSize--;
        front = (front) % arrSize;
        return x;
    }
    int Front(){
        return this->arr[this->front];
    }
    void display(){

        for (int i = 0; i < arrSize;i++){
            
            int idx = (i + front) % arrSize;
            if(arr[idx])
            cout << arr[idx] << " ";
        }
    }
};

int main(){

    Queue qu(5);

    qu.push(10);
    qu.push(12);
    qu.push(122);
    qu.push(22);
    int x = qu.pop();
    qu.push(45);
    qu.pop();
    qu.push(95);
    qu.display();
}