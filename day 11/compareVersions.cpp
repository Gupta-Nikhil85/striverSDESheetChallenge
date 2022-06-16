#include<bits/stdc++.h>
int compareVersions(string a, string b) 
{
    // Write your code here
    vector<string> v1,v2;
    int d1=0,d2=0;
    for(int i=0; i<a.length(); i++){
        if(a[i]=='.') d1++;
    }
    for(int j=0; j<b.length(); j++) if(b[j]=='.') d2++;
    while(d1<d2) {
        a+=".0";
        d1++;
    }
    while(d2<d1){
        b+=".0";
        d2++;
    }
    a+=".";
    b+=".";
    
    int i=0,j=0;
    while(d1>=0){
        string s="",t="";
        while(i<a.length()){
            if(a[i]!='.')s+=a[i];
            else break;
            i++;
        }
        i++;
        while(j<b.length()){
            if(b[j]!='.')t+=b[j];
            else break;
            j++;
        }
        j++;
        if(s.length()>t.length()) return 1;
        else if(t.length()>s.length()) return -1;
        else{
            if(s>t) return 1;
            if(t>s) return -1;
        }
        d1--;
    }
    return 0;
}