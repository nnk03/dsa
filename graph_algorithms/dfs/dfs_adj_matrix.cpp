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

class Graph
{
private:
    ll num_vertices;
    ll num_edges;
    vector<vector<ll>> adj_matrix;
    unordered_map<ll, ll> visited;
    unordered_map<ll, char> colour;
    unordered_map<ll, ll> start;
    unordered_map<ll, ll> finish;
    unordered_map<ll, ll> parent;
    ll time;

public:
    Graph(ll n, ll m)
    {
        this->num_vertices = n;
        this->num_edges = m;
        for_loop(i, 0, this->num_vertices)
        {
            vector<ll> row(this->num_vertices, 0);
            this->adj_matrix.pb(row);
        }
        for_loop(i, 0, n)
        {
            this->visited[i] = 0;
            this->parent[i] = -1;
            this->colour[i] = 'w';
        }
    }

    Graph(ll n, vector<pair<ll, ll>> edges, bool undirected = false)
    {
        ll m = edges.size();
        this->num_vertices = n;
        this->num_edges = m;
        for_loop(i, 0, this->num_vertices)
        {
            vector<ll> row(this->num_vertices, 0);
            this->adj_matrix.pb(row);
        }
        for (auto p : edges)
        {
            this->addEdge(p.first, p.second);
            if (undirected)
                this->addEdge(p.second, p.first);
        }
        for_loop(i, 0, n)
        {
            this->visited[i] = 0;
            this->parent[i] = -1;
            this->colour[i] = 'w';
        }
    }

    void reset_dfs()
    {
        for_loop(i, 0, this->num_vertices)
        {
            this->visited[i] = 0;
            this->colour[i] = 'w';
            this->start[i] = llma;
            this->finish[i] = llmi;
            this->parent[i] = -1;
        }
        this->time = 0;
    }

    void print_start_finish()
    {
        for_loop(i, 0, this->num_vertices)
        {
            co("Start time of " << i << " is " << this->start[i]);
            co("Finish time of " << i << " is " << this->finish[i]);
            cout << new_line;
        }
    }

    void iterative_dfs_cpp()
    {

        reset_dfs();
        this->time = 0;
        // for_loop(i, 0, this->num_vertices)
        for_loop_reverse(i, this->num_vertices - 1, -1)
        {
            if (this->colour[i] == 'w')
            {
                iterative_dfs_explore(i);
            }
        }
        return;
    }

    void iterative_dfs_explore(ll vertex)
    {
        // this->time++;
        // this->start[vertex] = time;

        stack<ll> s;
        stack<ll> finish_stack;
        s.push(vertex);
        ll u, neighbour;
        while (s.size())
        {
            u = s.top();
            s.pop();
            if (this->colour[u] == 'w')
            {
                // ties are broken in decreasing order because of stack
                this->time++;
                this->start[u] = time;
                this->colour[u] = 'g';
                // head *h = this->adj_list[u];
                // node *temp = h->adj_head;
                vl row = this->adj_matrix[u];
                // while (temp)
                // {
                //     s.push(temp->val);
                //     this->parent[temp->val] = u;
                //     temp = temp->next;
                // }
                for_loop(i, 0, this->num_vertices)
                {
                    neighbour = i;
                    if (row[i] && this->colour[neighbour] == 'w')
                    {
                        s.push(neighbour);
                        this->parent[neighbour] = u;
                    }
                }
                this->colour[u] = 'b';
                finish_stack.push(u);
            }
        }
        while (finish_stack.size())
        {
            u = finish_stack.top();
            finish_stack.pop();

            this->time++;
            this->finish[u] = time;
        }
        return;
    }

    void dfs_cpp()
    {
        reset_dfs();
        this->time = 0;
        for_loop(i, 0, this->num_vertices)
        {
            if (this->colour[i] == 'w')
            {
                dfs_explore(i);
            }
        }
    }

    void dfs_explore(ll vertex)
    {
        this->time++;
        this->start[vertex] = time;
        this->colour[vertex] = 'g';
        ll neighbour;
        vl row = this->adj_matrix[vertex];
        for_loop(i, 0, this->num_vertices)
        {
            neighbour = i;
            if (row[i] && this->colour[neighbour] == 'w')
            {
                this->parent[neighbour] = vertex;
                dfs_explore(neighbour);
            }
        }
        this->colour[vertex] = 'b';
        this->time++;
        this->finish[vertex] = time;
        return;
    }

    void addEdge(ll x, ll y)
    {
        // adding edge from x to y
        this->adj_matrix[x][y] = 1;
        // this->adj_matrix[y][x] = 1;
        // if undirected
    }

    void printGraph()
    {
        for_loop(i, 0, this->num_vertices)
        {
            vl row = this->adj_matrix[i];
            co("Vertices adjacent to " << i);
            for_loop(j, 0, this->num_vertices)
            {
                if (row[j])
                    cval(j);
            }
            cout << new_line;
            cout << new_line;
        }
    }
};

void cp()
{
    ll n, m;
    cin >> n >> m;
    Graph *g = new Graph(n, m);
    ll a, b;
    while (m--)
    {
        cin >> a >> b;
        g->addEdge(a, b);
        g->addEdge(b, a);
    }
    g->printGraph();
    cout << new_line;

    g->dfs_cpp();
    g->print_start_finish();

    cout << new_line;
    g->iterative_dfs_cpp();
    g->print_start_finish();

    // vector<pair<ll, ll>> edges;
    // ll a, b;
    // while (m--)
    // {
    //     cin >> a >> b;
    //     edges.push_back({a, b});
    // }
    // Graph *g = new Graph(n, edges);
    // g->printGraph();
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
