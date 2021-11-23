#include <iostream>
#include <vector>
#include <string>
using namespace std;
void printPermutation(string s,string asf)
{
    if (s.length() == 0)
    {
        cout << asf;
        cout << endl;
        return;
    }

    for (int i = 0; i < s.length();i++){
        char ch = s[i];
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        printPermutation(left + right, asf + ch);
    }
}
int main()
{
    string s;
    cin >> s;
    printPermutation(s,"");

}