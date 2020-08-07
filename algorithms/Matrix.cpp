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



const int sizeM = 10;
struct matrix{
    int row, col;
    vector<vector<ll> > vm;
    matrix(){row = 0; col = 0;}
    matrix(ll a[][sizeM], int nx, int ny){ //nx la so hang, ny la so cot, start from 1
        vector <ll> v;
        For(i,1,nx){
            v.clear();
            For(j,1,ny) v.pb(a[i][j]);
            vm.pb(v);
        }
        row = nx; col = ny;
    }
    matrix operator + (matrix A){ //same row and col with matrix
        matrix res;
        vector <ll> v;
        For(i,0,row - 1){
            v.clear();
            For(j,0,col - 1) v.pb((vm[i][j] + A.vm[i][j]) % mod);
            res.vm.pb(v);
        }
        res.col = col; res.row = row;
        return res;
    }
    matrix operator * (ll k){
        k = k % mod;
        matrix res;
        vector<ll> v;
        For(i,0,row - 1){
            v.clear();
            For(j,0,col - 1) v.pb((vm[i][j] * k) % mod);
            res.vm.pb(v);
        }
        res.col = col; res.row = row;
        return res;
    }
    matrix operator * (matrix A){
        matrix res;
        vector <ll> v; ll x;
        For(i,0,row-1){
            v.clear();
            For(j,0,row - 1){
                x = 0ll;
                For(k,0,col - 1){
                    x += vm[i][k] * A.vm[k][j];
                    x = x % mod;
                }
                v.pb(x);
            }
            res.vm.pb(v);
        }
        res.row = row; res.col = row;
        return res;
    }
    matrix operator ^ (ll k){

        if(k == 0) {
            ll x[sizeM][sizeM];
            ms(x, 0);
            For(i,1,row) x[i][i] = 1ll;
            matrix X(x, row, row);
            return X;
        }
        if(k == 1) return *this;
        if(k % 2 == 0){
            matrix ans = *this ^ (k/2);
            return ans * ans;
        }
        return *this * (*this ^ (k-1));
    }
    void display(){
        For(i,0,row - 1){
            For(j,0,col - 1) cout << vm[i][j] << " ";
            cout << el;
        }
    }
};




int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	std::ios::sync_with_stdio(false);

    ll a[sizeM][sizeM], b[sizeM][sizeM];
    For(i,1,10) For(j,1,10) a[i][j] = i + j;
    For(i,1,10) For(j,1,10) b[i][j] = i;
    matrix A(a, 2, 4), B(b, 4, 2), C;
    C = A * B;
    For(i,0,1){
        For(j,0,3) cout << A.vm[i][j] << " ";
        cout << el;
    }
    cout << el << el;
    A = A * 2;
    For(i,0,1){
        For(j,0,3) cout << A.vm[i][j] << " ";
        cout << el;
    }
    cout << el << el;
    For(i,0,3){
        For(j,0,1) cout << B.vm[i][j] << " ";
        cout << el;
    }
    cout << el << el;

    For(i,0,C.row - 1){
        For(j,0,C.col - 1) cout << C.vm[i][j] << " ";
        cout << el;
    }
    cout << el << el;
    C = C ^ 3123012;
    For(i,0,C.row - 1){
        For(j,0,C.col - 1) cout << C.vm[i][j] << " ";
        cout << el;
    }
    return 0;
}
