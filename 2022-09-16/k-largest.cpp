//--- Problem Statement ---

/*Given an array of N positive integers, print k largest elements from the array. */

//--- Solution ---

vector<int> kLargest(int arr[], int n, int k)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+k);
    for(int i=k; i<n; i++)
    {
        if(arr[i]>pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
