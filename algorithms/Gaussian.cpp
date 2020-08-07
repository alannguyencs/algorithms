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

// paste source code========================================================
vector<ld> gauss(vector< vector<ld> > A) {
    int n = A.size();
    vector<ld> x(n), y;
    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        ld maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            ld tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
           //if(A[i][i] == 0) return y;
           ld c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A

    for (int i=n-1; i>=0; i--) {
        //if(A[i][i] == 0) return y;
        x[i] = A[i][n]/A[i][i];
        //if(!isNonnegativeInteger(x[i])) return y;
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}

// declare ========================================================
vector< vector<ld> > V;
vector<ld> x, y;
bool flag;
int n, j_Count, Count;
ll b[205], c[205], a[205][205], ans;
// create function========================================================
bool isNonnegativeInteger(ld xx){
    return xx > -eps && abs(xx - (int)(xx + eps)) < eps;
}
ll cal(vector<ld> v){
    ll res = 0ll;
    For(i,0,j_Count - 1) res += (ll)(round(v[i])) * c[i];
    For(i,j_Count + 1, n - 1) res += (ll)(round(v[i-1])) * c[i];
    return res;
}

int sol(){
    //initialize array, vector, .........................
    Count = inf; ans = -1;
    cin >> n;
    For(i,0,n-1) cin >> c[i];
    For(i,0,n-2) cin >> b[i];
    For(i,0,n-2) {
        For(j,0,n-1) {
            cin >> a[i][j];
            if(a[i][j] != 0 && b[i] / a[i][j] < Count){
                Count = (int)(b[i] / a[i][j]);
                j_Count = j;
            }
        }
    }

    //solve...............................................
    //add coefficents to V
    V.assign(n-1, vector<ld>(n));
    For(i,0,n-2){
        For(j,0,j_Count - 1) V[i][j] = a[i][j];
        For(j,j_Count + 1, n - 1) V[i][j-1] = a[i][j];
    }
    For(i,0,n-2) V[i][n-1] = b[i];

   //get solutions
    x = gauss(V);






    flag = true;
    For(i,0,n-2) if(!isNonnegativeInteger(x[i])) {
        flag = false;
        break;
    }
    if(flag) ans = max(ans, cal(x));
    //------next-------------------
    V.assign(n-1, vector<ld>(n));
    For(i,0,n-2){
        For(j,0,j_Count - 1) V[i][j] = a[i][j];
        For(j,j_Count + 1, n - 1) V[i][j-1] = a[i][j];
    }
    For(i,0,n-2) V[i][n-1] = - a[i][j_Count];
    y = gauss(V);
    //------- - a[j_Count] --------------------------
    For(id,1,Count){
        For(i,0,n-2){
            x[i] += y[i];
        }
        flag = true;
        For(i,0,n-2) if(!isNonnegativeInteger(x[i])) {
            flag = false;
            break;
        }
        if(flag) ans = max(ans, cal(x) + c[j_Count] * id);
    }







    //display result......................................
    //cout << Count << el;
    cout << ans << el;

}

int main(){
	int xtest;
//	#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	#endif
//	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> xtest;
    while(xtest--)  sol();
    return 0;
}
