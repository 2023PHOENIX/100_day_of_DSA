#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class TwoStack
{
public:
    vector<int> data;
    int tos1;
    int tos2;
    int n;
    TwoStack(int cap)
    {
        n = cap;
        data = vector<int>(n, -1);
        tos1 = -1;
        tos2 = n;
    }

    int size1()
    {
        return tos1 + 1;
        // write your code here
    }

    int size2()
    {
        return n - tos2;
        // write your code here
    }

    void push1(int val)
    {
        if (tos1 + 1 == tos2)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        tos1++;
        data[tos1] = val;
    }

    void push2(int val)
    {
        // write your code here
        if (tos2 - 1 == tos1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        tos2--;
        data[tos2] = val;
    }

    int pop1()
    {
        if (tos1 == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int x = data[tos1];
        data[tos1] = 0;
        tos1--;
        return x;
    }

    int pop2()
    {
        if (tos2 == n)
        {
            cout << "Stack undeflow" << endl;
            return -1;
        }

        int x = data[tos2];
        tos2++;
        return x;
        // write your code here
    }

    int top1()
    {
        if (this->tos1 == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return this->data[this->tos1];
        // write your code here
    }

    int top2()
    {
        if (this->tos2 == n)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        // cout << this->tos2 << endl;
        return this->data[this->tos2];
        // write your code here
    }
};

int main()
{
    string str;

    int cap;
    cin >> cap;
    TwoStack st(cap);

    while (true)
    {
        getline(cin, str);
        if (str[0] == 'q')
        {
            break;
        }
        else if (str[0] == 'p' && str[4] == '1')
        {
            string ss = str.substr(6, 2);
            int n = stoi(ss);
            st.push1(n);
        }
        else if (str[0] == 't' && str[3] == '1')
        {
            int tp = st.top1();
            if (tp != -1)
                cout << tp << endl;
        }
        else if (str[0] == 'p' && str[3] == '1')
        {
            int tp = st.pop1();
            if (tp != -1)
                cout << tp << endl;
        }
        else if (str[0] == 'p' && str[4] == '2')
        {
            string ss = str.substr(6, 2);
            int n = stoi(ss);
            st.push2(n);
        }
        else if (str[0] == 't' && str[3] == '2')
        {
            int tp = st.top2();
            if (tp != -1)
                cout << tp << endl;
        }
        else if (str[0] == 'p' && str[3] == '2')
        {
            int tp = st.pop2();
            if (tp != -1)
                cout << tp << endl;
        }
    }
    return 0;
}