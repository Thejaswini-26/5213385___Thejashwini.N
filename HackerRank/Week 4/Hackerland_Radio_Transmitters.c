int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

 

int hackerlandRadioTransmitters(int x_count, int* x, int k) {
     qsort(x, x_count, sizeof(int), cmpfunc);
    int transmitters = 0;
    int i = 0;
    while (i < x_count) {
        transmitters++;
        int loc = x[i] + k;
        while (i < x_count && x[i] <= loc) i++;
        int pos = x[i - 1] + k;
        while (i < x_count && x[i] <= pos) i++;
    }
    return transmitters;

}