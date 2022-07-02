//---Problem Discription
//Given an array of 0s, 1s, and 2s.
//Arrange the array elements such that all 0s come first, followed by all the 1s and then, all the 2s.

int partition2(int arr[], int low, int high, int pivot)
    {
        //int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element
 
        for (int j = low; j <= high; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] < pivot)
            {
                i++;    // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        //swap(arr[i + 1], arr[high]);
        return i+1;
    }
    void segragate012(int arr[], int N)
    {
        // Your Code Here
        int low = partition2(arr, 0, N-1, 1);
        partition2(arr, low, N-1, 2);
    }
