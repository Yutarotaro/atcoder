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

vector<vector<vector<double>>> dp;
map<vector<int>, int> mp;
int num_1, num_2, num_3;
int N;

double dfs(int n3, int n2, int n1) {
  if(mp[{n3, n2, n1}]){
    return dp[n3][n2][n1];
  }

  double ret = N / double(n3 + n2 + n1);

  mp[{n3, n2, n1}] = 1;

  if (n3) {
    ret += dfs(n3 - 1, n2 + 1, n1) * double(n3) / (n1 + n2 + n3);
  }

  if (n2) {
    ret += dfs(n3, n2 - 1, n1 + 1) * double(n2) / (n1 + n2 + n3);
  }

  if (n1 >= 1) {
    ret += dfs(n3, n2, n1 - 1) * double(n1) / (n1 + n2 + n3);
  }


  return dp[n3][n2][n1] = ret;
}

int main() {
  // cout << fixed << setprecision(10)
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector<int> a(N);
  cin >> a;
  vector<int> cnt(3);
  for (auto i : a) {
    cnt[--i]++;
  }

  num_1 = cnt[0];
  num_2 = cnt[1];
  num_3 = cnt[2];
  dp.assign(num_3 + 1,
            vector<vector<double>>(num_3 + num_2 + 2, vector<double>(N + 1)));

  mp[{0, 0, 1}] = 1;
  dp[0][0][1] = N;

  for(int i = 0;i <= num_1;++i){
    for(int j = 0)
  }


  cout << fixed << setprecision(10) << dfs(num_3, num_2, num_1) << endl;
}
