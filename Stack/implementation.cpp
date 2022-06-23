#include<iostream>

using namespace std;

class Mystack{
private:
    int *arr;
    int arrSize;
    int stackSize;
    int top;
public:
    Mystack(int n)
    {
        this->arrSize = n;
        arr = new int[arrSize];
        stackSize = 0;
        top = -1;
    }


    void push(int val){
        this->top++;
        if(top==arrSize){
            this->top--;
            cout << "overflow";
            return;
        }

        arr[top] = val;
        stackSize++;
    }
    int peek(){
        if(this->top< 0 or this->top > stackSize){
            cout << "empty";
            return -1;
        }
        return this->arr[this->top];
    }
    void pop(){
        if(this->top==-1){
            cout << "underflow";
            return;
        }
        this->arr[this->top] = -1;
        this->top--;
        this->stackSize--;
    }
};
int main(){
    Mystack st(2);

    st.push(4);
    st.push(6);
    st.push(6);
    st.push(6);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << st.peek();
}