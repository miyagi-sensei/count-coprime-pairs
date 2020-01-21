// optimized upon v1
#include "stdc++.h"
using namespace std;

int Q;
set<int> s;
long long Beauty = 0;
clock_t elapsed = 0;

int gcd(int a, int b) {
    // clock_t start = clock();
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    // elapsed += (clock() - start);
    return a;
}

void print_set() {
    set<int>::iterator it;
    for (it=s.begin(); it!=s.end(); it++) {
        cout << (*it) << " ";
    }
    cout << "size: " << s.size() << endl;
}

long long compute_beauty() {
    long long beauty = 0;
    set<int>::iterator i, j;
    for (i=s.begin(); i!=s.end(); i++) {
        for (j=next(i); j!=s.end(); j++) {
            if (gcd(*i, *j) == 1) {
                beauty++;
            }
        }
    }
    return beauty;
}

void add_num(int n) {
    set<int>::iterator it;
    for (it=s.begin(); it!=s.end(); it++) {
        if (gcd(*it, n) == 1) {
            Beauty++;
        }
    }
    s.insert(n);
}

void remove_num(int n) {
    set<int>::iterator it;
    s.erase(n);
    for (it=s.begin(); it!=s.end(); it++) {
        if (gcd(*it, n) == 1) {
            Beauty--;
        }
    }
}

int main() {
    int type, x;

    cin >> Q;
    for (int i=0; i<Q; i++) {
        cin >> type >> x;
        if (type == 1) {
            add_num(x);
        } else {
            remove_num(x);
        }
        cout << Beauty << endl;
    }
    fprintf(stderr, "%.2f s\n", 1.0 * elapsed / CLOCKS_PER_SEC);
    return 0;
}