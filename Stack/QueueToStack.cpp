#include <iostream>
#include <exception>
#include <vector>
#include <queue>
using namespace std;

class QueueToStackAdapter
{
public:
    queue<int> mainQ;
    queue<int> helperQ;

    int size()
    {
        return mainQ.size();
    }

    void push(int data)
    {
        // use sime push in main Q
        mainQ.push(data);
    }

    int top()
    {
        // write your code here
        while(mainQ.size() > 1){
            int x = mainQ.front();
            mainQ.pop();
            helperQ.push(x);
        }        
        // for last element
        int l = mainQ.front();
        mainQ.pop();
        helperQ.push(l);

        auto temp = mainQ;
        mainQ = helperQ;
        helperQ = temp;

        return l;
    }

    int pop()
    {
        if(mainQ.size() == 0){
            cout << "Stack underflow";
            return -1;
        }
        while(mainQ.size() > 1){
            int x = mainQ.front();
            mainQ.pop();
            helperQ.push(x);
        }

        int l = mainQ.front();
        mainQ.pop();
        auto temp = mainQ;
        mainQ = helperQ;
        helperQ = temp;
        return l;
    }
};

int main()
{
    QueueToStackAdapter st;
    string str;
    cin >> str;

    while (str != "quit")
    {
        if (str == "push")
        {
            int val;
            cin >> val;
            st.push(val);
        }
        else if (str == "pop")
        {
            int val = st.pop();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "top")
        {
            int val = st.top();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "size")
        {
            cout << st.size() << endl;
        }
        cin >> str;
    }
    return 0;
}