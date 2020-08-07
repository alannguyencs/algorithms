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
const int MX = 1e4 + 7;
const int MAX = 15 + 7;

// paste source code========================================================
ll perm[MX], perm_inv[MX];

ll pow_k(ll n, ll k) {
    if(k == 0ll) return 1 % mod;
    if(k == 1ll) return n % mod;
    if(k % 2 == 0){
        ll ans = pow_k(n, k/2);
        return (ans * ans) % mod;
    }
    return (n * pow_k(n, k - 1)) % mod;
}
void set_perm(){
    perm[0] = 1ll;
    For(i,1,MX-5) perm[i] = (perm[i-1] * i) % mod;
    For(i,0,MX-5) perm_inv[i] = pow_k(perm[i], mod - 2);
}
ll comb(ll n, ll k){
    if(n < k) return 0;
    ll ans = (perm[n] * perm_inv[k]) % mod;
    ans = (ans * perm_inv[n-k]) % mod;
    return ans;
}

// declare ========================================================
ll elem_on_class[MX], pre_elem_on_class[MX]; //how many ways to assign "elem" elements to "class_" classes
ll eq_on_elem[MX]; //how many ways to group "elem" elements
ll num_elem, ans = 0ll;
// create function========================================================
void compute_num_equivalence_relation(int num_elem){
    pre_elem_on_class[1] = 1ll;
    For(elem, 1, num_elem){
        //Using pre_elem_on_class to compute elem_on_class
        For(class_, 1, elem){
            elem_on_class[class_] = (pre_elem_on_class[class_] * class_ + pre_elem_on_class[class_-1]) % mod;

            //update eq_on_elem
            eq_on_elem[elem] = (eq_on_elem[elem] + elem_on_class[class_]) % mod;
        }

        //update pre_elem_on_class
        For(class_, 1, elem) pre_elem_on_class[class_] = elem_on_class[class_];
    }

}


int sol(){
    set_perm();
    cin >> num_elem;
    compute_num_equivalence_relation(num_elem);
    For(elem, 0, num_elem-1){
        ans = (ans + comb(num_elem, elem) * eq_on_elem[elem]) % mod;
    }
    ans = (ans + 1) % mod;  //add empty set
    cout << ans << el;
}

//http://codeforces.com/problemset/problem/568/B
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
