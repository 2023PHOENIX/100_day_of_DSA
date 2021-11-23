#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    vector<int> c(n + m, 0);

    int i = 0, j = 0, k = 0;

    while (i < n and j < m)
    {

        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else if (a[i] > b[j])
        {
            c[k++] = b[j++];
        }
        else
        {
            c[k++] = a[i++];
            c[k++] = b[j++];
        }
    }

    while (i < n)
    {
        c[k++] = a[i++];
    }
    while (j < m)
    {
        c[k++] = b[j++];
    }
    return c;
}

vector<int> mergeSort(vector<int> &A, int low, int high)
{
    if (low == high)
    {
        vector<int> b(1, 0);
        b[0] = A[low];
        return b;
    }
    int mid = low + (high - low) / 2;


    vector<int> firstFaith = mergeSort(A, low, mid);
    vector<int> secondFaith = mergeSort(A, mid + 1, high);


    return merge(firstFaith, secondFaith);
}
int main()
{

    vector<int> A = {1132, 330, 8, 119,9};

    // vector<int> b = {19, 87, 373};

    A = mergeSort(A, 0, A.size() - 1);    for(auto x : A){
        cout << x << " ";
    }
}

// T(N) = k * log (N) + T(n-1)