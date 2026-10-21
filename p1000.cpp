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
    string s; cin>>s;
    ll i = 0;
    ll cnt0=0, cnt1=0;
    while(i<s.size()){
        if(s[i]=='0') cnt0++;
        else cnt1++;
        i++; 
    }
    // cout << abs(cnt0 - cnt1)<<endl;
    ll lt = 0;
    for(ll i=0; i<s.size(); i++){
        if(s[i]=='0' && cnt1 > 0){
            cnt1--;
            lt++;
        } else if(s[i]=='1' && cnt0 > 0){
            cnt0--;
            lt++;
        }
        else break;
    }
    cout << s.size()-lt << endl;
 }

 void solve2(){
 ll n,k;
 cin>>n>>k;
 vector<ll>a(n);
 for(ll i=0; i<n; i++) cin>>a[i];

 ll ans = INT_MAX;
 ll evn = 0;
 for(ll i=0; i<n; i++){
    if(a[i]%2 == 0) evn++; 
    if(a[i]%k == 0) ans=0;
     else ans = min(ans, (k - a[i] % k));
 }
  if(k==4){
    ll evns=2;
    if(evn >= 2) evns = 0;
    else if (evn == 1) evns = 1;
     ans = min(ans, evns);
  }
  cout << ans << endl;
 }

 void solve3(){
    ll n,p; cin>>n>>p;
    vector<ll>a(n),b(n);
    ll cost=p, per=n-1;
    for(ll i=0; i<n; i++) cin>>a[i];
    for(ll i=0; i<n; i++) cin>>b[i];
    // sort(b.begin(), b.end());
    vector<pair<ll,ll>>v(n);
     for(ll i=0; i<n; i++){
        v[i]={b[i],a[i]};
     }
     sort(v.begin(), v.end());
     
    for(ll i=0; i<n; i++){
        if(v[i].first<p){
            if((per - v[i].second)>=0){
                cost+= v[i].first*v[i].second;
                per -= v[i].second;
            } 
            else if(per <v[i].second){
                cost += per*v[i].first;
                per=0;
            }
          if(per == 0){
            break;
          }
        } 
    } 
    if(per > 0) cost += per*p;
    cout << cost << endl;
 }

 void solve4(){
  ll n; cin>>n;
  vector<pair<ll,vector<ll>>>v(n);
  for(ll i=0; i<n; i++){

    // cin>>v[i].first;
    // ll m = v[i].first;

    ll m;
    cin>>m;
    v[i].first = m;
    v[i].second.resize(m);

    for(ll j=0; j<m; j++){
        cin>>v[i].second[j];
    }
  }
  vector<ll>b;
  ll minim=INT_MAX, sum=0;
  for(ll i=0; i<n; i++){
    sort(v[i].second.begin(), v[i].second.end());
    b.pb(v[i].second[1]);
    sum += v[i].second[1];
    minim = min(minim, v[i].second[0]);
  }
  sort(b.begin(), b.end());
  cout << sum + minim - b[0] << endl;
 }
   
 void solve5(){
    ll n,k; cin>>n>>k;
    vector<pair<ll,ll>>a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i].first;
        if(a[i].first % k != 0) a[i].first = a[i].first % k;
        if(a[i].first % k == 0) a[i].first = k;
        a[i].second = i;
    }
    // sort(a.begin(), a.end());
    sort(a.begin(), a.end(), [](const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
        if (p1.first != p2.first) {
            return p1.first > p2.first; // Descending for 1st element
        }
        return p1.second < p2.second;   // Ascending for 2nd element
    });
     for(ll i=0; i<n; i++) cout<<a[i].second + 1<<" ";
     cout<<endl;
 }

 void solve6(){
     ll n,k,q;
     cin>>n>>k>>q;
     vector<ll>a(n);
    //  vector<ll>can;
    //  for(ll i=0; i<n; i++){
    //     cin>>a[i];
    //     if(a[i]<=q){
    //         can.pb(i+1);
    //     }
    //  }

    //  ll ans = 0;
    // //  if(can.size() <k) {
    // //      cout<<"0\n";
    // //      return;
    // //  }
    //       ll cons=0;
    //  for(ll i=1; i<can.size(); i++){
        
    //       if(can[i]==can[i-1]+1){
    //          cons++;
    //          continue;
    //       }
    //       if(cons>=k){
    //         ans+= ((cons-k+1)*(cons-k+2))/2;
    //       }

    //        cons=0;
    //  }

    //  cout<< ans << endl;
    for(ll i=0; i<n; i++) cin>>a[i];

    ll ans =0;
    ll len = 0;
    for(ll i=0; i<n; i++){
        if(a[i]<=q){
            len++;
        } else {
            if(len >= k){
                ans += ((len-k+1)*(len-k+2))/2;
            }
            len = 0;
        }
    }

    if(len >= k){
        ans += ((len-k+1)*(len-k+2))/2;
    }

    cout<< ans << endl;
      
 }

 void solve7(){
    ll n; cin>>n;
    vector<ll>a(n),b(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    for(ll i=0; i<n; i++) cin>>b[i];


    ll c=1;
    vector<ll>largea(2*n+1,0);
    vector<ll>largeb(2*n+1,0);
    for(ll i=1; i<n; i++){
        if(a[i] == a[i-1])
        c++;
        else {
          largea[a[i-1]] = max(largea[a[i-1]],c);
          c=1;
        }
    }
    largea[a[n-1]]=max(largea[a[n-1]],c);
    c=1;

    for(ll i=1; i<n; i++){
        if(b[i]==b[i-1]){
            c++;
        } else{
            largeb[b[i-1]]=max(largeb[b[i-1]],c);
            c=1;
        }
    }
    largeb[b[n-1]]=max(largeb[b[n-1]],c);
    ll maxf=-1;
    for(ll i=1; i<=2*n; i++){
      maxf = max(maxf , largea[i]+largeb[i]);
    }
    cout<< maxf << endl;
 }

 void solve8(){
    ll n;
    cin>>n;
    string st; cin>>st;
     vector<ll>p(n,0);
     vector<ll>s(n,0);
     vector<bool>seenp(26,false);
     ll unique=0;
     for(ll i=0; i<n; i++){
        ll idx = st[i]-'a';
        if(!seenp[idx]){
            seenp[idx]=true;
            unique++;
        }
        p[i]=unique;
     }

     vector<bool> seen(26, false);
    unique = 0;
    for (int i = n - 1; i >= 0; i--) {
        int idx = st[i] - 'a';
        if (!seen[idx]) {
            seen[idx] = true;
            unique++;
        }
        s[i] = unique;
    }

    ll ans=0;
    for(ll i=0; i<n-1; i++){
        ans = max(ans, p[i]+s[i+1]);
    }
    cout << ans << endl;
 }

 void solve9(){
    ll n; cin>>n;
    // cout << "1"<<" "<< n-1 << endl;
    if(n%2 == 0) {
        cout<< (n/2) << " "<< (n/2) << endl;
        return;
    }
    // for(ll i=n/2; i<=n; i++){

    // }
    ll a ,b;
    ll p =n;
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
          p=i;
          break;
        }
    }
    a = n/p;
    b = n-a;
    // a=b=n/2;
    // ll i=n/2;
    // while( a !=0 ||  b!=n){
    //  if( b %a ==0 &&  a+b == n){
    //     break;
    //  }
    //  a--;
    //  b++;
    // }
    cout << a << " "<< b << endl;
 }

 void solve10(){
    ll n ; char c; cin>>n>>c;
    string s; cin>>s; 
    string s1 = s+s;
    ll n1 = s1.size();
    ll idx=-1;
    ll maxg=0;
    for(ll i=n1-1; i>=0; i--){
        if(s1[i]=='g'){
          idx = i;
        }
        if(s1[i]==c){
            maxg = max (maxg , (idx-i));
        }
    }
    cout << maxg << endl;
 }

 void solve11(){
    ll n,d;  cin>>n>>d;
    vector<ll>a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    ll l=-1, r= n-1;
    ll team=0, teamsize=1;
    while(l<r){
        if(a[r]*teamsize  <= d  &&  l<r){
           l++;
           teamsize++; 
        } else{
            team++;
            teamsize=1;
            r--;
        }
    }

    cout << team << endl;
 }

 void solve12(){
    ll n,k,b,s;
    cin>> n>>k>>b>>s;
     vector<ll>a(n,0); 
     a[0]= k*b;
     if((s>= k*b) && (s<= k*b+ n*(k-1))){
       ll sd = s - k*b;
       for(ll i=0; i<n; i++){
        if(sd > (k-1)){
            a[i]+= (k-1);
            sd -= (k-1);
        } else if(sd <= (k-1)  &&  sd>0){
            a[i]+=sd;
            sd=0;
        } else if (sd==0) break;
       }

       for(ll i=0; i<n; i++){
        cout << a[i] << " ";
     } cout << endl;
     }
     else{
        cout << "-1\n";
     }
     
 }

 void solve13(){
    ll n,x;   cin>>n>>x;
    vector<ll>a(n);
    for(ll i=0; i<n; i++) cin>>a[i]; 
      ll change=0;

    vector<pair<ll,ll>> segments(n);
    
     for(ll i=0; i<n; i++){
        segments[i]= {a[i]-x, a[i]+x};
     }

        ll l= segments[0].first;
     ll r= segments[0].second;

     for(ll i=1; i<n; i++){
        l = max(l, segments[i].first);
        r = min(r, segments[i].second);
        if(l>r){
        change++;
        l = segments[i].first;
        r = segments[i].second;
      }
     }
        
      
     
    cout<< change << endl;

 } 

 void solve14(){
    ll n; cin>>n;
    vector<ll>s(n); for(ll i=0; i<n; i++) cin>>s[i];

    vll p(n);
    ll l=0;
    while(l<n){
        ll r=l;
        while(r<n && s[r]==s[l]) r++;
        if(r-l == 1){
            cout<<"-1\n";
            return;
        }
        for(ll i=l; i<r-1; i++) p[i]=i+2;
        p[r-1]=l+1;
        l=r;
    }
    for(ll i=0; i<n; i++) cout<<p[i]<< (i == n-1 ? "" : " ");
    cout << "\n";
 }

 void solve15(){
    ll n,k; cin>>n>>k;
    string s;
    cin>>s;

    // ********  WRONG (TLE)************
  // SLIDING WINDOW TYPE (MY GUESS)
  // BRUTE FORCE (O(N^2))
//   ll minw=k;
//   for(ll i=0; i+k-1 < n; i++ ){
//     ll w=0;
//     ll l=i;
//     ll r = i+k-1;
//     for(ll j=l; j<=r; j++){
//         if(s[j]=='W') w++;
//     }
//     minw = min (minw, w);
//   }
//   cout << minw << endl;


 //  ****** CORRECT *********
// PREFIX ARRAY SUM 
//  vll p(n+1,0);
//  for(ll i=0; i<n; i++){
//     p[i+1]=p[i]+(s[i]=='W'); 
//  }
//  ll ans=INT_MAX; 
//  for(ll i=0; i+k<=n; i++){
//   ll diff = p[i+k]-p[i];
//   ans = min ( ans , diff);
//  }
//  cout << ans << endl;


 // *******CORRECT SLIDING WINDOW APPROACH*******
ll w=0;
for(ll i=0; i<k; i++){
    if(s[i]=='W') w++;
}
ll minw=w;
    for(ll i=k; i<n; i++){
        if(s[i]=='W')w++; 
        if(s[i-k]=='W') w--;
        minw = min (minw , w);
    }
    cout << minw << endl;
 }

 void solve16(){
    ll n,r,b;
    cin>>n>>r>>b;
    // string s(n,'R');
    ll fill = r/(b+1);
    ll ext = r % (b+1);
    string ans="";
    ll i=fill;
    for(ll i=0; i<=b; i++){
        ll count = fill+(ext > 0 ? 1:0);
        ans.append(count,'R');
        if(ext > 0) ext--;
        if(i<b) ans += 'B';
    }
    cout << ans << endl;
 }

 void solve17(){
    ll n; cin>>n;
    ll t = log2(n-1);
    t = pow(2,t);
    for(ll i=t-1; i>=0; i--) cout << i << " ";
    for(ll i=t; i<n; i++) cout << i << " ";
    cout << endl;
 }
  
 void solve31(){
    ll n; cin>>n;
    string s; cin>>s;
    bool pos = false;
    ll x,y;
    for(ll i=1; i<n; i++){
        if(s[i]<s[i-1]){
            pos = true;
            x=i-1;
            y=i;
            
               break;
           
        }
    }
    if(pos) cout << "YES\n" << x+1 << " "<< y+1 << endl;
    else  cout << "NO\n";
 }

 void solve30(){
  ll n; cin>>n;
  vll a(n);
  for(ll i=0; i<n; i++) cin>>a[i];
  sort(all(a));
  for(ll i=n-1; i>=0; i--) cout << a[i]<<" ";
  cout<<endl;

//   for(ll i=0; i<n; i++){
//     cout << i - a[n-1-i] << " ";
//   } cout << endl;
 }

 void solve29(){
    ll a,b; cin>>a>>b;

    if(a==b){
        cout << 0<<endl;
        return;
    }

    ll mn = min(a,b);
    ll mx = max(a,b);

    if( mx % mn !=0) {
        cout << "-1\n";
        return;
    }

    ll t = mx/mn;
    ll cnt=0;

     while(t%2 == 0){
         cnt++;
         t/= 2;
     }

     if(t!= 1){
        cout << "-1\n";
        return;
     }

      ll op=0;
      op += cnt/3;
      cnt %= 3;

      op+= cnt/2;
      cnt%= 2;

      op+= cnt;
      cout << op << endl;

 }

 void solve21(){
    ll n; cin>>n;
    vll a(n); 
    for(ll i=0; i<n; i++) cin>>a[i];
    ll curr=0;
    ll global=0;
  //  if(a[0]==0) curr++;
    for(ll i=0; i<n; i++){
        if(a[i]==0) curr++;
        else curr=0;
        global = max (global, curr);
    }
    cout << global << endl;
 }
 void solve18(){
    ll w,h; cin>>w>>h;
    ll k; cin>>k;
    ll x1,x2;
    cin>>x1;
    for(ll i=1; i<k-1; i++){
        ll t; cin>>t;
    }
    cin>>x2;
    cin>>k;
    ll x12,x22;
    cin>>x12;
    for(ll i=1; i<k-1; i++){
        ll t; cin>>t;
    }
    cin>>x22;

    cin>>k;
    ll y1,y2;
    cin>>y1;
    for(ll i=1; i<k-1; i++){
        ll t; cin>>t;
    }
    cin>>y2;

    cin>>k;
    ll y12,y22;
    cin>>y12;
    for(ll i=1; i<k-1; i++){
        ll t; cin>>t;
    }
    cin>>y22;
    ll x = max((x2-x1) , (x22-x12));
    ll y= max((y2-y1), (y22-y12));
    cout << max (x*h , y*w) << endl;
 }

 void solve19(){
     ll n; cin>>n;
     vll a(n); for(ll i=0; i<n; i++) cin>>a[i];
     vector<pair<ll,ll>> b;
     for(ll i=0; i<n; i++) b.pb({a[i],i});
      sort(b.rbegin(), b.rend());

      vll ans(n+1,0);

      ans[0]=0;
      ll m=0;
      ll cor=1;
      for(ll i=0; i<n; i++){
        ans[b[i].second+1] = cor;
        m += (2* abs(cor)*b[i].first);
         if(cor <0) cor = abs(cor)+1;
         else cor = -cor;
      }
      cout << m << endl;
      for(ll i=0; i<=n; i++) cout << ans[i] << " ";
      cout << endl;
 }
  
 
 int main(){
    fast;
    ll T;
    T=1;
     cin>>T;
    while(T--){
        solve19();
    }
    return 0;
 }