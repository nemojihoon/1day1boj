//10830 Divide and Conquer
#include <iostream>

using namespace std;

#define MOD 1000

long long n, b;

long long** matMul(long long** A, long long** B) {
    long long** res = new long long*[n];

    for(int i = 0; i < n; i++) {
        res[i] = new long long[n];
        for(int j = 0; j < n; j++) {
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += (A[i][k] * B[k][j]) % MOD;
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

long long** f(long long** arr, long long k) {
    if(k <= 1) {
        return arr;
    } else {
        long long** tmp;
        if(k%2 == 0) {
            tmp = f(arr, k/2);
            return matMul(tmp, tmp);
        } else {
            tmp = f(arr, (k-1)/2);
            return matMul(arr, matMul(tmp, tmp));
        }
    }
}

int main() {
    cin >> n >> b;

    long long** a = new long long*[n];

    for(int i = 0; i < n; i++) {
        a[i] = new long long[n];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] %= MOD;
        }
    }

    long long** ans = f(a, b);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}