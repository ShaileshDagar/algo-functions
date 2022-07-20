//--- Problem Statement ---

/*Given an array containing 0s and 1s.
Find the number of subarrays having equal number of 0s and 1s.*/

//--- Solution ---

long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        for(int i=0; i<n; i++)
            if(arr[i]==0)
                arr[i]=-1;
        long long int ans=0;
        int presum[n+1];
        presum[0]=0;
        unordered_map<int, int> m; 
        for(int i=0; i<n; i++)
            presum[i+1]=presum[i]+arr[i];
        int b;
        for(int i=0; i<=n; i++)
        {
            b=presum[i];
            ans+=m[presum[i]];
            m[b]++;
        }
        return ans;
    }
