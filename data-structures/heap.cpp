#include <bits/stdc++.h>
using namespace std;

class Heap 
{
    int *h;
    int size;
    int max_size;
    int pos_size;

    void resize(){
        max_size = 2 * max_size;
        int *n;
        n = new int[max_size];
        for (int i = 0; i < size; i++)
            n[i] = h[i];
        swap(n,h);
        delete n;
    }
    void heapify(int i){
        int m = i, l = 2*i + 1, r = 2*i + 2;
        //se o filho tem maior prioridade que o pai, ele se torna o de maior prioridade
        if (l < size && h[l] > h[m]) m = l;
        if (r < size && h[r] > h[m]) m = r;
        if (m != i)
        {
            swap(h[i], h[m]);
            heapify(m);
        }
    }
    void bubble_up(int i){
        while (i > 0 && h[i] > h[(i-1)/2])
        {
            swap(h[i], h[(i-1)/2]);
            i = (i-1)/2;
        }
    }
public:
    Heap(int n)
    {
        h = new int[n];
        size = 0;
        max_size = n;
    }
    
    void extract(int i){
        if (size == 0) return;

        swap(h[i], h[size-1]);
        size--;
        heapify(i);
    }
    void insert(int val){
        if (size == max_size) resize();

        h[size] = val;
        bubble_up(size);
        size++;
    }
};