#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    string str;
    cin >> str;
    unordered_map<char, int> ump;

    for(char ch : str){
        ump[ch]++;
    }

    int max_char = 0;
    char ch = 'x';

    for(pair<char,int> p : ump){
       if(max_char < ump[p.first]){
           ch = p.first;
           max_char = p.second;
       }
    }
    cout << ch << endl;
    cout << max_char << endl;
    cout << ump.at('a') << endl;

    for(pair<char,int> p : ump){
        cout << p.first << " " << p.second << " exist in bucket # " << ump.bucket(p.first) << endl;
    }

    cout << ump.bucket_count() << endl;
    cout << ump.count('v') << endl;
}