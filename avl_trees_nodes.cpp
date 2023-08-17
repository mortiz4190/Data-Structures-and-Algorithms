#include <iostream>
using namespace std;
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(){
      data = 0;
      left = NULL;
      right = NULL;
    }
    Node(int val){
      data = val;
      left = NULL;
      right = NULL;
    }
};
void inorder(Node *currentPtr);
Node* insert(Node *root,
                         Node *element);
int add(Node *currentPtr);
int find(Node *currentPtr, int val);
Node* parent(Node *root, Node *node);
Node* minVal(Node *root);
Node* maxVal(Node *root);
int isLeaf(Node *node);
int hasOnlyLeftChild(Node *node);
int hasOnlyRightChild(Node *node);
Node* findNode(Node *currentPtr, int value);
Node* deleteNode(Node* root, int value);
void RotateRight(Node *x);
Node *Next(Node *N);
Node *findSearch(int x, Node *R);
int computeHeight(Node *root);
void sum(Node *root, int k1, int k2);
Node *LeftDescendant(Node *N);
Node *RightAncestor(Node *N);
int menu();



void inorder(Node *currentPtr) {
  // Only traverse the node if it's not null.
  if (currentPtr != NULL) {
    inorder(currentPtr->left); // Go Left.
    cout<<" "<<currentPtr->data; // Print the root.
    inorder(currentPtr->right); // Go Right.
  }
}



Node* insert(Node *root,
                         Node *element) {
  // Inserting into an empty tree.
  if (root == NULL){
    return element;
  }
  else {
    // element should be inserted to the right.
    if (element->data > root->data) {
      // There is a right subtree to insert the node.
      if (root->right != NULL)
        root->right = insert(root->right, element);
      // Place the node directly to the right of root.
      else
        root->right = element;
    }
    // element should be inserted to the left.
    else {
      // There is a left subtree to insert the node.
      if (root->left != NULL)
        root->left = insert(root->left, element);
      // Place the node directly to the left of root.
      else
        root->left = element;
    }
    // Return the root pointer of the updated tree.
    return root;
  }
}



int find(Node *currentPtr, int val) {
  // Check if there are nodes in the tree.
  if (currentPtr != NULL) {
    // Found the value at the root.
    if (currentPtr->data == val)
      return 1;
    // Search to the left.
    if (val < currentPtr->data)
      return find(currentPtr->left, val);
    // Or search to the right.
    else
      return find(currentPtr->right, val);
  }
  else
    return 0;
}



int add(Node *currentPtr) {
  if (currentPtr != NULL)
    return currentPtr->data+add(currentPtr->left)+
           add(currentPtr->right);
  else
    return 0;
}



// Returns the parent of the node pointed to by node in the tree rooted at
// root. If the node is the root of the tree, or the node doesn't exist in
// the tree, null will be returned.
Node* parent(Node *root, Node *node) {
  // Take care of NULL cases.
  if (root == NULL || root == node)
    return NULL;
  // The root is the direct parent of node.
  if (root->left == node || root->right == node)
    return root;
  // Look for node's parent in the left side of the tree.
  if (node->data < root->data)
    return parent(root->left, node);
  // Look for node's parent in the right side of the tree.
  else if (node->data > root->data)
    return parent(root->right, node);
  return NULL; // For any other cases.
}



// Returns a pointer to the node storing the minimum value in the tree
Node* minVal(Node *root) {
  // Root stores the minimal value.
  if (root->left == NULL)
    return root;
  // The left subtree of the root stores the minimal value.
  else
    return minVal(root->left);
}



// Returns a pointer to the node storing the maximum value in the tree
Node* maxVal(Node *root) {
  // Root stores the maximal value.
  if (root->right == NULL)
    return root;
  // The right subtree of the root stores the maximal value.
  else
    return maxVal(root->right);
}





// Returns 1 if node is a leaf node, 0 otherwise.
int isLeaf(Node *node) {
  return (node->left == NULL && node->right == NULL);
}



// Returns 1 iff node has a left child and no right child.
int hasOnlyLeftChild(Node *node) {
  return (node->left!= NULL && node->right == NULL);
}



