//--- Problem Statement ---
/*Given a string S consisting of uppercase and lowercase characters.
The task is to sort uppercase and lowercase letters separately such that
if the ith place in the original string had an Uppercase character
then it should not have a lowercase character after being sorted and vice versa.*/

//--- Solution ---

string caseSort(string str, int n)
    {
        // your code here
        string ans;
        string s=str;
        sort(s.begin(), s.end());
        int l=0,u=0;
        while(l<n)
        {
            if(s[l]>='a')
                break;
            l++;
        }
        for(int i=0; i<n; i++)
        {
            if(str[i]>='a')
            {
                ans+=s[l];
                l++;
            }
            else
            {
                ans+=s[u];
                u++;
            }
        }
        return ans;
    }
