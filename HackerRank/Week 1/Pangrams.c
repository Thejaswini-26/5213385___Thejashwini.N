char* pangrams(char* s) {
    int alpha[26]={0};
    for(int i=0;s[i]!='\0';i++){
        char ch = tolower(s[i]);
        if(ch>='a' && ch<='z'){
            int index = ch-'a';
            alpha[index]=1;
        }
    }
    for(int i=0;i<26;i++){
        if(alpha[i]==0){
            return "not pangram";
        }
    }
  return "pangram"; 
}
