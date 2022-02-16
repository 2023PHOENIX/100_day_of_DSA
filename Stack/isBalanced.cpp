#include<isotream>
#include<vector>

using namespace std;

int main(){
	string str;

	getline(cin,str);


	stack<char> st;


	for(int i = 0; i<str.length();i++){
		char ch = str[i];

		if(ch=='(' or ch=='[' or ch=='{'){
			st.push(ch);
		}

		else if(ch==')'){
			if(st.size() == 0){
				cout<<"false"<<endl;
				return;
			}else if(st.top()!='('){
				cout<<"false"<<endl;
				return;
			}else{
				st.pop();
			}
		}else if(ch=='}'){
			if(st.size() == 0){
				cout<<"false"<<endl;
				return;
			}else if(st.top()!='('){
				cout<<"false"<<endl;
				return;
			}else{
				st.pop();
			}
		}else if(ch==']'){
			if(st.size() == 0){
				cout<<"false"<<endl;
				return;
			}else if(st.top()!='['){
				cout<<"false"<<endl;
				return;
			}else{
				st.pop();
			}

		}
	}

	(st.size() > 0)?cout<<"true";cout<<"false"<<endl;
}