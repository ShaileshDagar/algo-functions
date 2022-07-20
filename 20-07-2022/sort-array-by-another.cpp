//--- Proeblem Statement ---
/*Given two integer arrays A1[ ] and A2[ ] of size N and M respectively.
Sort the first array A1[ ] such that all the relative positions of the elements
in the first array are the same as the elements in the second array A2[ ].

Note: If elements are repeated in the second array, consider their first occurance only.*/

//--- Solution ---

vector<int> sortA1ByA2(vector<int> a1, int n, vector<int> a2, int m) 
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0; i<m; i++)
        {
            if(mp.find(a2[i])==mp.end())
                mp[a2[i]]=INT_MIN+i;
        }
        pair<int, int> p[n];
        for(int i=0; i<n; i++)
        {
            if(mp.find(a1[i])!=mp.end())
            {
                p[i].first=mp[a1[i]];
            }
            else
                p[i].first=a1[i];
            p[i].second=a1[i];
        }
        sort(p, p+n);
        for(auto x : p)
            ans.push_back(x.second);
        return ans;
    } 
