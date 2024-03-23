#include <bits/stdc++.h>
using namespace std;

#define MAX INT_MAX
#define MIN INT_MIN
#define ll long long int
#define nline "\n"
#define BIG 998244352
#define MOD 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<ll,ll>
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vi>
#define vpii vector<pii>
#define ff first
#define ss second
#define mkp make_pair
#define pb emplace_back

const int MAXN = 100001;
vi parent(MAXN);
vi setsz(MAXN);

void make_set(ll v) {
	parent[v] = v;
	setsz[v] = 1;
}

ll find_set(ll v) {
	if (v == parent[v]) return v;
	else return parent[v] = find_set(parent[v]);
}

void union_sets(ll u, ll v) {
	u = find_set(u);
	v = find_set(v);
	if (u != v) {
		if (setsz[u] < setsz[v]) swap(u,v);
		parent[v] = u;
		setsz[u] += setsz[v];
	}
}
