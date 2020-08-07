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
//#define TEST
vector<double> solve2Equation(double a, double b, double c){
    vector <double> v;
    if(a < eps && a > -eps){
        if(b < eps && b > -eps) return v;
        else {
            v.pb(-c / b);
            return v;
        }
    }else{
        double delta = b * b - 4 * a * c;
        if(delta > eps){
            double x1 = (-b - sqrt(delta)) / (2 * a);
            double x2 = (-b + sqrt(delta)) / (2 * a);
            v.pb(x1); v.pb(x2);
            return v;
        }else{
            if(delta < -eps) return v;
            else{
                double x = -b / (2.0 * a);
                v.pb(x);
                return v;
            }
        }
    }
}
//vector<double> intersectionCircle(double a1, double b1, double a2, double b2, double r1, double r2){ //A, B la 2 diem phan biet
//    //tra ve toa do giao diem
//    vector<double> ans;
//    double M = a1 * a1 + b1 * b1 - a2 * a2 - b2 * b2 - r1 * r1 + r2 * r2;
//    if(eps > b1 - b2 && b1 - b2 >-eps){
//        double x = M / (2 * (a1 - a2));
//        double b = -2 * b1;
//        double c = b1 * b1 + (x - a1) * (x - a1) - r1 * r1;
//        vector<double> v = solve2Equation(1, b, c);
//        if(v.size() == 0) return ans;
//        if(v.size() == 1){
//            ans.pb(x); ans.pb(v[0]); return ans;
//        }
//        if(v.size() == 2){
//            ans.pb(x); ans.pb(v[0]);
//            ans.pb(x); ans.pb(v[1]); return ans;
//        }
//    }else{
//        double k = (a2 - a1) / (b1 - b2);
//        double q = M / (2 * (b1 - b2));
//        double a = 1 + k * k;
//        double b = -2 * a1 + 2 * k * (q - b1);
//        double c = a1 * a1 + (q - b1) * (q - b1) - r1 * r1;
//        vector <double> v = solve2Equation(a, b, c);
//        if(v.size() == 0) return ans;
//        if(v.size() == 1){
//            ans.pb(v[0]); ans.pb(v[0] * k + q);
//            return ans;
//        }
//        if(v.size() == 2){
//            ans.pb(v[0]); ans.pb(v[0] * k + q);
//            ans.pb(v[1]); ans.pb(v[1] * k + q);
//            return ans;
//        }
//    }
//}

double dist(double xa, double ya, double xb, double yb) {
	xa -= xb; ya -= yb;
	return sqrt(xa * xa + ya * ya);
}
double angle(double ox, double oy, double ax, double ay, double bx, double by){ // goc AOB
    double a, b, c, alpha;
		a = dist(ax, ay, bx, by);
		b = dist(ox, oy, ax, ay);
		c = dist(ox, oy, bx, by);
		alpha = acos((a * a - b * b - c * c) / (-2.0 * b * c));
    return alpha;
}
//double areaTriangle(double a, double b, double c){
//    return 0.25 * sqrt((a + b + c) * (a + b - c) * (a - b + c) * (-a + b + c));
//}
//double areaCircle(double alpha, double r){
//    return alpha * r * r / 2.0;
//}
//int lineEquation(int x1, int y1, int x2, int y2, int x, int y){ // line equation di qua diem (x1, y1) va (x2, y2)
//    ll nx = 0ll + y2 - y1, ny = 0ll + x1 - x2;
//    ll kq = (nx * (x - x1) + ny * (y - y1));
//    if(kq == 0) return 0;
//    if(kq > 0) return 1; else return -1;
//}
//vector<double> findCircle(double xa, double ya, double xb, double yb, double xc, double yc){ // truong hop 3 diem khong thang hang
//    double a1 = 2.0 * (xa - xb), b1 = 2 * (ya - yb), c1 = xa * xa + ya * ya - xb * xb - yb * yb;
//    double a2 = 2.0 * (xa - xc), b2 = 2 * (ya - yc), c2 = xa * xa + ya * ya - xc * xc - yc * yc;
//    double x = (b2 * c1 - b1 * c2) / (b2 * a1 - b1 * a2);
//    double y = (a2 * c1 - a1 * c2) / (a2 * b1 - a1 * b2);
//    double R = sqrt((x - xa) * (x - xa) + (y - ya) * (y - ya));
//    vector<double> ans;
//    ans.pb(x); ans.pb(y); ans.pb(R);
//    return ans;
//}

//typedef double T;
//typedef pair<T,T> PT;
//T det(const PT &a, const PT &b){
//    return a.fi * b.se - a.se * b.fi;
//}
//T area2(const PT &a, const PT &b, const PT &c){ // >0 neu theo chieu duong,  <0 neu theo chieu am, =0 neu thang hang; ko phai gia tri dien tich
//    return det(a, b) + det(b, c) + det(c, a);
//}
//bool between(const PT &a, const PT &b, const PT &c){ //return true if b is between a & c
//    return (fabs(area2(a, b, c)) < eps &&
//           (a.fi - b.fi) * (c.fi - b.fi) <= 0 &&
//           (a.se - b.se) * (c.se - b.se) <= 0);
//}
int main(){
	#ifdef TEST
		freopen("in.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false);
    vector<double> v = findCircle(0.0, 0.0, 3.0, 0.0, 0.0, 4.0);
    cout << v[0] << el;
    cout << v[1] << el;
    cout << v[2] << el;
    PT a = mp(0,0), b = mp(1, 0), c = mp(2, 0);
    cout << area2(a, c, b) << el;
    if(between(a, b, c)) cout << "true" << el;
    else cout << "false" << el;
    return 0;
}
