//--- Problem Statement ---

/*Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.*/

//--- Solution ---

long long getMaxArea(long long arr[], int n)
{
    long long ans=INT_MIN;
    stack<int> minm;
    int p[n];
    int b;
    for(int i=0; i<n; i++)
    {
        while(!minm.empty() && arr[minm.top()]>=arr[i])
            minm.pop();
        if(minm.empty())
            p[i]=-1;
        else
            p[i]=minm.top();
        minm.push(i);
    }
    while(!minm.empty())
        minm.pop();
    for(int i=n-1; i>=0; i--)
    {
        while(!minm.empty() && arr[minm.top()]>=arr[i])
            minm.pop();
        if(minm.empty())
            b=n;
        else
            b=minm.top();
        minm.push(i);
        ans=max(ans, arr[i]*(b-p[i]-1));
    }
    return ans;
}
