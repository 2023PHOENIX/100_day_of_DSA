#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf)
{
    // write your code here
    if (sr > dr or sc > dc)
    {
        return;
    }
    if (sr == dr and sc == dc)
    {
        cout << psf << endl;
        return;
    }

    for (int i = 1; i <= dc - sc; i++)
    {
        printMazePaths(sr, sc + i, dr, dc, psf + "h" + to_string(i));
    }
    for (int i = 1; i <= dr - sr; i++)
    {
        printMazePaths(sr + i, sc, dr, dc, psf + "v" + to_string(i));
    }

    for (int d = 1; d <= dr - sr and d <= dc - sc; d++)
    {
        printMazePaths(sr + d, sc + d, dr, dc, psf + "d" + to_string(d));
    }
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}