#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
#include <bits/stdc++.h>
using namespace std;
using graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define INF (int)(1e9)
#define MAXX 1.1529215e+18
#define EPS (1e-7)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define PI acos(-1.0)
#define sz(a) a.size()
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const int MAX = 10000000;
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> T gcd(T a, T b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// output
template <class t> using vc = vector<t>;
template <class t> ostream &operator<<(ostream &os, const vc<t> &v) {
    os << "{";
    for (auto e : v)
        os << e << " ";
    return os << "}";
}
template <class t> ostream &operator<<(ostream &os, const set<t> &st) {
    os << "{";
    for (auto e : st)
        os << e << ",";
    return os << "}";
}
template <class t, class u> ostream &operator<<(ostream &os, const map<t, u> &mp) {
    for (auto [k, v] : mp)
        os << k << " " << v << endl;
    return os;
}

template <class t, class u> ostream &operator<<(ostream &os, const pair<t, u> &p) {
    return os << "{" << p.first << " " << p.second << "}";
}

// input
template <typename T, typename U> std::istream &operator>>(std::istream &is, pair<T, U> &pair) {
    return is >> pair.first >> pair.second;
}
template <class t> ostream &operator>>(ostream &os, const vc<t> &v) {
    for (auto e : v)
        os >> e;
    return os;
}
template <class t, class u> ostream &operator>>(ostream &os, const pair<t, u> &p) { return os >> p.first >> p.second; }
template <typename T> std::istream &operator>>(std::istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

template <class T> T extgcd(T a, T b, T &x, T &y) {
    T d = a;
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return d;
}

void yesno(bool flag, string yes = "Yes", string no = "No") {
    if (flag) {
        cout << yes << endl;
    } else {
        cout << no << endl;
    }
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
/* class内での演算子オーバーロード
bool operator<(const Info& another) const
{
    return age < another.age;  //年齢を比較
};*/
/*--------------------------------------------*/

int N;
vector<int> a;
vector<int> seen;

int ct = 0;

vector<set<int>> loops;

map<int, int> ct2ind;

map<int, int> inloop;

void dfs(int v, const int start, set<int> &s) {
    if (seen[v])
        return;
    seen[v] = ++ct;
    ct2ind[ct] = v;

    if (seen[a[v]]) {
        if (seen[a[v]] >= start) {
            for (int i = seen[a[v]]; i <= ct; ++i) {
                inloop[ct2ind[i]] = loops.size();
                s.insert(ct2ind[i]);
            }
        }
    } else {
        dfs(a[v], start, s);
    }
}

map<int, ll> memo;

ll dfs2(int v) {
    if (memo.contains(v)) {
        return memo[v];
    }

    if (inloop.contains(v)) {
        return memo[v] = ll(size(loops[inloop[v]]));
    }

    return memo[v] = dfs2(a[v]) + 1LL;
}

int main() {
    // cout << fixed << setprecision(10)
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    a.resize(N);
    cin >> a;
    seen.resize(N);

    rep(i, N) { --a[i]; }

    vector<ll> val(N);

    rep(i, N) {
        if (!seen[i]) {
            set<int> s;
            dfs(i, ct + 1, s);
            if (size(s)) {
                loops.push_back(s);
            }
        }
    }

    ll ans = 0;

    vector<ll> dp(N);

    rep(i, N) { ans += dfs2(i); }

    cout << ans << endl;
}
