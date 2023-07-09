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

//output
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
template <class t, class u> ostream &operator<<(ostream &os, const map<t,u> &mp) {
  for (auto [k, v] : mp)
    os << k << " " << v << endl;
  return os;
}

template <class t, class u>
ostream &operator<<(ostream &os, const pair<t, u> &p) {
  return os << "{" << p.first << " " << p.second << "}";
}

//input
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

int N1, N2;
graph g1, g2;

int main() {
  // cout << fixed << setprecision(10)
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N1 >> N2;
  g1.resize(N1);
  g2.resize(N2);

  int M;cin >> M;
  int M1 = 0, M2 = 0;

  rep(i, M){
    int a, b;cin >> a >> b;
    --a;--b;

    if(a < N1){
      g1[a].push_back(b);
      g1[b].push_back(a);
    }else{
      a -= N1; b -= N1;
      g2[a].push_back(b);
      g2[b].push_back(a);
    }
  }

  queue<pii> q1;
  q1.push({0, 0});
  vector<ll> d1s(N1, __INT_MAX__);
  vector<int> seen1(N1);

  while (!q1.empty())
  {
    auto [now, dist] = q1.front();
    q1.pop();
    d1s[now] = dist;

    seen1[now] = 1;

    for(int to: g1[now]){
      if(!seen1[to]){
        seen1[to] = 1;
        q1.push({to, dist+1});
      }
    }
  }


  queue<pii> q2;
  q2.push({N2-1, 0});
  vector<ll> d2s(N2, __INT_MAX__);
  vector<int> seen2(N2);

  while (!q2.empty())
  {
    auto [now, dist] = q2.front();
    q2.pop();
    d2s[now] = dist;


    seen2[now] = 1;

    for(int to: g2[now]){
      if(!seen2[to]){
        seen2[to] = 1;
        q2.push({to, dist+1});
      }
    }
  }


  ll d1 = *max_element(ALL(d1s));
  ll d2 = *max_element(ALL(d2s));
  // cout << d1 << ' ' <<  d2 << ' ' << endl;
  cout << d1 + d2 + 1 << endl;
    

}


