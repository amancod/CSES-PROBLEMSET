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

vector<int>segTree,lazy;

void buildTree(int i,int l,int r,vector<int>&arr){
    if(l==r){
        segTree[i]=arr[l];return;
    }
    int m = l+(r-l)/2;
    buildTree(2*i+1,l,m,arr);
    buildTree(2*i+2,m+1,r,arr);
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

void updateQ(int i,int l,int r,int &st,int &end,int &val){
    if(lazy[i]!=0){
        segTree[i]+=(r-l+1)*lazy[i];
        if (l != r) {
           lazy[2*i+1] += lazy[i];
           lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(st>r || end<l)return;
    if(st<=l && r<=end){
        segTree[i]+=(r-l+1)*val;
        if (l != r) {
           lazy[2*i+1] += val;
           lazy[2*i+2] += val;
        }
        return;
    }
    int m = l+(r-l)/2;
    updateQ(2*i+1,l,m,st,end,val);
    updateQ(2*i+2,m+1,r,st,end,val);
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

int valueAtPosQ(int i,int l,int r,int ind){
    if (lazy[i] != 0) {
        segTree[i] += (r - l + 1) * lazy[i];
        if (l != r) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(l==r){
        return segTree[i];
    }
    int m = l+(r-l)/2;
    if(ind<=m){
        return valueAtPosQ(2*i+1,l,m,ind);
    }
    else return valueAtPosQ(2*i+2,m+1,r,ind);
}

void solve() {
    int n,q;
    cin>>n>>q;

    vector<int>arr(n);
    cin>>arr;

    segTree.resize(4*n);
    lazy.resize(4*n);

    buildTree(0,0,n-1,arr);

    while(q--){
        int type;
        cin>>type;

        if(type==1){
            int st,end,val;
            cin>>st>>end>>val;
            --st,--end;
            updateQ(0,0,n-1,st,end,val);
        }
        else{
            int ind;
            cin>>ind;
            cout<<valueAtPosQ(0,0,n-1,ind-1)<<endl;
        }
    }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
//   cin >> t;
  while (t--) solve();
  return 0;
}