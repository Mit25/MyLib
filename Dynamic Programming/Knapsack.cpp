#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

#define si(x) scanf("%d",&x);
#define sl(x) scanf("%ld",&x);
#define sll(x) scanf("%lld",&x);

#define pi(x) printf("%d",x);
#define pl(x) printf("%ld",x);
#define pll(x) printf("%lld",x);
#define pn printf("\n");
#define ps printf(" ");

const ll mod=1000000007ll;
const ll Mod=1000000009ll;
const ll inf=(ll)5e18;
const ld eps=1e-12;
const ll N=1000005;
const ll LOGN=19;
const ld PI=3.14159265358979323846;

#define sf(x) sort(x.begin(),x.end(),func)
#define s(x) sort(x.begin(),x.end())

#define all(v) v.begin(),v.end()
#define rs(v) { s(v) ; r(v) ; }
#define r(v) {reverse(all(v));}

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define f(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)

#define len(a) sizeof(a)/sizeof(a[0])
#define printArray(a) for(int i=0;i<length(a);i++){cout << a[i];cout << " ";}cout << endl;

template <class T>T max2(T a,T b){return a<b?b:a;}
template <class T>T min2(T a,T b){return a<b?a:b;}
template <class T>T max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T min4(T a,T b,T c,T d){return Min2(Min2(a,b),Max2(c,d));}

void print(int a[],int s,int e){for(int i=s;i<=e;i++)cout<<a[i]<<" ";cout<<"\n";}
void print(vector<int> &v,int s,int e){for(int i=s;i<=e;i++)cout<<v[i]<<" ";cout<<"\n";}
void print(vector<int> &v){for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<"\n";}

ll mul(ll a,ll b,ll m=Mod){return (ll)(a*b)%m;}
ll add(ll a,ll b,ll m=Mod){a+=b; if(a>=m) a-=m; if(a<0) a+=m; return a;}
ll power(ll a,ll b,ll m=Mod){if(b==0) return 1; if(b==1) return (a%m); ll x=power(a,b/2,m); x=mul(x,x,m); if(b%2) x=mul(x,a,m); return x;}

ll *wt,*val;

ll knapsack(vector<ll> *v,ll n,ll W){
	if(n==0)
		return 0;
	else if(W==0)
		return 0;
	else if(wt[n-1]>W){
		if(v[n-1][W]==-1)
			v[n-1][W]=knapsack(v,n-1,W);
		return v[n-1][W];
	}
	else{
		if(v[n-1][W]==-1)
			v[n-1][W]=knapsack(v,n-1,W);
		if(v[n-1][W-wt[n-1]]==-1)
			v[n-1][W-wt[n-1]]=knapsack(v,n-1,W-wt[n-1]);
		return max2<ll>(v[n-1][W],v[n-1][W-wt[n-1]]+val[n-1]);
	}
}

int main(){
	ll n,W;sll(n);sll(W);
	wt=new ll[n];val=new ll[n];
	f(i,n)
	    sll(val[i]);
	f(i,n)
	    sll(wt[i]);
	vector<ll> *v=new vector<ll>[n+1];
	f(i,n+1)
		f(j,W+1)
			v[i].pb(-1);
	pll(knapsack(v,n,W));pn;
    return 0;
}