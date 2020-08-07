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
#define el "\n"
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

struct UnionFind {
	vi p, rank, setSize;
	int numSets;

	int init(int N){
		setSize.assign(N, 1);
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		Rep(i, N) p[i] = i;
	}

	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)){
			numSets--;
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank[x] > rank[y]){
				p[y] = x;
				setSize[x] += setSize[y];
			}else{
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}

	int numDisjointSets(){
		return numSets;
	}

	int sizeOfSet(int i){
		return setSize[findSet(i)];
	}
} UF; //--> attention: UF.init()

int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "Assume that there are 5 disjoint sets initially" << el;
	int n = 5;
	UF.init(n);
	cout << "Number of sets: " << UF.numDisjointSets() << el; //5
	UF.unionSet(0, 1);
	cout << "Number of sets: " << UF.numDisjointSets() << el; //4
	UF.unionSet(2, 3);
	cout << "Number of sets: " << UF.numDisjointSets() << el; //3
	UF.unionSet(4, 3);
	cout << "Number of sets: " << UF.numDisjointSets() << el; //2
	cout << "isSameSet(0, 3) = " << UF.isSameSet(0, 3) << el; // will return 0 (false)
	cout << "isSameSet(4, 3) = " << UF.isSameSet(4, 3) << el; // will return 1 (true)
	Rep(i, n)
		cout << "findSet(" << i << ") = " << UF.findSet(i) << ", sizeOfSet(" << i << ") = " << UF.sizeOfSet(i) << el;
	UF.unionSet(0, 3);
	cout << "Number of sets: " << UF.numDisjointSets() << el; //1
	Rep(i, n)
		cout << "findSet(" << i << ") = " << UF.findSet(i) << ", sizeOfSet(" << i << ") = " << UF.sizeOfSet(i) << el;
}
