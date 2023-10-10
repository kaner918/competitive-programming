//https://onlinejudge.org/external/133/13300.pdf
//13300

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define fl(i, a, b) for (int i = a; i < b; ++i)

#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))

#define pb push_back
#define mp make_pair

#define dig(i) (s[i] - '0')
#define slen(s) s.length()

#define fr first
#define sc second

#define len(x) x.size()
#define fill(x, y) memset(x, y, sizeof(x))
#define clr(a) fill(a, 0)
#define endl '\n'

#define PI 3.14159265358979323

#define trace1(x1) cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2) \
    cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)                                                  \
    cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 \
         << ": " << x3 << endl;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <typename T>
T power(T x, T y, ll m = MOD) {
    T ans = 1;
    x %= m;
    while (y > 0) {
        if (y & 1ll) ans = (ans * x) % m;
        y >>= 1ll;
        x = (x * x) % m;
    }
    return ans % m;
}

typedef struct pt {
    ld x, y;
};

ld cross(ld x1, ld y1, ld x2, ld y2) { return x1 * y2 - x2 * y1; }

ld polygon_area(vector<pt>& a) {
    ld ans = 0.0;

    for (int i = 2; i < len(a); i++)
        ans += cross(a[i].x - a[0].x, a[i].y - a[0].y, a[i - 1].x - a[0].x,
                     a[i - 1].y - a[0].y);

    return fabs(ans / 2);
}

int orientation(pt a, pt b, pt c) {
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1;  // clockwise
    if (v > 0) return +1;  // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y) <
                   (p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size() - 1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin() + i + 1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 &&
               !cw(st[st.size() - 2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}

int main() {
    FAST_IO;

    int n;

    while (cin >> n) {
        ld ans = 0.0;
        vector<pt> v(n);

        for (pt& p : v) cin >> p.x >> p.y;

        convex_hull(v);

        n = len(v);

        fl(i, 0, n) {
            int j = i + 1, k = j + 1;

            while (k < n) {
                pt ij = {v[i].x - v[j].x, v[i].y - v[j].y};
                pt ik = {v[i].x - v[k].x, v[i].y - v[k].y};
                pt ijp = {v[i].x - v[j + 1].x, v[i].y - v[j + 1].y};
                pt ikp = {v[i].x - v[(k + 1) % n].x, v[i].y - v[(k + 1) % n].y};

                ld cross_ijk = abs(cross(ij.x, ij.y, ik.x, ik.y));
                ld cross_ijkp = abs(cross(ij.x, ij.y, ikp.x, ikp.y));
                ld cross_ijpk = abs(cross(ijp.x, ijp.y, ik.x, ik.y));

                ans = max(ans, cross_ijk);

                if (j == k || cross_ijpk < cross_ijkp)
                    k++;
                else
                    j++;
            }
        }

        printf("%.1Lf\n", ans / 2.0);
    }

    return 0;
}