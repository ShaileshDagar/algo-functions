//--- Problem Statement ---

/*You are given a special linked list with N nodes where each node has a next pointer pointing to its next node.
You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.
Construct a copy of the given list. The copy should consist of exactly N new nodes,
where each new node has its value set to the value of its corresponding original node.
Both the next and random pointer of the new nodes should point to new nodes in the copied list 
such that the pointers in the original list and copied list represent the same list state.
None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y,
then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.*/

//--- Solution ---

Node *copyList(Node *head)
{
    unordered_map<Node*, int> og;
    unordered_map<int, Node*> copy;
    Node* ans= new Node(0);
    Node* curr=head;
    Node* temp=ans;
    int count=1;
    while(curr)
    {
        temp->next = new Node(curr->data);
        og[curr]=count;
        temp=temp->next;
        copy[count]=temp;
        curr=curr->next;
        count++;
    }
    temp=ans;
    ans=ans->next;
    delete temp;
    temp=ans;
    curr=head;
    while(curr)
    {
        if(curr->arb)
        {
            temp->arb=copy[og[curr->arb]];
        }
        curr=curr->next;
        temp=temp->next;
    }
    return ans;
}
