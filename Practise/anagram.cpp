#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    
   vector<int> hash1(26);
   vector<int> hash2(26);
   vector<int> ans;
   for(int i = 0; i<p.length();i++){
   		hash1[p[i]-'a']++;
   		hash2[s[i]-'a']++;
   }
   int j = 0;
   for(int i = p.length() ; i<s.length();i++,j++){
       
       if(hash1==hash2){
       	ans.push_back(j);
       }

       hash2[s[i]]++;
       hash2[s[j]]--;

   }

   if(hash1 == hash2){
   	ans.push_back(j);
   }
   return ans;

}
int main(){

	string s;	cin>>s;
	string p;	cin>>p;
	auto v = findAnagrams(s,p);
	for(int x : v)cout<<x<<",";
}