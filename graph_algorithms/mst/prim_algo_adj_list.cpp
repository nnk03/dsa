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
    ll weight;
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

ll parent(ll i)
{
    return (i % 2) ? i / 2 : i / 2 - 1;
}
ll left(ll i)
{
    return (2 * i + 1);
}
ll right(ll i)
{
    return 2 * (i + 1);
}

// max-heapify O(lg n)
// build-max-heap O(n)
// max-heap-insert, heap-extract-max, heap-increase-key, heap-maximum -> O(lg n)
void min_heapify(vpl &v, ll i, ll heap_size)
{
    ll l = left(i);
    ll r = right(i);
    ll index_minimum = i;
    if (l < heap_size && v[l] < v[index_minimum])
    {
        index_minimum = l;
    }
    if (r < heap_size && v[r] < v[index_minimum])
    {
        index_minimum = r;
    }
    if (index_minimum != i)
    {
        pl temp = v[index_minimum];
        v[index_minimum] = v[i];
        v[i] = temp;
        min_heapify(v, index_minimum, heap_size);
    }
}

void build_min_heap(vpl &v)
{
    ll heap_size = v.size();
    for_loop_reverse(i, (ll)(v.size() / 2), -1)
    {
        min_heapify(v, i, heap_size);
    }
    // print_all(v);
    // cout << new_line;
}

ll heap_minimum(vl &v)
{
    return v[0];
}

pl heap_extract_min(vpl &v, ll *heapsize_ptr)
{
    if (v.size() == 0)
        return {llma, llma};

    pl min = v[0];
    v[0] = *v.rbegin();
    v.pop_back();
    *heapsize_ptr = *heapsize_ptr - 1;
    min_heapify(v, 0, *heapsize_ptr);
    return min;
}

void heap_decrease_key(vpl &v, ll index, pl key)
{
    if (key > v[index])
    {
        co("ERROR: NEW VALUE IS GREATER THAN OLD VALUE");
        return;
    }
    v[index] = key;

    // ll temp;
    // while (index > 0 && v[parent(index)] < v[index])
    // {
    //     temp = v[index];
    //     v[index] = v[parent(index)];
    //     v[parent(index)] = temp;
    //     index = parent(index);
    // }

    // another way of implementing: find the topmost parent with value less than key

    while (index > 0 && v[parent(index)] < key)
    {
        v[index] = v[parent(index)];
        index = parent(index);
    }
    v[index] = key;
    return;
}

void min_heap_insert(vpl &v, pl key, ll *heap_size_ptr)
{
    *heap_size_ptr = *heap_size_ptr + 1;
    if (v.size() >= *heap_size_ptr)
    {
        v[*heap_size_ptr - 1] = {llma, llma};
    }
    else
    {
        v.pb({llma, llma});
        // is it correct??
    }
    heap_decrease_key(v, *heap_size_ptr - 1, key);
    return;
}

