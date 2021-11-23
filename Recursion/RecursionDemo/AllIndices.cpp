#include <iostream>
#include <vector>
using namespace std;

vector<int> allIndex(vector<int> &arr, int idx, int data, int count)
{
    if(idx == arr.size()){
        vector<int> v;
        return v;
    }

    vector<int> result;
    if (arr.at(idx) == data)
    {
        result.push_back(idx);
    }

    vector<int> faith = allIndex(arr, idx + 1, data, count);
    
    for(auto f : faith){
        result.push_back(f);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        arr.push_back(d);
    }
    int data;
    cin >> data;
    vector<int> ans = allIndex(arr, 0, data, 0);
    if (ans.size() == 0)
    {
        cout << endl;
        return 0;
    }
    for (int ele : ans)
        cout << ele << endl;

    return 0;
}