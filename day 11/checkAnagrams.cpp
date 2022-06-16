bool areAnagram(string &str1, string &str2){
    vector<int> arr(26,0);
    for(auto ch :str1) arr[ch-'a']++;
    for(auto ch : str2) arr[ch-'a']--;
    for(auto a : arr){
        if(a!=0) return false;
    }
    return true;
}