#include <bits/stdc++.h>

#define ll long long
#define us unsigned short
#define ui unsigned int
#define INF 999999999

using namespace std;

vector<vector<pair<int, int> > > g;

vector<int> dijkstra(int s) {
    int v, u;
    vector<int> ws(g.size(), INF);
    queue<int> q;
    q.push(s);
    ws[s] = 0;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (const pair<int, int> &u : g[v]) {
            if (ws[v] + u.second < ws[u.first]) {
                ws[u.first] = ws[v] + u.second;
                q.push(u.first);
            }
        }
    }

    return ws;
}

int main() {  // Tests
    vector<int> ws, ws_expected;

    g = {
        {{1, 2}, {2, 1}},
        {{0, 2}, {2, 3}, {3, 3}},
        {{0, 1}, {1, 3}, {4, 3}},
        {{1, 3}, {4, 5}},
        {{2, 3}, {3, 5}}
    };
    ws = dijkstra(0);
    ws_expected = {0, 2, 1, 5, 4};
    if (ws != ws_expected) {
        for (const int &x : ws) cout << x << ' ';
        cout << "should be ";
        for (const int &x : ws_expected) cout << x << ' ';
        cout << '\n';
        return 1;
    }

    g = {
        {{1, 7}, {3, 2}},
        {{0, 7}, {2, 1}, {3, 3}},
        {{1, 1}, {3, 9}, {4, 1}},
        {{0, 2}, {1, 3}, {2, 9}, {5, 3}},
        {{2, 1}, {5, 2}, {6, 10}},
        {{3, 3}, {4, 2}},
        {{4, 10}}
    };
    ws = dijkstra(0);
    ws_expected = {0, 5, 6, 2, 7, 5, 17};
    if (ws != ws_expected) {
        for (const int &x : ws) cout << x << ' ';
        cout << "should be ";
        for (const int &x : ws_expected) cout << x << ' ';
        cout << '\n';
        return 1;
    }

    cout << "All tests passed!\n";
    return 0;
}