//--- Problem Statement ---

/*Given an array of n elements, where each element is at most k away from its target position,
you need to sort the array optimally.*/

//--- Solution ---

vector <int> nearlySorted(int arr[], int n, int k){
  vector<int> ans;
  priority_queue<int, vector<int>, greater<int>> pq(arr, arr+k+1);
  ans.push_back(pq.top());
  pq.pop();
  for(int i=k+1; i<n; i++)
  {
      pq.push(arr[i]);
      ans.push_back(pq.top());
      pq.pop();
  }
  while(!pq.empty())
  {
      ans.push_back(pq.top());
      pq.pop();
  }
  return ans;
}
