#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int n, t[4*MAXN], lazy[4*MAXN];

void push(int v) {
	t[v*2] += lazy[v];
	lazy[v*2] += lazy[v];
	t[v*2+1] += lazy[v];
	lazy[v*2+1] += lazy[v];
	lazy[v] = 0;
}

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) t[v] = a[tl];
	else {
		int tm = (tl+tr)/2;
		build(a,v*2,tl,tm);
		build(a,v*2+1,tm+1,tr);
		t[v] = max(t[v*2],t[v*2+1]);
	}
}

// Update tree based on query
void update(int v, int tl, int tr, int l, int r, int add) {
	if (l > r) return;
	if (l == tl && r == tr) {
		t[v] += add;
		lazy[v] += add;
	}
	else {
		push(v);
		int tm = (tl+tr)/2;
		update(v*2,tl,tm,l,min(r,tm),add);
		update(v*2+1,tm+1,tr,max(l,tm+1),r,add);
		t[v] = max(t[v*2],t[v*2+1]);
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r) return INT_MIN;
	if (l == tl && r == tr) return t[v];
	push(v);
	int tm = (tl+tr)/2;
	return max(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(l,tm+1),r));
}

int main() {
	int a[6] = {0,1,3,-2,8,-7};
	n = 5;
	build(a,1,1,n);
	cout << query(1,1,n,1,3) << "\n";
	update(1,1,n,1,1,3);
	cout << query(1,1,n,1,3) << "\n";
	update(1,1,n,3,5,8);
	cout << query(1,1,n,1,3) << "\n";
}


