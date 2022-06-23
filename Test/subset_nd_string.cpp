#include <bits/stdc++.h>

using namespace std;

vector<string> input()
{
    int n, r;
    cin >> n >> r;
    cin.ignore();
    vector<string> v;

    string str;
    getline(cin, str);

    // cout << str << endl;
    string curr = "";
    for (auto &x : str)
    {
        if (x == ',')
        {
            v.push_back(curr);
            curr = "";
        }
        else
        {
            curr += x;
        }
    }
    if (curr != "")
    {
        v.push_back(curr);
    }
    return v;
}
bool comp(string &a,string &b){
    return a.length() < b.s
}
int main()
{

    auto v = input();

    int n = v.size();
    vector<string> allstring;
    for (int i = 0; i < n;i++){
        string s = "";
        for (int j = i; j < n;j++){
            s += v[j] + ",";
            
            cout << s << endl;
        }
    }

    stable_sort(allstring.begin(), allstring.end(), comp);
}