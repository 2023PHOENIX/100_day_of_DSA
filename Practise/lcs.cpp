#include<iostream>
#include<cstring>
using namespace std;


int longestCommonSubsequence(string text1, string text2) {
       int n = text1.size();
       int m = text2.size();
        
        int dp[n][m] = {0};
        
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
               if(i==0 and j==0){
               	dp[i][j] = (text1[i]==text2[j])?1:0;
               }else if(i==0){
               	dp[i][j] = (text1[i]== text2[j])?1:dp[i][j-1];
               }else if(j==0){
               	dp[i][j] = (text1[i] == text2[j])?1:dp[i-1][j];
               }else{
               	dp[i][j] = (text1[i]==text2[j])?1 + dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]);
               }
            }
        }
        
        return dp[n-1][m-1];
    }


int main(){
	string s1;	cin>>s1;
	string s2;	cin>>s2;

	int ans =longestCommonSubsequence(s1,s2);
	cout<<ans<<endl;
}