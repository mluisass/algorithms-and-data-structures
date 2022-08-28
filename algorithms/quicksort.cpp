#include<bits/stdc++.h>
using namespace std;

int pivot(int l, int r){
    int p = rand() % (r + l);
    return p;
}

int partition(int v[], int l, int r){
    int p = pivot(l, r);
    swap(v[l],v[p]);
    int i = l, j = (r-1);
    while (i <= j){
        while (i < r && v[i] <= v[l]) i++;
        while(v[j] > v[l]) j--;
        if (i < j){
            swap(v[i],v[j]);
        }
    }
    swap(v[l],v[j]);
    return j;
}

void qsort(int v[], int l, int r){
    if ((r-l) <= 1) return;
    int p = partition(v, l, r);
    qsort(v, p+1, r);
    qsort(v, l, p);
}

void quicksort(int v[], int size){
    qsort(v, 0, size);
}

