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

#define TEST
/*
Properties
So cac so nho hon n va nguyen to cung nhau voi n
The following properties of Euler Totient Function are enough to calculate it for any number.

If p is a prime number, ϕ(p)=p−1 as gcd(p,q)=1 where 1<=q<p.
If p is a prime number and k>0, ϕ(pk)=pk−p(k−1)
If a and b are relatively prime, ϕ(ab)=ϕ(a).ϕ(b)
We can get easily Euler function for any n through factorization ( decomposing n into its prime factors ).
If

n=P1a1⋅P2a2⋅P3a3⋅…⋅Pkak where Pi are prime factors of n.

ϕ(n)=ϕ(P1a1)⋅ϕ(P2a2)⋅…⋅ϕ(Pkak)
=(P1a1−P1a1−1)⋅(P2a2−P2a2−1)⋅…⋅(Pkak−Pkak−1)
=n⋅(1−1P1a1)⋅(1−1P2a2)⋅…⋅(1−1Pkak)
*/
int phi(int n){
    int result = 1, m = sqrt(n);
    For(i,2,m){ // xet tat ca cac uoc nguyen to nho hon m
        if(n % i == 0){
            n = n / i;
            while(n % i == 0){
                n = n/i;
                result *= i;
            }
            result *= (i-1);
        }
        if(n==1) return result;
    }
    if(n > 1) result *= (n-1);
    return result;

}
int main(){
	#ifdef TEST
		freopen("in.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false);

    For(i,1,22) cout << i << " " << phi(i) << el;


	return 0;
}
