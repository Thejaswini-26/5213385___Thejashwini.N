int* solve(int arr_count, int* arr, int queries_count, int* queries, int* result_count) {
    int* results = malloc(queries_count * sizeof(int));
    for (int k = 0; k < queries_count; k++) {
        int d = queries[k];
        int* maxima = malloc((arr_count - d + 1) * sizeof(int));
        int front = 0, back = -1;
        int deque[arr_count];
        for (int i = 0; i < d; i++) {
            while (back >= front && arr[deque[back]] <= arr[i]) back--;
            deque[++back] = i;
        }
        maxima[0] = arr[deque[front]];
        for (int i = d; i < arr_count; i++) {
            while (front <= back && deque[front] <= i - d) front++;
            while (back >= front && arr[deque[back]] <= arr[i]) back--;
            deque[++back] = i;
            maxima[i - d + 1] = arr[deque[front]];
        }
        int minVal = maxima[0];
        for (int i = 1; i <= arr_count - d; i++) {
            if (maxima[i] < minVal) minVal = maxima[i];
        }
        results[k] = minVal;
        free(maxima);
    }
    *result_count = queries_count;
    return results;
}