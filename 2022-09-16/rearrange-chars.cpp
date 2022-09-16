//--- Problem Statement ---

/*Given a string S such that it may contain repeated lowercase alphabets. 
Rearrange the characters in the string such that no two adjacent characters are same.*/

//--- Solution ---

string rearrangeString(string str)
{
  int idx=0;
  int n=str.length();
  char ans[n+1];
  pair<int, char> p;
  unordered_map<char, int> m;
  priority_queue<pair<int, char>> pq;
  for(char x : str)
      m[x]++;
  for(auto y : m)
      pq.push({y.second, y.first});
  while(!pq.empty())
  {
      p=pq.top();
      pq.pop();
      for(int i=0; i<p.first; i++)
      {
          ans[idx]=p.second;
          idx+=2;
          idx = (idx>=n) ? 1 : idx;
      }
  }
  ans[n] = '\0';
  return ans;
}