// Returns 1 iff node has a right child and no left child.
int hasOnlyRightChild(Node *node) {
  return (node->left== NULL && node->right != NULL);
}



// Returns a pointer to a node that stores value in it in the subtree
Node* findNode(Node *currentPtr, int value) {
  // Check if there are nodes in the tree.
  if (currentPtr != NULL) {
    // Found the value at the root.
    if (currentPtr->data == value)
      return currentPtr;
    // Search to the left.
    if (value < currentPtr->data)
      return findNode(currentPtr->left, value);
    // Or search to the right.
    else
      return findNode(currentPtr->right, value);
  }
  else
    return NULL; // No node found.
}



// Will delete the node storing value in the tree rooted at root. The
// value must be present in the tree in order for this function to work.
// The function returns a pointer to the root of the resulting tree.
Node* deleteNode(Node* root, int value) {
  Node *delnode, *newDelNode, *saveNode;
  Node *par;
  int saveVal;
  delnode = findNode(root, value); // Get a pointer to the node to delete.
  par = parent(root, delnode); // Get the parent of this node.
  // Take care of the case where the node to delete is a leaf node.
  if (isLeaf(delnode)) {// case 1
    // Deleting the only node in the tree.
    if (par == NULL) {
      delete root; // free the memory for the node.
      return NULL;
    }
    // Deletes the node if it's a left child.
    if (value < par->data) {
      delete par->left; // Free the memory for the node.
    }
    // Deletes the node if it's a right child.
    else {
      delete par->right; // Free the memory for the node.
      par->right = NULL;
    }
    return root; // Return the root of the new tree.
  }
  // Take care of the case where the node to be deleted only has a left
  // child.
  if (hasOnlyLeftChild(delnode)) {
    // Deleting the root node of the tree.
    if (par == NULL) {
      saveNode = delnode->left;
      delete delnode; // Free the node to delete.
      return saveNode; // Return the new root node of the resulting tree.
    }
    // Deletes the node if it's a left child.
    if (value < par->data) {
      saveNode = par->left; // Save the node to delete.
      par->left = par->left->left; // Readjust the parent pointer.
      delete saveNode; // Free the memory for the deleted node.
    }
    // Deletes the node if it's a right child.
    else {
      saveNode = par->right; // Save the node to delete.
      par->right = par->right->left; // Readjust the parent pointer.
      delete saveNode; // Free the memory for the deleted node.
    }
    return root; // Return the root of the tree after the deletion.
  }
  // Takes care of the case where the deleted node only has a right child.
  if (hasOnlyRightChild(delnode)) {
    // Node to delete is the root node.
    if (par == NULL) {
      saveNode = delnode->right;
      delete delnode;
      return saveNode;
    }
    // Delete's the node if it is a left child.
    if (value < par->data) {
      saveNode = par->left;
      par->left = par->left->right;
      delete saveNode;
    }
    // Delete's the node if it is a right child.
    else {
      saveNode = par->right;
      par->right = par->right->right;
      delete saveNode;
    }
    return root;
  }
//when delnode has two children
  // Find the new physical node to delete.
  newDelNode = minVal(delnode->right);
  saveVal = newDelNode->data;
  deleteNode(root, saveVal);  // Now, delete the proper value.
  // Restore the data to the original node to be deleted.
  delnode->data = saveVal;
  return root;
}


//Rotates AVL tree to the right
void RotateRight(Node *X){
  Node *P = X->parent;
  Node *Y = X->left;
  Node *B = Y->right;
  Y->parent = P;
  P->left = Y;
  X->parent = Y;
  Y->right = X;
  B->parent = X;
  X->left = B;
}



//Provides next element after a given key 
Node *Next(Node *N) {
  if (N->right != NULL)
    return LeftDescendant(N->right);
  else
    return RightAncestor(N);
}



Node *findSearch(int x, Node *R) {
  // Check if there are nodes in the tree.
  if (R != NULL) {

    //found
    if (R->data == x)
      return R;

    else if (R->data > x)
      if (R->left != NULL)
        return findSearch(x, R->left);
    return R;
  } else  //no nodes
    return NULL;
}



