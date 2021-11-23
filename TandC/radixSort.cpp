#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void Display(vector<int> &arr)
{
    for (int ele : arr)
    {
        cout << ele << " ";
    }
}

void countsort(vector<int> &arr, int d)
{

    int n = arr.size();

    vector<int> range(19, 0);
    vector<int> ans(arr.size(), 0);

    // fill the digit
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / d) % 10;
        range[digit]++;
    }

    // prefix
    for (int i = 1; i < 10; i++)
    {
        range[i] += range[i - 1];
    }

    // fill the ans
    for (int i = n - 1; i >= 0; i--)
    {
        int val = arr[i] / d % 10;
        int idx = range[val];
        ans[idx-1] = arr[i];
        range[val]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }

    cout << "After sorting on " << d << " place -> ";
    Display(arr);
    cout << endl;
}

void radixSort(vector<int> &arr)
{
    // write your code here
    int mx = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        mx = max(mx, arr[i]);
    }

    // count the digit of largest element
    int digit = 1;

    while (mx / digit > 0)
    {
        countsort(arr, digit);
        digit = digit * 10;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    radixSort(arr);
    Display(arr);
    return 0;
}