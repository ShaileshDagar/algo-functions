//--- Problem Statement ---
/*Hashing is very useful to keep track of the frequency of the elements in a list.

You are given an array of integers.
You need to print the count of non-repeated elements in the array.*/

//---Solution ---

int countNonRepeated(int arr[], int n)
    {
        //Your code here
        int ans=0;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++)
            m[arr[i]-1]++;
        for(auto x : m)
            if(x.second==1)
                ans++;
        return ans;
    }
