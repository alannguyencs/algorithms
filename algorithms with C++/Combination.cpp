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

const ll maxGT = (ll) 1e6 + 15;
ll gt[maxGT], GT[maxGT];

ll powk(ll n, ll k) {
    if(k == 0ll) return 1 % mod;
    if(k == 1ll) return n % mod;
    if(k % 2 == 0){
        ll ans = powk(n, k/2);
        return (ans * ans) % mod;
    }
    return (n * powk(n, k - 1)) % mod;
}
void setGT(){
    gt[0] = 1ll;
    For(i,1,maxGT-5){
        gt[i] = (gt[i-1] * i) % mod;
    }
    For(i,0,maxGT-5){
        GT[i] = powk(gt[i], mod - 2);
    }
}
ll C(ll n, ll k){
    if(n < k) return 0;
    ll ans = (gt[n] * GT[k]) % mod;
    return (ans * GT[n-k]) % mod;
}




const int maxC = 50;
ll C[maxC + 5][maxC + 5];
void setC(){
    C[0][0] = 1ll;
    For(n,1,maxC){
        For(k,0,n) C[n][k] = C[n-1][k] + C[n-1][k-1];
    }
}
int sol(int test){

    printf("Case %d: \n",test);

}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
    //setGT();
    //cout << C(3, 1) << el;
    setC();
    cout << C[0][0] << el;
    cout << C[3][1] << el;
    cout << C[50][25] << el;

//	int nTest;
//	scanf("%d",&nTest);
//    For(test,1,nTest){
//        sol(test);
//    }
}
