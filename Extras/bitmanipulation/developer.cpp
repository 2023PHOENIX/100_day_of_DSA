#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


void solution(vector<int> masks,int nskills,int currSkills,vector<int> &sol,int smaks){

	if(currSkills == masks.size()){

		if(smaks == (1<<nskills) - 1){
			for(auto x : sol){
				cout<<x<<endl;
			}
		}

		return;
	}

	solution(masks,nskills,currSkills + 1,sol,smaks);


	sol.push_back(currSkills);
	solution(masks,nskills,currSkills + 1,sol,smaks | masks[currSkills]);
	sol.pop_back();
}

int main(){
	int n;	cin>>n;

	unordered_map<string,int> ump;
	for(int i = 0; i<n;i++){
		string x;	cin>>x;
		ump[x] = i;
	}


	int m;	cin>>m;
	vector<int> masks(m,0);

	for(int i = 0; i<m;i++){
		int skills;	cin>>skills;
		for(int j = 0; j<skills;j++){
			string skill;	cin>>skill;
			int idx = ump[skill];

			masks[i] = masks[i] | (1<<idx); 
		}
	}
	
}