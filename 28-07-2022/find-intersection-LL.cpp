//--- Problem Statement ---
/*Given two singly linked lists of size N and M,
write a program to get the point where two linked lists intersect each other.*/

//--- Solution ---

int intersectPoint(Node* h1, Node* h2)
{
    Node* curr=h1;
    int n=0,m=0;
    while(curr)
    {
        n++;
        curr=curr->next;
    }
    curr=h2;
    while(curr)
    {
        m++;
        curr=curr->next;
    }
    if(n>m)
    {
        while(n!=m)
        {
            h1=h1->next;
            n--;
        }
    }
    else
    {
        while(m!=n)
        {
            h2=h2->next;
            m--;
        }
    }
    while(h1 && h2)
    {
        if(h1==h2)
            return h1->data;
        h1=h1->next;
        h2=h2->next;
    }
    return -1;
}
