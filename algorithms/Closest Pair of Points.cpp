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
#define debug(x) { cout << #x << " = "; cout << (x) << endl; }

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }
template<class T> int disp(T s) { Rep(i,sz(s)) cout << s[i] << " "; cout << el; }
template<class T> int disp(T s,int n) { For(i,1,n) cout << s[i] << " "; cout << el; }
const ld PI = acos(-1.0);
const ld eps = 1e-9;
const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const ll mod = (ll)1e9 + 7;
const int MX = 1e6 + 7;

// paste source code========================================================
typedef double D;
typedef pair<D,D> PD;
D dist(PD x, PD y){
    return sqrt((x.fi - y.fi) * (x.fi - y.fi) + (x.se - y.se) * (x.se - y.se));
}
// A Brute Force method to return the smallest distance between two points
D bruteForce(PD P[], int n){
    D ans = (D)(1e15);
    For(i,0,n-1) For(j,i+1,n-1) ans = min(ans, dist(P[i], P[j]));
    return ans;
}
/*
A utility function to find the distance beween the closest points of strip of given size. All points in strip[] are sorted accordint to
 y coordinate. They all have an upper bound on minimum distance as d. Note that this method seems to be a O(n^2) method, but it's a O(n)
 method as the inner loop runs at most 6 times
*/
bool cmpy(PD A, PD B){
    if(A.se == B.se) return A.fi < B.fi;
    else return A.se < B.se;
}
D stripClosest(PD strip[], int ns, D d){
    D ans = d;
    sort(strip, strip + ns, cmpy);
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    For(i,0,ns - 1) for(int j = i + 1; j < ns && strip[j].se - strip[i].se < d; j++){
        ans = min(ans, dist(strip[i], strip[j]));
    }
    return ans;
}
// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
D closestUtil(PD P[], int n){
    if(n <= 3) return bruteForce(P, n);
    int mid = n/2;
    PD midPoint = P[mid];
    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    D dl = closestUtil(P, mid);
    D dr = closestUtil(P + mid, n-mid);
    // Find the smaller of two distances
    D d = min(dl, dr);
    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    PD strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].fi - midPoint.fi) < d)
            strip[j] = P[i], j++;

    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}
D closest(PD P[], int n){
    sort(P, P + n);
    return closestUtil(P, n);
}
int sol(){
    //solve...............................................
    PD P[10];
    P[0] = mp(2, 3);
    P[1] = mp(12, 30);
    P[2] = mp(40, 50);
    P[3] = mp(5, 1);
    P[4] = mp(12, 10);
    P[5] = mp(3, 4);

    cout << closest(P, 6) << el;


    //display result......................................


}
int sltest = 2;
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
