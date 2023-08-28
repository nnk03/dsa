#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> v({1, 2, 3, 4, 5, 6});
    vector<int> prefix_sums(v.size() + 1, 0);
    // prefix_sums.push_back(0);
    for (int i = 0; i < v.size(); i++)
    {
        // prefix_sums.push_back(prefix_sums[i] + v[i]);
        prefix_sums[i + 1] = v[i] + prefix_sums[i];
    }
    for (int x : prefix_sums)
    {
        cout << x << ' ';
    }

    cout << endl;

    return 0;
}