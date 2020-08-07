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
/*
Bai toan tim upper enveloppe
Neu cho truoc 1 vector he so a, b thi do phuc tap la O(nlogn)
Neu update lien tuc thi do phuc nap la O(n * n log n), co the cai tien thanh O(n * n)
*/
typedef double T;
typedef pair<T,T> PT;
typedef vector<PT> VPT;
typedef vector<T> VT;
bool cmpx(PT a, PT b){
    if(a.fi == b.fi) return a.se > b.se;
    else return a.fi < b.fi;
}
T xIntersect(const PT &a, const PT &b) { //giao diem 2 duong thang khong song song
    return - (a.se - b.se) / (a.fi - b.fi);
}
void uppper_envelope(VPT &pts, VT &x){
    //sap xep va loai bo cac duong thang song song khong can thiet
    x.clear();
    sort(pts.begin(), pts.end(), cmpx);
    VPT ptsx; ptsx.pb(pts[0]);
    For(i,1,pts.size()-1) if(pts[i].fi != pts[i-1].fi) ptsx.pb(pts[i]);
    pts = ptsx;
    //lay ra nhung duong thang va nhung diem can thiet
    VPT up;
    if(pts.size() > 1) x.push_back(xIntersect(pts[0], pts[1])), up.push_back(pts[0]), up.push_back(pts[1]);
    For(i,2,pts.size() - 1){
        while(up.size() > 1 && xIntersect(pts[i], up.back()) <= x.back()) up.pop_back(), x.pop_back();
        x.push_back(xIntersect(pts[i], up.back())); up.push_back(pts[i]);
    }
    pts = up;
}

VPT ab;
VT x;
T a, b;
int n;
int sol(){
    //initialize array, vector, .........................
    cin >> n;
    For(i,1,n){
        cin >> a >> b;
        ab.pb(mp(a, b));
    }
    //solve...............................................
    uppper_envelope(ab, x);
    For(i,0,ab.size() - 1) cout << ab[i].fi << " " << ab[i].se << el;
    For(i,0,x.size() - 1) cout << "x " << x[i] << el;
    cout << "------------" << el;
    ab.pb(mp(0.0, 3.0));
    uppper_envelope(ab, x);
    For(i,0,ab.size() - 1) cout << ab[i].fi << " " << ab[i].se << el;
    For(i,0,x.size() - 1) cout << "x " << x[i] << el;
    //display result......................................


}
int sltest = 1;
int main(){
	int xtest = 1;
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	xtest = sltest;
	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
    while(xtest--)  sol();
    return 0;
}
