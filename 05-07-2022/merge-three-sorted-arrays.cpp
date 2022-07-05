//--- Problem Statement ---

/*Given three sorted arrays A, B and C of size N, M and P respectively.
The task is to merge them into a single array which must be sorted in increasing order.*/

void mergeTwo(vector<int>& a, vector<int>& b, vector<int>& merged)
    {
        int i=0, j=0;
        int n=a.size();
        int m=b.size();
        while(i<n && j<m)
        {
            if(a[i]<=b[j])
            {
                merged.push_back(a[i]);
                i++;
            }
            else
            {
                merged.push_back(b[j]);
                j++;
            }
            if(i==n)
            {
                while(j<m)
                {
                    merged.push_back(b[j]);
                    j++;
                }
            }
            else if(j==m)
            {
                while(i<n)
                {
                    merged.push_back(a[i]);
                    i++;
                }
            }
        }
    }
    vector<int> mergeThree(vector<int>& a, vector<int>& b, vector<int>& c) 
    { 
        //Your code here
        vector<int> ans;
        vector<int> temp;
        mergeTwo(a, b, temp);
        mergeTwo(temp, c, ans);
        return ans;
    } 
