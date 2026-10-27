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
   ll a,b; cin>>a>>b;
   ll xk, yk , xq,yq; cin>>xk>>yk>>xq>>yq;
   set<pair<ll,ll>>k;
   set<pair<ll,ll>>q;
   // k.pb({(xk-a),(yk-b)});
   // k.pb({(xk+a),(yk+b)});
   // k.pb({(xk-a),(yk+b)});
   // k.pb({(xk+a),(yk-b)});
   // q.pb({(xq-a),(yq-b)});
   // q.pb({(xq+a),(yq+b)});
   // q.pb({(xq-a),(yq+b)});
   // q.pb({(xq+a),(yq-b)});
   ll dx[] = {a, a , -a, -a, b, b, -b, -b};
   ll dy[]= {b, -b, b, -b, a, -a, a, -a};

   for(ll i=0;i<8;i++){
      k.insert({xk+dx[i], yk+dy[i]});
      q.insert({xq+dx[i], yq+dy[i]});

   }

   map<pair<ll,ll>,ll>freq;

   for(auto p: k) freq[p]++;
   for(auto p: q) freq[p]++;
   
   ll ans=0;
   for(const auto&p : freq){
      if(p.second==2){
         ans++;
      }
   }
    cout<< ans << endl;
 }

 void solve2(){
    ll n,k; cin>>n>>k;
    string s; cin>>s;
    vector<ll>freq(26,0);
    for(ll i=0;i<n;i++){
        freq[s[i]-'a']++;
    }
      ll odd=0;
      for(ll i=0; i<26; i++){
         if(freq[i]%2 !=0) odd++;
      }
      if(odd <= k) cout<<"YES\n";
      else if(odd == k+1) cout<<"YES\n";
      else cout<<"NO\n";
      
 }
 void solve3(){
   ll n,k,x; cin>>n>>k>>x;
   ll small=0, large=0;
   small = (k*(k+1))/2;
   large = (k*(2*n - k +1))/2;
   if((x>=small) && (x<= large)) cout<<"YES\n";
   else cout<< "NO\n";
 }
 void solve4(){
   ll a, b, n; cin>>a>>b>>n;
   vector<ll>x(n); for(ll i=0; i<n; i++) cin>>x[i];
   ll life=b-1;
    b = 1;
    for(ll i=0; i<n; i++){
      b= min (b+x[i],a);
      life += (b-1);
      b=1;
    }
    cout<< life+1 << endl;
 }

 void solve5(){
   ll n; cin>>n;
   vector<ll>a(n); ll x =0;
   for(ll i=0; i<n; i++) {
      cin>>a[i];
      x = (x^a[i]);
   }
   if(n%2==0){
      cout<< 2 << endl;
      cout<< 1 <<" "<< n << endl << 1 <<" "<< n << endl;
   }
   else {
      cout<< 4 << endl;
      cout<< 1 <<" "<< n-1 << endl<< 1 <<" "<< n-1 << endl;
      cout<< n-1 <<" "<< n << endl << n-1 <<" "<< n <<endl;
   }
   
 }
 // BRUTE FORCE BUT STILL WRONG SOMEHOW SOMEWHERE
 void solve6(){
   ll n; cin>>n;
   ll count1=1, count2=1;
   ll s1=1, s2=1;
   for(ll i=1; i*i<=n; i++){
      
    if(n%i==0){
      if(n%(i+1) == 0){
        s1++;
      count1 = max(count1, s1);

      ll p = n/i;
      if(n%p==0){
         s2++;
         count2 = max(count2, s2);
      }
      } else s1=1, s2=1;
       
    }
   }
   cout<< max(count1, count2)<<endl;
 }

 void solve6Optimal(){
   ll n; cin>>n;
   ll i=1; 
   // while(i<=40){
   //    if(n%i == 0) i++;
   //    else break;
   // }
   while(true){
      if(n%i == 0) i++;
      else break;
   }
   cout<< i-1 << endl;
 }

 

 void solve7(){
   ll n; cin>>n; ll k; cin>>k;
   vector<ll>a(n); for(ll i=0; i<n; i++) cin>> a[i];
   sort(a.begin(), a.end());
   ll max_valid=1, current=1;
   for(ll i=1; i<n; i++){
      if((a[i]-a[i-1])<=k ){
         current++;
         max_valid=  max(max_valid , current);
      } else {
         
         current=1;
      }
   }
   max_valid = max (max_valid, current);
   cout<< n-max_valid << endl;
 }
 void solve8(){
   ll n; cin>>n ; 
   string s; cin>>s;
   // unordered_map<ll,ll>freq;
   // ll val = n;
   // freq[val]=1;
   // for(ll i=0; i<n; i++){
   //   if(s[i] == '<'){
   //    val++;
   //    freq[val]++;
   //   }
   //   else{
   //    val--;
   //    freq[val]++;
   //   }
   // }
   // cout<< freq.size() << endl;

   ll current=1, maxi = 1;
   for(ll i=1; i<n; i++){
      if(s[i]==s[i-1]){
         current++;
         maxi = max (maxi, current);
      } else current = 1;
   }
   maxi = max (maxi , current);
   cout<< maxi+1 << endl;
 }

 void solve9(){
   ll n; cin>>n;
   vector<ll>p(n); for(ll i=0; i<n; i++) cin>>p[i];
   ll k = abs(p[0]-1);
   for(ll i=1; i<n; i++){
      k = __gcd(k, abs(p[i]-(i+1)));
   }
   cout<< k << endl;
 }

 void solve10(){
ll n,q; cin>> n >>q;
vector<ll>a(n+1),pf(n+1);
pf[0]=0;
 for(ll i=1;i<=n;i++){
    cin>>a[i];
    pf[i]=pf[i-1]+a[i];
 }
 
   while(q--){
      ll l,r,k; cin>>l>>r>>k;
      ll sum=pf[n] - (pf[r]-pf[l-1])  + (r-l+1)*k;
      if(sum%2 != 0) cout<<"YES\n";
      else cout<< "NO\n";
   }
 }

 void solve11(){
   ll n; cin>>n;
   vector<ll>a(n); 
   for(ll i=0; i<n; i++) {
      cin>>a[i];
      if(a[i]==1) a[i]++;
   }
   for(ll i=1; i<n; i++){
      if(a[i]%a[i-1] == 0) a[i]+=1;
   }
   for(ll i=0; i<n; i++) cout<<a[i]<<" ";
   cout<<endl;
   
 }
 void solve12(){
   ll n; cin>>n;
   vector<ll>a(n);

   for(ll i=0; i<n; i++){
      cin>>a[i];
   }
   // ll act = a[n-1]-a[0];
   // ll sec;
   // if(a[n-2]>a[n-1]) sec = a[n-2]-a[0];
   // ll third = a[n-1]-mini;
   // ll fourth = a[n-1]-a[n-2];
   // cout << max (max (act,fourth) , max (sec, third))<<endl;
   ll alt1,alt2=INT_MIN,alt3=INT_MIN,alt4=INT_MIN;
   alt1=a[n-1]-a[0];
   for(ll i=1; i<n; i++){
    alt2 = max(alt2, (a[i]-a[0]));
   }
   for(ll i=0; i<n-1; i++){
      alt3 = max (alt3, (a[n-1]-a[i]));
   }
   for(ll i=0; i<n-1 ; i++){
      alt4 = max (alt4 , (a[i]-a[i+1]));
   }
   cout << max (max(alt1 , alt2), max(alt3,alt4))<<endl;
 }

 void solve13(){
   ll n; cin>>n;
   vector<ll>a(n);
   ll count=0;
   bool flag = false;
  for(ll i=0; i<n; i++){
   cin>>a[i];
   if(a[i] >0){
      if(!flag){
         count++;
         flag = true;
      } 
   } else flag = false;
  }

  // Another method for counting intervals
//   for(ll i=0; i<n; i++){
//    if(a[i]!=0){
//       if(i==0 || a[i-1]==0){
//          count++;
//       }
//    }
//   }
//   cout<< count << endl;

  if(count==0 || count ==1) cout << count << endl;
  else cout << 2 << endl; 
 }

 void solve14(){
   ll n; cin>>n;
   ll x,y;

     if(n<4 ||  n%2 !=0){
      cout <<"-1"<<endl;
      return;
   }

   for(ll i=0; i<=100000; i++){
      if((n- 6*i)%4==0) {
         y = (n - 6*i)/4;
           y += i;
         break;
      }
   }
   for(ll i=0; i<=1000000; i++){
      if((n- 4*i)%6==0) {
         x = (n - 4*i)/6;
         x += i;
         break;
      }
   }
   // another optimal solution in O(1) TC
   // x = (n+5)/6; (minimum)
   // y = n/4;   (maximum)
 
   cout << x << " " << y << endl;
 }

 void solve15(){
   ll n; cin>>n;
   vector<ll>a(n); for(ll i=0; i<n; i++) cin>>a[i];


   if(n==1){ cout<< "0"<<endl; return;}

   // bool poss = true;

   // for(ll i=n-1; i>=1; i--){

   //   if(a[i]<= a[i-1]){
   //    while(a[i]<a[i-1] && a[i-1]>0){
   //       a[i-1]/=2;
   //       ans++;
   //    }
   //   }
   // } 
   //    cout<<endl;
   //    for(ll i=0; i<n; i++) cout<<a[i]<<" ";
   //    cout<<endl;
   //    cout<<ans<<endl;
   //  else cout <<"-1"<<endl;

     ll ans=0;
     for(ll i=n-2; i>=0; i--){
      while(a[i]>=a[i+1]){
         ans++;
         a[i]/=2;
         if(a[i]==0) break;
      }
      if(a[i]==0 && a[i+1]==0){
         ans = -1;
         break;
      }
     }
     cout<< ans << endl;
 }