class Graph
{
private:
    ll num_vertices;
    ll num_edges;
    vector<head *> adj_list;
    vector<pl> edge_set_of_mst;
    // unordered_map<pl, ll> weight;
    map<pl, ll> weight;
    // unordered map would be better ????
    // but how to create hash function for pair to int

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
    }

    Graph(ll n, vector<pair<ll, pair<ll, ll>>> edges, bool undirected = false)
    {
        // vector weight, pair of vertices
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
            this->addEdge(p.second.first, p.second.second, p.first);
            // this->weight[{p.second.first, p.second.second}] = p.first;
            if (undirected)
            {
                this->addEdge(p.second.second, p.second.first, p.first);
                // this->weight[{p.second.second, p.second.first}] = p.first;
            }
        }
    }

    Graph *mst_prim(ll root)
    {
        unordered_map<ll, ll> cost;
        unordered_map<ll, ll> parent;
        for_loop(i, 0, this->num_vertices)
        {
            cost[i] = llma;
            parent[i] = -1;
        }
        cost[root] = 0;
        // vector<pl> v = {};
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;

        q.push({cost[root], 0});
        vector<int> is_in_cut_s(this->num_vertices, 0);
        vector<int> inQueue(this->num_vertices, 1);
        is_in_cut_s[root] = 1;
        // inQueue[root] = 0;

        while (q.size())
        {
            pl p = q.top();
            q.pop();
            ll u = p.second;
            // co("HERE");
            // if (is_in_cut_s[u])
            //     continue;
            is_in_cut_s[u] = 1;
            inQueue[u] = 0;

            auto h = this->adj_list[u];
            // if (!h)
            //     co("HERE.......");
            node *temp = h->adj_head;
            while (temp)
            {
                if (!is_in_cut_s[temp->val] && this->weight[{u, temp->val}] < cost[temp->val])
                {
                    cost[temp->val] = this->weight[{u, temp->val}];
                    parent[temp->val] = u;
                    q.push({cost[temp->val], temp->val});
                    // this method can be inefficient because, we might add same vertex everytime but will decreasing costs ?????????
                    // how to do the update method of queue
                }
                temp = temp->next;
            }
        }

        vector<pair<ll, pl>> edge_set = {};
        for (auto p : parent)
        {
            if (p.second == -1)
                continue;
            edge_set.push_back({this->weight[p], p});
            edge_set.push_back({this->weight[p], {p.second, p.first}});
        }
        Graph *g = new Graph(this->num_vertices, edge_set);
        return g;

        // for_loop(i, 0, this->num_vertices)
        // {
        //     v.push_back({cost[i], i});
        // }

        // vector<int> inQueue(this->num_vertices, 1);
        // ll heapsize = v.size();
        // build_min_heap(v);

        // while(v.size()){
        //     pl p = heap_extract_min(v, &heapsize);
        //     ll u = p.second;
        //     inQueue[u] = 0;
        //     auto h = this->adj_list[u];
        //     node *temp = h->adj_head;
        //     while(temp){
        //         ll neighbour = temp->val;
        //         if(inQueue[neighbour] && this->weight[{u, neighbour}] < cost[neighbour]){
        //             cost[neighbour] = this->weight[{u, neighbour}];
        //             parent[neighbour] = u;

        //         }
        //     }

        // }
    }

    // void mst_prim(ll root)
    // {
    //     unordered_map<ll, ll> cost;
    //     unordered_map<ll, ll> parent;
    //     for_loop(i, 0, this->num_vertices)
    //     {
    //         cost[i] = llma;
    //         parent[i] = -1;
    //     }
    //     cost[root] = 0;

    //     vector<pl> v = {};
    //     for_loop(i, 0, this->num_vertices){
    //         v.push_back({cost[i], i});
    //     }
    //     // vector of elements which are {cost, vertex}

    //     priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q(full(v));

    //     vector<int> inQueue(this->num_vertices, 1);
    //     // initially all vertices are in queue

    //     while(q.size()){
    //         auto p = q.top();
    //         q.pop();
    //         ll u = p.second;
    //         inQueue[u] = 0;
    //         auto h = this->adj_list[u];
    //         node *temp = h->adj_head;
    //         while(temp){
    //             ll neighbour = temp->val;
    //             if(inQueue[neighbour] && this->weight[{u, neighbour}] < cost[neighbour]){
    //                 parent[neighbour] = u;
    //                 cost[neighbour] = weight[{u, neighbour}];

    //             }

    //         }

    //     }

    // }

    void printSLL(head *h)
    {
        printSLL(h->adj_head);
    }

    vpl getEdgeSetOfGraph()
    {
        vpl edge_set = {};
        for (auto h : this->adj_list)
        {
            if (h)
            {
                node *temp = h->adj_head;
                ll a = h->vertex;

                while (temp)
                {
                    ll b = temp->val;
                    edge_set.push_back({a, b});
                    temp = temp->next;
                }
            }
        }
        return edge_set;
    }

    // bool compare_weights(pl e1, pl e2)
    // {
    //     return this->weight[e1] < this->weight[e2];
    // }

    // void mst_kruskal()
    // {
    //     vector<pl> edge_set_of_graph = this->getEdgeSetOfGraph();
    //     DisjointSet *d = new DisjointSet(this->num_vertices);
    //     // assumes vertices are numbered from 0 to n-1
    //     sort(full(edge_set_of_graph), [&](pl e1, pl e2) -> bool
    //          { return this->compare_weights(e1, e2); });

    //     vpl edge_set_mst = {};

    //     for (auto e : edge_set_of_graph)
    //     {
    //         ll u = e.first;
    //         ll v = e.second;
    //         if (d->findSet(u) != d->findSet(v))
    //         {
    //             edge_set_mst.push_back({u, v});
    //             d->union_set(u, v);
    //         }
    //     }
    //     this->edge_set_of_mst = edge_set_mst;
    // }

    // void print_edge_set_mst()
    // {
    //     for (auto e : this->edge_set_of_mst)
    //     {
    //         co(e.first << ' ' << e.second << ' ' << "weight is " << this->weight[e]);
    //     }
    // }

    // Graph *getMST(bool undirected = false)
    // {
    //     this->mst_kruskal();
    //     vector<pair<ll, pl>> e_set = {};
    //     for (auto e : this->edge_set_of_mst)
    //     {
    //         e_set.push_back({this->weight[e], e});
    //         if (undirected)
    //             e_set.push_back({this->weight[e], {e.second, e.first}});
    //     }

    //     Graph *g = new Graph(this->num_vertices, e_set);
    //     return g;
    // }

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

    void addEdge(ll x, ll y, ll weight)
    {
        // adding edge from x to y
        head *vertex = this->adj_list[x];
        this->weight[{x, y}] = weight;
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
            node *tempnode = temp->adj_head;
            while (tempnode)
            {
                ll b = tempnode->val;
                cval((this->weight[{i, b}]));
                tempnode = tempnode->next;
            }
            cout << new_line;
        }
    }
};

void cp()
{
    ll n, m;
    cin >> n >> m;
    Graph *g = new Graph(n, m);
    ll a, b, weight;
    while (m--)
    {
        cin >> a >> b >> weight;
        g->addEdge(a, b, weight);
        g->addEdge(b, a, weight);
    }
    // g->printGraph();
    cout << new_line;
    ll root;
    cin >> root;
    g->printGraph();

    cout << new_line;
    cout << new_line;
    cout << new_line;

    Graph *g_mst = g->mst_prim(root);
    g_mst->printGraph();

    // didn't yet check for DIRECTED GRAPHS............***********************************************************************............***********************************************************************............***********************************************************************............***********************************************************************............***********************************************************************............***********************************************************************............***********************************************************************............***********************************************************************............***********************************************************************............***********************************************************************............***********************************************************************............***********************************************************************............***********************************************************************
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

// sample input

// 9 14
// 0 1 4
// 0 7 8
// 1 7 11
// 1 2 8
// 7 8 7
// 8 6 6
// 7 6 1
// 2 8 2
// 6 5 2
// 2 5 4
// 2 3 7
// 3 5 14
// 3 4 9
// 4 5 10
