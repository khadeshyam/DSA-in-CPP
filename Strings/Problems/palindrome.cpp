class Solution {
public:

    string updateString (string str){
         string newStr;
         int n=str.length();

         for(int i=0;i<n;i++){
             if(isalpha(str[i])){
                 char ch = tolower(str[i]);
                 newStr.push_back(ch);
             }
            else if(isdigit(str[i])){
                char ch = str[i];
                newStr.push_back(ch);
            }
         }
         return newStr;
    }
    bool isPalindrome(string s) {

        string updatedString = updateString(s);
        int n = updatedString.length();

        int l = 0;
        int r = n-1;
        
        while(l<=r){
             if(updatedString[l]!=updatedString[r]){
                 return false;
             }else{
                l++,r--;
             }
        }

        return true;
    }
};