//  void solve16(){
//    string s,t;
//    cin>>s>>t;

//    if(t.size()>s.size()){
//       cout<<"NO\n";
//       return;
//    }


//    ll store=-1;
  

//    for(ll j=t.size()-1; j>=0; j--){
//       for(ll i=s.size()-1; i>=0; i--){       
//       if(s[i]==t[j]){
//          store=i;
//          break;
//       }
//       }
//    }
//    if(store== -1){ cout<<"NO\n"; return;}

//    ll j = t.size()-2;
//     bool poss = true;

//    for(ll i=store-1; i>=0; i--){

//     if(s[i]==t[j] && i<store){

//        for(ll k =store; k<s.size(); k++){
//          if(s[k]==s[i]){
//             poss = false;
//             break;
//          }
//        }

//         store = i;
//     }
//     j--;
//    }
//    if(poss) cout<<"YES\n";
//    else cout<< "NO\n";
//  }

void solve16(){
   string s,t;
   cin>>s>>t;
   ll n= s.size();
   ll m= t.size();

   vector<ll>v(26,0);

   for(ll i=0; i<m; i++){
      v[t[i]-'A']++ ;
   }
   for( ll i = n-1; i>=0; i--){
      if(v[s[i]-'A']>0) v[s[i]-'A']--;
      else s[i]='.';
   }
   string ans="";
   for(ll i=0; i<n; i++){
      if(s[i]!='.') ans += s[i];
   }
   if(ans==t) cout<<"YES\n";
   else cout<<"NO\n";
}

