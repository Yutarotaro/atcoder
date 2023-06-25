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

int main() {
  // cout << fixed << setprecision(10)
  cin.tie(0);
  ios::sync_with_stdio(false);

  int HA, WA, HB, WB, HX, WX;
  
  cin >> HA >> WA;
  vector<string> a(HA);
  cin >> a;

  cin >> HB >> WB;
  vector<string> b(HB);
  cin >> b;

  cin >> HX >> WX;
  vector<string> x(HX);
  cin >> x;

  int num_sharp_a = 0, num_sharp_b = 0;

  rep(i, HA){
    rep(j, WA){
      num_sharp_a += (a[i][j] == '#');
    }
  }

  rep(i, HB){
    rep(j, WB){
      num_sharp_b += (b[i][j] == '#');
    }
  }

  for(int shift_a_x = -10;shift_a_x <= 10;++shift_a_x){
    for(int shift_a_y = -10; shift_a_y <= 10;++shift_a_y){
      for(int shift_b_x = -10;shift_b_x <= 10;++shift_b_x){
        for(int shift_b_y = -10; shift_b_y <= 10;++shift_b_y){
          int tmp_num_sharp_a = 0;
          int tmp_num_sharp_b = 0;
          bool big_flag = true;
          rep(i, HX){
            rep(j, WX){
              if(x[i][j] == '.')continue;

              bool flag = false; //#があればtrue

              pii ind_at_a = {i - shift_a_x, j-shift_a_y};
              if(ind_at_a.first >= 0 && ind_at_a.first < HA && ind_at_a.second >= 0 && ind_at_a.second < WA){
                flag |= (a[ind_at_a.first][ind_at_a.second] == '#');
                tmp_num_sharp_a += (a[ind_at_a.first][ind_at_a.second] == '#');
              }

              pii ind_at_b = {i - shift_b_x, j-shift_b_y};
              if(ind_at_b.first >= 0 && ind_at_b.first < HB && ind_at_b.second >= 0 && ind_at_b.second < WB){
                flag |= (b[ind_at_b.first][ind_at_b.second] == '#');
                tmp_num_sharp_b += (b[ind_at_b.first][ind_at_b.second] == '#');
              }
              
              big_flag &= flag;
            }
          }

          if(big_flag && (tmp_num_sharp_a == num_sharp_a) && (tmp_num_sharp_b == num_sharp_b) ){
            yesno(true);
            return 0;
          }
        }
      }
    }
  }

  yesno(false);








}
