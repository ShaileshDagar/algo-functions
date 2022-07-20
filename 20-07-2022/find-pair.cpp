//--- Problem Statement ---

/*You are given an array of distinct integers and a sum.
Check if there's a pair with the given sum in the array.*/

//--- Solution ---

int sumExists(int arr[], int n, int sum) {
    unordered_set<int> s;
    int x;
    for(int i=0; i<n; i++)
    {
        x=sum-arr[i];
        if(s.find(x)!=s.end())
            return 1;
        s.insert(arr[i]);
    }
    return 0;
