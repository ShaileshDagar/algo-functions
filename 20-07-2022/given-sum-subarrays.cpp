//--- Problem Statement ---
/*Given an unsorted array of integers and a sum.
The task is to count the number of subarray which adds to the given sum.*/

//--- Solution ---

int subArraySum(int arr[], int n, int sum)
    {
        //Your code here
        int ans=0;
        int presum[n+1];
        presum[0]=0;
        unordered_map<int, int> m; 
        for(int i=0; i<n; i++)
            presum[i+1]=presum[i]+arr[i];
        int b;
        for(int i=0; i<=n; i++)
        {
            b=presum[i]+sum;
            ans+=m[presum[i]];
            m[b]++;
        }
        return ans;
    }
