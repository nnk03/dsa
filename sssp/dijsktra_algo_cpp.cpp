#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
//
//
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #endif
//
//

using namespace std;

#define ll long long
// #define llll long long
#ifndef llll
#define llll int
#endif
#define ld long double
#ifndef ld
#define ld double
#endif
#define ima INT_MAX
#define imi INT_MIN
#define uima UINT_MAX
#ifndef ll
#define ll int
#define llma INT_MAX
#define llmi INT_MIN
#define ull unsigned int
#define ullma UINT_MAX
#else
#define llma __LONG_LONG_MAX__
#define llmi LLONG_MIN
#define ull unsigned long long
#define ullma ULLONG_MAX
#endif
#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vl>
#define vvi vector<vi>
#define vpl vector<pair<ll, ll>>
#define vpi vector<pair<int, int>>
#define new_line '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
#define pl pair<ll, ll>
#define pii pair<int, int>
#define full(v) v.begin(), v.end()
#define rfull(v) v.rbegin(), v.rend()
#define vln(v, n) vector<ll> v(n, 0)
#define vin(v, n) vector<int> v(n, 0)
#define minof(v) min_element(full(v))
#define maxof(v) max_element(full(v))
// #define maxPQ priority_queue<ll>
// #define minPQ priority_queue<ll, vector<ll>, greater<int>>
#define lb(v, x) lower_bound(full(v), x)
#define ub(v, x) upper_bound(full(v), x)
#define co(val) cout << val << '\n'
#define cval(val) cout << val << ' '
#define for_loop(i, a, b) for (llll i = a; i < b; i++)
#define for_loop_reverse(i, a, b) for (llll i = a; i > b; i--)
// #define receive(arr, n) \
//     for_loop(asdfasdf, 0, n) { cin >> arr[asdfasdf]; }
//
//
#define receive(arr)           \
    for (auto &asdfasdf : arr) \
    {                          \
        cin >> asdfasdf;       \
    }

#define print_all(arr)           \
    for (auto asdfasdf : arr)    \
    {                            \
        cout << asdfasdf << ' '; \
    }                            \
    cout << new_line;
#define print_all_in_separate_lines(arr) \
    for (auto asdfasdf : arr)            \
    {                                    \
        co(asdfasdf);                    \
    }
#define Y "YES"
#define N "NO"
//
//
//
#ifdef ONLINE_JUDGE
#define debug(x) ;
#endif
//

template <typename T>
using maxPQ = priority_queue<T>;
template <typename T>
using minPQ = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
llll find_gcd(T &v)
{
    llll ans = v[0];
    for (auto val : v)
    {
        if (val > 0)
        {
            ans = gcd(ans, val);
        }
    }
    return ans;
};

template <typename T>
llll find_sum(T &v)
{
    llll ans = 0;
    for (auto val : v)
    {
        ans += val;
    }
    return ans;
};

template <typename T>
unordered_map<llll, llll> Counter(T &v)
{
    unordered_map<llll, llll> m;
    for (auto val : v)
    {
        m[val]++;
    }
    return m;
};
template <typename T>
map<llll, llll> Counter_map(T &v)
{
    map<llll, llll> m;
    for (auto val : v)
    {
        m[val]++;
    }
    return m;
};

ll find_pow(ll a, ll b, ll prime)
{
    if (b == 0)
        return 1;
    ll temp = find_pow(a, b / 2, prime);
    if (b % 2)
        return ((temp % prime) * (((temp % prime) * (a % prime)) % prime)) % prime;
    else
        return ((temp % prime) * (temp % prime)) % prime;
}
#ifndef llll
llll find_pow(llll a, llll b, llll prime)
{
    if (b == 0)
        return 1;
    llll temp = find_pow(a, b / 2, prime);
    if (b % 2)
        return ((temp % prime) * (((temp % prime) * (a % prime)) % prime)) % prime;
    else
        return ((temp % prime) * (temp % prime)) % prime;
}
#endif
// #define MOD 1e9 + 7
const int MOD = (int)(1e9 + 7);
#define INF 1e18
template <typename T>
// for vector
using V = vector<T>;
// vector of bool
using vb = V<bool>;
// vector of long double
using vd = V<long double>;
// vector of string
using vstr = V<string>;

