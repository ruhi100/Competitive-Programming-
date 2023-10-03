#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vec vector
#define int long long
#define ld long double

#define f first
#define s second

#define pb push_back

#define fe(x, a) for (auto& x : a)

#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define lv (v + 1)
#define rv (v + 2 * (m - l + 1))

using pii = pair<int, int>;

const int mod = 1e9 + 7;
const int OO = 1e9;
const int N = 2e5;
const ld eps = 1e-3;

template<typename T>
bool umn (T &a, T b) { return a > b ? (a = b, 1) : 0; }

template<typename T>
bool umx (T &a, T b) { return a < b ? (a = b, 1) : 0; }

int segm[N];

struct noda {
    vec < int > r;
    vec < int > len;
    vec < int > pmn;
};

noda tr[2 * N + 2];

struct mxtre {
    int n;
    vec < int > vr;
    mxtre (int _n) {
        n = _n;
        vr.assign(2 * n + 2, OO);
    }

    void set (int v, int l, int r, int i, int x) {
        if (l == r)
            vr[v] = x;
        else {
            int m = l + r >> 1;
            if (i <= m)
                set(lv, l, m, i, x);
            else
                set(rv, m + 1, r, i, x);
            vr[v] = min(vr[lv], vr[rv]);
        }
    }
    int get (int v, int l, int r, int ql, int qr) {
        if (l > qr || r < ql)
            return OO;
        if (l >= ql && r <= qr)
            return vr[v];
        int m = l + r >> 1;
        return min(get(lv, l, m, ql, qr), get(rv, m + 1, r, ql, qr));
    }
};

void build (int v, int l, int r) {
    if (l == r)
        tr[v] = {{segm[l]}, {segm[l] - l + 1}, {segm[l] - l + 1}};
    else {
        int m = l + r >> 1;
        build(lv, l, m);
        build(rv, m + 1, r);
        int l1 = 0, l2 = 0;
        int prv = OO;
        while (l1 != sz(tr[lv].r) || l2 != sz(tr[rv].r)) {
            if (l1 == sz(tr[lv].r)) {
                tr[v].r.pb(tr[rv].r[l2]);
                tr[v].len.pb(tr[rv].len[l2]);
                tr[v].pmn.pb(min(tr[v].len.back(), prv));
                prv = tr[v].pmn.back();
                l2++;
                continue;
            }
            if (l2 == sz(tr[rv].r)) {
                tr[v].r.pb(tr[lv].r[l1]);
                tr[v].len.pb(tr[lv].len[l1]);
                tr[v].pmn.pb(min(tr[v].len.back(), prv));
                prv = tr[v].pmn.back();
                l1++;
                continue;
            }
            if (tr[lv].r[l1] < tr[rv].r[l2]) {
                tr[v].r.pb(tr[lv].r[l1]);
                tr[v].len.pb(tr[lv].len[l1]);
                tr[v].pmn.pb(min(tr[v].len.back(), prv));
                prv = tr[v].pmn.back();
                l1++;
            } else {
                tr[v].r.pb(tr[rv].r[l2]);
                tr[v].len.pb(tr[rv].len[l2]);
                tr[v].pmn.pb(min(tr[v].len.back(), prv));
                prv = tr[v].pmn.back();
                l2++;
            }
        }
    }
}

int get (int v, int l, int r, int ql, int qr, int x) {
    if (l > qr || r < ql)
        return OO;
    if (l >= ql && r <= qr) {
        int pos = --upper_bound(all(tr[v].r), x) - tr[v].r.begin();
        if (pos < 0) return OO;
        return tr[v].pmn[pos];
    }
    int m = l + r >> 1;
    return min(get(lv, l, m, ql, qr, x), get(rv, m + 1, r, ql, qr, x));
}

void slv () {
    int n, q;
    cin >> n >> q;
    vec < int > a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i <= 2 * n + 1; ++i) {
        tr[i].r.clear();
        tr[i].len.clear();
        tr[i].pmn.clear();
    }
    stack < int > stack1;
    auto b = a;
    sort(all(b));
    b.erase(unique(all(b)), b.end());

    mxtre pos(n);
    mxtre r(n);
    for (int i = n - 1; i >= 0; --i) {
        int c = lower_bound(all(b), a[i]) - b.begin();
        int ri = pos.get(1, 0, n - 1, c, n - 1);
        segm[i] = r.get(1, 0, n - 1, c, n - 1);
        pos.set(1, 0, n - 1, c, i);
        r.set(1, 0, n - 1, c, ri);
    }

    build(1, 0, n - 1);
    while (q--) {
        int le, ri;
        cin >> le >> ri;
        --le, --ri;
        cout << max(-1ll, ri - le + 1 - get(1, 0, n - 1, le, ri, ri) + 3) << "\n";
    }
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        slv();
    }
}