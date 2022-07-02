//--- Problem Statement ---
/*Given an array arr of size n and an integer X.
Find if there's a triplet in the array which sums up to the given integer X*/

bool find3Numbers(int a[], int n, int x)
    {
        //Your Code Here
        for(int i=0; i<n-2; i++)
        {
            unordered_set<int> s;
            int sum=x-a[i];
            for(int j=i+1; j<n; j++)
            {
                if(s.find(sum-a[j])!=s.end())
                    return true;
                s.insert(a[j]);
            }
        }
        return false;
    }