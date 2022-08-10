//--- Problem Statement ---
/*You are given string str. You need to remove the pair of duplicates.
Note: The pair should be of adjacent elements and after removing a pair the remaining string is joined together.*/

//--- Solution ---

string removePair(string str)
{
    stack<char> s;
    string ans;
    for(auto x : str)
    {
        if(s.empty() || s.top()!=x)
            s.push(x);
        else
            s.pop();
    }
    while(!s.empty())
    {
        ans=s.top()+ans;
        s.pop();
    }
    return ans;
}
