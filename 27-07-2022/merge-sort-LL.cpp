//--- Problem Statement ---
/*Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.*/

//--- Solution ---

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* ans=head1;
    Node* prev1=head1;
    Node* curr1=head1;
    Node* curr2=head2;
    if(curr2->data>=curr1->data)
        curr1=curr1->next;
    else
    {
        prev1=curr2;
        curr2=curr2->next;
        prev1->next=curr1;
        ans=prev1;
    }
    while(curr1 && curr2)
    {
        if(curr2->data<=curr1->data)
        {
            prev1->next=curr2;
            curr2=curr2->next;
            prev1=prev1->next;
            prev1->next=curr1;
        }
        else
        {
            prev1=curr1;
            curr1=curr1->next;
        }
    }
    if(curr1==nullptr)
    {
        prev1->next=curr2;
        curr2=nullptr;
    }
    return ans;
}  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        int n=0;
        Node* curr=head;
        Node* s;
        while(curr)
        {
            n++;
            curr=curr->next;
        }
        if(n<2)
            return head;
        int k = (n+1)/2;
        curr=head;
        int count=1;
        while(count!=k)
        {
            count++;
            curr=curr->next;
        }
        s=curr->next;
        curr->next=nullptr;
        return sortedMerge(mergeSort(head), mergeSort(s));
    }
