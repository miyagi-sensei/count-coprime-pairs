// assuming all x's are powers of prime numbers
// solve subtask 1-5: 80 points
#include <iostream>
using namespace std;

int Q;
int Factors_count[50000];   // Factors_count[i] = the count of numbers in the set so far that has factor i; factors_count[1] is always 0
long long Beauty = 0;

// this assumes n only has 1 factor (other than 1)
int factorize(int n) {
    int i = 2;
    while ((i*i) <= n) {
        if (n % i == 0) {
            return i;
        } else {
            i++;
        }
    }
    return n;
}

void add_num(int n, int size) {
    if (n == 1) {
        Beauty += size;
        return;
    }
    int f = factorize(n);
    Beauty += (size - Factors_count[f]);
    Factors_count[f]++;
}

void remove_num(int n, int size) {
    if (n == 1) {
        Beauty -= (size-1);
        return;
    }
    int f = factorize(n);;
    Beauty -= (size - Factors_count[f]);
    Factors_count[f]--;
}

int main() {
    int type, x, set_size = 0;
    cin >> Q;
    for (int i=0; i<Q; i++) {
        cin >> type >> x;
        if (type == 1) {
            add_num(x, set_size);
            set_size++;
        } else {
            remove_num(x, set_size);
            set_size--;
        }
        cout << Beauty << endl;
    }

    return 0;
}
