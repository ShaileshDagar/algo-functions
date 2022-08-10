//--- Problem Statement ---
/*You are given string str. 
You need to remove the consecutive duplicates from the given string using a Stack.*/

//--- Solution ---

string removeConsecutiveDuplicates(string str)
{
    string ans;
    stack<char> s;
    s.push(str[0]);
    for(int i=1; i<str.length(); i++)
    {
        if(s.top()!=str[i])
            s.push(str[i]);
    }
    while(!s.empty())
    {
        ans=s.top()+ans;
        s.pop();
    }
    return ans;
}
