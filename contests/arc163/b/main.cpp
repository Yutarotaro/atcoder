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

  int N, M;cin >> N >> M;
  ll l, r;cin >> l >> r;
  int K = N - 2;
  vector<ll> a(K);cin >> a;
  sort(ALL(a));

  ll ans = 0;

  if(M == K){
    cout << max(0LL, l - a[0]) + max(0LL, a[K-1] - r) << endl;
    return 0;
  }

  auto now_l = lower_bound(ALL(a), l); //l以上最小
  if(now_l == a.end()){ //lがどれよりも大きいとき
    --now_l;
    ans += (l - *now_l);
    l = *now_l;
  }
  else if(now_l == a.begin()){
    l = *now_l;
  }

  auto now_r = upper_bound(ALL(a), r); //r以下最大
  if(now_r == a.begin()){ //rがどの要素よりも小さいとき
    ans += a[0] - r;
    r = a[0];
  }else if(now_r == a.end()){
    --now_r;
    r = *now_r;   
  }else{
    --now_r;
  }

  //元々OKなら終わる
  if(distance(now_l, now_r)+1 >= M){
    cout << ans << endl;
    return 0;
  }

  //終わらないなら、lを*now_l, rをnow_rにする
  if(l != *now_l){
    --now_l;
    ans += (l - *now_l);
  }
  if(r != *now_r){
    ++now_r;
    ans += (*now_r - r);
  }


  while (1){
    //OKなら終わる
    if(distance(now_l, now_r)+1 >= M){
      break;
    }

    auto tmp_l = now_l;
    if(tmp_l == a.begin()){ //lは減らせないのでrを増やす
      ll tmp_r_val = *now_r;
      now_r++;
      ans += (*now_r - tmp_r_val);
      continue;
    }
    tmp_l--;
    int l_gap_to_next =  *now_l - *tmp_l;

    auto tmp_r = now_r;
    if(tmp_r == a.end() - 1){ //逆
      ll tmp_l_val = *now_l;
      now_l--;
      ans += (tmp_l_val - *now_l);
      continue;
    }
    tmp_r++;
    int r_gap_to_next = *tmp_r - *now_r;

    if(l_gap_to_next < r_gap_to_next){
      ans += l_gap_to_next;
      --now_l;
    }else{
      ans += r_gap_to_next;
      ++now_r;
    }
  }
  
  cout << ans << endl;
}
