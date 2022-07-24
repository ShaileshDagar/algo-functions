//--- Problem Statement ---
/*Given an array and a number c, find if there exist a pair in the array such that a^b=c.*/

//--- Solution ---

bool pairExists(int arr[], int n, int c)
{
    unordered_set<int> s;
    for(int i=0; i<n; i++)
    {
        if(s.find(arr[i])!=s.end())
            return true;
        s.insert(arr[i]^c);
    }
    return false;
}
