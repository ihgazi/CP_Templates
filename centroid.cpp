#include <bits/stdc++.h>
using namespace std;

vector<set<int>> adj;
vector<int> treesz, parent;

// CENTROID DECOMPOSITION
int cursz = 0;
void dfs1(int u, int par) {
    treesz[u] = 1;
    cursz++;

    for (auto &v: adj[u]) {
        if (v == par) continue;
        dfs1(v, u);
        treesz[u] += treesz[v];
    }
}

int dfs2(int u, int par) {
    for (auto &v: adj[u]) {
        if (v == par) continue;
        if (treesz[v] > cursz / 2) {
            return dfs2(v, u);
        } 
    }
    return u;
}

void decompose(int u, int par) {
    cursz = 0;
    dfs1(u, par);
    int ctr = dfs2(u, par);
    parent[ctr] = par;

    for (auto &v: adj[ctr]) {
        if (v == par) continue;
        adj[v].erase(ctr);
        decompose(v, ctr);
    }
}
