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

void solve2(){
   ll n,k; cin>>n>>k;
   vll a(n),b(n);
   for(ll i=0; i<n; i++) cin>>a[i];
   for(ll i=0; i<n; i++) cin>>b[i];

   vll p(n);
   p[0]=a[0];
   for(ll i=1; i<n; i++) p[i] = p[i-1]+a[i];
   
   vll mb(n);
   mb[0] = b[0];
   for(ll i=1; i<n; i++) mb[i] = max(mb[i-1],b[i]);

   ll ans=0;
   for(ll i=0; i<n; i++){
    if(k>= i+1)  ans = max (ans, p[i]+ (k-i-1)*mb[i]);
   }
   cout << ans << endl;
}
void solve3(){
   
}

 int main(){
    ll T;
    T=1;
     cin>>T;
    while(T--){
        solve2();
    }
    return 0;
 }