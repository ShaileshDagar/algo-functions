//--- Problem Statement ---
/*Given text and a pattern string, find if the pattern in present in the given text*/

//--- Solution ---

void computeLPSArray(const string& s, int m, int* lps) 
{ 
	// Your code here
	lps[0]=0;
	int i=1,len=0;
	while(i<m)
	{
	    if(s[i]==s[len])
	    {
	        len++;
	        lps[i]=len;
	        i++;
	    }
	    else if(len==0)
	    {
	        lps[i]=0;
	        i++;
	    }
	    else
	    {
	        len=lps[len-1];
	    }
	}
} 

//Function to check if the pattern exists in the string or not.
bool KMPSearch(string pat, string txt) 
{
    // Your code here
    int n=txt.length();
    int m=pat.length();
    int lps[m];
    computeLPSArray(pat, m, lps);
    int i=0, j=0;
    while(i<n)
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==m)
            return true;
        else if(i<n && txt[i]!=pat[j])
        {
            if(j==0)
                i++;
            else
            {
                j=lps[j-1];
            }
        }
    }
    return false;
}
