void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify_up(int *heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i] < heap[parent]) {
            swap(&heap[i], &heap[parent]);
            i = parent;
        } else break;
    }
}

void heapify_down(int *heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify_down(heap, size, smallest);
    }
}

void heap_insert(int *heap, int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapify_up(heap, *size - 1);
}

int heap_extract_min(int *heap, int *size) {
    if (*size <= 0) return -1;
    int min = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify_down(heap, *size, 0);
    return min;
}

int cookies(int k, int A_count, int* A) {
    int heap[A_count];
    int heap_size = 0;
    for (int i = 0; i < A_count; i++) {
        heap_insert(heap, &heap_size, A[i]);
    }
    int operations = 0;
    while (heap_size > 0 && heap[0] < k) {
        if (heap_size < 2) return -1;
        int least = heap_extract_min(heap, &heap_size);
        int second = heap_extract_min(heap, &heap_size);
        int new_cookie = least + 2 * second;
        heap_insert(heap, &heap_size, new_cookie);
        operations++;
    }
    return operations;
}