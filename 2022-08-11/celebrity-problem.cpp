//--- Problem Statement ---
/*A celebrity is a person who is known to all but does not know anyone at a party.
If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that
if an element of row i and column j  is set to 1 it means ith person knows jth person. 
Here M[i][i] will always be 0.
Note: Follow 0 based indexing.*/

//--- Solution ---

int celebrity(vector<vector<int> >& M, int n) 
{
    int count=0;
    int i=0,j=0;
    while(i<n)
    {
        if(i==j)
        {
            j=(j+1)%n;
            continue;
        }
        else if(M[i][j]==M[j][i])
        {
            if(j<i)
                return -1;
            else
            {
                i=j+1;
                count=0;
            }
        }
        else if(M[i][j]==0)
        {
            count++;
            if(count==n-1)
                return i;
        }
        else
        {
            if(j<i)
                return -1;
            else
            {
                i=j;
                count=0;
            }
        }
        j=(j+1)%n;
    }
    return -1;
}
