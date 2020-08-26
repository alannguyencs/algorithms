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
/*
Xet cac duong thang co dang y = a * x + b;
Cac he so cho truoc trong vector aa, bb;
Voi moi bien x, ta chi ra A[cur] va B[cur] sao cho y = a * x + b la nho nhat
*/
double height[MX], aa[MX], bb[MX];
vector <double> A, B;
int cur = 0;
// Suppose the last 3 lines added are : (l1, l2, l3)
// Line l2 becomes irrelevant, if l1/l3 x-intersection is to the left of l1/l2 x-intersection
bool bad(double m1, double b1, double m2, double b2, double m3, double b3) {
	return (b1 - b3) * (m2 - m1) < (b1 - b2) * (m3 - m1);
}

void add(double m, double b) {
	while ( (int) A.size() >= 2 && bad(A[A.size() - 2], B[B.size() - 2], A[A.size() - 1], B[B.size() - 1], m, b)) {
		A.pop_back(); B.pop_back();
	}
	A.push_back(m); B.push_back(b);
}

void setCur(double x) {
	if (cur > (int) A.size() - 1)
		cur = (int) A.size() - 1;
	// Best-line pointer goes to the right only when queries are non-decreasing (x argument grows)
	while (cur < (int) A.size() - 1 && 1.0 * A[cur + 1] * x + B[cur + 1] <= 1.0 * A[cur] * x + B[cur])
		cur++;
}
// declare ========================================================


// create function========================================================


int sol(){
    int n, x, m;
    double y;
    cin >> n;
    For(i,1,n) cin >> aa[i];
    For(i,1,n) cin >> bb[i];
    For(i,1,n) add(aa[i], bb[i]);
    cin >> m;
    For(i,1,m){
       cin >> y;
       setCur(y);
        cout << y << " " << A[cur] << " " << B[cur] <<  " " << A[cur] * y + B[cur] << el;
    }
//	for (int i = 1; i <= n; i++)
//		cin >> height[i];
//	for (int i = 1; i <= n; i++)
//		cin >> aa[i];
//
//	// Formula is bb[i] = min(aa[j] * height[i] + bb[j] | j = 1 .. i - 1)
//	// Here aa[j] is considered as m value, and bb[j] as b value in line equation y = m * x + b
//	for (int i = 1; i <= n; i++) {
//		if (i == 1) {
//			bb[i] = 0;
//		}
//		else {
//			setCur(height[i]);
//			bb[i] = A[cur] * height[i] + B[cur];
//		}
//		add(aa[i], bb[i]);
//	}
//
//	cout << bb[n];

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
