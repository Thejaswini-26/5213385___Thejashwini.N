int* countingSort(int arr_count, int* arr, int* result_count) {

int* frequency = (int*)calloc(100,sizeof(int));
for(int i=0;i<arr_count;i++){
    frequency[arr[i]]++;
}
*result_count=100;
return frequency;
}
