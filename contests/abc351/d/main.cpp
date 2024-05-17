#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
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

int main() {
    // cout << fixed << setprecision(10)
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    cin >> s;

    dsu uf(H * W);

    vector<vector<bool>> is_out(H, vector<bool>(W));
    //隣接するいずれかのマスが#であればtrue

    // outを設定
    rep(i, H) {
        rep(j, W) {
            rep(k, 4) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (0 <= nx && nx < H && 0 <= ny && ny < W && s[nx][ny] == '#') {
                    is_out[i][j] = true;
                }
            }
        }
    }

    //自由に移動可能なマス同士を繋ぐ
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == '.' && !is_out[i][j]) {
                rep(k, 4) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (0 <= nx && nx < H && 0 <= ny && ny < W && s[nx][ny] == '.' && !is_out[nx][ny]) {
                        uf.merge(i * W + j, nx * W + ny);
                    }
                }
            }
        }
    }

    //自由に移動可能な連結成分の中でその近傍も加算　
    ll ans = 0;

    for (auto &group : uf.groups()) {
        int x = group[0] / W;
        int y = group[0] % W;

        ll candi = size(group);
        set<ll> st;
        //このgroupが自由に移動可能なら
        if (s[x][y] == '.' && !is_out[x][y]) {

            for (auto &now : group) {
                rep(k, 4) {
                    int nx = now / W + dx[k];
                    int ny = now % W + dy[k];

                    if (0 <= nx && nx < H && 0 <= ny && ny < W && s[nx][ny] == '.' && is_out[nx][ny]) {
                        st.insert(nx * W + ny);
                    }
                }
            }
        }
        chmax(ans, candi + size(st));
    }

    cout << ans << endl;
}
