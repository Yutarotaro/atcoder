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
template <class t, class u>
ostream &operator<<(ostream &os, const map<t, u> &mp) {
  for (auto [k, v] : mp)
    os << k << " " << v << endl;
  return os;
}

template <class t, class u>
ostream &operator<<(ostream &os, const pair<t, u> &p) {
  return os << "{" << p.first << " " << p.second << "}";
}

// input
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

int N, M;
graph g;
bool flag = true;
vector<int> color;

int dfs(int v, int c) {
  // cout << v+1 << ' ' << c << endl;
  color[v] = c;

  for (int to : g[v]) {
    if(to == v){
      flag = false;
      return 1;
    }
    if (color[to] != -1) {
      if (color[to] == c) {
        flag = false;
        return 1;
      }
    }else{
      dfs(to, 1 - c);
    }
  }

  return 0;
}

int main() {
  // cout << fixed << setprecision(10)
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  vector<ll> a(M), b(M);
  cin >> a >> b;

  g.resize(N);
  color.assign(N, -1);

  rep(i, M) {
    ll c = a[i] - 1;
    ll d = b[i] - 1;

    g[c].push_back(d);
    g[d].push_back(c);
  }

  rep(i, N){
    if(color[i] == -1){
      dfs(i, 0);
    }
  }

  yesno(flag);

  // dsu d(N);

  // rep(i, M){
  //   if(!d.same(a[i]-1, b[i]-1)){
  //     d.merge(a[i]-1, b[i]-1);
  //   }else{
  //     cout << i << endl;
  //     yesno(0);
  //     return 0;
  //   }
  // }

  // yesno(1);
}
