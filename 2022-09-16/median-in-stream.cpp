//--- Problem Statement ---

/*Given an input stream of N integers. 
The task is to insert these numbers into a new stream and find the median 
of the stream formed by each insertion of X to the new stream.*/

//--- Solution ---

priority_queue<int> maxh;
priority_queue<int, vector<int>, greater<int>> minh;
void insertHeap(int &x)
{
  if(maxh.empty())
      maxh.push(x);
  else
  {
      if(x<maxh.top())
          maxh.push(x);
      else
          minh.push(x);
  }
  int bal = maxh.size() - minh.size();
  if(abs(bal)>1)
      balanceHeaps(bal);
}

//Function to balance heaps.
void balanceHeaps(int bal)
{
  if(bal>0)
  {
      minh.push(maxh.top());
      maxh.pop();
  }
  else
  {
      maxh.push(minh.top());
      minh.pop();
  }
}

//Function to return Median.
double getMedian()
{
  int bal = maxh.size()-minh.size();
  if(bal==0)
      return (maxh.top() + minh.top())/2.0;
  else if(bal>0)
      return maxh.top();
  else
      return minh.top();
}
