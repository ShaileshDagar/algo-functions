//--- Problem Stement ---
/*Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1.
The characters in the strings are in lowercase.*/

//--- Solution ---

bool areRotations(string s1,string s2)
    {
        // Your code here
        string s=s1+s1;
        return (s1.length()==s2.length() && s.find(s2)!=-1);
    }
