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
map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

// long long gcd(long long a, long long b) { // 2つの場合の最大公約数
//     if (b == 0) {
//         return a;
//     } else {
//         return gcd(b, a % b);
//     }
// }
int gcd_vec(vector<int> const &A) { // N個の要素に対する最大公約数
    int size = (int)A.size();
    long long ret = A[0];
    for (int i = 1; i < size; i++) {
        ret = gcd(ret, A[i]);
    }
    return ret;
}

int main() {
  // cout << fixed << setprecision(10)
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;cin >>N;
  vector<int> a(N);cin >> a;


  ll ans = 0;

  int gc = gcd_vec(a);
  if(gc != 1){
    rep(i, N){
      a[i] /= gc;
    }
  }

  gc = gcd_vec(a);

  int minn = *min_element(ALL(a));
  if(gc == 1){
    minn = 1;
  }

  rep(i, N){
    if(a[i] % minn != 0){
      // cout << a[i] % minn << endl;
      cout << -1 << endl;
      return 0;
    }

    int now = a[i] / minn;

    if(now == 1)continue;

    auto pf = prime_factor(now);


    if(size(pf) == 1){
      if(pf[2]){
        ans += pf[2];
      }else if(pf[3]){
        ans += pf[3];
      }else{
      cout << -1 << endl;
      return 0;
      }
    }else if(size(pf) == 2){
      if(pf[2] && pf[3]){
        ans += pf[2] + pf[3];
      }else{
      cout << -1 << endl;
      return 0;
      }
    }else{
      cout << -1 << endl;
      return 0;
    }

  }

  cout << ans << endl;


}
