//--- Problem Statement ---

/*Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the exact BST from it's given preorder traversal.*/

//--- Solution ---

class element{
public:
Node* n;
int r_min;
int r_max;
element(Node* node, int minr, int maxr)
{
    n=node;
    r_min=minr;
    r_max=maxr;
}
};

Node* post_order(int arr[], int n)
{
    //code here
    Node* root = newNode(arr[0]);
    element* e = new element(root, INT_MIN, INT_MAX);
    stack<element*> s;
    s.push(e);
    for(int i=1; i<n; i++)
    {
        while(arr[i]<(e->r_min) || arr[i]>(e->r_max))
        {
            s.pop();
            e=s.top();
        }
        if(arr[i]<(e->n)->data)
        {
            (e->n)->left=newNode(arr[i]);
            element* f = new element((e->n)->left, e->r_min, (e->n)->data);
            s.push(f);
        }
        else
        {
            (e->n)->right = newNode(arr[i]);
            element* f = new element((e->n)->right, (e->n)->data, e->r_max);
            s.pop();
            s.push(f);
        }
        e=s.top();
    }
    return root;
}
