//--- Problem Statement ---
/*You are given a string s.
You need to find the missing characters in the string to make a panagram
( a sentence using every letter of english alphabet at least once ).
Note: The output characters will be lowercase and lexicographically sorted.*/

//--- Solution ---

string missingPanagram(string str){
        bool count[26] = {0};
        string ans;
        for(auto x : str)
        {
            if(x>='a')
                count[x-'a']=true;
            else
                count[x-'A']=true;
        }
        for(int i=0; i<26; i++)
        {
            if(count[i]==false)
                ans+='a'+i;
        }
        if(ans.empty())
            return "-1";
        return ans;
    }
