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
typedef vector<double> vd;
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
#define pf push_front
#define fi first
#define se second
#define var(a, b) typeof(b) a(b)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define last(a) (sz(a) - 1)
#define ms(a,x) memset(a, x, sizeof(a))
#define Exist(a, b) (find(all(a), (b)) != (a).end())
#define Sort(a) sort(all(a))
#define Gsort(a) sort(all(a), greater<typeof(*((a).begin()))>())
#define Unique(a) Sort(a); (a).resize(unique(all(a)) - (a).begin())
#define Enum(a) Fit(it, (a)) cout << *it << " "; cout << endl;
#define el '\n'
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define debug(x) { cout << #x << " = "; cout << (x) << endl; }

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); } //number of bit 1
template<class T> int disp(T s) { Rep(i,sz(s)) cout << s[i] << " "; cout << el; }
template<class T> int disp(T s,int n) { For(i,1,n) cout << s[i] << " "; cout << el; }
const ld PI = acos(-1.0);
const ld eps = 1e-9;
const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const ll mod = (ll)1e9 + 7;
const int MX = 1e5 + 7;
const int MAX = 15 + 7;

// paste source code========================================================
ll prime_arr[MX]; int max_prime = 5e4;
bool is_prime[MX];
ll prime_dual_sum_arr[MX];
bool is_dual_sum[MX];

void setPrimeArray(){
    int cnt = 1;
    is_prime[1] = false;
    For(i,2,max_prime) is_prime[i] = true;
    For(i,2,max_prime){
        if(is_prime[i]){
            prime_arr[cnt] = i; cnt ++;
            for(int j = 2 * i; j <= max_prime; j += i)
                is_prime[j] = false;
        }
    }

    int cnt_pp = 1, dual_sum;
    For(i,0,cnt){
        For(j,1,cnt){
            dual_sum = prime_arr[i] + prime_arr[j];
            if (!is_dual_sum[dual_sum]){
                prime_dual_sum_arr[cnt_pp++] = dual_sum;
                is_dual_sum[dual_sum] = true;
            }
        }
    }
}

bool isPrime(ll n){
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

// declare ========================================================
ll n, k;

// create function========================================================

int sol(){
    setPrimeArray();
    cin >> n;

    if(isPrime(n)){
        cout << 1 << el << n << el;
        return 1;
    }

    For(cnt_pp_, 1, max_prime*2){
        k = prime_dual_sum_arr[cnt_pp_];

        if(isPrime(n-k)){
            if(isPrime(k)){
                cout << 2 << el << k << " " << n - k << el;
                return 1;
            }
            For(j,0,k){
                if(isPrime(j) && isPrime(k - j)){
                    cout << 3 << el << j << " " << k - j << " " << n - k << el;
                    return 1;
                }
            }
        }
    }


}
//http://codeforces.com/problemset/problem/584/D
int main(){

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

    sol();

    return 0;
}
