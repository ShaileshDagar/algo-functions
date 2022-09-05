//--- Problem Statement ---

/*Given an array of size N containing level order traversal of a BST. 
The task is to complete the function constructBst(), that construct the BST (Binary Search Tree) from its given level order traversal.*/

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

//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    // Code here
    Node* root = new Node(arr[0]);
    element* e = new element(root, INT_MIN, INT_MAX);
    queue<element*> q;
    q.push(e);
    for(int i=1; i<n; i++)
    {
        while(arr[i]<(e->r_min) || arr[i]>(e->r_max))
        {
            q.pop();
            e=q.front();
        }
        if(arr[i]<(e->n)->data)
        {
            (e->n)->left=new Node(arr[i]);
            element* f = new element((e->n)->left, e->r_min, (e->n)->data);
            q.push(f);
        }
        else
        {
            (e->n)->right = new Node(arr[i]);
            element* f = new element((e->n)->right, (e->n)->data, e->r_max);
            q.push(f);
            q.pop();
            e=q.front();
        }
    }
    return root;
}
