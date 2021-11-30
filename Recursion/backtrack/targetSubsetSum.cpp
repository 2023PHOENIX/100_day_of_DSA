#include <bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar)
{
    // write your code here
    if(idx == arr.size()){
        if(sos==tar){
        cout << set <<"."<< endl;
        }
        return;
    }

    printTargetSumSubsets(arr, idx + 1, set + to_string(arr[idx]) + ", ", sos + arr[idx], tar);
    printTargetSumSubsets(arr, idx + 1, set+"",sos + 0, tar);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int target;
    cin >> target;
    printTargetSumSubsets(v, 0, "", 0, target);
}
/*
import java.io.*;
import java.util.*;

public
class Main
{

public
    static void main(String[] args) throws Exception
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++)
        {
            arr[i] = scn.nextInt();
        }
        int tar = scn.nextInt();
        printTargetSumSubsets(arr, 0, "", 0, tar);
    }

    // set is the subset
    // sos is sum of subset
    // tar is target
public
    static void printTargetSumSubsets(int[] arr, int idx, String set, int sos, int tar)
    {
        if (idx == arr.length)
        {
            if (sos == tar)
            {
                System.out.println(set + ".");
            }
            return;
        }
        printTargetSumSubsets(arr, idx + 1, set + arr[idx] + ", ", sos + arr[idx], tar);
        printTargetSumSubsets(arr, idx + 1, set + "", sos + 0, tar);
    }
}
*/