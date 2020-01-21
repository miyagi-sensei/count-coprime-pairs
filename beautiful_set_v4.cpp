// solve subtask 1-6: 100 points
#include "stdc++.h"
using namespace std;

int Q;
int Factors_count[50000];   // factors_count[i] = the count of numbers in the set so far that has factor i; factors_count[1] is always 0
long long Beauty = 0;
vector<int> Factor_cache[50001];
vector<int> Prime_factor_cache[50001];

void print(vector<int> v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << ". ";
}

vector<int> factorize(int x) {
    vector<int> factors;
    int i = 2, remnant = x;
    while ((i*i) <= x) {
        if (remnant % i == 0) {
            remnant = remnant / i;
            if (factors.size() == 0 || i != factors[factors.size()-1]) {
                factors.push_back(i);
            }
            if (remnant == 1) {
                break;
            }
        } else {
            i++;
        }
    }
    if (remnant != 1) {
        factors.push_back(remnant);
    }

    return factors;
}

vector<int> compound(vector<int> factors) {
    int i = 2, j, k, l, m, n, n_prime_factors;    
    // compound the prime factors into all combinations of factors
    n_prime_factors = factors.size();
    for (i=0; i<n_prime_factors; i++) {
        for (j=i+1; j<n_prime_factors; j++) {
            for (k=j+1; k<n_prime_factors; k++) {
                for (l=k+1; l<n_prime_factors; l++) {
                    for (m=l+1; m<n_prime_factors; m++) {
                        for (n=m+1; n<n_prime_factors; n++) {
                            factors.push_back(factors[i] * factors[j] * factors[k] * factors[l] * factors[m] * factors[n]);
                        }
                        factors.push_back(factors[i] * factors[j] * factors[k] * factors[l] * factors[m]);
                    }
                    factors.push_back(factors[i] * factors[j] * factors[k] * factors[l]);
                }
                factors.push_back(factors[i] * factors[j] * factors[k]);
            }
            factors.push_back(factors[i] * factors[j]);
        }
    }
    return factors;
}

void add_num(int x, int size) {
    if (x == 1) {
        Beauty += size;
        return;
    }
    int i, j, k, l, m, n, factor2, factor3, factor4, factor5, factor6;
    int n_prime_factors = Prime_factor_cache[x].size();
    Beauty += size;
    for (i=0; i<n_prime_factors; i++) {
        Beauty -= Factors_count[Prime_factor_cache[x][i]];
        for (j=i+1; j<n_prime_factors; j++) {
            factor2 = Prime_factor_cache[x][i] * Prime_factor_cache[x][j];
            Beauty += Factors_count[factor2];
            for (k=j+1; k<n_prime_factors; k++) {
                factor3 = factor2 * Prime_factor_cache[x][k];
                Beauty -= Factors_count[factor3];
                for (l=k+1; l<n_prime_factors; l++) {
                    factor4 = factor3 * Prime_factor_cache[x][l];
                    Beauty += Factors_count[factor4];
                    for (m=l+1; m<n_prime_factors; m++) {
                        factor5 = factor4 * Prime_factor_cache[x][m];
                        Beauty -= Factors_count[factor5];
                        for (n=m+1; n<n_prime_factors; n++) {
                            factor6 = factor5 * Prime_factor_cache[x][n];
                            Beauty += Factors_count[factor6];
                        }
                    }
                }
            }
        }
    }
    for (i=0; i<Factor_cache[x].size(); i++) {
        Factors_count[Factor_cache[x][i]]++;
    }
}

void remove_num(int x, int size) {
    if (x == 1) {
        Beauty -= (size - 1);
        return;
    }
    int i, j, k, l, m, n, factor2, factor3, factor4, factor5, factor6;
    int n_prime_factors = Prime_factor_cache[x].size();
    Beauty -= (size - 1);
    for (i=0; i<n_prime_factors; i++) {
        Beauty += (Factors_count[Prime_factor_cache[x][i]] - 1);
        for (j=i+1; j<n_prime_factors; j++) {
            factor2 = Prime_factor_cache[x][i] * Prime_factor_cache[x][j];
            Beauty -= (Factors_count[factor2] - 1);
            for (k=j+1; k<n_prime_factors; k++) {
                factor3 = factor2 * Prime_factor_cache[x][k];
                Beauty += (Factors_count[factor3] - 1);
                for (l=k+1; l<n_prime_factors; l++) {
                    factor4 = factor3 * Prime_factor_cache[x][l];
                    Beauty -= (Factors_count[factor4] - 1);
                    for (m=l+1; m<n_prime_factors; m++) {
                        factor5 = factor4 * Prime_factor_cache[x][m];
                        Beauty += (Factors_count[factor5] - 1);
                        for (n=m+1; n<n_prime_factors; n++) {
                            factor6 = factor5 * Prime_factor_cache[x][n];
                            Beauty -= (Factors_count[factor6] - 1);
                        }
                    }
                }
            }
        }
    }
    for (i=0; i<Factor_cache[x].size(); i++) {
        Factors_count[Factor_cache[x][i]]--;
    }}

int main() {
    int type, x, set_size = 0, max_factors = 0;
    for (int i=2; i<=50000; i++) {
        Prime_factor_cache[i] = factorize(i);
        Factor_cache[i] = compound(Prime_factor_cache[i]);
        // cout << i << " "; print(factors);
    }
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
        // printf("%lld: ", Beauty); print(Prime_factor_cache[x]); print(Factor_cache[x]); cout << endl;
        cout << Beauty << endl;
    }

    return 0;
}