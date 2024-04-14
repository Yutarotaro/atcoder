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

int main() {
  // cout << fixed << setprecision(10)
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<vector<ll>> a(3, vector<ll>(3));
  cin >> a;

  set<pair<ll, pll>> corners, others;
  for (int i = 0; i <= 2; i += 2) {
    for (int j = 0; j <= 2; j += 2) {
      corners.insert({-a[i][j], {i, j}});
    }
  }

  others.insert({-a[0][1], {0, 1}});
  others.insert({-a[1][0], {1, 0}});
  others.insert({-a[2][1], {2, 1}});
  others.insert({-a[1][2], {1, 2}});

  auto Corners = corners;
  auto Others = others;

  // 1手目に真ん中
  ll takahashi = a[1][1], aoki = 0;
  while (corners.size()) {
    auto itr = corners.begin();
    auto [ptr, xy] = *itr;
    aoki += -ptr;
    corners.erase(itr);

    pll diag = {2 - xy.first, 2 - xy.second};
    ll x = diag.first;
    ll y = diag.second;
    takahashi += a[x][y];
    corners.erase(corners.find({-a[x][y], {x, y}}));
  }

  while (others.size()) {
    auto itr = others.begin();
    auto [ptr, xy] = *itr;
    aoki += -ptr;
    others.erase(itr);

    pll diag = {2 - xy.first, 2 - xy.second};
    ll x = diag.first;
    ll y = diag.second;
    takahashi += a[x][y];
    others.erase(others.find({-a[x][y], {x, y}}));
  }
  // cout << takahashi << ' ' << aoki << endl;
  if (takahashi > aoki) {
    cout << "Takahashi" << endl;
    return 0;
  }

  takahashi = 0, aoki = 0;

  // 1
  takahashi += -(*Corners.begin()).first;
  auto [x1, y1] = (*Corners.begin()).second;
  Corners.erase(Corners.begin());

  // 2
  aoki += a[1][1];

  // 3
  takahashi += a[2 - x1][2 - y1];
  Corners.erase(Corners.find({-a[2 - x1][2 - y1], {2 - x1, 2 - y1}}));

  // 4
  aoki += -(*Others.begin()).first;
  auto [x2, y2] = (*Others.begin()).second;
  Others.erase(Others.begin());

  // 5
  takahashi += a[2 - x2][2 - y2];
  Others.erase(Others.find({-a[2 - x2][2 - y2], {2 - x2, 2 - y2}}));

  // 6
  aoki += -(*Others.begin()).first;
  auto [x3, y3] = (*Others.begin()).second;
  Others.erase(Others.begin());

  // 7
  takahashi += a[2 - x3][2 - y3];
  Others.erase(Others.find({-a[2 - x3][2 - y3], {2 - x3, 2 - y3}}));

  // 8
  aoki += -(*Corners.begin()).first;
  auto [x4, y4] = (*Corners.begin()).second;
  Corners.erase(Corners.begin());

  // 9
  takahashi += a[2 - x4][2 - y4];
  Corners.erase(Corners.find({-a[2 - x4][2 - y4], {2 - x4, 2 - y4}}));

  if (takahashi > aoki) {
    cout << "Takahashi" << endl;
  }else{
    cout << "Aoki" << endl;
  }



}
