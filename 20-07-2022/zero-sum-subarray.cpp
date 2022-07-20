//--- Problem Statement ---

/*Given an array of positive and negative numbers.
Find if there is a subarray (of size at-least one) with 0 sum.*/

//--- Solution ---

bool subArrayExists(int arr[], int n)
    {
        //Your code here
        int sum=0;
        unordered_set<int> s;
        s.insert(0);
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
            if(s.find(sum)!=s.end())
                return true;
            s.insert(sum);
        }
        return false;
    }
