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
template <class t> using vc = vector<t>;
template <class t> ostream &operator<<(ostream &os, const vc<t> &v) {
  os << "{";
  for (auto e : v)
    os << e << ",";
  return os << "}";
}
template <class t, class u>
ostream &operator<<(ostream &os, const pair<t, u> &p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <typename T, typename U>
std::istream &operator>>(std::istream &is, pair<T, U> &pair) {
  return is >> pair.first >> pair.second;
}
template <class t> ostream &operator>>(ostream &os, const vc<t> &v) {
  for (auto e : v)
    os >> e;
  return os;
}
template <class t, class u>
ostream &operator>>(ostream &os, const pair<t, u> &p) {
  return os >> p.first >> p.second;
}
template <typename T>
std::istream &operator>>(std::istream &is, vector<T> &vec) {
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
using p = pair<mint, int>;

p op(p a, p b) {
  return pair{mint(a.first + b.first), a.second + b.second};
}

p e() { return pair{mint(0), 0}; }

int main() {
  // cout << fixed << setprecision(10)
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> A(N);
  vector<mint> a(N);
  cin >> A;
  rep(i, N){
    a[i] = mint(A[i]);
  }

  vector<mint> dp(N); // K=i+1の答え
  dp[0] = a[0];

  vector<pii> b(N);
  rep(i, N) {
    b[i].first = a[i].val();
    b[i].second = i;
  }

  sort(ALL(b));

  map<int, int> idx_to_sorted_idx;
  rep(i, N) { idx_to_sorted_idx[b[i].second] = i; }

  segtree<p, op, e> seg(N);
  seg.set(idx_to_sorted_idx[0], p{a[0], 1});

  mint sum = a[0];

  for (mint i = 0; i.val() < N - 1; ++i) {
    int idx = idx_to_sorted_idx[(i + 1).val()];
    mint tmp = ((i + 1).val() * a[(i + 1).val()] + sum -
                seg.prod(0, idx).first + seg.prod(idx + 1, N).first +
                a[(i + 1).val()] *
                    (seg.prod(0, idx).second - seg.prod(idx + 1, N).second)) /
               mint(2);

    dp[(i + 1).val()] = (dp[i.val()] * (i + 1).pow(2) + a[(i + 1).val()] +
                         2 * tmp) /
                        (i + 2).pow(2);
    seg.set(idx, p{a[(i + 1).val()], 1});
    sum += a[(i + 1).val()];
  }

  rep(i, N) { cout << dp[i].val() << endl; }
}
