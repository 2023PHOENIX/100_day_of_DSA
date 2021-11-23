#include<iostream>
#include<vector>

using namespace std;

vector<string> getMazePath(int sr,int sc,int er,int ec){
    // base condition
    if(sr == er and sc == ec){
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    if(sr > er or sc > ec){
        vector<string> ans;
        return ans;
    }

    vector<string> ans;
    for (int i = 1; i <= ec - sc; i++)
    {

        vector<string> faith_h = getMazePath(sr, sc + i, er, ec);
        for (auto h : faith_h)
        {
            ans.push_back("h" + to_string(i) + h);
        }
    }

    for (int i = 1; i <= er - sr; i++)
    {

        vector<string> faith_v = getMazePath(sr + i, sc, er, ec);
        for(auto v : faith_v){
            ans.push_back("v" + to_string(i) + v);
        }
    }
    
    for (int i = 1; i <= er - sr and i <= ec - sc; i++){
        vector<string> faith_d = getMazePath(sr + i, sc + 1, er, ec);
        for(auto d : faith_d){
            ans.push_back("d" + to_string(i) + d);
        }
    }

    return ans;
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<string> paths = getMazePath(0, 0, n-1, m-1);
    cout << "[";
    for (int i = 0; i < paths.size();i++){
        if(i==paths.size() -1 ){
            cout << paths.at(i);
        }
        else{
            cout << paths.at(i) << ", ";
        }
    }
        cout << "]";
}