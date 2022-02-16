#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int operation(int a, int b, char c)
{
    if(c == '+')
    {
        return a + b;
    }
    else if(c == '-')
    {
        return a - b;
    }
    else if(c == '/')
    {
        return a / b;
    }
    else if(c == '*')
    {
        return a * b;
    }
}
int priority(char x)
{
    if(x == '+' or x == '-')
    {
        return 1;
    }
    else if(x == '/' or x == '*')
        return 2;
}
void performOperation(stack<int> &vStack, stack<char> &opStack)
{
    int b = vStack.top();
    vStack.pop();
    int a = vStack.top();
    vStack.pop();
    char op = opStack.top();
    opStack.pop();

    int res = operation(a, b, op);
    // cout<<a<<" "<<op<<" "<<b<<" == "<< res<<endl;
    vStack.push(res);
}

int main()
{
    string str;
    getline(cin, str);

    stack<int> vStack;
    stack<char> opStack;

    for(int i = 0; i < str.length() ; i++)
    {
        char ch = str[i];

        if(ch == '(')
        {
            opStack.push(ch);
        }
        else if(ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            //          check weather higher priority is there in stack
            while(opStack.size() > 0 and opStack.top() != '(' and priority(ch) <= priority(opStack.top()))
            {
                performOperation(vStack, opStack); 

            }
            opStack.push(ch);
        }
        else if(ch >= '0' && ch <= '9')
        {
            vStack.push(ch - '0');
        }
        else if(ch == ')')
        {
            while(opStack.size() > 0 and opStack.top() != '(')
            {
                performOperation(vStack, opStack);
            }
            // remove opening bracket
            opStack.pop();

        }
    }

    // if any operation still left
    while(opStack.size() > 0)
    {
        performOperation(vStack, opStack);
    }
    cout << vStack.top() << endl;
}