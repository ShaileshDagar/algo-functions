//--- Problem Statement ---
/*Given two strings A and B, find if A is a subsequence of B.
A subsequence is a sequence that can be derived from another sequence
by deleting some elements without changing the order of the remaining elements.*/

//--- Solution ---

bool isSubSequence(string A, string B)
    {
        int n=B.length();
        int m=A.length();
        int i=-1,j=0;
        while(i++<n)
        {
            if(B[i]==A[j])
            {
                j++;
                if(j==m)
                    return true;
            }
        }
        return false;
    }
