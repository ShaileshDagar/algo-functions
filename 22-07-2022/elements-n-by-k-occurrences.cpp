//--- Problem Statement ---

/* Print elements which have more than n/k occurences in the array.*/

//--- Solution ---

void printNByK(int arr[], int n, int k)
{
    unordered_map<int,int> m;
    
    for(int i=0;i<n;i++)
        m[arr[i]]++;
    for(auto e: m)
        if(e.second>n/k)
            cout<<e.first<<" ";
    
}
