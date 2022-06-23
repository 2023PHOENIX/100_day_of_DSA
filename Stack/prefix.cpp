#include<iostream>
#include<stack>

using namespace std;

int operation(int a,int b,char ch){
	if(ch=='+'){
		return a+b;
	}else if(ch=='-'){
		return a - b;
	}else if(ch=='/'){
		return a/b;
	}
	return a *b;
}
void performOperation(stack<int> &valueStack,char ch,stack<string> &infix,stack<string> &postfix){

	// in prefix iterate in reverse
	int a = valueStack.top();
	valueStack.pop();
	int b = valueStack.top();
	valueStack.pop();

	// for infix
	string x = infix.top();
	infix.pop();
	string y = infix.top();
	infix.pop();

	string temp = "(";
	temp+= x;
	temp += ch;
	temp+= y;
	temp += ")";
	infix.push(temp);

	x = postfix.top();
	postfix.pop();
	y = postfix.top();
	postfix.pop();

	temp = x + y ;
	temp += ch;
	postfix.push(temp);

	int res = operation(x,y,ch);
	valueStack.push(res);

}

void solve(string str){
	stack<int> vStack;
	
	stack<string> infix;
	stack<string> postfix;
	for(int i = str.length() - 1; i>=0;i--){
		char ch = str[i];

		if(ch=='+' or ch=='-' or ch=='/' or ch=='*'){
			performOperation(vStack,ch,infix,postfix);
		}else{	// means this is 0 to 9
			vStack.push(ch - '0');
			infix.push(""+ch);
			postfix.push(""+ ch);
		}
	}

	cout<<vStack.top()<<endl;
	cout<<infix.top()<<endl;
	cout<<postfix.top()<<endl;
}

int main(){

	string str;	getline(cin,str);


	solve(str);
}