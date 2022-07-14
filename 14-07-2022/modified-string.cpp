//--- Problem Statement ---
/*Ishaan is playing with strings these days. He has found a new string. He wants to modify it as per the following rules to make it valid:

The string should not have three consecutive same characters (Refer example for explanation).
He can add any number of characters anywhere in the string. 
Find the minimum number of characters which Ishaan must insert in the string to make it valid.*/

//--- Solution ---

int modified (string a)
    {
        // Your code here
        int ans=0;
        unordered_map<char, int> m;
        int n=a.length();
        if(n<3)
            return ans;
        int i=0;
        m[a[0]]++;
        m[a[1]]++;
        for(int j=2; j<n; j++)
        {
            m[a[j]]++;
            if(m[a[j]]==3)
            {
                ans++;
                m[a[j]]=1;
                i=j-1;
                j++;
                if(j<n)
                    m[a[j]]++;
            }
            else
                m[a[i]]--;
            i++;
        }
        return ans;
    }
