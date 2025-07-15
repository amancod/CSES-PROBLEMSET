#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve(){
  int n;
  cin>>n;
 
  while(1){
    if(n!=1 && n%2==1){
      cout<<n<<" ";
      n=(n*3)+1;
    }
    else if(n%2==0){
      cout<<n<<" ";
      n/=2;
    }
    else{
      cout<<1<<endl;
      break;
    }
  }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}