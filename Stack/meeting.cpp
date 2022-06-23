#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair
{
    int start;
    int end;
};

bool comp(Pair p1, Pair p2)
{

    if (p1.start != p2.start)
    {
        return p1.start < p2.start;
    }
    return p1.end < p2.end;
}
int main()
{

    int n;
    cin >> n;

    vector<Pair> vp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vp[i].start >> vp[i].end;
    }
    sort(vp.begin(), vp.end(), comp);
   
    stack<Pair> st;
    st.push(vp[0]);

    for (int i = 1; i < n; i++)
    {
        Pair top = st.top();

        if (vp[i].start > top.end)
        {
            st.push(vp[i]);
        }
        else
        {

            // cout << "max" << top.end <<" "<<vp[i].end<< endl;
            if(vp[i].end > top.end){
                st.top().end = vp[i].end;
            }
        }
    }

    // cout << st.size() << endl;
    vector<Pair> ans(st.size());

    n = st.size();
    for (int i = n - 1; i >= 0;i--){
        ans[i] = st.top();
        st.pop();
    }
    for (auto x : ans)
    {
        cout << x.start << " " << x.end << endl;
    }
}