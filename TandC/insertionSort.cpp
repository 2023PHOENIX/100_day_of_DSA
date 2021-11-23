#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);
    // selection sort
    // for (int i = 0; i < n - 1;i++){
    //     // find the smallest element of arr
    //     int minEle = arr[i];
    //     int idx = i;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if(minEle > arr[j]){
    //             minEle = arr[j];
    //             idx = j;
    //         }
    //     }

    //     swap(arr[i], arr[idx]);
    // }

    // selection sort

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}