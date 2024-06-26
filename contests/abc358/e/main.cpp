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
// const int MAX = 10000000;
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

using mint = modint998244353;
const int MAX = 510000;
mint fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

// 二項係数計算
mint COM(int n, int k) {
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * finv[k] * finv[n - k];
}

int main() {
    // cout << fixed << setprecision(10)
    cin.tie(0);
    ios::sync_with_stdio(false);

    COMinit();

    ll K;
    cin >> K;
    vector<ll> c(26);
    cin >> c;

    vector<vector<mint>> dp(26, vector<mint>(K + 1, 0));
    rep(i, min(K, c[0]) + 1) { dp[0][i] = 1; }
    rep(i, 26) { dp[i][0] = 1; }

    rep(i, 25) {
        rep(j, K) {                //もと
            rep(k, c[i + 1] + 1) { //足す個数
                if (!k) {
                    if (j + 1 <= K) {
                        dp[i + 1][j + 1] = dp[i][j + 1];
                    }
                } else if (j + k <= K) {
                    dp[i + 1][j + k] = dp[i][j + k] + dp[i][j] * COM(k + j, k);
                }
            }
        }
        //        rep(j, K + 1) { cout << char('a' + i + 1) << ' ' << dp[i + 1][j].val() << endl; }
    }

    mint ans = 0;
    for (int i = 1; i <= K; ++i) {
        ans += dp[25][i];
    }

    cout << ans.val() << endl;
}
