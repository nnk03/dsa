#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vl vector<ll>
#define new_line '\n'
#define mp make_pair
#define pb push_back
#define pf push_front
#define pl pair<ll, ll>
#define llma __LONG_LONG_MAX__
#define llmi LLONG_MIN
#define full(v) v.begin(), v.end()
#define rfull(v) v.rbegin(), v.rend()
#define vl vector<ll>
#define vpl vector<pair<ll, ll>>
#define vi vector<int>
#define vi_n(v, n) vector<int> v(n, 0)
#define vl_n(v, n) vector<ll> v(n, 0)
#define vpl vector<pair<ll, ll>>
#define minOf(v) min_element(full(v))
#define maxOf(v) max_element(full(v))
#define maxPQ priority_queue<ll>
#define minPQ priority_queue<ll, vector<ll>, greater<int>>
#define lb(v, x) lower_bound(full(v), x)
#define ub(v, x) upper_bound(full(v), x)
#define co(val) cout << val << '\n'
#define cval(val) cout << val << ' '
#define for_loop(i, a, b) for (ll i = a; i < b; i++)
#define for_loop_reverse(i, a, b) for (ll i = a; i > b; i--)
#define receive(arr, n) \
    for_loop(i, 0, n) { cin >> arr[i]; }
#define print_all(arr)    \
    for (auto x : arr)    \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << new_line;
#define print_all_in_separate_lines(arr) \
    for (auto x : arr)                   \
    {                                    \
        co(x);                           \
    }

// int c = 1;

class DisjointSet
{
private:
    ll num;
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

public:
    DisjointSet(ll num)
    {
        this->num = num;
        for_loop(i, 1, num + 1)
        {
            makeSet(i);
        }
    }

    void makeSet(ll x)
    {
        this->parent[x] = x;
        this->rank[x] = 0;
    }

    ll findParent(ll x)
    {
        // if (x <= 0)
        //     return 0;
        // while (this->parent[x] != x && x != 0)
        // {
        //     x = this->parent[x];
        // }
        // if (x == 0)
        //     return 0;
        // return x;
        if (x <= 0)
            return 0;

        if (x != this->parent[x])
        {
            this->parent[x] = findParent(this->parent[x]);
        }
        return this->parent[x];
    }

    void union_set(ll x, ll y)
    {
        link(findParent(x), findParent(y));
    }

    void link(ll x, ll y)
    {
        if (x == 0 || y == 0)
            return;
        if (this->rank[x] < this->rank[y])
        {
            this->parent[x] = y;
        }
        else if (this->rank[x] > this->rank[y])
        {
            this->parent[y] = x;
        }
        else
        {
            this->parent[y] = x;
            this->rank[x]++;
        }
    }

    void printSet()
    {
        vector<vl> v(this->num + 1);
        for_loop(i, 1, this->num + 1)
        {
            ll rep = this->findParent(i);
            v[rep].push_back(i);
        }

        for_loop(i, 1, this->num + 1)
        {
            vl vec = v[i];
            for (auto val : vec)
            {
                cval(val);
            }
            cout << new_line;
        }
    }

    ll getRank(ll x)
    {
        return this->rank[x];
    }
};

void cp()
{
    ll num = 10;
    DisjointSet *d = new DisjointSet(num);
    d->printSet();
    d->union_set(2, 3);
    d->union_set(2, 5);
    d->union_set(1, 10);
    d->printSet();
    co(d->getRank(d->findParent(5)));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    bool single_test_case = true;
    if (single_test_case)
        t = 1;
    else
        cin >> t;
    // cin >> t;
    // t = 1;
    while (t--)
    {
        cp();
    }
    return 0;
}
