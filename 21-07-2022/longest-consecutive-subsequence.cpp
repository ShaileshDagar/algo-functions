//--- Problem Statement ---
/*Given an array of positive integers.
Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers,
the consecutive numbers can be in any order.*/

//--- Solution ---

int findLongestConseqSubseq(int arr[], int n)
    {
        int count;
        int ans=0;
        unordered_map<int, bool> mp;
        for(int i=0; i<n; i++)
            mp[arr[i]]=false;
        int x,z;
        for(auto y : mp)
        {
            if(y.second==false)
            {
                y.second=true;
                count=1;
                x=y.first-1;
                z=y.first+1;
                while(mp.find(x)!=mp.end())
                {
                    count++;
                    mp[x]=true;
                    x--;
                }
                while(mp.find(z)!=mp.end())
                {
                    count++;
                    mp[z]=true;
                    z++;
                }
                ans=max(ans, count);
            }
        }
        return ans;
    }
