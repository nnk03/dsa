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

class NO_TOPO_ORDER : std::exception
{
public:
    NO_TOPO_ORDER()
    {
        co("NO TOPO ORDER");
    }
};

class Graph
{
private:
    ll num_vertices;
    ll num_edges;
    vector<head *> adj_list;
    unordered_map<ll, ll> visited;
    unordered_map<ll, char> colour;
    unordered_map<ll, ll> start;
    unordered_map<ll, ll> finish;
    unordered_map<ll, ll> parent;
    vector<ll> topo_order;
    ll time;

public:
    Graph(ll n, ll m)
    {
        this->num_vertices = n;
        this->num_edges = m;
        for_loop(i, 0, n)
        {
            head *temp = createHead(i);
            this->adj_list.push_back(temp);
        }
        for_loop(i, 0, n)
        {
            this->visited[i] = 0;
            this->colour[i] = 'w';
            this->start[i] = llma;
            this->finish[i] = llmi;
            this->parent[i] = -1;
        }
        this->time = 0;
        this->topo_order = {};
    }

    Graph(ll n, vector<pair<ll, ll>> edges, bool undirected = false)
    {
        ll m = edges.size();
        this->num_vertices = n;
        this->num_edges = m;
        for_loop(i, 0, n)
        {
            head *temp = createHead(i);
            this->adj_list.push_back(temp);
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
            this->colour[i] = 'w';
            this->start[i] = llma;
            this->parent[i] = -1;
            this->finish[i] = llmi;
        }
        this->time = 0;
        this->topo_order = {};
    }

    void reset_dfs(bool topo_reset = true)
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
        if (topo_reset)
            this->topo_order = {};
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

    void iterative_dfs_topo_cpp()
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
        vl t = this->topo_order;
        reverse(full(t));
        this->topo_order = t;
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
            if (this->colour[u] == 'g')
                throw NO_TOPO_ORDER();
            // above condition is wrong or right in iterative calls??
            if (this->colour[u] == 'w')
            {
                // ties are broken in decreasing order because of stack
                this->time++;
                this->start[u] = time;
                this->colour[u] = 'g';
                head *h = this->adj_list[u];
                node *temp = h->adj_head;
                while (temp)
                {
                    s.push(temp->val);
                    this->parent[temp->val] = u;
                    temp = temp->next;
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
            this->topo_order.pb(u);
        }
        return;
    }

    void dfs_topo_cpp()
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
        vl t = this->topo_order;
        // for (auto val : t)
        // {
        //     cval(val);
        // }
        cout << new_line;
        reverse(full(t));
        this->topo_order = t;
    }

    void print_topo_order()
    {
        for (auto val : this->topo_order)
        {
            cval(val);
        }
        cout << new_line;
    }

    void dfs_explore(ll vertex)
    {
        this->time++;
        this->start[vertex] = time;
        this->colour[vertex] = 'g';
        head *h = this->adj_list[vertex];
        node *temp = h->adj_head;
        ll neighbour;
        while (temp)
        {
            neighbour = temp->val;
            if (this->colour[neighbour] == 'g')
            {
                throw NO_TOPO_ORDER();
            }
            // above condition is wrong or right??????
            if (this->colour[neighbour] == 'w')
            {
                this->parent[neighbour] = vertex;
                dfs_explore(neighbour);
            }
            temp = temp->next;
        }
        this->colour[vertex] = 'b';
        this->time++;
        this->finish[vertex] = time;
        this->topo_order.push_back(vertex);
        return;
    }

    void printSLL(head *h)
    {
        printSLL(h->adj_head);
    }

    void printSLL(node *start)
    {
        node *temp = start;
        while (temp)
        {
            cval(temp->val);
            temp = temp->next;
        }
        cout << new_line;
    }
    void push(head *h, node *val_node)
    {
        if (h->adj_head == NULL)
        {
            h->adj_head = val_node;
            return;
        }
        // place it in correct sorted position
        node *parent = NULL;
        node *temp = h->adj_head;
        while (temp && temp->val < val_node->val)
        {
            parent = temp;
            temp = temp->next;
        }
        if (!parent)
        {
            val_node->next = h->adj_head;
            h->adj_head = val_node;
            return;
        }
        val_node->next = parent->next;
        parent->next = val_node;
        return;
    }

    void addEdge(ll x, ll y)
    {
        // adding edge from x to y
        head *vertex = this->adj_list[x];
        node *to_push = createNode(y);
        push(vertex, to_push);
    }

    void printGraph()
    {
        for_loop(i, 0, this->num_vertices)
        {
            co("Vertices adjacent to " << i);
            head *temp = this->adj_list[i];
            printSLL(temp);
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
        // g->addEdge(b, a);
    }
    g->printGraph();
    cout << new_line;

    g->dfs_topo_cpp();
    g->print_start_finish();
    // recursive topo working ?????
    // g->print_topo_order();
    cout << new_line;
    // g->iterative_dfs_topo_cpp();
    // g->print_topo_order();
    // iterative topo not working??????

    // g->print_start_finish();

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
