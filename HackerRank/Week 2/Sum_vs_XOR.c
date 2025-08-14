long sumXor(long n) {
    if (n==0){
        return 1;
    }    
    int count=0;
    while(n>0){
        if((n&1)==0){
            count++;
        }
        n>>=1;
    }
    return 1L<<count;
    
}