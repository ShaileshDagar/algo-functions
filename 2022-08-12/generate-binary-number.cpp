//--- Problem Statement ---
/*Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.*/

//--- Solution ---

vector<string> generate(int n)
{
    vector<string> ans;
    for(int i=1; i<=n; i++)
    {
        string no = "1";
        stack<char> s;
        int j=i;
        while(j>1)
        {
            s.push(j%2 + '0');
            j>>=1;
        }
        while(!s.empty())
        {
            no+=s.top();
            s.pop();
        }
        ans.push_back(no);
    }
    return ans;
}
