
typedef struct {
    int value;
    int index;
} Pair;

int compare_asc(const void* a, const void* b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

int compare_desc(const void* a, const void* b) {
    return ((Pair*)b)->value - ((Pair*)a)->value;
}

int count_swaps(int* arr, Pair* sorted, int n) {
    int* visited = calloc(n, sizeof(int));
    int* position = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        position[sorted[i].index] = i;
    }

    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] || position[i] == i) continue;
        int cycle_size = 0, j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = position[j];
            cycle_size++;
        }
        swaps += cycle_size - 1;
    }

    free(visited);
    free(position);
    return swaps;
}

int lilysHomework(int arr_count, int* arr) {
    Pair* asc = malloc(arr_count * sizeof(Pair));
    Pair* desc = malloc(arr_count * sizeof(Pair));

    for (int i = 0; i < arr_count; i++) {
        asc[i].value = arr[i];
        asc[i].index = i;
        desc[i] = asc[i];
    }

    qsort(asc, arr_count, sizeof(Pair), compare_asc);
    qsort(desc, arr_count, sizeof(Pair), compare_desc);

    int asc_swaps = count_swaps(arr, asc, arr_count);
    int desc_swaps = count_swaps(arr, desc, arr_count);

    free(asc);
    free(desc);

    return asc_swaps < desc_swaps ? asc_swaps : desc_swaps;
}
