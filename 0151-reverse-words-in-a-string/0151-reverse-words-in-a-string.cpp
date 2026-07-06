class Solution {
public:
   string reverseWords(string s) {
    string ans = "";
    int start = -1, end = -1;
    for(int i=0; i<s.size(); i++){
        while(s[i]==' ')
            i++;
        start = i;
        while(i<s.size() && s[i]!=' ')
            i++;
        end = i;
        string temp = s.substr(start,end-start);
        reverse(temp.begin(),temp.end());
        ans = ans+" "+temp;
    }
    reverse(ans.begin(),ans.end());
    int i=0, j=ans.size()-1;
    while(ans[i]==' ')
        i++;
    while(ans[j]==' ')
        j--;
    ans = ans.substr(i,j-i+1);
    return ans;
}

};