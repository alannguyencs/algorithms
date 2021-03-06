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
const int MX = 1e6 + 7;
void disp(int arr[], int narr){
    For(i,1,narr) cout << arr[i] << " ";
    cout << el;
}
void disp(vector<int> v){
    int nv = v.size(), nn = min(nv, 15);
    For(i,0,nn - 1) cout << v[i] << " ";
    cout << el;
}
// paste source code========================================================
#define LSOne(S) (S & (-S))
struct FenwickTree {
	vi ft;

	void init(int n) {   //ft co bao nhieu phan tu
		ft.assign(n + 1, 0);
	}

	int rsq(int b){
		int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	int rsq(int a, int b){ //hieu tu vi tri a den b (Ub - U(a-1))
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}

	void adjust(int k, int v){
		for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
	}
	void display(int n){
        For(i,1,n) cout << rsq(i) << " ";
        cout << el;
	}
} ft;

// declare ========================================================
int n;
ll ans = 0ll;
int a[MX], f[MX];
map<int, int> L, R, check;
// create function========================================================


int sol(){
    //initialize array, vector, .........................
    cin >> n;
    For(i,1,n) cin >> a[i];
    //solve...............................................
    ft.init(n);
    Ford(i,n,1){
        R[a[i]] ++;
        f[i] = R[a[i]];
        ft.adjust(f[i], 1);
    }

    For(i,1,n){
        ft.adjust(f[i],-1);
        L[a[i]] ++;
        ans += ft.rsq(L[a[i]] - 1);
    }
    //display result......................................
    cout << ans << el;

}
int xtest = 1;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
    while(xtest--)  sol();
    return 0;
}
