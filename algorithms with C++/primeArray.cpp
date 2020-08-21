#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define RepP(i,n) for(int i = 1; i <= (n); i++) //Repeat Pascal style
#define RepdP(i, n) for(int i = n; i > 0; i--) //Repeat backward Pascal style
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define el "\n"

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }

const ld PI = acos(-1.0);
const ld eps = 1e-9;
const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const ll mod = (ll)1e9 + 7;
const int maxn = 10005;
const int MX = 1e5 + 7;

#define TEST
ll primes[MX]; int max_prime = 1e5;
bool is_primes[MX];
void setup_prime_array(){
    int pid = 1;
    is_primes[1] = false;
    For(i,2,max_prime) is_primes[i] = true;
    For(i,2,max_prime){
        if(is_primes[i]){
            primes[pid] = i; pid ++;
            for(int j = 2 * i; j <= max_prime; j += i)
                is_primes[j] = false;
        }
    }
}
bool is_prime(ll n){
    if(n < 2) return false;
    if(n < 4) return true;
    int m = sqrt(n);
    if(n % 2 == 0) return false;
    if(n % 3 == 0) return false;
    if(n >= 25){
        for(int i = 5; i<= m; i+=2){
            if(n % i == 0) return false;
        }
    }
    return true;
}
int numberOfDivisor(ll n){ //ham tim so uoc cua so nguyen n ~ 1e12; khong su dung void setCP()
    if(n == 1) return 1;
    int dem, ans = 1;
    for(int i = 1; p[i] * p[i] <= n && i < cnt; i++){
        dem = 0;
        while(n % p[i] == 0){
            dem ++;
            n /= p[i];
        }
        ans *= (dem + 1);
        if(n == 1) return ans;
    }
    return 2 * ans;
}
//======================================================
int N = 510510;
vi v; bool b[MX]; int p[] = {1, 2, 3, 5, 7, 11, 13, 17};
void fast_isPrime(){
  For(i,1,7) for(int j = p[i]; j <= N; j += p[i]) b[j] = 1;
  For(i,18,N) if(!b[i]) v.pb(i);
  v.pb(N + 1);
}
bool isPrime(ll n){   //this is for big number ~1e18
    if(n == 1) return false;
    For(i,1,7) if(n == p[i]) return true;
    For(i,1,7) if(n % p[i] == 0) return false;
    ll k = sqrt(n);
    For(i,0,sz(v) - 1){
        for(ll j = ll(v[i]); j <= k; j += N) if(n % j == 0) return false;
    }
    return true;
}
//==========================================================
// FAST CHECK PRIME NUMBER
ll mul(ll a, ll b, ll &m){
    if(a==0) return 0;
    ll t=mul(a/2,b,m);
    t=t*2%m;
    if(a&1) t=(t+b)%m;
    return t;
}

ll mpow(ll base, ll n, ll &mod){
    if(n==0) return 1;
    ll t=mpow(base,n/2,mod);
    t=mul(t,t,mod);
    if(n&1) return mul(t,base,mod);
    return t;
}

bool isPrime(ll n){
    for(int r=0; r<2000; ++r){
        int v=rand()+1;
        while(v==n) v=rand()+1;
        if(mpow(v,n-1,n)>1){
            return 0;
        }
    }
    return 1;
}
int main(){
	#ifdef TEST
		freopen("in.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false);


    setPrimeArray();
    cout << cnt << el;
    For(i,5,100) cout << p[i] << el;
    if(isPrime(1e8 + 7)) cout << "yes" << el;
    else cout << "no" << el;



	return 0;
}
