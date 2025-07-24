/**
 *  Author: Aman Maurya
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define ft first
#define sd second
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;
typedef long long ll;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int INFLL = 1e18 + 5;
const int maxN = 101;
const int maxK = 8001;

void printbit(int x, int len) {
  string s = "\n";
  while (len--) {
    s = ((x % 2) ? '1' : '0') + s;
    x /= 2;
  }
  cout << s;
}

template<class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (T& x : v) in >> x;
  return in;
}

template<class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (T& x : v) out << x << ' ';
  cout << '\n';
  return out;
}

// Helper Functions
ll countSetBits(ll n) { return __builtin_popcountll(n); }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool isPrime(ll n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
ll factorial(ll n) { return (n == 0 || n == 1) ? 1 : n * factorial(n - 1); }
int smallestDivisor(int n) {
  if (n % 2 == 0) return 2;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return i;
  return n;
}
int largestDivisor(int n) { return n / smallestDivisor(n); }
ll nCr(ll n, ll r) {
  if (r > n) return 0;
  ll p = 1, k = 1;
  if (n - r < r) r = n - r;
  while (r) {
    p *= n--, k *= r--;
    ll m = __gcd(p, k);
    p /= m, k /= m;
  }
  return p;
}

void solve() {
    int k ;
    cin>>k;

    int cnt = 9;
    int skipped = 0;

    for(int len=1;1;len++){
        if(k>cnt*len){
            k-=cnt*len;
            skipped+=cnt;
        }
        else{
            int skip = (k-1)/len;
            k-=skip*len;
            skipped+=skip;
            int num = skipped+1;
            cout<<to_string(num)[k-1]<<"\n";
            return;
        }
        cnt*=10;
    }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}