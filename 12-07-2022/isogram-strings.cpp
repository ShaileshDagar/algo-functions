//--- Problem Statement ---
/*Given a string S of lowercase alphabets, check if it is isogram or not.
An Isogram is a string in which no letter occurs more than once.*/

//--- Solution ---

bool isIsogram(string s)
    {
        //Your code here
        int count[26]={0};
        int n=s.length();
        for(int i=0; i<n; i++)
        {
            if(count[s[i]-'a']==1)
                return false;
            else
                count[s[i]-'a']++;
        }
        return true;
    }