void solve17(){
   ll n; cin>>n;
   unordered_map<ll,ll> freq;
   vector<ll>a(n);
      ll most=a[0];
     for(ll i=0; i<n; i++){
      ll x; cin>>x;
      freq[x]++;
      if(freq[x] > freq[most]) most = x;
      a[i]=x;
     }

   //   bool all_same = (adjacent_find(a.begin(), a.end(), not_equal_to<ll>()) == a.end());
   // if(n==1 || all_same){
   //    cout<<"0"<<endl;
   //    return;
   // }

   // ll ans=0;

//  for(ll i=0; i<n; i++){
//    if(a[i]!=most){
//       ll x = most;
//     ans++;
//     x--;
//     if(x==0){
//       x = 2*most;
//     }
//    }
//  }

// ll y = n - freq[most];
// ans += freq[most];
// while(y > freq[most]) {
//    ans++;
//    y -= freq[most];
//    ans += freq[most];
//    freq[most] *= 2;
// }
// if(y<=freq[most]){
//    ans += y;
// }
// cout<<ans<<endl; 
// ll curr = freq[most];
// while(curr<n){
//    ans++;
//    if(curr*2 <=n){
//       ans += curr;
//       curr *= 2;
//    } else {
//       ans += (n-curr);
//       curr = n;
//    }
// }
// cout << ans << endl;
ll ans=0;
ll curr = freq[most];
while(curr<n){
   ans++;
   if(curr*2 <= n){
      ans += curr;
      curr *= 2;
   } else {
      ans += n-curr;
      curr = n;
   }
}
cout << ans << endl;
}

