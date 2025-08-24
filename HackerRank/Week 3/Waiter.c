int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return 0;
    return 1;
}

int* waiter(int number_count, int* number, int q, int* result_count) {
    int* result = malloc(100000 * sizeof(int));
    int res_idx = 0;

    int primes[q], p = 0, num = 2;
    while (p < q) {
        if (is_prime(num)) primes[p++] = num;
        num++;
    }

    int* A = malloc(number_count * sizeof(int));
    int topA = -1;
    for (int i = 0; i < number_count; i++) {
        A[++topA] = number[i];
    }

    for (int i = 0; i < q; i++) {
        int prime = primes[i];
        int* nextA = malloc(number_count * sizeof(int));
        int topNextA = -1;
        int* B = malloc(number_count * sizeof(int));
        int topB = -1;

     
        while (topA != -1) {
            int val = A[topA--];
            if (val % prime == 0)
                B[++topB] = val;
            else
                nextA[++topNextA] = val;
        }
        
        
        for (int j = topB; j >= 0; j--)
            result[res_idx++] = B[j];

        free(A);
        A = nextA;
        topA = topNextA;
    }

  
    for (int j = topA; j >= 0; j--)
        result[res_idx++] = A[j];

    free(A);
    *result_count = res_idx;
    return result;
}
