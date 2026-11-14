  #include<bits/stdc++.h>
 using namespace std;

 typedef long long ll;
 #define pb push_back
   #define eb emplace_back
 #define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define vi vector<int>
#define vll vector<ll>
#define vdd vector<dd>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpll vector<pll>
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
   ll n; cin>>n;
   vector<pll> v;
   for(ll i=0; i<n; i++){
      ll x;
      cin>>x;
      v.pb({x,i});
   }
   sort(all(v)); 
   vll p(n);
   p[0] = v[0].first;
   for(ll i=1; i<n; i++) p[i] = p[i-1]+v[i].first;
   vll ans(n);
   ans[n-1] = n-1;
   for(ll i=n-2; i>=0; i--){
      if(p[i] >= v[i+1].first){
         ans[i]=ans[i+1];
      } else {
         ans[i]=i;
      }
   }
   vll res(n);
   for(ll i=0; i<n; i++){
      res[v[i].second] = ans[i];
   }

   for(ll i=0; i<n; i++) cout << res[i] << " ";
   cout << endl;
  
}

void solve4(){
   ll n; cin>>n;
   vll a(n); for(ll i=0; i<n; i++) cin>>a[i];

   ll i=0, j=1;
   ll curr=a[0];
   ll global = curr;

   while(j<n){
     if(abs(a[j])%2 == abs(a[j-1])%2){
      i=j;
      curr= a[j];
     }
     else if(curr <= 0){
      i=j;
      curr = a[j];
     } 
     else {
      curr += a[j];
     }
     global = max(global , curr);
     j++;
   }

   cout << global << endl;

}

   // SOLVE THIS

// void solve5(){
//    ll n; cin>>n;
//    vll a(n); for(ll i=0; i<n; i++) cin>>a[i];
//    vll k;
//    for(ll i=2; i*i<=n ; i++){
//       if(n%i == 0) {
//          k.pb(i);
//          while(n%i == 0) n/= i;
//       }
//    }
// }

void solve6(){
   ll n,q; cin>>n>>q;
   vll a(n);
   for(ll i=0; i<n; i++) cin>>a[i];
   vll b;
   vector<bool> seen(32,false);
 //  unordered_set<ll>b;
   for(ll i=0; i<q; i++){
      ll x; cin>>x;
 //    b.insert(x);
 if(!seen[x]){
   seen[x] = true;
   b.pb(x);
 }
   }
   for(ll i=0; i<n; i++){
      for(auto j : b){
         ll t = 1 << j;
         if(a[i] % t == 0) a[i]+= (1 << (j-1));
      }
   }
   for(ll i=0; i<n; i++) cout << a[i] << " ";
   cout << endl;
}

void solve7(){
//    ll n,x; cin>>n>>x;
//    vll a(n); for(ll i=0; i<n; i++) cin>>a[i];
//    ll w=0;
//    ll h=1;
//    ll low=0, high = 2e9;
//  //  ll ans=0;
//    while(low<high){
//       ll mid= low + (high - low)/2;
//       ll amount=0;
//    for(ll i=0; i<n; i++){
//       if(a[i] < mid) {
//         amount += (h-a[i]);
//       }
//    }
//    w+= amount;
//    if(w<=x) {
//       h = mid;
//       low = mid + 1;
//    } 
//    else if(w > x) high = mid-1;
//    }

   ll n,x; cin>>n>>x; 
   vll a(n);
   for(ll i=0; i<n; i++) cin>>a[i];
    ll st = 1, end = 2e9;
    ll ans=0;
    while(st <= end){
      ll mid = st+ (end - st)/2;
      ll w=0;
      ll amount=0;
      for(ll i=0; i<n; i++){
         if(a[i]<mid) amount+= (mid - a[i]);
      }
      if(amount <= x){
         ans = mid;
         st = mid+1;
      }
      else if(amount > x) end = mid-1;
    }
    cout << ans << endl;

}

void solve8(){
   ll n, k, a, b; cin >> n >> k >> a >> b;
   vpll v(n);
   for(ll i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
   
   ll ca = abs(v[a-1].first - v[b-1].first) + abs(v[a-1].second - v[b-1].second);
   if(k == 0) { cout << ca << endl; return; }

   ll d1 = LLONG_MAX, d2 = LLONG_MAX;
   for(ll i = 0; i < k; i++){
      d1 = min(d1, abs(v[a-1].first - v[i].first) + abs(v[a-1].second - v[i].second));
      d2 = min(d2, abs(v[b-1].first - v[i].first) + abs(v[b-1].second - v[i].second));
   }
   
   cout << min(ca, d1 + d2) << endl;
}

void solve9(){
   ll n,c; 
   cin>>n>>c;
   ll t0=0,t1=0;
   for(ll i=0; i<n; i++){
      ll x; cin>>x;
      t0 += x;
      t1 += (x*x);
   }
   ll st=1, end = 2e9;
   while(st <= end){
      ll mid = st + (end - st)/2;
      // long double xyz = (long double) n * mid*mid  + (long double)2 * mid*t0;
      // long double target = (long double)(c-t1);

      long double xyz = 4.0L*n*mid*mid + 4.0L*t0*mid;
      long double target = (c-t1);

      if(xyz == target){
         cout << mid << endl;
         return;
      }
      else if (xyz > target) end = mid-1;
      else if ((xyz ) < target) st = mid+1;
   }
   
}

void solve10(){
   ll n,x; cin>>n>>x;  
   vll p[3];
   for(ll i=0; i<3; i++){
      ll a=0;
      p[i].pb(a);
       for(ll j=0; j<n; j++){
         ll b; cin>>b;
         if((a|b) != a) {
            a |= b;
            p[i].pb(a);
         }
       }
   }

   bool ans = false;

   for(ll  a0 :p[0]){
      for(ll b0 : p[1]){
         for(ll c0 : p[2]){
            if((a0 | b0 | c0) == x) ans = true;
         }
      }
   }

   cout << (ans ? "YES\n" : "NO\n");
}

 int main(){
   fast;
    ll T;
    T=1;
     cin>>T;
    while(T--){
        solve10();
    }
    return 0;
 }