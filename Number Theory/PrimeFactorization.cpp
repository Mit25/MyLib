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

#define f(i,n) for(ll i=0;i<n;i++)
#define rep(i,a,b) for(ll i=a;i<=b;i++)

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
void print(vector<ll> &v){for(ll i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<"\n";}

ll mul(ll a,ll b,ll m=Mod){return (ll)(a*b)%m;}
ll add(ll a,ll b,ll m=Mod){a+=b; if(a>=m) a-=m; if(a<0) a+=m; return a;}
ll power(ll a,ll b,ll m=Mod){if(b==0) return 1; if(b==1) return (a%m); ll x=power(a,b/2,m); x=mul(x,x,m); if(b%2) x=mul(x,a,m); return x;}

vector<ll> prime,factor;
ll *pf;

void Seive(ll n){
	bool flag[n];
	f(i,n)
		flag[i]=true;
	for(ll i=2;i*i<n;i++)
		if(flag[i])
			for(ll j=2;j*i<n;j++){
				flag[j*i]=false;
				pf[j*i]=i;
			}
	for(ll i=2;i<n;i++)
		if(flag[i])
			prime.pb(i);
}

void factorization(ll n){
	while(n>1){
		factor.pb(pf[n]);
		ll tmp=pf[n];
		while(n%tmp==0)
			n=n/tmp;
	}
}

int main(){
	pf=new ll[101];
	f(i,101)
		pf[i]=i;
	Seive(101);
	ll n;sll(n);
	factorization(n);
	sort(factor.begin(),factor.end());
	print(factor);
    return 0;
}