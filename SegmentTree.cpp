#include <bits/stdc++.h>
using namespace std;

/**
 * Point update max-tree
 * Range queries of form [l,r)
 * Array must be 0-indexed
 */

template <typename T> struct SegTree {
    vector<T> tree;
    static constexpr T unit = INT_MIN;
    int n;
    SegTree(int n = 0, T def = unit): tree(2*n, def), n(n) {}
    T f(T a, T b) { return max(a,b); }
    void update(int pos, T val) {
        for (tree[pos += n] = val; pos /= 2;)
            tree[pos] = f(tree[2*pos], tree[2*pos+1]);
    }
    T query(int l, int r) {
        T rl = unit, rr = unit;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l%2) rl = f(rl, tree[l++]);
            if (r%2) rr = f(tree[--r], rr);
        }
        return f(rl,rr);
    }
};
