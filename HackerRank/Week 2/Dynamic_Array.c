int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int** arr=calloc(n, sizeof(int*));
    int* sizes=calloc(n, sizeof(int));
    int* res=malloc(queries_rows * sizeof(int));
    int last=0,k=0;
    
    for(int i=0; i<queries_rows;i++){
        int t=queries[i][0], x=queries[i][1], y=queries[i][2];
        int idx = (x^last)%n;
        
        if(t==1){
            arr[idx]=realloc(arr[idx], ++sizes[idx] * sizeof(int));
            arr[idx][sizes[idx]-1]=y;
        }
        else{
            last=arr[idx][y%sizes[idx]];
            res[k++]=last;
        }
    }
    *result_count = k;
    free(sizes);
    for(int i=0;i<n;i++)free(arr[i]);
    free(arr);
    return res;
}
