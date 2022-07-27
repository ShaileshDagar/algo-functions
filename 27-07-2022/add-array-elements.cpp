//--- Problem Statement ---
/*Given an array Arr[] of size N and an integer K,
you have to add the first two minimum elements of the array until all the elements
are greater than or equal to K and find the number of such operations required.*/

//--- Soltuion ---

int minOperations(int arr[], int n, int k) {
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=arr[i];
        if(sum<k)
            return -1;
        priority_queue<int, vector<int>,greater<int>> pq(arr, arr+n);
        int count=0;
        int a,b;
        while(pq.top()<k)
        {
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            pq.push(a+b);
            count++;
        }
        return count;
    }
