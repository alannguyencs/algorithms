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
const int MX = 3e4 + 5;
/*
Given a list of numbers of length n
This function will show the length of longest increasing subsequence contain each number.
Number of that length
Complexity: nlog(n)
example input:
13
16 5 8 6 1 10 5 2 15 3 2 4 1
*/

// declare ========================================================
 //length is the longest length
 //deg[i] + 1 la do dai day con tang dai nhat co diem cuoi la phan tu i
                        //Count la so day tang co do dai lon nhat do.
                        //minDeg la phan tu nho nhat trong s[deg[i]]


// create function========================================================
struct cmp{
    bool operator()(const ii& a, const ii& b) const{
        if(a.fi == b.fi) return a.se > b.se;
        else return a.fi < b.fi;
    }
};
vii value; //
vi deg, minDEG, Count, demo;
vi::iterator itv;
set<ii, cmp> s[MX];
set<ii, cmp>::iterator its;
vi LIS(vi v){ //thay doi gia tri cua deg, tra ve day tang dai nhat
    //===init================================================
    int n = v.size(), k, length = 0, xxx, mx;
    For(i,0,n - 1){
        value.pb(mp(v[i], i));
    }
    s[0].insert(value[0]);
    //========================================================
    For(i,0,n - 1){
        // increase strictly thi dung lowwer_bound, not strictly thi dung upper_count
        itv = lower_bound(minDEG.begin(), minDEG.end(), value[i].fi);
        //itv = upper_bound(minDEG.begin(), minDEG.end(), value[i].fi);
        if(itv == minDEG.end()){
            s[length].insert(value[i]);
            minDEG.pb(value[i].fi);
            deg.pb(length);
            length++;
        }else{
            xxx = itv - minDEG.begin();
            s[xxx].insert(value[i]);
            minDEG[xxx] = value[i].fi;
            deg.pb(xxx);
        }
        //Count number of LIS====================================
        if(deg[i] == 0){
            if(s[0].size() == 1) Count.pb(1);
            else {
                its = s[0].begin(); its++;
                Count.pb(1 + Count[(*its).se]);
            }
        }else{
            its = s[deg[i]-1].lower_bound(value[i]);
            //its = s[deg[i]-1].upper_bound(value[i]);
            if(its == s[deg[i]-1].end()) k = 0; else k = Count[(*its).se];
            //debug(i); debug(k); //neu sua thanh day tang ko hoan toan,(not strictly) thi sua cmp
            its = s[deg[i]-1].begin();
            k = Count[(*its).se] - k;
            if(s[deg[i]].size() == 1) Count.pb(k);
            else{
                its = s[deg[i]].begin(); its++;
                Count.pb(k + Count[(*its).se]);
            }
        }
        //--------------------------------------------------------------------
    }
    //===========print out table================
    For(i,0,length - 1){
        for(its = s[i].begin(); its != s[i].end(); its++) cout << (*its).fi << ":" << Count[(*its).se] << " ";
        cout << el;
    }
    //show length
    cout << length << el;
    //----------deg----------
    cout << "Deg: " ;
    disp(deg);
    //SHOW DEMO        ======================================
    k = length - 1, mx = 1e9 + 7;
    Ford(i,n-1,0){
        if(deg[value[i].se] == k && value[i].fi <= mx){
            k--; mx = value[i].fi;
            demo.pb(value[i].fi);
        }
        if(k == -1) break;
    }
    cout << "Demo: ";
    reverse(demo.begin(), demo.end());
    disp(demo);
    //=========show count=================================
    its = s[length - 1].begin();
    cout << "Count: ";
    cout << Count[(*its).se] << el;
    return demo;
}
//===================================================================
vi v, lis;
int n, xxx;
int sol(){
    //initialize array, vector, .........................
    cin >> n;
    For(i,0,n-1) cin >> xxx, v.pb(xxx);
    //solve...............................................

    lis = LIS(v);
    disp(lis);
    //display result......................................


}
int xtest = 1;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false);
    while(xtest--)  sol();
    return 0;
}
