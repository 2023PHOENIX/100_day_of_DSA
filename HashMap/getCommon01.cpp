#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1;
    int arr1[n1];
    unordered_map<int, int> ump;
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
        ump[arr1[i]]++;
    }
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];

        // write your code here
        for (auto x : arr2)
        {
            if (ump[x] > 0)
            {
                cout << x <<endl;
                ump[x] = 0;
            }
        }
    }
}