void preCalculate();
void cp();
//
//
//
//
//

// ll C = 0;

vector<bool> Sieve(llll n)
{
    vector<bool> Prime(max((llll)3, n + 1), 1);
    Prime[0] = Prime[1] = false;

    for (llll i = 2; i * i <= n; i++)
    {
        if (Prime[i])
        {
            for (llll j = i * i; j <= n; j += i)
            {
                Prime[j] = false;
            }
        }
    }
    return Prime;
}

void preCalculate()
{
}

typedef struct Node node;
struct Node
{
    ll val;
    node *next;
};

typedef struct Head head;
struct Head
{
    ll vertex;
    node *adj_head;
};

node *createNode(ll val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

head *createHead(ll val)
{
    head *temp = (head *)malloc(sizeof(head));
    temp->vertex = val;
    temp->adj_head = NULL;
    return temp;
}

class Graph
{
private:
    int num_vertices;
    int num_edges;
    // vector<vector<int>> adj;
    vector<vector<pair<int, int>>> adj;
    // map<pair<int, int>, int> weight;
    unordered_map<int, int> parent;
    unordered_map<int, int> d;

public:
    Graph(int n, int m)
    {
        this->num_vertices = n;
        this->num_edges = m;
        this->adj = vector<vector<pair<int, int>>>(n);
        while (m--)
        {
            int x, y, w;
            cin >> x >> y >> w;
            adj[x].eb(y, w);
            adj[y].eb(x, w);
            // undirected graph
        }
    }

    bool print_path(int source, int vertex)
    {
        if (source == vertex)
        {
            cval(source);
            return true;
        }
        else if (parent[vertex] == -1)
        {
            co("No path");
            return false;
        }
        else
        {
            if (print_path(source, parent[vertex]))
            {
                cval(vertex);
                return true;
            }
            return false;
        }
    }

    void Dijkstra(int source)
    {
        for (int i = 0; i < this->num_vertices; i++)
        {
            d[i] = INT_MAX;
        }
        d[source] = 0;
        // minPQ<pair<int, int>> q;
        maxPQ<pair<int, int>> q;
        vector<int> processed(num_vertices);
        q.push(mp(0, source));
        while (!q.empty())
        {
            int a = q.top().second;
            q.pop();
            if (processed[a])
                continue;
            processed[a] = 1;
            for (auto u : adj[a])
            {
                int b = u.first, w = u.second;
                if (d[a] + w < d[b])
                {
                    d[b] = d[a] + w;
                    q.push(mp(-d[b], b));
                }
            }
        }
    }
};

void cp()
{
    int n, m;
    cin >> n >> m;
    Graph *g = new Graph(n, m);

    int source = 0;
    int vertex;
    cin >> vertex;
    g->Dijkstra(source);
    g->print_path(0, vertex);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("./input_file_check.txt", "r", stdin);
    //     freopen("./output_file_check.txt", "w", stdout);
    //     freopen("./error_file_check.txt", "w", stderr);
    // #endif
    bool interactive_question = false;
    if (!interactive_question)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }
    bool multi_test_case = false;
    bool single_test_case = !multi_test_case;
    //
    //
    //
    //
    //
    bool pre_calculate = true;

    //
    //
    //
    //
    bool check_time = true;
    if (check_time)
    {
        auto start_time_of_program = chrono::high_resolution_clock::now();
        int t;
        if (pre_calculate)
            preCalculate();
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

        auto end_time_of_program = chrono::high_resolution_clock::now();

        double time_taken_for_program = chrono::duration_cast<chrono::nanoseconds>(end_time_of_program - start_time_of_program).count();
        time_taken_for_program *= 1e-9;
        cerr << "\nTIME TAKEN FOR THE PROGRAM\n";
        cerr << fixed << time_taken_for_program << setprecision(9) << endl;
    }

    //
    //
    //
    //
    else
    {
        int t;
        if (pre_calculate)
            preCalculate();
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
    }

    return 0;
}
