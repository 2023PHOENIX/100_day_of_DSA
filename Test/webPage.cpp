#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    cin.ignore();
    vector<list<int>> vec(n + 1);

    for (int i = 1; i <= n;i++){
        string str;
        getline(cin, str);
        string num = "";
        for (auto x : str)
        {
            if (x==' ')
            {
                vec[i].push_back(stoi(num));
                num = "";
            }
            else
            {

                num += x;
            }
        }
        if(num != ""){
            vec[i].push_back(stoi(num));
        }
    }

    int start, end;
    cin >> start >> end;

    queue<int> qu;

    qu.push(start);
    vector<bool> visited(n + 1, false);

    bool isExist = false;
    int cnt = 0;
    while(qu.empty()==false){
        int size = qu.size();

        while(size-- > 0){
        auto top = qu.front();
        qu.pop();

        if(visited[top]==true){
            continue;
        }  
        if(top == end){
            isExist = true;
            cout << cnt << endl;
            return 0;
        }
        visited[top] = true;

        for(auto nbr : vec[top]){
            if(!visited[nbr]){
                qu.push(nbr);
            }
        }
        }

        cnt++;
    }

    cout << -1 << endl;
}