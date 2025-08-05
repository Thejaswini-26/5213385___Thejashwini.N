char* timeConversion(char* s) {
static char time[9];
int hr;
hr=(s[0]-'0')*10+(s[1]-'0');

if (s[8]=='A'){
    if(hr==12)
       hr=0;
}
else{
    if(hr!=12)
    hr+=12;
}
time[0]=(hr/10)+'0';
time[1]=(hr%10)+'0';
time[2]=':';
time[3]=s[3];
time[4]=s[4];
time[5]=':';
time[6]=s[6];
time[7]=s[7];
time[8]='\0';
return time;

}
