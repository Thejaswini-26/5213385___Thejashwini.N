int sockMerchant(int n, int ar_count, int* ar) {
    int count[101]={0};
    int pairs_of_socks=0;
    for(int i=0;i<n;i++){
         count[ar[i]]++;
    }
    for(int i=0;i<101;i++){
        pairs_of_socks+=count[i]/2;
    }
    return pairs_of_socks;

}