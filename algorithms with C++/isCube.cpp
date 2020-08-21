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

// declare ========================================================
ll a[10][4], f[10];
int index[10];
bool done;
// create function========================================================
ll dist2(ll aa[], ll bb[] ){ //tinh binh phuong khoang cach
    ll ans = 0ll;
    For(i,1,3) ans += (aa[i] - bb[i]) * (aa[i] - bb[i]);
    return ans;
}
bool is90(ll aa[], ll bb[], ll cc[]){ //kiem tra vuong goc
    ll ans = 0ll;
    For(i,1,3) ans += (cc[i] - aa[i]) * (bb[i] - aa[i]);
    return (ans == 0);
}
bool cmp(int id, int it){
    return f[id] < f[it];
}
bool isExist(ll xa, ll ya, ll za){ //kiem tra toa do nay co nam trong array ko
    For(i,1,8){
        if(xa == a[i][1] && ya == a[i][2] && za == a[i][3]) return true;
    }
    return false;
}
bool isCube(){
    For(i,2,8) f[i] = dist2(a[1], a[i]);
    sort(index + 1, index + 9, cmp); //sort theo cai nao gan vs a[1] nhat
    if(f[index[2]] == 0) return false;
    if(f[index[2]] != f[index[3]]) return false; //khoang cach tu 2, 3, 4 den 1 bang nhau
    if(f[index[3]] != f[index[4]]) return false;
    if(!is90(a[1], a[index[2]], a[index[3]])) return false; //2, 3, 4 doi mot vuong goc
    if(!is90(a[1], a[index[2]], a[index[4]])) return false;
    if(!is90(a[1], a[index[4]], a[index[3]])) return false;
    ll x[4];
    For(i,1,3) x[i] = - a[1][i] + a[index[2]][i] + a[index[3]][i]; //kiem tra 5, 6, 7, 8
    if(!isExist(x[1], x[2], x[3])) return false;
    For(i,1,3) x[i] = - a[1][i] + a[index[2]][i] + a[index[4]][i];
    if(!isExist(x[1], x[2], x[3])) return false;
    For(i,1,3) x[i] = - a[1][i] + a[index[4]][i] + a[index[3]][i];
    if(!isExist(x[1], x[2], x[3])) return false;
    For(i,1,3) x[i] = - 2 * a[1][i] + a[index[2]][i] + a[index[3]][i] + a[index[4]][i];
    if(!isExist(x[1], x[2], x[3])) return false;
    return true;
}
void dfs(int k){
    if(k == 9){
        if(isCube() && !done){
            cout << "YES" << el;
            For(i,1,8) disp(a[i], 3);
            done = true;
        }
    }else{
        do{
            dfs(k + 1);
        }while(next_permutation(a[k] + 1, a[k] + 4));
    }
}

int sol(){
    //initialize array, vector, .........................
    For(i,1,8) For(j,1,3) cin >> a[i][j];
    For(i,1,8) index[i] = i;
    //solve...............................................
    For(i,1,8) sort(a[i] + 1, a[i] + 4);
    done = false;
    dfs(2);
    //display result......................................
    if(!done) cout << "NO" << el;

}
int sltest = 1;
int main(){
	int xtest = 1;
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	xtest = sltest;
	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
    while(xtest--)  sol();
    return 0;
}
