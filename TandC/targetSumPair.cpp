#include <iostream>

using namespace std;
// two pointer approach
void TargetPairSum(int arr[], int target)
{
    int low = 0, high = sizeof(arr) - 1;

    while (low < high)
    {
        if (arr[low] + arr[high] < target)
        {
            low++;
        }
        else if (arr[low] + arr[high] > target)
        {
            high--;
        }
        else
        {
            cout << arr[low] << " " << arr[high] << endl;
            low++;
            high--;
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

    int target;
    cin >> target;
}