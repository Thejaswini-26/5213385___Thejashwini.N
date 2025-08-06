int lonelyinteger(int a_count, int* a) {
    for(int i=0;i<a_count;i++){
        int count=0;
        for(int j=0;j<a_count;j++){
            if(a[i]==a[j]){
                count++;
            }
        }
        if(count==1){
            return a[i];
        }
         
    }
    return -1;

}