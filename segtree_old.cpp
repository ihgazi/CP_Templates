#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int MAXN = 100001;
ll n, t[4*MAXN];

// array should be 1 indexed
void build(ll a[], ll v, ll tl, ll tr) {
	if (tl == tr) t[v] = a[tl];
	else {
		ll tm = (tl+tr)/2;
		build(a,v*2,tl,tm);
		build(a,v*2+1,tm+1,tr);
		t[v] = t[v*2]+t[v*2+1];
	}
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r) return 0;
	if (l == tl && r == tr) return t[v];
	ll tm = (tl + tr)/2;
	return query(v*2,tl,tm,l,min(r,tm))+query(v*2+1,tm+1,tr,max(l,tm+1),r);
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
	if (tl == tr) t[v] = new_val;
	else {
		ll tm = (tl+tr)/2;
		if (pos <= tm) update(v*2,tl,tm,pos,new_val);
		else update(v*2+1,tm+1,tr,pos,new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int main() {
	int a[6] = {0,1,3,-2,8,-7};
	n = 5;
	build(a,1,1,n);
	cout << sum(1,1,n,2,4) << "\n";
	update(1,1,n,3,-1);
	cout << sum(1,1,n,2,4) << "\n";
}
