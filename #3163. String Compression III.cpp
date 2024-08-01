class Solution {
public:
    string compressedString(string word) {
       char ch='0';
       int c=0;
       string comp="";
       for(int i=0;i<word.length();i++){
        if(ch=='0'){
            ch=word[i];
        }
        if(word[i]==ch){
            c++;
        }else{
            while(c>9){
                comp+='9';
                comp+=ch;
                c=c-9;
            }
            comp+=to_string(c);
            c=1;
            comp+=ch;
            ch=word[i];
        }
       }
       while(c>9){
                comp+='9';
                comp+=ch;
                c=c-9;
            }
       comp+=to_string(c);
       comp+=ch;
       return comp;
    }
};