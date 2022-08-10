//--- Problem Statement ---
/*Given string S representing a postfix expression, the task is to evaluate the expression and find the final value.
Operators will only include the basic arithmetic operators like *, /, + and -.*/

//--- Solution ---

int evaluatePostfix(string s)
{
    stack<int> y;
    int a,b;
    for(char x : s)
    {
        if(x>='0' && x<='9')
            y.push(x-'0');
        else
        {
            b=y.top();
            y.pop();
            a=y.top();
            y.pop();
            if(x=='*')
                y.push(a*b);
            else if(x=='+')
                y.push(a+b);
            else if(x=='-')
                y.push(a-b);
            else
                y.push(a/b);
        }
    }
    return y.top();
}
