//--- Problem Statement ---
/*Given an array of integers and a number K.
Find the count of distinct elements in every window of size K in the array.*/

//--- Solution ---

vector <int> countDistinct (int a[], int n, int k)
    {
        //code here.
        vector<int> ans;
        unordered_map<int, int> m;
        int i=0;
        while(i<k)
        {
            m[a[i]]++;
            i++;
        }
        ans.push_back(m.size());
        while(i<n)
        {
            if(m[a[i-k]]==1)
                m.erase(a[i-k]);
            else
                m[a[i-k]]--;
            m[a[i]]++;
            ans.push_back(m.size());
            i++;
        }
        return ans;
    }
