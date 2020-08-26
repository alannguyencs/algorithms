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

// C++ routines for computational geometry.
double INF = 1e100;
double EPS = 1e-7;
struct PT {
    double x, y;
    PT (){}
    PT (double x, double y) : x(x), y(y){}
    PT (const PT &p) : x(p.x), y(p.y){}
    PT operator - (const PT &p){ return PT(x - p.x, y - p.y);}
    PT operator + (const PT &p){ return PT(x + p.x, y + p.y);}
    PT operator * (double c){ return PT(x * c, y * c); }
    PT operator / (double c){ return PT(x/c, y/c); }
    bool operator == (const PT &p) {return x == p.x && y == p.y; }
    bool operator != (const PT &p) {return x != p.x || y != p.y; }
};
double dot(PT p, PT q){ return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q){ return dot(p-q,p-q); }
double cross(PT p, PT q){ return p.x*q.y-p.y*q.x; }
ostream &operator<< (ostream &os, const PT &p){
os << "("<< p.x << ","<< p.y << ")";
}
// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p){ return PT(-p.y,p.x); } //+90
PT RotateCW90(PT p){ return PT(p.y, -p.x); } // -90
PT RotateCCW(PT p, double t){
    return PT(p.x * cos(t) - p.y * sin(t), p.x*sin(t)+p.y*cos(t));
}
PT RotateCCW90(PT origin, PT pt){
    pt = pt - origin; pt = RotateCCW90(pt);
    pt = pt + origin; return pt;
}
bool isSquare(PT pt1, PT pt2, PT pt3, PT pt4){
    PT center = pt1 + pt2 + pt3 + pt4;
    center = center * 0.25;
    if(center == pt1) return false;
    PT pt = RotateCCW90(center, pt1); if(pt != pt2 && pt != pt3 && pt != pt4) return false;
    pt = RotateCCW90(center, pt); if(pt != pt2 && pt != pt3 && pt != pt4) return false;
    pt = RotateCCW90(center, pt); if(pt != pt2 && pt != pt3 && pt != pt4) return false;
    return true;
}
bool isRectangle(PT pt1, PT pt2, PT pt3, PT pt4){
    PT center = pt1 + pt2 + pt3 + pt4;
    center = center * 0.25;
    if(center == pt1) return false;
    if(pt1 + pt2 == (center * 2.0) && pt3 + pt4 == (center * 2.0) && dist2(pt1, pt2) == dist2(pt3, pt4)) return true;
    if(pt1 + pt3 == (center * 2.0) && pt2 + pt4 == (center * 2.0) && dist2(pt1, pt3) == dist2(pt2, pt4)) return true;
    if(pt1 + pt4 == (center * 2.0) && pt2 + pt3 == (center * 2.0) && dist2(pt1, pt4) == dist2(pt3, pt2)) return true;
    return false;
}
double area(PT a, PT b, PT c){
    PT ab = b - a, ac = c - a;
    return 0.5 * (abs(cross(ab, ac)));
}
// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c){
    return a + (b-a) * dot(c-a,b-a)/dot(b-a,b-a);
}
// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c){
    double r = dot(b-a,b-a);
    if(fabs(r) < EPS) return a;
    r = dot(c-a,b-a)/r;
    if(r < 0) return a;
    if(r > 1) return b;
    return a + (b-a)*r;
}
// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z, double a, double b, double c, double d){
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}
// determine if two lines are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d){
    return fabs(cross(b-a,c-d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d){
    return LinesParallel(a,b,c,d) && fabs(cross(a-c,d-c)) < EPS;
}
// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d){
    if(cross(d-a,b-a) * cross(c-a,b-a) > 0) return false;
    if(cross(a-c,d-c) * cross(b-c,d-c) > 0) return false;
    return true;
}
// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists
PT ComputeLineIntersection(PT a, PT b, PT c, PT d){
    b=b-a; d=c-d; c=c-a;
    if(dot(b,b) < EPS) return a;
    if(dot(d,d) < EPS) return c;
    return a + b*cross(c,d)/cross(b,d);
}
// compute center of circle given three points
PT ComputeCircleCenter(PT a, PT b, PT c){
    b=(a+b)/2;
    c=(a+c)/2;
    return ComputeLineIntersection (b,b + RotateCW90(a-b), c, c + RotateCW90(a-c));
}
// determine if point is in a possibly non-convex polygon
// (by William Randolph Franklin); returns 1 for strictly
// interior points, 0 for strictly exterior points, and
// 0 or 1 for the remaining points
// note that it is possible to convert this into an *exact*
// test using integer arithmetic by taking care of the
// division appropriately (making sure to deal with signs
// properly) and then by writing exact tests for checking
// point on polygon boundary
bool PointInPolygon(const vector<PT> &p, PT q){
    bool c = 0;
    for(int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    if((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) &&
       q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)) c = !c;
    }
    return c;
}
// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p, PT q){
    for(int i = 0; i < p.size(); i++)
    if(dist2(ProjectPointSegment (p[i], p[(i+1)%p.size()], q), q) < EPS)    return true;
    return false;
}
// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<PT> CircleLineIntersection (PT a, PT b, PT c, double r){
    vector<PT> ret;
    PT d = b-a;
    double D = cross(a-c,b-c);
    double e = r*r*dot(d,d)-D*D;
    if(e < 0) return    ret;
    e = sqrt(e);
    ret.push_back (c+PT(D*d.y+(d.y>=0?1:-1)*d.x*e,-D*d.x+fabs(d.y)*e)/dot(d,d));
    if(e > 0)
    ret.push_back (c+PT(D*d.y-(d.y>=0?1:-1)*d.x*e,-D*d.x-fabs(d.y)*e)/dot(d,d));
    return ret;
}
// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
// Khong xet truong hop a == b && r == R
vector<PT> CircleCircleIntersection (PT a, PT b, double r, double R){
    vector<PT> ret;
    double d = sqrt(dist2(a,b));
    if(d > r+R || d+min(r,R) < max(r,R)) return ret;
    double x = (d*d-R*R+r*r)/(2*d);
    double y = sqrt(r*r-x*x);
    PT v = (b-a)/d;
    ret.push_back (a+v*x + RotateCCW90(v)*y);
    if(y > 0)
    ret.push_back (a+v*x - RotateCCW90(v)*y);
    return ret;
}
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
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);




    return 0;
}
