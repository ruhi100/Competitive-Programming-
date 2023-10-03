#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <climits>
#include <iomanip>

using ll = long long;

constexpr ll mod = 998244353;
constexpr ll maxn = 100000;

ll inv(long long i){
    return i <= 1 ? i : mod - (mod / i) * inv(mod % i) % mod;
}

std::vector<int> t;

void update(int v, int tl, int tr, int val, int idx){
    if (tl == tr){
        t[v] = val;
    } else {
        int tm = (tl + tr) >> 1;
        if (idx <= tm)
            update(2*v, tl, tm, val, idx);
        else 
            update(2*v+1, tm+1, tr, val, idx);
        t[v] = std::max(t[2*v], t[2*v+1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
    if (l > r)
        return INT_MIN;
    if (tl == l && tr == r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return std::max(query(2*v, tl, tm, l, std::min(tm, r))
            , query(2*v+1, tm+1, tr, std::max(tm+1, l), r));
}

void solve(){
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i=0;i<n;i++){
        std::cin >> a[i];
    }

    struct Query{
        int l;
        int r;
        int idx;
    };

    std::vector<Query> queries(q);
    for (int i=0;i<q;i++){
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        queries[i] = {l, r, i};
    }

    struct Info{
        int l;
        int r;
        int idx;
    };

    std::vector<Info> info(n, {-1, (int)1e6});
    std::stack<int> s;
    for (int i=0;i<n;i++){
        info[i].idx = i;
        while (!s.empty() && a[i] >= a[s.top()]){
            info[s.top()].r = i;
            s.pop();
        }
        s.push(i);
    }

    s = {};
    for (int i=n-1;i>=0;i--){
        while (!s.empty() && a[i] <= a[s.top()]){
            info[s.top()].l = i;
            s.pop();
        }
        s.push(i);
    }

    std::sort(queries.begin(), queries.end(), [](const Query& left, const Query& right){
        return left.l < right.l;
    });

    // for (int i=0;i<n;i++){
    //     std::cout << info[i].l << ", " << info[i].r << "] ";
    // }
    // std::cout << '\n';

    std::sort(info.begin(), info.end(), [](const Info& left, const Info& right){
        return left.l < right.l;
    });

    std::vector<std::pair<int, int>> next_greater(n);
    for (int i=0;i<n;i++){
        next_greater[i] = {info[i].r, info[i].idx};
    }

    std::sort(next_greater.begin(), next_greater.end());
    std::vector<int> index(n);
    std::vector<int> right(n);

    t.resize(4 * n, INT_MIN);
    for (int i=0;i<n;i++){
        right[i] = next_greater[i].first;
        index[next_greater[i].second] = i;
    }

    for (int i=0;i<n;i++){
        update(1, 0, n - 1, info[i].l - info[i].r, index[info[i].idx]);
    }
    // std::cout << '\n';

    // for (int i=0;i<n;i++){
    //     std::cout << query(1, 0, n - 1, i, i) << ' ';
    // }
    // std::cout << '\n';

    std::vector<int> ans(q, -1);
    int j = 0;
    for (int i=0;i<q;i++){
        auto [l, r, idx] = queries[i];
        while (j < n && info[j].l < l){
            update(1, 0, n - 1, INT_MIN, index[info[j].idx]);
            j++;
        }

        int kl = std::lower_bound(right.begin(), right.end(), l) - right.begin();
        int kr = std::upper_bound(right.begin(), right.end(), r) - right.begin();

        // std::cout << "[kl, kr] : " << kl << ", " << kr << ", ";
        int qr = query(1, 0, n - 1, kl, kr - 1);
        // std::cout << "[" << l << ", " << r << ", " << qr << "],";
        ans[idx] = std::max(ans[idx], r - l + 3 + qr);
    }
    // std::cout << '\n';

    for (int x : ans){
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--){
        solve();
    }

    return 0;
}

/*

*/
