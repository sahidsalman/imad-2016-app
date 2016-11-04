#include <iostream>
#include<cstdlib>
using namespace std;

// A generic tree node class
class Node
{
    int key;
    Node* left;
    Node* right;
    Node* parent;
public:
    Node() { key=-1; left=NULL; right=NULL; parent = NULL;}

    void setKey(int aKey) { key = aKey; }
    void setLeft(Node* aLeft) { left = aLeft; }
    void setRight(Node* aRight) { right = aRight; }
    void setParent(Node* aParent) { parent = aParent; }

    int Key() { return key; }
    Node* Left() { return left; }
    Node* Right() { return right; }
    Node* Parent() { return parent; }
};

// Binary Search Tree class
class Tree
{
    Node* root;
public:
    Tree();
    ~Tree();
    Node* Root() { return root; };
    void addNode(int key);
    Node* findNode(int key, Node* parent);
    void walk(Node* node);
    void deleteNode(int key);
    Node* min(Node* node);
    Node* max(Node* node);
    Node* successor(int key, Node* parent);
    Node* predecessor(int key, Node* parent);
private:
    void addNode(int key, Node* leaf);
    void freeNode(Node* leaf);
};

// Constructor
Tree::Tree()
{
    root = NULL;
}

// Destructor
Tree::~Tree()
{
    freeNode(root);
}

// Free the node
void Tree::freeNode(Node* leaf)
{
    if ( leaf != NULL )
    {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        delete leaf;
    }
}

// Add a node [O(height of tree) on average]
void Tree::addNode(int key)
{
    // No elements. Add the root
    if ( root == NULL ) {
        cout << "add root node ... " << key << endl;
        Node* n = new Node();
        n->setKey(key);
    root = n;
    }
    else {
    cout << "add other node ... " << key << endl;
    addNode(key, root);
    }
}

// Add a node (private)
void Tree::addNode(int key, Node* leaf) {
    if ( key <= leaf->Key() )
    {
        if ( leaf->Left() != NULL )
            addNode(key, leaf->Left());
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setLeft(n);
        }
    }
    else
    {
        if ( leaf->Right() != NULL )
            addNode(key, leaf->Right());
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setRight(n);
        }
    }
}

// Find a node [O(height of tree) on average]
Node* Tree::findNode(int key, Node* node)
{
    if ( node == NULL )
        return NULL;
    else if ( node->Key() == key )
        return node;
    else if ( key <= node->Key() )
        findNode(key, node->Left());
    else if ( key > node->Key() )
        findNode(key, node->Right());
    else
        {cout<<" Node Not Found !";
        return NULL;}
}

// Print the tree
void Tree::walk(Node* node)
{
    if ( node )
    {

        walk(node->Left());
        cout << node->Key() << " ";
        walk(node->Right());
    }
}

// Find the node with min key
// Traverse the left sub-tree recursively
// till left sub-tree is empty to get min
Node* Tree::min(Node* node)
{
    if ( node == NULL )
        return NULL;

    if ( node->Left()!=NULL )
        min(node->Left());
    else
        return node;
}

// Find the node with max key
// Traverse the right sub-tree recursively
// till right sub-tree is empty to get max
Node* Tree::max(Node* node)
{
    if ( node == NULL )
        return NULL;

    if ( node->Right()!=NULL )
        max(node->Right());
    else
        return node;
}

// Find successor to a node
// Find the node, get the node with max value
// for the right sub-tree to get the successor
Node* Tree::successor(int key, Node *node)
{
    Node* thisKey = findNode(key, node);
    if ( thisKey )
        return thisKey->Right();
         else
            return NULL;
}

// Find predecessor to a node
// Find the node, get the node with max value
// for the left sub-tree to get the predecessor
Node* Tree::predecessor(int key, Node *node)
{
    Node* thisKey = findNode(key, node);
    if (thisKey)
        return thisKey->Left();
        else
            return NULL;
}

// Delete a node
// (1) If leaf just delete
// (2) If only one child delete this node and replace
// with the child
// (3) If 2 children. Find the predecessor (or successor).
// Delete the predecessor (or successor). Replace the
// node to be deleted with the predecessor (or successor).
void Tree::deleteNode(int key)
{
    // Find the node.
    Node* thisKey = findNode(key, root);

    // (1)
    if ( thisKey->Left() == NULL && thisKey->Right() == NULL )
    {
        if ( thisKey->Key() > thisKey->Parent()->Key() )
            thisKey->Parent()->setRight(NULL);
        else
            thisKey->Parent()->setLeft(NULL);

        delete thisKey;
    }

    // (2)
    if ( thisKey->Left() == NULL && thisKey->Right() != NULL )
    {
        if ( thisKey->Key() > thisKey->Parent()->Key() )
            thisKey->Parent()->setRight(thisKey->Right());
        else
            thisKey->Parent()->setLeft(thisKey->Right());

        delete thisKey;
    }
    if ( thisKey->Left() != NULL && thisKey->Right() == NULL )
    {
        if ( thisKey->Key() > thisKey->Parent()->Key() )
            thisKey->Parent()->setRight(thisKey->Left());
        else
            thisKey->Parent()->setLeft(thisKey->Left());

        delete thisKey;
    }

    // (3)
    if ( thisKey->Left() != NULL && thisKey->Right() != NULL )
    {
        Node* sub = predecessor(thisKey->Key(), thisKey);
        if ( sub == NULL )
            sub = successor(thisKey->Key(), thisKey);

        if ( sub->Parent()->Key() <= sub->Key() )
            sub->Parent()->setRight(sub->Right());
        else
            sub->Parent()->setLeft(sub->Left());

        thisKey->setKey(sub->Key());
        delete sub;
    }
}

// Test main program
int main() {
    int inp,num;
    Tree* tree = new Tree();
  while(1)
  {
      cout<<" Binary Search tree. \n";
   cout<<"1. Add Node\n2.Delete node\n3.Traverse\n4.Minimum\n5.Maximum\n6.Predecessor\n7.Successor\n8.exit\nEnter the Choice:";
   cin>>inp;

 switch(inp)
   {
     case 1: cout<<"\nEnter the Element you want to add:";
	         cin>>num;
	         tree->addNode(num);
	         break;
     case 2:  cout<<"\nEnter the Element you want to delete:";
             cin>>num;
             tree->deleteNode(num);
             break;
     case 3:     tree->walk(tree->Root());
                 cout << endl;
                 break;
     case 4:     cout << "Min=" <<tree->min(tree->Root())->Key()<< endl;
                 cout << endl;
                 break;
     case 5:     cout << "Max=" <<tree->max(tree->Root())->Key()<< endl;
                 cout << endl;
                 break;
     case 6:     cout<<"\nSuccessor of which element?:";
                 cin>>num;
                 if(tree->successor(num, tree->Root())->Key())
                 cout << "Successor to "<<num<<"=" <<tree->successor(num, tree->Root())->Key() << endl;
                 else
                    cout<<"\n No Successor!!";
                 break;
     case 7:     cout<<"\nPredecessor of which element?:";
                 cin>>num;
                 if(tree->predecessor(num, tree->Root())->Key())
                 cout << "Predecessor to "<<num<<"=" <<tree->predecessor(num, tree->Root())->Key() << endl;
                 else cout<<"\n No Predeccessor !!!";
                 break;
      case 8:    exit(0);
     default: cout<<"\nPlease Enter a Valid Choice(1-8)!!!";
   }
  }


    delete tree;
    return 0;
}
