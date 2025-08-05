void miniMaxSum(int arr_count, int* arr) {
    long long max, min,arrsum=0;
    max=min=arr[0];
    
    for(int i=0;i<arr_count;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
        arrsum+=arr[i];
    }
    printf("%lld %lld\n",arrsum-max,arrsum-min);
   
}