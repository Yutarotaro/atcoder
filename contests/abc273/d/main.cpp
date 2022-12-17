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
template <class t> ostream &operator<<(ostream &os, const set<t> &st) {
  for (auto e : st)
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
template <typename T> std::istream &operator>>(std::istream &is, set<T> &set) {
  for (T &x : set)
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

  ll H, W;
  cin >> H >> W;
  pll now;
  cin >> now;

  ll N;
  cin >> N;

  vector<pll> wall(N);
  cin >> wall;

  vector<set<ll>> h_wall = {set<ll>{}}, w_wall = {set<ll>{}};
  map<ll, ll> x2h_wall_idx, y2w_wall_idx;
  int x_idx = 1;
  int y_idx = 1;

  for (auto [x, y] : wall) {
    if (!x2h_wall_idx[x]) {
      x2h_wall_idx[x] = x_idx++;
      h_wall.push_back(set<ll>{y});
    } else {
      h_wall[x2h_wall_idx[x]].insert(y);
    }

    if (!y2w_wall_idx[y]) {
      y2w_wall_idx[y] = y_idx++;
      w_wall.push_back(set<ll>{x});
    } else {
      w_wall[y2w_wall_idx[y]].insert(x);
    }
  }

  int Q;
  cin >> Q;

  rep(_, Q) {
    char d;
    ll l;
    cin >> d >> l;

    if (d == 'L') {
      int x_idx = x2h_wall_idx[now.first];
      if (!x_idx) {
        now.second = max(1LL, now.second - l);
      } else {
        auto itr = h_wall[x_idx].lower_bound(now.second);
        if (itr == h_wall[x_idx].begin()) {
          now.second = max(1LL, now.second - l);
        } else {
          --itr;
          now.second = *itr + 1;
        }
      }

      cout << now << endl;
      continue;
    }

    if (d == 'R') {
      int x_idx = x2h_wall_idx[now.first];
      if (!x_idx) {
        now.second = min(W, now.second + l);
      } else {
        auto itr = h_wall[x_idx].upper_bound(now.second);
        if (itr == h_wall[x_idx].end()) {
          now.second = max(W, now.second + l);
        } else {
          now.second = *itr - 1;
        }
      }

      cout << now << endl;
      continue;
    }

    if (d == 'U') {
      int y_idx = y2w_wall_idx[now.second];
      if (!y_idx) {
        now.first = max(1LL, now.first - l);
      } else {
        auto itr = w_wall[y_idx].lower_bound(now.first);
        if (itr == w_wall[y_idx].begin()) {
          now.first = max(1LL, now.first - l);
        } else {
          --itr;
          now.first = *itr + 1;
        }
      }

      cout << now << endl;
      continue;
    }

    if (d == 'D') {
      int y_idx = y2w_wall_idx[now.second];
      if (!y_idx) {
        now.first = min(H, now.first + l);
      } else {
        auto itr = w_wall[y_idx].upper_bound(now.first);
        if (itr == w_wall[y_idx].end()) {
          now.first = min(H, now.first + l);
        } else {
          now.first = *itr - 1;
        }
      }

      cout << now << endl;
      continue;
    }
  }
}
