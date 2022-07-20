//--- Problem Statement ---

/*Given an array of distinct integers,
find all the pairs having both negative and positive values of a number in the array.*/

//--- Solution ---

vector <int> findPairs(int arr[], int n) 
    {
        unordered_set<int> s;
        vector<int> temp;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(s.find(-arr[i])!=s.end())
                temp.push_back(abs(arr[i]));
            s.insert(arr[i]);
        }
        for(int x : temp)
        {
            ans.push_back(-x);
            ans.push_back(x);
        }
        return ans;
    }
