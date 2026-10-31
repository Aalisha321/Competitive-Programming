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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll MOD = 1e9 + 7;

 void solve1(){
    ll n,k; cin>>n>>k;
    vector<ll>a(n); for(int i=0;i<n;i++) cin>>a[i];
   vector<ll>b = a;
    sort(b.begin(), b.end());
    if(a==b) {
        cout<<"YES\n";
        return;
    }
    if(k==1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
 }

 void solve2(){
    ll n,x; cin>>n>>x;
    vector<ll>a(n); for(ll i=0;i<n;i++) cin>> a[i];
    ll d= a[0];
    for(ll i=1;i<n;i++){
         d = max(d, a[i]-a[i-1]);
    }
    d= max(d, 2*(x-a[n-1]));
    cout<< d << endl;
 }

 void solve3(){
    ll n; cin>>n; string s; cin>>s;
    bool cons3 = false;
    ll countdot=0;
    for(ll i=1;i<n-1;i++){
      if( s[i-1]=='.' && s[i]=='.' && s[i+1]=='.'){
        cons3 = true;
      }
    }
    for(ll i=0;i<n;i++){
        if(s[i]=='.') countdot++;
    }
    if(cons3) cout<< 2 << endl;
    else cout<< countdot << endl;
 }

 void solve4(){
    ll n; cin>>n;
    if(n%3 == 0) cout<< "Second"<< endl;
    else cout<< "First"<<endl;
 }

 void solve5(){
    ll n; cin>>n;
    vector<ll>a(n); for(ll i=0; i<n; i++) cin>>a[i];
  if(a[0]==1) cout<< "YES\n";
  else cout<< "NO\n";
 }

 void solve6(){
    ll n; cin>>n;
    map<ll,ll>occ;
     for(ll i=0;i<n;i++){
        int x;
         cin>>x;
         occ[x]++;
     }
     if(occ.size()>=3) puts("NO");
     else{
        if(abs(occ.begin()->second - occ.rbegin()->second) <=1){
            puts("YES");
        } else{
            puts("NO");
        }
     }
 }

 void solve7(){
   ll n,m; cin>>n>>m;
   string x,s; cin>> x >> s;
   int count=0;
   for(ll i=0; i<=5; i++){
    if(x==s){
      cout<< count<<endl;
      return;
    }
   }
 }
 void solve7m2(){
      ll n,m; cin>>n>>m;
   string x,s; cin>> x >> s;
   for(int i=0; i<6; i++){
      if(x.find(s) != string::npos){
         cout<<i<<endl;
         return;
      }
      x+=x;
   }
   cout<< -1 << endl;
 }


 void solve8(){
   ll n,k; cin>> n>> k;
   vector<ll>a(n);  for(ll i=0;i<n;i++) cin>> a[i];
   for(ll i=0;i<n;i++){
      if(a[i]==k){
         cout<< "YES\n";
         return;
      }
   }
   cout<< "NO\n";
 }

 void solve9(){
   ll n; cin>>n;  ll sum=0;
   for(ll i=0;i<n-1;i++){
     ll x; cin>> x;
     sum+= x;
   }
   cout<< (-1)*sum << endl;
 }

 void solve10(){
   string s[10]; for(ll i=0;i<10;i++) cin>>s[i];
   ll point=0;
   for(ll i=0;i<10;i++){
      for(ll j=0;j<10; j++){
        if(s[i][j]=='X'){
         ll min_dis=min({i,9-i,j,9-j});
         point += (min_dis+1);
          
        }
      }
   }
   cout<< point << endl;
 }

 void solve10m2(){
   int score[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int ans=0;
for(ll i=0;i<10;i++){
   for(ll j=0;j<10;j++){
      char c;
      cin>> c;
      if(c=='X') ans += score[i][j];
   }
}
cout<< ans << endl;

 }

 void solve11(){
   ll n; cin>> n;
   vector<ll>a(n); 
   for(ll i=0;i<n;i++){
      ll x;
      cin>> x;
      x = abs(x);
     a[i]=x;
   }
   ll find = *min_element(a.begin(), a.end());
   cout<< find<< endl;
 }

 void solve12(){
   ll n; cin>>n;
   vector<ll>b(n),a; for(ll i=0;i<n;i++) cin>>b[i];
   a.pb(b[0]);
   ll j=0;
   for(ll i=1;i<n;i++){
      a.pb(b[i]);
      j++;
      if(a[j]< a[j-1]){
         a.pb(a[j]);
         j++;
      }
   }
   cout<< a.size()<<endl;
   //cout<<j<<endl;
   for(ll i=0;i<a.size();i++) cout<< a[i]<<" ";
   cout<< endl;
 }

 void solve13(){
   ll n; cin>>n; vector<ll>a(n);
   ll max_el = INT_MIN;
   for(ll i=0;i<n;i++){
      ll x; cin>>x;
      max_el = max(max_el, x);
      a[i]=x; 
   }
   bool all_equal = equal(a.begin()+1, a.end(), a.begin());
   if(all_equal){
       cout<< -1 << endl;
       return;
   } else{
      vector<ll>b,c;
      for(ll i=0;i<n;i++){
         if(a[i] != max_el){
            b.pb(a[i]);
         } else c.pb(a[i]);
      }
      cout<< b.size() <<" "<< c.size() << endl;
      for(ll i=0; i<b.size(); i++) cout<< b[i]<<" ";
      cout<< endl;
      for(ll i=0; i<c.size(); i++) cout<< c[i]<<" ";
      cout<< endl;
   }
 }

 void solve14(){
   ll a,b,c; cin>> a>>b>>c;
    ll k = (c/2);
    ll an  = (c-k)+a;
    k+= b;
    if(an>k) cout<< "First\n";
    else if (k > an) cout<< "Second\n";
    else if (k == an) cout<< "Second\n";
 }

 void solve15(){
  ll n; cin>>n; 
  if(n==1){
   cout<< "NO\n";
   return;
  } ll count=0;
  for(ll i=0;i<n;i++){
   ll x; cin>>x;
    if(x%2 !=0) count++;
  }
  if(count%2 == 0) cout<< "YES\n";
  else cout<< "NO\n";
 }

 void solve16(){
   ll n; cin>>n;
   vector<ll>a(n); for(ll i=0;i<n;i++)cin>>a[i];
   vector<ll>b=a;
   sort(b.begin(), b.end());
   ll diff = INT_MAX;
   if(b==a){
      // if(n==2){
      //    cout<< 1 << endl;
      //    return;
      // }
     for(ll i=1;i<n;i++){
      diff = min(diff, (a[i]-a[i-1]));
     }
        cout<< (diff)/2 + 1<< endl;
        return;
   } 
   cout<< "0"<<endl;

 }

 void solve17(){
   ll n,k,x; cin>> n>> k >> x;
   if((k==1 && x==1) || (n%2 != 0 && k==2 && x==1) ){
      cout << "NO\n";
      return;
   }
   cout << "YES\n";
   if(x != 1){
     cout << n << endl;
     for(ll i=0; i<n; i++) cout << "1 ";
     cout << endl;
   }else {
      if(n %k != 1){
      ll d=n/k;
      if(n%k != 0) cout << d+1 << endl; else cout<< d << endl;
      for(ll i=0; i<d; i++) cout << k << " ";
      if(n%k != 0) cout << n%k;
      cout << endl;
      } else {
      ll d=n/k;
      if(n%k != 0) cout << d+1 << endl; else cout<< d << endl;
      for(ll i=0; i<d-1; i++) cout << k << " ";
      cout << k-1 << " "<< 2 << endl;
      }
      

   }
 }
 
 void solve18(){
   ll x,k; cin>>x>>k;
   if(x % k != 0) {
      cout << 1 << endl;
      cout << x << endl;
   } else {
      cout << "2\n";
      cout << x-1 << " 1" << endl;
   }
 }

 void solve19(){
   ll c=0,n; cin>>n;
   for(ll i=0; i<n; i++){
      ll x;
      cin>>x;
      if(x == -1) c++;
   }
   ll ans=0;
   while(c > n/2){
       ans++;
       c--;
   }
   if(c%2 != 0) ans++;
   cout << ans << endl;
   // if(c%2 == 0){
   //    if(c <= n/2) cout << "0\n";
   //    else cout << c-n/2 << endl;
   // } else {
   //    if(c <= n/2) cout << "1\n";
   //    else {
   //       if(n%2 == 0) cout << c -  n/2 << endl;
   //       else 
   //    }
   // }
 }

 void solve20(){
   ll n,m=0; cin>>n;
   vll a(n);
   for(ll i=0; i<n; i++) {
      cin>>a[i];
      if(a[i] >= m) m=a[i];
   }
   for(ll i=0; i<n; i++){
      cout << m+1-a[i] << " ";
   } cout << endl;
 }

 void solve22(){
   ll n,k; cin>>n>>k;
   if(n%2 == 0) cout << "YES\n";
   else {
      if(k%2 == 0) cout << "NO\n";
      else cout << "YES\n";
   }
 }

 void solve23(){
   ll a,b,c,d;
   cin>>a>>b>>c>>d;
   if(d < b ) {
      cout << "-1\n";
      return;
   }
    if((d-b) >=0 ){
    if(c > a+d-b) {
      cout << "-1\n";
      return;
    }
    else cout << (d-b)+a+d-b-c << endl;
   }
 }

 void solve24(){
   ll n; cin>>n;
   ll t=0;
   for(ll i=0; i<n; i++){
       ll x; cin>>x;
       t = (t^x);
   }
   if(n%2 == 0){
      if(t==0) cout << "0\n";
      else cout << "-1\n";
      return;
   }
   cout << t << endl;
 }

 void solve25(){
   ll n; cin>>n; string s; cin>>s;
   if(n==0 || n==1){
      cout << n << endl;
      return;
   }
   ll ans=0;
   ll i=0, j=n-1;
   while(i<j){
      if(s[i] != s[j]){
         ans++;
      } else break;
      i++;
      j--;
   }
   cout << n - 2*ans << endl;
 }

 void solve26(){
   ll n; cin>>n; vll a(n); 
   for(ll i=0; i<n; i++) {
      cin>>a[i];
   }
   if(n < 2) {
      cout << "NO\n";
      return;
   }
   bool poss = false;
   for(ll i=0; i<n-1; i++){
      for(ll j=i+1; j<n; j++){
        if(__gcd(a[i], a[j]) <= 2) {
         poss = true;
         break;
        }
      }
   }
   if(poss) cout << "YES\n";
   else cout << "NO\n";
   
 }

  void solve30(){
   string s;
   cin>>s;
   ll n= s.size();
   ll ans=0;
   while(n-1>0){
     ans+= 9;
     n--;
   }
   n = s[0]-'0';
   ans += n;
   cout << ans << endl;
 }


 void solve31(){
   ll n,a,b; cin>> n>>a>>b;
   if((a+b+2 <= n) || (a==n && b==n)) {
      cout << "yes\n";
   } else{
      cout <<"No\n";
   }
 }



 int main(){
   fast;
    int T;
    T=1;
   cin>>T;
    while(T--){
     solve26();
    }
    return 0;
 }

