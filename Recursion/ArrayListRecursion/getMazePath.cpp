#include <iostream>
#include <vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector<string> getMazePaths(int sr, int sc, int dr, int dc)
{
    // base case 
    if(sr > dr or sc > dc){
        vector<string> emp;
        return emp;
    }
    if(sr==dr and sc == dc){
        vector<string> ans;
        ans.push_back("");
        return ans;
    }

    // faith
    vector<string> Horizontal = getMazePaths(sr, sc + 1, dr, dc);
    vector<string> Vertical = getMazePaths(sr + 1, sc, dr, dc);
    

    // expectation
    vector<string> ans;
    for (auto h : Horizontal)
    {
        ans.push_back("h" + h);
    }
    for(auto v : Vertical){
        ans.push_back("v" + v);
    }

    return ans;
}

void display(vector<string> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans = getMazePaths(0, 0, n - 1, m - 1);
    display(ans);

    return 0;
}