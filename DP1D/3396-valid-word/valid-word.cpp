class Solution {
public:
    bool isValid(string word) {
        bool v=false;
        bool con=false;
        for(char& c : word){
            if(!((c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z'))){
                return false;
            }
            if(c=='A' || c=='E'||c=='I' ||c=='O' ||c=='U' ||c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u'){
                v=true;
            }
            else{
                if(!((c>='0' && c<='9')))   con=true;
            }
        }
        return (word.size()>=3 && v && con);
        
    }
};