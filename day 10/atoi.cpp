int atoi(string str) {
    // Write your code here.
    int ans=0;
    int sign=1;
    if(str[0]=='-') sign=-1;
    for(auto ch : str){
        if(ch<='9' && ch>='0'){
            ans*=10;
            ans+=ch-'0';
        }
    }
    return ans*sign;
}