char* caesarCipher(char* s, int k) {
 int len = strlen(s);
 char* result = (char*)malloc((len+1)*sizeof(char));
 
 for(int i=0;i<len;i++){
    char ch=s[i];
    
    if(ch>='a' && ch<='z'){
        result[i]=((ch-'a'+k)%26)+'a';
    }
    else if (ch>='A'&&ch<='Z'){
        result[i]=((ch-'A'+k)%26)+'A';
    }
    else {
        result[i]=ch;
    }
 }   
result[len]='\0';
return result;
}
