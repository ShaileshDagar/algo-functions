//--- Problem Statement ---

/*Given an array arr containing N words consisting of lowercase characters. 
Your task is to find the most frequent word in the array. 
If multiple words have same frequency, 
then print the word whose first occurence occurs last in the array as compared to the other strings with same frequency.*/

//--- Solution ---

class TrieNode
{
    public:
    bool isend;
    int count;
    vector<TrieNode*> child;
    TrieNode()
    {
        count=0;
        isend=false;
        child.resize(58);
        for(int i=0; i<58; i++)
            child[i]=nullptr;
    }
    int insert(const string& s)
    {
        TrieNode* temp = this;
        int i;
        for(char x : s)
        {
            i = x - 'A';
            if(temp->child[i] == nullptr)
                temp->child[i] = new TrieNode();
            temp = temp->child[i];
        }
        (temp->count)++;
        temp->isend = true;
        return (temp->count);
    }
};
class Solution
{
    public:
    
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        TrieNode* t = new TrieNode();
        pair<string, int> ans;
        int c;
        ans.first=arr[n-1];
        ans.second=1;
        for(int i=n-1; i>=0; i--)
        {
            c = t->insert(arr[i]);
            if(c>ans.second)
            {
                ans.first =arr[i];
                ans.second = c;
            }
        }
        return ans.first;
    }
};
