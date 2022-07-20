//--- Problem Statement ---

/*Given an array arr[] of size n, find the first repeating element.
The element should occurs more than once and the index of its first occurrence should be the smallest.*/

//--- Solution ---

int firstRepeated(int arr[], int n) {
        // code here
        int ans=INT_MAX;
        unordered_map<int, pair<int, int>> m;
        for(int i=0; i<n ;i++)
        {
            if(m[arr[i]].first==0)
                m[arr[i]].second=i;
            m[arr[i]].first++;
        }
        for(auto x : m)
        {
            if(x.second.first>1)
                ans=min(ans, x.second.second);
        }
        if(ans==INT_MAX)
            return -1;
        else 
            return ans+1;
    }
