#include<bits/stdc++.h>

using namespace std;

struct Bag
{
    int weight;
    int value;
    double ratio;
};

bool comp(Bag &b1, Bag &b2)
{
    return b1.ratio < b2.ratio;
};
int main()
{


    int n;
    cin >> n;

    vector<Bag> bag(n);
    for(int i = 0; i < n; i++)
    {
        cin >> bag[i].value;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> bag[i].weight;
        bag[i].ratio = bag[i].value * 1.0 / bag[i].weight;
    }

    sort(bag.begin(), bag.end(), comp);

    double vib = 0;
    int space;
    cin >> space;


    int i = n - 1;

    while(space > 0 && i >= 0)
    {
        if(space >= bag[i].weight)
        {
            vib = vib + bag[i].value;
            space = space - bag[i].weight;
        } 
        else
        {
            vib += (space * bag[i].value * 1.0) / bag[i].weight;
            space = 0;
            break;
        }
        i--;
    }

    cout << vib << endl;

}