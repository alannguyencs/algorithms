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

struct bit_tree { // giong fenwick tree
    int n;
    vi T;
    int init(int _n){
        n = _n;
        T.assign(n+1,0);
    }
    int update(int p, int k){
        int i;
        for (i=p; i<=n; i+=i&-i) T[i]+=k;
    }
    int get(int p){
        int i; int r=0;
        for (i=p; i>=1; i-=i&-i) r+=T[i];
        return r;
    }
};

// moi thao tac update hoac get la O(log N)
struct super_bit { // BIT - SUM
    bit_tree tr, lazy;
    int init(int _n){ // Khoi nao tu 1 -> n
        tr.init(_n);
        lazy.init(_n);
    }
    void update(int u, int x){ // update tu 1-> u gia tri x
        tr.update(u,u*x); lazy.update(u,x);
    }
    int get(int u){ // tong tu 0 -> u
        return tr.get(u) + u*(lazy.get(tr.n)-lazy.get(u));
    }
    void update(int ll, int rr, int x){ // Update doan tu ll -> rr them x
        update(rr,x); if (ll > 1 ) update(ll-1,-x);
    }
    int get(int ll, int rr){ //Tra ve gia tri tong tu ll -> rr
         return get(rr) - (ll == 1 ? 0 : get(ll - 1));
    }
};
/*
tr.update(i,i,a[i]);
tr.get(k,k)
*/
super_bit tr;
int n, m;

int main(){
    // DEMO
    n = 5;
    int a[6] = {0,2,3,4,1,2} ;// khoi tao 5 phan tu 2 3 4 1 2
    tr.init(5); // khoi tao BIT tu 1-> 5
    For(i,1,5){
        tr.update(i,i,a[i]); // khoi tao
    }
    For(k,1,n) cout << tr.get(k,k) << " " ; cout << el; // print
    tr.update(1,n,2); // update tu 1 -> n them 2
    For(k,1,n) cout << tr.get(k,k) << " " ; cout << el; // print
    cout << tr.get(2,3) << el; // tinh tong tu 2-> 3
}
