#include <bits/stdc++.h>

#define ll long long
#define us unsigned short
#define ui unsigned int

using namespace std;

vector<vector<int> > g;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (const int &u : g[v]) {
        if (!visited[u])
            dfs(u);
    }
}

int main() {  // Tests
    vector<bool> visited_expected;

    g = {
        {1, 2, 3},
        {0, 3},
        {0},
        {0, 1},
        {5, 6},
        {4, 6},
        {4, 5}
    };
    visited.resize(7);
    dfs(0);
    visited_expected = {1, 1, 1, 1, 0, 0, 0};
    if (visited != visited_expected) {
        for (const int &x : visited) cout << x << ' ';
        cout << "should be ";
        for (const int &x : visited_expected) cout << x << ' ';
        return 1;
    }

    g[2].push_back(6);
    visited.clear();
    visited.resize(7);
    dfs(0);
    visited_expected = {1, 1, 1, 1, 1, 1, 1};
    if (visited != visited_expected) {
        for (const int &x : visited) cout << x << ' ';
        cout << "should be ";
        for (const int &x : visited_expected) cout << x << ' ';
        cout << '\n';
        return 1;
    }

    g = {
        {1, 2},
        {3, 4},
        {5, 6},
        {1},
        {1},
        {2},
        {2},
        {8},
        {7},
        {}
    };
    visited.clear();
    visited.resize(10);
    dfs(0);
    visited_expected = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0};
    if (visited != visited_expected) {
        for (const int &x : visited) cout << x << ' ';
        cout << "should be ";
        for (const int &x : visited_expected) cout << x << ' ';
        cout << '\n';
        return 1;
    }

    cout << "All tests passed!\n";
    return 0;
}