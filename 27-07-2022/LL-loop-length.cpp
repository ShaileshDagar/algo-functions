//--- Problem Stetement ---
/*Given a linked list of size N.
The task is to complete the function countNodesinLoop() that checks whether
a given Linked List contains a loop or not and if the loop is present
then return the count of nodes in a loop or else return 0.
C is the position of the node to which the last node is connected. If it is 0 then no loop.*/

//--- Solution ---

bool detectLoop(Node* head, Node*& p1, Node*& p2)
    {
        while(p2 && p1!=p2)
        {
            p1=p1->next;
            p2=p2->next;
            if(p2)
                p2=p2->next;
        }
        if(p2==nullptr)
            return false;
        return true;
    }
int countNodesinLoop(struct Node *head)
{
    int ans=0;
    Node* p1=head;
    Node* p2=head->next;
    if(detectLoop(head, p1, p2))
    {
        ans++;
        p1=p1->next;
        while(p1!=p2)
        {
            p1=p1->next;
            ans++;
        }
    }
    return ans;
}
