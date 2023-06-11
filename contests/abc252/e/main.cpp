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

int N, M;
vector<vector<pii>> g;

int main() {
  // cout << fixed << setprecision(10)
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> N >> M;
  g.resize(N);

  map<pii, int> road_idx;

  rep(i, M){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    --a;--b;

    g[a].push_back({b, c});
    g[b].push_back({a, c});

    road_idx[pii{a, b}] = i + 1;
    road_idx[pii{b, a}] = i + 1;
  }

  vector<int> used_road(N), dist(N, __INT_MAX__);

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push(pii{0, 0});
  dist[0] = 0; //node 0までの最短経路は0

  while(!pq.empty()){
    auto [cost, v] = pq.top();
    pq.pop();

    if(dist[v] < cost){
      continue;
    }

    for(auto [to, cost_]:g[v]){
      if(chmin(dist[to],dist[v] + cost_)){
        used_road[to] = road_idx[pii{v, to}];
        pq.push(pii{dist[to], to});
      }
    }
  }

  for(int i = 1; i < N;++i){
    cout << used_road[i] << (i < N - 1 ? " ": "\n");
  }


}
