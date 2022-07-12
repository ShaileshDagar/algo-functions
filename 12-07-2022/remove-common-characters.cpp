//--- Problem Statement ---
/*Given two strings s1 and s2.
Modify both the strings such that all the common characters of s1 and s2
are to be removed and the uncommon characters of s1 and s2 are to be concatenated.
Note: If all characters are removed print -1.*/

//--- Solution ---

string concatenatedString(string s1, string s2) 
    { 
        // Your code here
        string ans;
        bool p[26]={0};
        bool q[26]={0};
        int n=s1.length();
        int m=s2.length();
        for(int i=0; i<n; i++)
            p[s1[i]-'a']=true;
        for(int i=0; i<m; i++)
            q[s2[i]-'a']=true;
        for(int i=0; i<n; i++)
        {
            if(p[s1[i]-'a'] && q[s1[i]-'a']);
            else if(p[s1[i]-'a'] || q[s1[i]-'a'])
                ans+=s1[i];
        }
        for(int i=0; i<m; i++)
        {
            if(p[s2[i]-'a'] && q[s2[i]-'a']);
            else if(p[s2[i]-'a'] || q[s2[i]-'a'])
                ans+=s2[i];
        }
        if(ans.length()==0)
            cout<<-1;
        return ans;
    }
