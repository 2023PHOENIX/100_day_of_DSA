#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    vector<int> v = {1, 9, 6, 4, 8, 3, 12, 14, 24, 10,15};
    int target = 25;

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {

        int newTarget = target - v[i];
        int low = i + 1, high = v.size() - 1;
        // meet in the middle

        while (low < high)
        {
            if (v[low] + v[high] < newTarget)
            {
                low++;
            }else if(v[low] + v[high] > newTarget){
                high--; 
            }else{
                cout << v[i] << " " << v[low] << " " << v[high] << endl;
                low++;
                high--;
            }
        }
    }
    // O(n^2)
}

// sir live class lene me jyda maza aata hai but hostel me bache padne nh dete to recording dekhna pdta hai :p
sir college wale NOC nh dete