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

#include <bits/stdc++.h>
using namespace std;

/* UnionFind：素集合系管理の構造体(union by rank)
    isSame(x, y): x と y が同じ集合にいるか。 計算量はならし O(α(n))
    unite(x, y): x と y を同じ集合にする。計算量はならし O(α(n))
*/
struct UnionFind { // The range of node number is u 0 v n-1
  vector<int> rank, parents;
  UnionFind() {}
  UnionFind(int n) { // make n trees.
    rank.resize(n, 0);
    parents.resize(n, 0);
    for (int i = 0; i < n; i++) {
      makeTree(i);
    }
  }
  void makeTree(int x) {
    parents[x] = x; // the parent of x is x
    rank[x] = 0;
  }
  bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
  void unite(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);
    if (rank[x] > rank[y]) {
      parents[y] = x;
    } else {
      parents[x] = y;
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
  }
  int findRoot(int x) {
    if (x != parents[x])
      parents[x] = findRoot(parents[x]);
    return parents[x];
  }
};

// 辺の定義
struct Edge {
  long long u;
  long long v;
  long long cost;
};
bool comp_e(const Edge &e1, const Edge &e2) {
  return e1.cost < e2.cost;
} // 辺を直接比較するための関数

/* Kruskal :クラスカル法で minimum spanning tree を求める構造体
    入力: 辺のvector, 頂点数V
    最小全域木の重みの総和: sum
    計算量: O(|E|log|V|)
*/
struct Kruskal {
  UnionFind uft;
  long long sum; // 最小全域木の重みの総和
  vector<Edge> edges;
  int V;
  Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); }
  void init() {
    sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
    uft = UnionFind(V);
    sum = 0;
    for (auto e : edges) {
      if (!uft.isSame(e.u, e.v)) { // 閉路にならなければ加える
        uft.unite(e.u, e.v);
        sum += e.cost;
      }
    }
  }
};

int main() {
  int N;
  cin >> N;
  ll M;
  cin >> M;
  vector<ll> a(N);
  cin >> a;
  int V = N, E = N * (N - 1) / 2;

  vector<Edge> edges;

  rep(i, N) {
    for (int j = i + 1; j < N; ++j) {
      ll tmp = (pow_mod(a[i], a[j], M) + pow_mod(a[j], a[i], M)) % M;

      Edge e = {i, j, -tmp};
      edges.push_back(e);
    }
  }

  Kruskal krs(edges, V);

  cout << -krs.sum << endl;

  return 0;
}
