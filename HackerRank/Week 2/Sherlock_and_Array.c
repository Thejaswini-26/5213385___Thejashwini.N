char* balancedSums(int arr_count, int* arr) {
int total=0;
for(int i=0;i<arr_count;i++){
    total=total+arr[i];
}

int left_sum=0;
for(int i=0;i<arr_count;i++){
    int right_sum=total-left_sum - arr[i];
    if(left_sum==right_sum){
        return "YES";
    }
    left_sum=left_sum+arr[i];
}
return "NO";
}