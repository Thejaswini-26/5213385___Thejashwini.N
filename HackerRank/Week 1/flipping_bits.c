long flippingBits(long n) {
    long flip_bin=0,flip_int=0;
    for(int i=31; i>=0; i--){
        int bin = (n >> i) & 1;
        flip_bin=bin^1;
        flip_int |= ((long)flip_bin<<i);
    }
return flip_int;
}
