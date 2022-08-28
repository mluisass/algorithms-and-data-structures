#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int N = 1e5;
const int INF = 0xf3f3f3f3;
vector<ii> g[N];
int dist[N];

int dijkstra(int o, int n){
    for(int i = 0; i < N; i++) 
        dist[i] = INF;
        
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[o] = 0;
    pq.push({dist[o],o});

    while(!pq.empty()){
        auto [d,v] = pq.top(); 
        pq.pop();

        if (d != dist[v]) continue;
        if (v == n) return dist[v];

        for (auto [w,u] : g[v]){
            if (dist[u] > d + w){
                dist[u] = d + w;
                pq.push({dist[u],u});
            }
        }
    }
}
