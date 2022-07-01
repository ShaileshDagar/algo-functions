//--- Problem Statement ---

/*Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size n and m respectively, find their union.*/

vector<int> findUnion(int a[], int b[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        int i=0, j=0;
        while(i<n && j<m)
        {
            if(a[i]==b[j])
            {
                ans.push_back(a[i]);
                do
                {
                    i++;
                }while(i<n && a[i]==a[i-1]);
                do
                {
                    j++;
                }while(j<m && b[j]==b[j-1]);
            }
            else if(a[i]<b[j])
            {
                ans.push_back(a[i]);
                do
                {
                    i++;
                }while(i<n && a[i]==a[i-1]);
            }
            else
            {
                ans.push_back(b[j]);
                do
                {
                    j++;
                }while(j<m && b[j]==b[j-1]);
            }
            if(i==n)
            {
                while(j<m)
                {
                    if(b[j]!=ans.back())
                        ans.push_back(b[j]);
                    j++;
                }
            }
            else if(j==m)
            {
                while(i<n)
                {
                    if(a[i]!=ans.back())
                        ans.push_back(a[i]);
                    i++;
                }
            }
        }
        return ans;