//--- Problem Statement ---
/*Check weather the sum of every even length subarray is 0 or not*/

//--- Solution ---

string solve(int n, vector<int> &a)
    {
        for(int i=1; i<n; i++)
            if(a[i]!=-a[i-1])
                return "NO";
        return "YES";
    }
