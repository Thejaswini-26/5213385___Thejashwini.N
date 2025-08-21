char* isValid(char* s) {
    int freq[26]={0};
    int len=strlen(s);
    
    for(int i=0;i<len;i++){
        if(s[i]>='a' && s[i]<='z'){
        freq[s[i]-'a']++;
    }
    }
    
    int maxfreq=0;
    for(int i=0;i<26;i++){
        if(freq[i]>maxfreq){
            maxfreq=freq[i];
        }
    }
    
int* freqcount = calloc(maxfreq+1,sizeof(int));
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            freqcount[freq[i]]++;
        }
    }
    
    int uniquefreq=0;
    int f1=0,f2=0,c1=0,c2=0;
    for(int i=1;i<=maxfreq;i++){
        if(freqcount[i]>0){
            uniquefreq++;
            if(uniquefreq==1){
                f1=i;
                c1=freqcount[i];
            }
            else if(uniquefreq==2){
                f2=i;
                c2=freqcount[i];
            }
            else {
                free(freqcount);
                char* result = malloc(3);
                strcpy(result,"NO");
                return result;
            }
        }
    }
    free(freqcount);
    
    char* result = malloc(4);
    if(uniquefreq==1){
        strcpy(result,"YES");
    }
    else if((c1==1&&(f1-1==f2 || f1==1))||(c2==1 && (f2-1 == f1 || f2==1))){
        strcpy(result,"YES");
    }
    else{
        strcpy(result,"NO");
    }
return result;
}

