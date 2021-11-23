#include <iostream>
#include<vector>
using namespace std;

vector<string> codes = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf)
{
    if(ques.size() < 0){
        return;
    }
    if(ques.size()==0){

        cout << asf << endl;
        return;
    }

    int idx = ques.at(0) - '0';

    for(string str : codes[idx]){
        for(char ch : str){
            printKPC(ques.substr(1), asf + ch);
        }   
    }
}

int main()
{
    string str;
    cin >> str;
    printKPC(str, "");
}