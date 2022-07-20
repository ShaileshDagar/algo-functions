//--- Problem Statement ---

/*You are given an array A[] of  N Integers and an integer K. You have to choose K integers.
You can choose only the element which has the maximum frequency. The element will be removed from the array after being chosen.
If there are many elements with the maximum frequency then you can choose any. Your aim is to maximize the sum.*/

//--- Solution ---

class Comp{
    public:
    bool operator()(const pair<int, int>& p1, const pair<int ,int>& p2)
    {
        if(p1.first==p2.first)
            return p1.second<p2.second;
        return p1.first<p2.first;
    }
};

class Solution{
  public:
    long maximum_sum(int n, vector<int> a, int k)
    {
       // Your code here
        int count=0;
        long ans=0;
        unordered_map<int, int> m;
        for(int x : a)
            m[x]++;
        vector<pair<int, int>> v;
        for(auto y : m)
            v.push_back({y.second, y.first});
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq(v.begin(), v.end());
        pair<int, int> x;
        while(count!=k)
        {
            x=pq.top();
            ans+=x.second;
            pq.pop();
            if(x.first>1)
            {
                x.first--;
                pq.push(x);
            }
            count++;
        }
        return ans;
    }
};
