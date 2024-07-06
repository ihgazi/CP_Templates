#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

// order_of_key(k)    : number of elements strictly smaller than k
// find_by_order(ind) : iterator to set[ind]

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


#define MAX INT_MAX
#define MIN INT_MIN
#define ll long long int
#define nline "\n"
#define BIG 998244353
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

ll mult(ll p, ll q, ll m = MOD) {
    return (((p%m)*(q%m))%m);
}

ll binpow(ll p, ll q) {
    if (q == 0) return 1ll;
    ll temp = binpow(p, q/2);
    temp = mult(temp, temp);
    
    if (q%2) return mult(temp, p);
    return temp;
}

ll mod_inv(ll a, ll m = MOD) {
    return binpow(a, m - 2);
}

void binarysearch(int lo, int hi) {
    while (lo <= hi) {
        r = lo + (hi-lo)/2;

        // cout << r << " " << f(arr, r, k) << '\n';
        if (f(arr, r, k)) hi = r-1;
        else lo = r+1;
    }
}

int lcs(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1),
                   lcs(X, Y, m - 1, n));
}


void sieve(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
  
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}
// For fast prime factorization
// store px = smallest prime factor of x

// Ternary Search
    while (hi-lo>1) {
        ll mid = lo+(hi-lo)/2;
        ll val1 = helper(mid), val2 = helper(mid+1);
        //cout << val1 << " " << val2 << "\n";
        if (val1 > val2) hi = mid;
        else lo = mid;
    }

    cout << max(helper(original_lo),helper(lo+1)) << "\n";

stack<int> stack;
queue<int> queue;
vector<int> v(10, 0);

vector<int> manacher(string s) {
    string t = "";
    for (auto c: s) {
        t += '#', t += c;
    }
    t += "#";

    int n = t.size();
    t = "$"+t+"^";
    vector<int> p(n+2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = max(0, min(r-i, p[l+(r-i)]));
        while (t[i-p[i]] == t[i+p[i]])
            p[i]++;
        if (i+p[i] > r)  {
            l = i - p[i], r = i + p[i];
        }
    }

    return p;
}

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
