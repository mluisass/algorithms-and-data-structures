#include <bits/stdc++.h>
using namespace std;

int binary_search(int v[], int n, int x)
{
    int l = 0, r = n - 1;
    while (l <= r){
        int m = (l+r)/2;
        if (x == v[m]) return m;
        else if (x < v[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}