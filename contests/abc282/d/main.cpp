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

struct Info {
  ll num_1_node = 0;
  ll num_2_node = 0;
  ll num_edge = 0;

  ll num_node() { return num_1_node + num_2_node; }
};

graph g;
vector<int> seen;
vector<Info> info;

//連結成分の個数
int cnt = 0;

// trueは二部グラフである
bool dfs(int v, int value) {
  // cout << v<<' ' << value << endl;
  seen[v] = value;

  if (value == 1) {
    info[cnt].num_1_node++;
  } else {
    info[cnt].num_2_node++;
  }

  bool result = true;
  info[cnt].num_edge += size(g[v]);

  for (int to : g[v]) {
    if (!seen[to]) {
      result &= dfs(to, value == 1 ? 2 : 1);
    } else {
      result &= (seen[to] == (value == 1 ? 2 : 1));
    }
  }

  return result;
}

int main() {
  // cout << fixed << setprecision(10)
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  g.resize(N);
  seen.assign(N, 0);
  info.resize(N);

  rep(i, M) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;

    g[u].push_back(v);
    g[v].push_back(u);
  }

  rep(i, N) {
    if (!seen[i]) {
      if (!dfs(i, 1)) {
        cout << 0 << endl;
        return 0;
      } else {
        ++cnt;
      }
    }
  }

  ll ans = 0;

  rep(i, cnt) {
    // cout << info[i].num_1_node << ' ' << info[i].num_2_node << ' '
    //      << info[i].numge << ' ' << endl;

    info[i].num_edge /= 2;

    ans += info[i].num_1_node * info[i].num_2_node - info[i].num_edge;
  }

  if(cnt == 1){
    cout << ans << endl;
    return 0;
  }

  ll tmp = 0;

  rep(i, cnt) { tmp += info[i].num_node(); }

  ll tmp2 = tmp * (tmp - 1) / 2;

  rep(i, cnt) { tmp2 -= info[i].num_node()* (info[i].num_node() - 1)/ 2; }


  cout << ans + tmp2 << endl;
}
