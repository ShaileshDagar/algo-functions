//--- Problem Discription ---
/*
Given an array arr[] of n integers.
Check whether it contains a triplet that sums up to zero.*/

bool findTriplets(int a[], int n)
    { 
        //Your code here
        for(int i=0; i<n-2; i++)
        {
            unordered_set<int> s;
            int sum=-a[i];
            for(int j=i+1; j<n; j++)
            {
                if(s.find(sum-a[j])!=s.end())
                    return true;
                s.insert(a[j]);
            }
        }
        return false;
    }