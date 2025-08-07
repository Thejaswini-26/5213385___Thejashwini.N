int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int diag1_sum=0, diag2_sum=0,res;
    for(int i=0;i<arr_rows;i++){
        diag1_sum+=arr[i][i];
        diag2_sum+=arr[i][arr_columns-1-i];
    }
    if(diag1_sum>diag2_sum){
        res=diag1_sum-diag2_sum;
    }
    else {
        res=diag2_sum-diag1_sum;
    }
  return res;
}