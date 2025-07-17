#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
void solve(){
    string s ;
    cin>>s;
    int n =s.size();
    vector<int>helper(26,0);
    for(int i=0;i<n;i++){
        helper[s[i]-'A']++;
    }
    int cnt =0;
    char extra = '$';
    for(int i=0;i<26;i++){
        if(helper[i]&1){
            extra = 'A'+i;
            cnt++;
        }
    }
    if(cnt>1){
        cout<<"NO SOLUTION\n";
    }
    else{
        string half;
        for(int i = 0 ;i<26;i++){
            int rep = helper[i]/2;
            char c = 'A'+i;
            while(rep--){
                half.push_back(c);
            }
        }
        cout<<half;
        if(cnt)cout<<extra;
        reverse(half.begin(),half.end());
        cout<<half<<"\n";
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
