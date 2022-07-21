//--- Problem Statement ---

/*Given a AxB Grid.
Choose any positive integer C and paint any unpainted square of dimension CXC inside the grid.
Minimum number of moves to paint the entire grid.*/

//--- Solution ---

int minimumMoves(int a, int b) {
        int ans=0;
        while(a&b)
        {
            ans++;
            if(a>b)
                a-=b;
            else
                b-=a;
        }
        return ans;
    }
