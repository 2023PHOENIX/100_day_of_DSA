#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j)
{
    cout << ("Swapping index " + to_string(i) + " and index " + to_string(j)) << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void countSort(vector<int> &arr,int div,int mod,int range){
    int n = arr.size();
    vector<int> freqArray(range, 0);
    vector<int> A(arr.size(), 0);

    for (int i = 0; i < n;i++){
       int digi = arr[i] / div % mod;
       freqArray[digi]++;
    }
    for (int i = 1; i < range;i++){
        freqArray[i] += freqArray[i - 1];
    }

    for (int i = n - 1; i >= 0;i--){
        int val = arr[i] / div % mod;
        int idx = freqArray[val];
        A[idx - 1] = arr[i];
        freqArray[val]--;
    }

    for (int i = 0; i < n;i++){
        arr[i] = A[i];
    }
    return;
}

void sortDate(vector<int> &arr)
{
    // sort date
    countSort(arr, 1000000, 100,32);
    // sort month
    countSort(arr, 10000, 100,13);
    // sort year
    countSort(arr, 1, 10000,2501);
}
int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    sortDate(A);
    print(A);
    return 0;
}