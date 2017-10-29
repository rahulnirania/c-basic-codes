#include <iostream.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
}

class Tree
{
    public:
        int height(node *);
        int diff(node *);
        node *rr_rotation(node *);
        node *ll_rotation(node *);
        node *lr_rotation(node *);
        node *rl_rotation(node *);
        node* balance(node *);
        node* insert(node *, int );
        void display(node *, int);
        void inorder(node *);
        void preorder(node *);
        void postorder(node *);
        Tree()
        {
            root = NULL;
        }
};
main()
{

}