//Compute the height of an AVL tree
int computeHeight(Node *root){
  if (root == NULL)
    return 0;
  return (root->height);
}


void sum(node *root, int k1, int k2)
{
    /* base case */
    if ( NULL == root )
        return; 
    /* Since the desired o/p is sorted,
        recurse for left subtree first
        If root->data is greater than k1,
        then only we can get o/p keys
        in left subtree */
    if ( k1 < root->data )
        sum(root->left, k1, k2);
     
    /* if root's data lies in range,
    then prints root's data */
    if ( k1 <= root->data && k2 >= root->data )
        cout<<root->data<<" ";
     
    /* recursively call the right subtree */
   sum(root->right, k1, k2);
}



Node *LeftDescendant(Node *N){
  if (N->left == NULL)
    return N;
  else
    return LeftDescendant(N->left);
}



Node *RightAncestor(Node *N){
  if (N->data < N->parent->data)
    return N->parent;
  else
    return RightAncestor(N->parent);
}



// Prints out the menu of choices for the user and returns their choice.
int menu() {
  int ans;
  cout<<"Here are your choices.\n";
  cout<<"1. Insert an item into your tree.\n";
  cout<<"2. Delete an item from your tree.\n";
  cout<<"3. Search for an item in your tree.\n";
  cout<<"4. Print the sum of the nodes. \n";
  cout << "5. Print the next element of the node with key x.\n";
  cout << "6. Print the elements between x and y.\n";
  cout << "7. Print the height of the tree with root x.\n";
  cout << "8. Print the sum of the list of elements between x and y. \n";
  cout << "9. Print out the tree in an in-order traversal. \n";
  cout << "10. Exit. \n";
  cin>> ans;
  return ans;
}



//Main function
int main() {
  Node *myRoot=NULL, *tempNode;
  int done = 0,ans=1, val, val2, q6data;
  ans = menu();
  while (ans<11) {
    if (ans == 1) {
      // Get value to insert.
      cout<<"What value would you like to insert?";
      cin>>val;
      tempNode = new Node(val); // Create the node.
      // Insert the value.
      myRoot = insert(myRoot, tempNode);
    }
    if (ans == 2) {
      cout<<"What value would you like to delete?\n";
      cin>>val;
      if (!find(myRoot, val))
        cout<<"Sorry that value isn't in the tree to delete.\n";
      else {
        myRoot = deleteNode(myRoot, val);
      }
    }
    if (ans == 3) {
      cout<<"What value would you like to search for?\n";
      cin>>val;
      if (find(myRoot, val))
        cout<<" Found"<<val<<"in the tree.\n";
      else
        cout<<" Did not find %d in the tree.\n";
    }
    if (ans == 4){
      cout<<"The sum of the nodes in your tree is"<<add(myRoot)<<"\n";
      }
    if (ans == 5){
      cout << "Enter a key to print the element after it:\n";
      cin>>val;
      cout << "The next element after", val, "is:";
        myRoot = Next(Node *N);
    }
    if (ans == 6){
      cout << "Provide a starting element:\n";
      cin>>val;
      cout << "Provide an ending element\n";
      cin>>val2;
      cout << "The values between starting point", val, " and ", val2, " are:";
      myRoot = findSearch(val, val2);
    }
    if (ans == 7){
      cout << "Provide a root x in order to get tree height: ";
      cin>>val;
      myRoot = computeHeight(val);
    }
    if (ans == 8){
      cout << "Provide a starting element:\n";
      cin>>val;
      cout << "Provide an ending element\n";
      cin>>val2;
      cout << "The sum of all elements between " ,val, " and ", val2, "is:";
      myRoot = sum(myRoot, val, val2);
    }
    if (ans == 9) {
      // Print the resulting tree.
      cout<<"Here is an inorder traversal of your tree: ";
      inorder(myRoot);
      cout<<"\n";
    }
    if (ans == 10)
      return;
    
    // See if they want to insert more nodes.
    ans = menu();
    cout << endl;
  }
  return 0;
}