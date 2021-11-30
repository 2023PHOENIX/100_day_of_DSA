#include <iostream>
#include <string>
using namespace std;

void printEncoding(string str, string asf)
{
    if(str.length()==0){
        cout << asf << endl;
        return;
    }
    else if(str.length()==1){
        int x = str[0] - '0';
        char ch = x + 'a' - 1;
        if (x == 0)
        {
            return;
        }
        printEncoding(str.substr(1), asf + ch);
    }else{
        int x = str[0] - '0';
        if (x == 0)
        {
            return;
        }
        char ch = x + 'a' - 1;
        printEncoding(str.substr(1), asf + ch);

        int y = str[1] - '0';
        int z = x * 10 + y;
        if(z<=26){

        char c = z + 'a' - 1;
        printEncoding(str.substr(2), asf + c);
        }
    }
}

int main()
{
    string str;
    cin >> str;
    printEncoding(str, "");
}