void plusMinus(int arr_count, int* arr) {
    int pos=0, neg=0, zero=0;
    for(int i=0;i<arr_count;i++){
        if(arr[i]>0){
            pos++;
        }
        else if(arr[i]<0){
            neg++;
        }
        else {
        zero++;
        }
    }
printf("%.6f\n",(float)pos/arr_count);
printf("%.6f\n",(float)neg/arr_count);
printf("%.6f\n",(float)zero/arr_count);

}