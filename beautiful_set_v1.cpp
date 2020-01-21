#include <iostream>
#include <set>
using namespace std;

int q;
set<int> s;

int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

void print_set() {
    set<int>::iterator it;
    for (it=s.begin(); it!=s.end(); it++) {
        cout << (*it) << " ";
    }
    cout << "size: " << s.size() << endl;
}

int compute_beauty() {
    int beauty = 0;
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

int main() {
    int type, x;

    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> type >> x;
        if (type == 1) {
            s.insert(x);
        } else {
            s.erase(x);
        }
        cout << compute_beauty() << endl;
    }

    return 0;
}
