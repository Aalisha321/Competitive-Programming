  #include<bits/stdc++.h>
 using namespace std;

 typedef long long ll;
 #define pb push_back
 #define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define vi vector<int>
#define vll vector<ll>
#define vdd vector<dd>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll MOD = 1e9 + 7;

void solve1(){
 ll n; cin>>n;
 string s; cin>>s;
 map<char,ll> freq;
 ll cnt=0;
 vll dis(n,0);
  for(ll i=0; i<n; i++){
    freq[s[i]]++;
     if(freq[s[i]] == 1){
        cnt++;
     }
     dis[i] = cnt;
  }
  ll ans=0;
   for(ll i=0; i<n; i++) ans+= dis[i];
    cout << ans << endl;
}

 int main(){
    ll T;
    T=1;
     cin>>T;
    while(T--){
        solve1();
    }
    return 0;
 }