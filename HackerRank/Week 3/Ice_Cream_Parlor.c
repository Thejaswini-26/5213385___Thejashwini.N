int* icecreamParlor(int m, int arr_count, int* arr, int* result_count) {
    static int result[2];
    for(int i=0;i<MAX;i++){
        hash[i]=-1;
    }
    
    for(int i=0;i<arr_count;i++){
        int comp=m-arr[i];
        if(comp>=0&&hash[comp]!=-1){
            result[0]=hash[comp]+1;
            result[1]=i+1;
            *result_count=2;
            return result;
        }
        hash[arr[i]]=i;
        
    }
    *result_count=0;
    return NULL;
}
