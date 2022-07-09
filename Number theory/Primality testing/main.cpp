#include <bits/stdc++.h>

#define ll long long
#define us unsigned short
#define ui unsigned int

using namespace std;

bool is_prime(ll n) {
    for (ll i=2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {  // Tests
    if (!is_prime(5)) {
        cout << "false should be true (on 5)\n";
        return 1;
    }
    if (!is_prime(223)) {
        cout << "false should be true (on 223)\n";
        return 1;
    }
    if (!is_prime(4987)) {
        cout << "false should be true (on 4987)\n";
        return 1;
    }
    if (!is_prime(252097800611)) {
        cout << "false should be true (on 252097800611)\n";
        return 1;
    }
    if (is_prime(4)) {
        cout << "true should be false (on 4)\n";
        return 1;
    }
    if (is_prime(28)) {
        cout << "true should be false (on 28)\n";
        return 1;
    }
    if (is_prime(3526)) {
        cout << "true should be false (on 3526)\n";
        return 1;
    }
    if (is_prime(3462146998)) {
        cout << "true should be false (on 3462146998)\n";
        return 1;
    }

    cout << "All tests passed!\n";
    return 0;
}