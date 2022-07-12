//--- Problem Statement ---
/*Given a string str and another string patt.
Find the minimum index of the character in str that is also present in patt.*/

//--- Solution ---

int minIndexChar(string str, string pat)
    {
        // Your code here
        int ans=INT_MAX;
        vector<int> v1(26, INT_MAX);
        vector<bool> v2(26, false);
        int n = str.length();
        int m = pat.length();
        for(int i=0; i<n; i++)
        {
            v1[str[i]-'a']=min(v1[str[i]-'a'], i);
        }
        for(int i=0; i<m; i++)
            v2[pat[i]-'a']=true;
        for(int i=0; i<26; i++)
        {
            if(v1[i]!=INT_MAX && v2[i])
            {
                ans=min(ans, v1[i]);
            }
        }
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
    }
