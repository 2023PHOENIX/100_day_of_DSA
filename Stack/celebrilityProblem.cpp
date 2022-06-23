#include <iostream>
#include <stack>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++)
        {
            mat[i][j] = s[j]-'0';
        }
    }

    // for (int i = 0; i < n;i++){
    //     for (int j = 0; j < n;j++){
    //         cout << mat[i][j];
    //     }
    //     cout << endl;
    // }
        // approach O(N);
        stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        // elimination
        // mat[a][b] == 1   // means a is not celebirity a know b
        // mat[a][b] == 0   // means b can not be celebrity. because one person don't know him which is 'a'
        if (mat[a][b] == 1)
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }

    int x = st.top();
    // cout << x << endl;
    // check for x
    bool flag = false;
    for (int i = 0; i < n;i++){
        if(i!=x and mat[x][i]==1 and mat[i][x]==0){
            flag = true;
            break;
        }
    }
    if(flag)
        {cout << "none";}
    else
    {
        cout << x << endl;
    }
    
}