#include <bits/stdc++.h>
// 1405 - The Great Escape ---------- LightOJ


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
struct Dinic { // time |E| ^ 2 |V| là capcity lớn nhất
    vi last,level,que,run,adj,flow,cap,next;
    int n, s, t, E;
    void init(int _n, int _s, int _t) { // n : số đỉnh ; s = đỉnh bắt đầu ; t = đỉnh kết thúc
        n = _n; s = _s; t = _t; E = 0;
        //For(i, 0, n) last[i] = -1;
        last.assign(n+1,-1);
        adj.clear();flow.clear();cap.clear();next.clear();
    }

    void add(int u, int v, int c1, int c2) { // add thêm cạnh u->v có capacity là c1 và đường ngược là c2. thường add là (u,v,c1,0);
        adj.pb(v);flow.pb(0);cap.pb(c1);next.pb(last[u]);last[u] = E++;
        adj.pb(u);flow.pb(0);cap.pb(c2);next.pb(last[v]);last[v] = E++;
    }

    bool bfs() {
        level.assign(n+1,-1);
        level[s] = 0;
        que.assign(n+1,-1);
        int qsize = 0;
        que[qsize++] = s;

        Rep(i, qsize) {
            for (int u = que[i], e = last[u]; e != -1; e = next[e]) {
                int v = adj[e];
                if (flow[e] < cap[e] && level[v] == -1) {
                    level[v] = level[u] + 1;
                    que[qsize++] = v;
                }
            }
        }

        return level[t] != -1;
    }

    int dfs(int u, int bot) {
        if (u == t) return bot;
        for (int &e = run[u]; e != -1; e = next[e]) {
            int v = adj[e], delta = 0;
            if (level[v] == level[u] + 1 && flow[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flow[e]))) > 0) {
                flow[e] += delta; flow[e ^ 1] -= delta;
                return delta;
            }
        }
        return 0;
    }

    int maxflow() { // đưa maxflow
        int total = 0;
        run.assign(n+1,-1);
        while (bfs()) {
            For(i, 0, n) run[i] = last[i];
            for (int delta = dfs(s, inf); delta > 0; delta = dfs(s, inf)) total += delta;
        }
        return total;
    }
} dinic;

char a[200][200];
int sol(int test){
    int n,m,tong = 0;
    cin >> m >> n;
    int mn =(n+2) * (m+2);
    dinic.init(mn*2,0,mn * 2);
    int x,y,z;
    For(i,1,m){
        For(j,1,n){
            cin >> a[i][j];
            int u = i * (n+2) + j;
            if (a[i][j] == '*'){
                dinic.add(0,u,1,0);
                tong++;
            }
        }
    }
    For(i,1,m){
        For(j,1,n){
            int u = i * (n+2) + j;
            dinic.add(u,u+mn,1,0);
            Rep(k,4){
                int x = i + dr[k];
                int y = j + dc[k];
                int v = x * (n+2) + y;
                dinic.add(u+mn,v,1,0);
            }
        }
    }
    For(i,1,n){
        dinic.add(i,mn*2,1,0);
        dinic.add(i + (m+1) * (n+2),mn*2,1,0);
    }
    For(i,1,m){
        dinic.add(i * (n+2),mn*2,1,0);
        dinic.add(i * (n+2) + n + 1,mn*2,1,0);
    }
    cout << "Case " << test << ": ";
    if (tong == dinic.maxflow())
        cout << "yes" << el;
    else
        cout << "no" << el;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	int nTest;
	cin >> nTest;
    For(test,1,nTest){
        sol(test);
    }
}
