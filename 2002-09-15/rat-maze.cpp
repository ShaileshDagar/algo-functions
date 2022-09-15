//--- Problem Statement ---

/*Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
Find all possible paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix 
represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.*/

//--- Solution ---

void find(vector<vector<int>> &m, vector<string>& ans, string& x, int n, int i, int j)
{
    if(i==n-1 && j==n-1)
        ans.push_back(x);
    else
    {
        m[i][j]=-1;
        if(i<n-1 && m[i+1][j]>0)
        {
            x+='D';
            find(m, ans, x, n, i+1, j);
            x.pop_back();
        }
        if(j>0 && m[i][j-1]>0)
        {
            x+='L';
            find(m, ans, x, n, i, j-1);
            x.pop_back();
        }
        if(j<n-1 && m[i][j+1]>0)
        {
            x+='R';
            find(m, ans, x, n, i, j+1);
            x.pop_back();
        }
        if(i>0 && m[i-1][j]>0)
        {
            x+='U';
            find(m, ans, x, n, i-1, j);
            x.pop_back();
        }
        m[i][j]=1;
    }
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<string> ans;
    string x;
    if(m[0][0])
        find(m, ans, x, n, 0, 0);
    return ans;
}
