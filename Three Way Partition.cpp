//---Problem Discription
/*
Given an array of size n and a range [a, b].
The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order.
You are required to return the modified array.*/

int partition1(vector<int>& arr, int low, int high, int pivot)
    {
        //int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element
 
        for (int j = low; j <= high; j++)
        {
            // If current element is smaller than pivot
            if (arr[j] < pivot)
            {
                i++;    // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        //swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
    void partition2(vector<int>& arr, int low, int high, int pivot)
    {
        //int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element
 
        for (int j = low; j <= high; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot)
            {
                i++;    // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        //swap(arr[i + 1], arr[high]);
        return ;
    }
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here
        int high=array.size()-1;
        int low = partition1(array, 0, high, a);
        partition2(array, low, high, b);
        return ;
    }