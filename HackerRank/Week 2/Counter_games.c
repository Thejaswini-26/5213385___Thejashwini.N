char* counterGame(long n) {
    int turns=0;
    while(n>1){
        if((n&(n-1))==0){
            n=n/2;
        }
        else{
            long p=1;
            while(p*2<n){
                p=p*2;
            }
            n=n-p;
        }
        turns++;
    }
if(turns%2==0){
    return "Richard";
}
else{
    return "Louise";
}
}