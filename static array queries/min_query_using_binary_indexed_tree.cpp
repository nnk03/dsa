#include <bits/stdc++.h>
using namespace std;

// in this program, arrays are assumed to be 1-indexed which means arr[0] will be 0 always

int p(int k)
{
    // p(k) is the largest power of 2 which divides k
    return k & (-k);
}

// the following function calculates the value of sum of array(1, k)
int sum_arr(int k, vector<int> &tree)
{
    int s = 0;
    while (k >= 1)
    {
        s += tree[k];
        k -= p(k);
    }
    return s;
}

// the following function increases the array value at position k by x (x can be positive or negative)

void add(int k, int x, vector<int> &tree)
{
    int n = tree.size() - 1;
    // since tree is 1-indexed;
    while (k <= n)
    {
        tree[k] += x;
        k += p(k);
    }
}
// not completed
// >......................................................................................
vector<int> &make_tree(vector<int> &v)
{
    vector<int> tree(v.size(), 0);
    for (int i = 0; i < v.size(); i++)
    {
        tree[i] = v[i];
    }
    // how to MAKE the tree efficiently?????
    return tree;
    // how to return a vector?????
}

int main()
{
}