void solve18(){
   ll a,b,c;
   cin>> a>>b>>c;
   if((a==b && b==c) || (a+c == 2*b)){
      cout << "YES\n";
      return;
   }  
   bool m1 = (2*b - c >0) && ((2*b-c)%a == 0);
   bool m2 = (2*b - a >0) && ((2*b - a)%c ==0);
   bool m3 = ((a+c)%2 == 0) && (((a+c)/2)%b == 0);
   // if((2*b - c)%a ==0  || (2*b - a)%c ==0 || (a+c)%(2*b)==0) cout <<"YES\n";
   // else cout << "NO\n";
   if(m1 || m2 || m3) cout <<"YES\n";
   else cout <<"NO\n";
} 

void solve19(){
   ll x, n;
   cin>>x>>n;
   ll ans=0;
   if(x%2 !=0){
      if(n%4 == 1) ans= x+n;
      else if (n%4 == 2) ans = x-1;
      else if(n%4 == 3) ans = x-n-1;
      else if (n%4 == 0) ans = x;
   } else {
      if(n%4 == 1) ans= x-n;
      else if (n%4 == 2) ans = x+1;
      else if(n%4 == 3) ans = x+n+1;
      else if (n%4 == 0) ans = x;
   }
   cout << ans << endl;
}

void solve20(){
   string s;
   cin>>s;
   // ll cnt=1, min_length=0;
   // for(ll i=1; i<s.size(); i++){
   //    if(s[i]!=s[i-1]) cnt++;
   // }
   // if(cnt %2 !=0) { cout<<s<<endl; return; }

   if(s[0]==s[s.size()-1]){
      cout << s << endl;
   } else {
      if(s[0]=='a') s[0]='b';
      else s[0]='a';
      cout<< s << endl;
   }
}
// 21 SUBPART 
ll min_op(string s, string poss_val){
   ll op=0;
   ll idx = poss_val.size()-1;
   for(ll i=s.size()-1; i>=0; i--){
      if(s[i]==poss_val[idx]){
         idx--;
         if(idx<0) break;
      } else op++;
   }
    if(idx>=0) op = INT_MAX;
      return op;
}
void solve21(){
   string s;
   cin>>s;
 vector<string> poss = {"00", "25", "50", "75"};
 ll ans = INT_MAX;
 for(ll i=0; i< poss.size(); i++){
   ans = min(ans , min_op(s, poss[i]));
 }
   cout << ans << endl;
  }

  void solve22(){
   ll n; cin>>n;
   vector<ll>a(n);
   ll cnt0=0, cnt1=0;
   for(ll i=0; i<n; i++){
      cin>>a[i];
      if(a[i]==0) cnt0++;
      else if (a[i]==1) cnt1++;
   }
   // if(cnt0 != 0) cout << cnt1 * cnt0<< endl;
   // else cout<< cnt1 << endl;
   double ways = (1<<cnt0) * cnt1 ;
   cout<<  ways << endl;
    
}

