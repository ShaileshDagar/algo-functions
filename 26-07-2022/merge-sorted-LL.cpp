//--- Problem Statement ---
/*Given two sorted linked lists consisting of N and M nodes respectively.
The task is to merge both of the list (in-place) and return head of the merged list.*/

//--- Solution ---

Node* sortedMerge(Node* head1, Node* head2)  
{
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
