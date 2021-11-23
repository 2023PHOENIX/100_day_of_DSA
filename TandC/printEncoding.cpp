#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printEncoding(string x,string asf){

    if(x.length() == 0){
        cout << asf << endl;
        return;
    }

    char ch = 'a' + x[0] -'0'-1;

    if(ch >='a' and ch <= 'z'){

    printEncoding(x.substr(1), asf + ch);
    }
    
    if(x.size() > 1){
        int first = x[0] - '0';
        int sec = x[1] - '0';
        if(first * 10 + sec < 26){
            int c = first * 10 + sec;
            char chr = c + 'a' - 1;
            if(chr >='a' and chr <= 'z'){

            printEncoding(x.substr(2), asf + chr);
            }
        }
    }
}
int main(){
    string x;
    cin >> x;
    printEncoding(x, "");
}