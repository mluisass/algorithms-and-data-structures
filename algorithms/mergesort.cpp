#include <bits/stdc++.h>
using namespace std;

void merge (int v[], int a[], int l, int m, int r){
    int i = l, j = m;
    for (int k = l; k < r; k++){
        if (j == r){
            a[k] = v[i];
            i++;
        }
        else if (i == m){
            a[k] = v[j];
            j++;
        }
        else if(v[i] <= v[j]){
            a[k] = v[i];
            i++;
        }
        else if (v[i] > v[j]){
            a[k] = v[j];
            j++;
        }
    }
    for (int k = l; k < r; k++) v[k] = a[k];
}

void msort(int v[], int a[], int l, int r){
    if ((r-l) < 2) return;
    int m = (r+l)/2;
    msort(v, a, l, m);
    msort(v, a, m, r);
    merge(v, a, l, m, r);
}

void mergesort(int v[], int n) {
    int *a = new int[n];
    msort(v, a, 0, n);
}



