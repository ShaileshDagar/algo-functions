//--- Problem Statement ---

/*Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.*/

//--- Solution ---

vector <int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> ans;
    deque<int> dq;
    for(int i=0; i<k; i++)
    {
        if(dq.empty())
            dq.push_back(i);
        else
        {
            while(!dq.empty() && arr[dq.back()]<=arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
    }
    ans.push_back(arr[dq.front()]);
    for(int i=k; i<n; i++)
    {
        if(dq.front()==i-k)
            dq.pop_front();
        while(!dq.empty() && arr[dq.back()]<=arr[i])
            dq.pop_back();
        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }
    return ans;
}
