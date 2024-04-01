#include <bits/stdc++.h>
using namespace std;

/* Point update Fenwick Tree
 * Range queries of form [0,r]
 * Array must be 1-indexed
*/
template <typename T> struct BIT {
    vector<T> tree;
    int n;
    T DEFAULT;

    BIT(int sz = 0){
        n = sz+1, DEFAULT = 0;
        tree = vector<T>(n, DEFAULT);
    }

    void update(int idx, T val){
        for(; idx < n; idx = idx|(idx+1))
            tree[idx] = tree[idx]+val;
    }

    T query(int idx){
        T ans = DEFAULT;
        for(; idx >= 0; idx = (idx&(idx+1))-1) 
            ans = ans+tree[idx];
        return ans;
    }
};

