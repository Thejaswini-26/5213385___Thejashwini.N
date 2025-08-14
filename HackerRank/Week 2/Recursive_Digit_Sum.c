int superDigit(char* n, int k) {
    long long total=0;
    
    for(int i=0;n[i]!='\0';i++){
        total=total+n[i]-'0';
}

total*=k;

while(total>=10){
    long long temp=0;
    while(total>0){
        temp=temp+total%10;
        total=total/10;
    }
    total=temp;
}
return (int)total;
}