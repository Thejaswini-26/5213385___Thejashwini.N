#define MOD 1000000007

long mod_pow(long base, int exp) {
    long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int legoBlocks(int n, int m) {
    long row[m + 1];
    row[0] = 1;

    for (int i = 1; i <= m; i++) {
        row[i] = 0;
        for (int b = 1; b <= 4; b++) {
            if (i - b >= 0) {
                row[i] = (row[i] + row[i - b]) % MOD;
            }
        }
    }

    long total[m + 1];
    for (int i = 1; i <= m; i++) {
        total[i] = mod_pow(row[i], n);
    }

    long stable[m + 1];
    stable[0] = 1;

    for (int i = 1; i <= m; i++) {
        stable[i] = total[i];
        for (int j = 1; j < i; j++) {
            stable[i] = (stable[i] - (stable[j] * total[i - j]) % MOD + MOD) % MOD;
        }
    }

    return (int)stable[m];
}
