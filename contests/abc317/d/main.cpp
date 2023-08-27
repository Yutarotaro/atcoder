#include <iostream>
#include <vector>
typedef long long ll;

int main() {
    int N;
    std::cin >> N;

    std::vector<ll> z(N);
    std::vector<ll> res(N);
    ll sum_z = 0;
    ll sum_res = 0;

    for (int i = 0; i < N; ++i) {
        ll x, y, k;
        std::cin >> x >> y >> k;

        z[i] = k;
        if (y - x >= 0) {
            res[i] = (y - x) / 2 + 1;
            sum_res += (y - x) / 2 + 1;
        } else {
            res[i] = 0;
            sum_res += 0;
        }
        sum_z += k;
    }

    ll border = sum_z / 2;
    std::vector<std::vector<ll>> dp(N + 1, std::vector<ll>(border + 1, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= border; ++j) {
            if (j >= z[i]) {
                dp[i + 1][j] = std::max(dp[i][j - z[i]] + res[i], dp[i][j]);
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    std::cout << sum_res - dp[N][border] << std::endl;

    return 0;
}
// #if __has_include(<atcoder/all>)
// #include <atcoder/all>
// using namespace atcoder;
// #endif
// #include <bits/stdc++.h>
// using namespace std;
// using namespace atcoder;
// using graph = vector<vector<int>>;
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<long long, long long> pll;
// #define INF (int)(1e9)
// #define MAXX 1.1529215e+18
// #define EPS (1e-7)
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #define ALL(a) a.begin(), a.end()
// #define PI acos(-1.0)
// #define sz(a) a.size()
// const ll MOD = 1e9 + 7;
// const ll mod = 998244353;
// const int MAX = 10000000;
// template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
//   if (a > b) {
//     a = b;
//     return 1;
//   }
//   return 0;
// }
// template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
//   if (a < b) {
//     a = b;
//     return 1;
//   }
//   return 0;
// }
// template <typename T> T gcd(T a, T b) {
//   if (b == 0)
//     return a;
//   return gcd(b, a % b);
// }

// //output
// template <class t> using vc = vector<t>;
// template <class t> ostream &operator<<(ostream &os, const vc<t> &v) {
//   os << "{";
//   for (auto e : v)
//     os << e << " ";
//   return os << "}";
// }
// template <class t> ostream &operator<<(ostream &os, const set<t> &st) {
//   os << "{";
//   for (auto e : st)
//     os << e << ",";
//   return os << "}";
// }
// template <class t, class u> ostream &operator<<(ostream &os, const map<t,u> &mp) {
//   for (auto [k, v] : mp)
//     os << k << " " << v << endl;
//   return os;
// }

// template <class t, class u>
// ostream &operator<<(ostream &os, const pair<t, u> &p) {
//   return os << "{" << p.first << " " << p.second << "}";
// }

// //input
// template <typename T, typename U>
// std::istream &operator>>(std::istream &is, pair<T, U> &pair) {
//   return is >> pair.first >> pair.second;
// }
// template <class t> ostream &operator>>(ostream &os, const vc<t> &v) {
//   for (auto e : v)
//     os >> e;
//   return os;
// }
// template <class t, class u>
// ostream &operator>>(ostream &os, const pair<t, u> &p) {
//   return os >> p.first >> p.second;
// }
// template <typename T>
// std::istream &operator>>(std::istream &is, vector<T> &vec) {
//   for (T &x : vec)
//     is >> x;
//   return is;
// }

// template <class T> T extgcd(T a, T b, T &x, T &y) {
//   T d = a;
//   if (b == 0) {
//     x = 1;
//     y = 0;
//   } else {
//     d = extgcd(b, a % b, y, x);
//     y -= (a / b) * x;
//   }
//   return d;
// }

// void yesno(bool flag, string yes = "Yes", string no = "No") {
//   if (flag) {
//     cout << yes << endl;
//   } else {
//     cout << no << endl;
//   }
// }

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// /* class内での演算子オーバーロード
// bool operator<(const Info& another) const
// {
//     return age < another.age;  //年齢を比較
// };*/
// /*--------------------------------------------*/

// struct vote{
//   ll x,y,z;
// };

// int main() {
//   // cout << fixed << setprecision(10)
//   cin.tie(0);
//   ios::sync_with_stdio(false);

//   int N;cin >> N;
//   vector<vote> a(N);
//   ll z_sum = 0;
//   rep(i, N){
//     cin >> a[i].x >> a[i].y >> a[i].z;
//     z_sum += a[i].z;
//   }

//   vector<vector<ll>> dp(N, vector<ll>(z_sum+1, __LONG_LONG_MAX__)); //dp[i][j]は、i+1選挙区まででz議席獲得するために必要な最小の鞍替え数
//   rep(i, z_sum+1){
//     dp[0][i] = (i?(a[0].z >= i?max((a[0].y - a[0].x + 1) / 2, 0LL):__LONG_LONG_MAX__):0);
//   }


//   for(int i = 1;i < N;++i){
//     dp[i][0] = 0;
//     // dp[i][0] = min(dp[i-1][0], max((a[i].y - a[i].x + 1) / 2, 0LL));
//     for(int j = 1;j <= z_sum;++j){
//       if(dp[i-1][max(0LL, j-a[i].z)] != __LONG_LONG_MAX__){
//         dp[i][j] = dp[i-1][max(0LL, j-a[i].z)] + max((a[i].y - a[i].x + 1) / 2, 0LL); 
//       }else{
//         dp[i][j] = min(dp[i-1][j], __LONG_LONG_MAX__);
//       }
//       // if(dp[i-1][j] != -1){
//       //   dp[i][min(a[i].z + j, z_sum)] = dp[i-1][j] + max((a[i].y - a[i].x + 1) / 2, 0LL); 
//       // }else{ //i-1番目まででは、j議席獲得できない
//       // }
//     }
//   }

//   ll ans = __LONG_LONG_MAX__;

//   for(int i = (z_sum+1)/2;i <= z_sum;++i){
//     chmin(ans, dp[N-1][i]);
//   }

//   cout << ans << endl;
// }
