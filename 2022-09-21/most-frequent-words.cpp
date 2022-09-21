//--- Problem Statement ---

/*Given an array arr containing N words consisting of lowercase characters. 
Your task is to find the most frequent word in the array. 
If multiple words have same frequency, 
then print the word whose first occurence occurs last in the array as compared to the other strings with same frequency.*/

//--- Solution ---

string mostFrequentWord(string arr[], int n) 
{
    // code here
    pair<string, int> ans;
    ans.first=arr[n-1];
    ans.second=1;
    unordered_map<string, int> m;
    for(int i=n-1; i>=0; i--)
    {
        m[arr[i]]++;
        if(m[arr[i]]>ans.second)
        {
            ans.first =arr[i];
            ans.second = m[arr[i]];
        }
    }
    return ans.first;
}
