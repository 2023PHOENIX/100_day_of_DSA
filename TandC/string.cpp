#include<iostream>
#include<climits>
using namespace std;

int f(string s){

    int arr[26] = {0};

    for(char c : s){
        arr[c - 'a']++;
    }

    int maxi = 0;
    int idx = 0;
    for (int i = 0; i < 26; i++)
    {
        if(maxi < arr[i]){
            maxi = arr[i];
            idx = i;
        }
    }

    return idx;
    
}

int main(){

    string s;
    cin >> s;

    cout << char('a' + f(s)) << endl;
}