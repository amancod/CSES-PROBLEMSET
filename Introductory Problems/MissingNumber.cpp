 /**
 *  Author: Aman Maurya
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define rd(i,n) for(int i=0;i<n;i++)
#define rp(i,n) for(int i=1;i<=n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=b;i>=a;i--)
#define ft first
#define sd second
#define pb push_back
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;
 
const int MOD = 1e9+7;
const int INFLL = 1e18+5;
const int INF = 1e9;
const int maxN = 101;
const int maxK = 8001;
 
void printbit(int x, int len) {string s="\n";while(len--){s=((x%2)?'1':'0')+s;x/=2;} cout<<s;}
 
template<class T>
istream& operator>>(istream&in, vector<T>&v){
    for (T& x:v) in>>x;
    return in;
}
template<class T>
ostream& operator<<(ostream&out, vector<T>&v){
    for (T& x:v) out<<x<<' ';
    cout<<'\n';
    return out;
}
 
void solve(){
  int n;
  cin>>n;
 
  int x;
  int ans =0;
  
  for(int i=0;i<n-1;i++){
    cin>>x;
    ans=ans^x;
  }
 
  for(int i=1;i<=n;i++){
    ans^=i;
  }
  cout<<ans<<endl;
 
}
 
signed main() {
  // freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
 
    solve();   
    return 0;
}