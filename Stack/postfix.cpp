#include<iostream>
#include<stack>

using namespace std;



void solve(string str)
{


    stack<int> value;
    stack<string> infix;
    stack<string> prefix;
    for(int i = 0 ; i < str.length(); i++)
    {
        char ch = str[i];

        if(ch >= '0' and ch <= '9')
        {
            value.push(ch - '0');
            string x = "";
            x += ch;
            infix.push(x);
            prefix.push(x);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int b = value.top();
            value.pop();
            int a = value.top();
            value.pop();

            string y = infix.top();
            infix.pop();
            string x = infix.top();
            infix.pop();

            // infix 
            string temp = "";
            temp = x;
            temp += ch;
            temp += y;
            temp = '(' + temp;
            temp += ')';
            infix.push(temp);

            // prefix 
            y = prefix.top();
            prefix.pop();
            x = prefix.top();
            prefix.pop();

             temp = "";
            temp = ch;
            temp += x;
            temp += y;

            if(ch == '+')
            {
                value.push(a + b);
            }
            if(ch == '-')
            {
                value.push(a - b);
            }
            if(ch == '*')
            {
                value.push(a * b);
            }
            if(ch == '/')
            {
                value.push(a / b);
            }
        }
    }

    cout << value.top() << endl;
    cout << infix.top() << endl;
    cout<< prefix.top() <<endl;
}
int main()
{
    string str;
    getline(cin, str);

    solve(str);


}