void solve23(){
   ll n; cin>>n;
   vector<ll>a(n);
   for(ll i=0; i<n; i++) cin>>a[i];
   ll ans=a[0];
   for(ll i=1; i<n; i++){
      ans = (ans & a[i]);
   }
   cout<< ans << endl;
}

void solve24(){
   ll a,b;
   cin>>a>>b;
   if(a==b){
      cout <<0<<" "<<0<<endl;
      return;
   }
   ll g = abs(a-b);
   cout<< g <<" "<< min( b%g, g-(b%g)) <<endl;
}

void solve25(){
   ll n,m,i,j; cin>>n>>m>>i>>j;
    cout << 1 <<" "<<1 <<" "<< n << " "<<m<<endl;
}

void solve26(){
   ll n; cin>>n;
     while(n%2 == 0){
      n/=2;
     }
     if(n==1) cout<<"NO\n";
     else cout<<"YES\n";
}

void solve27(){
   ll n,x;
   cin>>n>>x;
   vector<ll>a(n);
   ll max_beauty=0, min_beauty=0;
   for(ll i=0; i<n; i++){
       cin>>a[i];
       max_beauty += (a[i]+x-1)/x;
       min_beauty += a[i];
   }
   cout<< (min_beauty+x-1)/x <<" "<<max_beauty << endl;
}

void solve28(){
   ll n,k; cin>>n>>k;
   ll size = n*k;
   vector<ll>a(size);
   for(ll i=0; i<size; i++){
      cin>>a[i];
   }
   sort(a.begin(), a.end());
   ll ans = 0;
   ll key = n*k;
   while(k--){
      key -= (n/2 +1);
      ans += a[key];
   }
   cout << ans << endl;
}

void solve29(){
   ll n; cin>>n; 
   vector<ll>p(n);
   for(ll i=0; i<n; i++) cin>>p[i];
   // ll pi = p[0];
   ll x,y,z;
   x=y=z=0;
   bool poss = false;
   for(ll i=1; i<n-1; i++){
    ll  pi_1 = p[i-1];
      if(p[i]>pi_1 && p[i]>p[i+1]){
          poss = true;
          x = i;
          y = i+1;
          z = i+2;
          break;
      }
      // pi = p[i];
   }
   if(poss) cout << "YES\n" << x <<" "<< y <<" "<< z << endl;
   else cout << "NO\n";
} 

void solve30(){
   string s;
   cin>>s;
   ll cnt_0=0, cnt_1=0;
   for(ll i=0; i<s.size(); i++) {
      if(s[i]=='0') cnt_0++;
      else cnt_1++;
   }
   ll mn = min(cnt_0, cnt_1);
   if(mn % 2 != 0) cout<<"DA\n";
   else cout << "NET\n";
}

void solve31(){
   ll n; cin>>n;
   if(n==1) {
      cout<<"0\n";
      return;
   }

   ll cnt2=0, cnt3=0;
   while(n%2 == 0) {
      cnt2++;
      n /= 2;
   }
   while(n%3 == 0){
      cnt3 ++;
      n /= 3;
   }
   if(n>1 || cnt2 > cnt3) cout<<"-1\n";
   else cout<<(cnt3 - cnt2) + cnt3 << endl;
   // ll n2=0, n3=0, dup=n;
   // while(dup != 1){
   //    if(dup%2==0){
   //       n2++;
   //       dup /= 2;
   //    }else if (dup % 3 == 0){
   //       n3++;
   //       dup /= 3;
   //    }
   // }
   // dup = n;
   // ll op = 0;
   // if(n2==n3) {
   //    dup /= (6*n2);
   //    op = n2;
   // }
   // else if (n2>n3) dup = -1 ; // false = -1
   // else if (n2 < n3){
   //    op = (n3 - n2)+ n3;
   //    dup /= (6*n3);
   // }

   // if(dup == 1) cout<< op << endl;
   // else cout << "-1\n";
}

 int main(){
   fast;
    ll T;
    T=1; 
    cin>>T;
    while(T--){
     solve31();
    }
    return 0;
 }