#include<iostream>
#include<stack>

using namespace std;

int priority(int x){
    return (x=='+' || x=='-')?1:2;
}

string operation(string a , string b,char ch){
    string P  =  a + b;
    P = ch + P;
    // cout<<P<<endl;
    return P;
}

string Postoperation(string a , string b,char ch){
    string P  =  a + b;
    P = P + ch;
    // cout<<P<<endl;
    return P;
}

void performOperation(stack<char> &opStack,stack<string> &valueStack){
    
    string b = valueStack.top();
    valueStack.pop();
    
    string a = valueStack.top();
    valueStack.pop();
    
    char ch = opStack.top();
    opStack.pop();
    
    
    string res = operation(a,b,ch);
    valueStack.push(res);
}

void PostperformOperation(stack<char> &opStack,stack<string> &valueStack){
    
    string b = valueStack.top();
    valueStack.pop();
    
    string a = valueStack.top();
    valueStack.pop();
    
    char ch = opStack.top();
    opStack.pop();
    
    
    string res = Postoperation(a,b,ch);
    valueStack.push(res);
}

void solve(string str){
    stack<char> opStack;
    stack<string> valueStack;
    
    for(int i = 0; i<str.length() ; i++){
            char ch = str[i];

            if(ch=='('){
                opStack.push(ch);
            }else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                while(opStack.size() > 0 and opStack.top() != '(' and priority(ch) <= priority(opStack.top())){
                    PostperformOperation(opStack,valueStack);
                }
                opStack.push(ch);
            }else if(ch==')'){
                while(opStack.size() > 0 and opStack.top()!='('){
                    PostperformOperation(opStack,valueStack);
                }
                opStack.pop();
            }else{
                string x= "";
                x += ch;
                valueStack.push(x);
            }
        }
    
    while(opStack.size() > 0){
        PostperformOperation(opStack,valueStack);
    }

    cout<<valueStack.top()<<endl;
    valueStack.pop();

    // prefix 
    

    for(int i = 0; i<str.length() ; i++){
        char ch = str[i];

        if(ch=='('){
            opStack.push(ch);
        }else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            while(opStack.size() > 0 and opStack.top() != '(' and priority(ch) <= priority(opStack.top())){
                performOperation(opStack,valueStack);
            }
            opStack.push(ch);
        }else if(ch==')'){
            while(opStack.size() > 0 and opStack.top()!='('){
                performOperation(opStack,valueStack);
            }
            opStack.pop();
        }else{
            string x= "";
            x += ch;
            valueStack.push(x);
        }
    }
    
    while(opStack.size() > 0){
        performOperation(opStack,valueStack);
    }

    cout<<valueStack.top()<<endl;

    
}

int main(){
    string str; getline(cin,str);

    solve(str);
}