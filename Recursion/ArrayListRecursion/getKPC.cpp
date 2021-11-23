#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> keys = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKPC(string str){

    if(str.length()==0){
        vector<string> v;
        v.push_back("");

        return v;
    }

    char ch = str.at(0) - '0';
    // faith
    vector<string> faith = getKPC(str.substr(1));
    vector<string> expectation;

    for(char c : keys.at(ch)){
        for(string x : faith){
            expectation.push_back(c + x);
        }
    }

    return expectation;
}

int main(){

    string str;
    cin >> str;

    vector<string> ans = getKPC(str);

    for(auto x : ans){
        cout << x << endl;
    }
}