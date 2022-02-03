#include<iostream>
#include<vector>

using namespace std;
class PriorityQueue{
    vector<int> data;

    public:
        PriorityQueue(vector<int> v){
            for(int x : v)data.push_back(x);

            for(int i = (data.size() -1)/2;i>=0;i--){
                downHeapify(i);
            }
        }
        void swap(int i ,int j){
            int temp = data[i];
            data[i] =data[j];
            data[j] = temp;
        }
        void upHeapify(int c){
            if(c==0){
                return;
            }
            int p = (c-1)/2;

            if(data[p] > data[c]){
                swap(p,c);
                upHeapify(p);
            }
        }
        void add(int val){
            data.push_back(val);
            upHeapify(data.size() -1);
        }

        void downHeapify(int p){

            int left = 2*p + 1;
            int right = 2*p + 2;

            int mn = p;
            if(left < data.size() and data[left] < data[mn])
                mn = left;
            if(right < data.size() and data[right] < data[mn])
                mn = right;
            
            if(mn != p){
                swap(mn,p);
                downHeapify(mn);
            }

        }
        int remove(){
            if(data.size() == 0){
                cout<<"Underflow"<<endl;
                return -1;
            }
            int val = data[0];
            data[0] = data[data.size() -1];
            data.pop_back();


            downHeapify(0);
            return val;
        }
        int peek(){
            if(data.size() == 0){
                cout<<"Underflow"<<endl;
                return -1;
            }

            return data[0];
        }
        int size(){
            return data.size();
        }
};
int main(){
    int n;  cin>>n;
    vector<int> v(n);
    for(int &x : v)cin>>x;
    PriorityQueue pq(v);

    while(pq.size()>0){
        cout<<pq.remove()<<","<<endl;
    }
 
}