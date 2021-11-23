//  1*x^n + 2*x^n-1 + 3*x^n-3 ...... n * x ^ 1

#include<iostream>

using namespace std;


int main(){

    int x;
    cin >> x;
    int n;
    cin >> n;

    int summation = 0;

    int p = x;


    while(n >= 1){
        summation += x * n;
        
        n = n - 1;
        x = x *p;
    }

    cout << summation << endl;
}