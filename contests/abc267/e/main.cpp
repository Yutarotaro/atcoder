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
  for (auto e : v)
    os << e << " ";
  return os;
}
template <class t, class u>
ostream &operator<<(ostream &os, const pair<t, u> &p) {
  return os << p.first << " " << p.second;
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

graph g;

int main() {
  // cout << fixed << setprecision(10)
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;cin >> N >> M;
  vector<ll> a(N); cin >> a;
  vector<ll> b(N);

  g.resize(N);

  map<pll, ll> not_deleted;

  rep(i, M){
    int u, v;
    cin >> u >> v;
    --u; --v;

    g[u].push_back(v);
    g[v].push_back(u);

    not_deleted[pll{u, v}] = 1;
    not_deleted[pll{v, u}] = 1;

    b[u] += a[v];
    b[v] += a[u];
  }

  ll l = 0, r = __LONG_LONG_MAX__;


  while(r - l > 1){
    ll mid = (l + r) / 2;
    //mid以下のコストで全頂点を削除できるか

    priority_queue<pll> pq;
    auto mp = not_deleted;

    rep(i, N) { pq.push(pll{b[i], i}); }

    bool ok_flag = true;

    while(!pq.empty()){
      auto [cost, v] = pq.top();
      pq.pop();

      bool changed = false;

      ll now_cost = 0;
      for(int i: g[v]){
        if(not_deleted[pll{v, i}]){
          now_cost += a[i];
        }
      }

      if(now_cost <= mid){
        changed = true;
        for(int i: g[v]) { not_deleted[pll{v, i}] = 0; }
      }else{
        pq.push(pll{now_cost, v});
      }

      if(!changed){
        ok_flag = false;
        break
      }
    }

    if(ok_flag){
      l = mid;
    }else{
      r = mid;
    }
  }

  cout << l << endl;
}
