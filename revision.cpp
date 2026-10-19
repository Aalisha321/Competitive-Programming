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

void s1(){
    ll n,k;
    cin>> n >> k;
    vll a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    if(k==1){
        if(!is_sorted(a.begin(), a.end())){
            cout << "NO\n";
            return;
        }
    }
   cout <<"YES\n";
}
void s2(){
    ll n,x;
    cin>>n>>x;
    vll a(n); for(ll i=0; i<n; i++) cin>>a[i];
    if(n==1){
        cout << max (a[0], 2*(x-a[0])) << endl;
        return;
    }
    ll d1 = 2*(x - a[n-1]);
    ll d2= a[0];
    for(ll i=1; i<n; i++){
        d2 = max(a[i] - a[i-1], d2);
    }
    cout << max(d1,d2) << endl;
}

void ss1(){
    ll n; cin>>n;
    ll x,y,z;
    cin>>x>>y>>z;
    ll sum=0;
    ll c=0,d=0;
    if(((x*x) + (y*y)) < z){
        sum += ((x*x) + (y*y));
        c=x, d=y;
    }
    else sum += z;
    n-=1;
    while(n--){
     //   ll x,y,z;
        cin>>x>>y>>z;
     //   sum += min (((x*x) + (y*y)), z);
     if(((x-c)*(x-c) + (y-d)*(y-d)) < z){
        sum += ((x-c)*(x-c) + (y-d)*(y-d));
        c=x, d=y;
     } else {
        sum+= z;
     }
    }
    cout << sum << endl;
}
void ss2(){
    ll a,b,c;
    cin>>a>>b>>c;
    if (a>=2026 || b>= 2026 || (a^b)>=2026){
        cout << "No\n";
        return;
    }
    else {
        cout << "Yes\n";
        cout << a+1 <<" ";
        for(ll i=0; i<a; i++) cout<< i <<" ";
        cout<< a+1 << endl;
        cout << b+1 <<" ";
        for(ll i=0; i<b; i++) cout<< i <<" ";
        cout<< b+1 << endl;
        ll c= a^b;
        cout << c+1 <<" ";
        for(ll i=0; i<c; i++) cout<< i <<" ";
        cout<< c+1 << endl;
    }
}
void s3(){
    ll n; cin>>n;  string s;  cin>>s;
    ll n1=0;
    ll ans=0;
    for(ll i=0; i< n; i++){
        if(s[i]=='.'){
            n1++;
        }
        if(n1 >= 3){
            cout << "2\n";
            return;
        }
        if(s[i]=='#'){
          if(n1 ==1) ans+=1;
          else if (n1 >=2) ans+=2;
          n1 =0;
        }
    }
    if(s[n-1] == '.'){
        if(n1 ==1) ans+=1;
          else if (n1 >=2) ans+=2;
          n1 =0;
    }
    cout << ans << endl;
}

void s4(){
    ll n; cin>>n;
    if(n%3 == 0) cout << "Second\n";
    else cout << "First\n";
}
void s5(){
    ll n; cin>>n; vll a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    if(a[0]==1) cout << "YES\n";
    else cout << "NO\n";
}
void s6(){
    ll n; cin>>n; 
    unordered_map<ll,ll> freq;
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        freq[x]++;
    }
    if(freq.size() > 2) cout << "NO\n";
    else if (freq.size()==1) cout << "YES\n";
    else {
        auto it = freq.begin();
        ll c1 = it->second;
        it++;
        ll c2 = it->second;
        if(abs(c1 - c2) <= 1) cout << "YES\n";
        else cout << "NO\n";
    }
}
int main(){
    ll T;
    T=1;
    cin>>T;
    while(T--){
        s6();
    }
    return 0;
}