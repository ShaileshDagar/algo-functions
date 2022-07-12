//--- Problem Statement ---
/*Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible
for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in str1 should map to the same character in str2*/

//--- Solution ---

bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if(str1.length()!=str2.length())
            return false;
        int n=str1.length();
        unordered_map<char, char> s1;
        unordered_map<char, char> s2;
        for(int i=0; i<n; i++)
        {
            unordered_map<char, char>::iterator itr = s1.find(str1[i]);
            if(itr==s1.end())
                s1[str1[i]]=str2[i];
            else if((*itr).second!=str2[i])
                return false;
        }
        for(int i=0; i<n; i++)
        {
            unordered_map<char, char>::iterator itr = s2.find(str2[i]);
            if(itr==s2.end())
                s2[str2[i]]=str1[i];
            else if((*itr).second!=str1[i])
                return false;
        }
        return true;
    }
