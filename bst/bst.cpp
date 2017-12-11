#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

void printMin(struct node* root){
    if(root->left == NULL)
      cout << "Minimum " << root->data << '\n';

    if(root->left)
      printMin(root->left);
}

void printMax(struct node* root){
    if(root->right == NULL)
      cout << "Maximum " << root->data << '\n';

    if(root->right)
      printMax(root->right);
}

void find(struct node* root, int key){
  if(root->data == key && root){
    cout << "Found! YAASS" << "\n";
    return;
  }

  if(root){
    if(root->data > key){
      if(root->left == NULL){
        std::cout << "NOO :(" << '\n';
        return;
      }
      find(root->left, key);
    }
    if(root->data < key){
      if(root->right == NULL){
        std::cout << "NOO :(" << '\n';
        return;
      }
      find(root->right, key);
    }
  }
}
// Have to debug a little. Better Approach - return root of the transformed tree and then print the new inorder
// traversal vals.

/*
void FIS(struct node* root, int &s){
  if(root){
    FIS(root->left,s);
    if(root->left == NULL && root->right == NULL)
    {
      free(root);
      s = root->data;
      return;
    }
    FIS(root->right,s);
  }
}

void del(struct node* root, int key){
  int s;
  if((root->left == NULL && root->right == NULL) && root->data == key){
    free(root);
    return;
  }

  if((root->left != NULL && root->right == NULL) && root->data == key)
  {
    root->data = root->left->data;
    free(root->left);
    return;
  }

  else if((root->right != NULL && root->left == NULL) && root->data == key)
  {
    root->data = root->right->data;
    free(root->right);
    return;
  }

  else if((root->left != NULL && root->right != NULL) && root->data == key){
    FIS(root,s);
    root->data = s;
  }

  if(root){
    if(root->data > key){
      if(root->left == NULL){
        std::cout << "Not found!" << '\n';
        return;
      }
      del(root->left, key);
    }
    if(root->data < key){
      if(root->right == NULL){
        std::cout << "Not Found!" << '\n';
        return;
      }
      del(root->right, key);
    }
  }
}
*/

struct node* findMin(struct node* root){
  if(root->left == NULL){
    return root;
  }
  if(root->left){
    struct node* temp = findMin(root->left);
    return temp;
  }
}

struct node* findMax(struct node* root){
  if(root->right == NULL){
    return root;
  }
  if(root->right){
    struct node* temp = findMax(root->right);
    return temp;
  }
}

int findMinInt(struct node* root){
  if(root->left == NULL){
    return root->data;
  }
  if(root->left){
    int temp = findMinInt(root->left);
    return temp;
  }
}

int findMaxInt(struct node* root){
  if(root->right == NULL){
    return root->data;
  }
  if(root->right){
    int temp = findMaxInt(root->right);
    return temp;
  }
}

// Inorder Successor = minimum element in the right sub-tree.
struct node* del(struct node* root, int key){
  if(root == NULL) return root;

  else if(root->data > key)
    root->left = del(root->left, key);

  else if(root->data < key)
    root->right = del(root->right, key);


  else{
    struct node *temp;
    if(root->left == NULL){
      temp = root->right;
      free(root);
      return temp;
    }

    else if(root->right == NULL){
      temp = root->left;
      free(root);
      return temp;
    }

    temp = findMin(root->right);
    root->data = temp->data;
    root->right = del(root->right, temp->data);
  }
  return root;
}

struct node* LCArec(struct node* root, int n1, int n2){
  if(root->data > n1 && root->data > n2)
    return LCArec(root->left, n1, n2);

  if(root->data < n1 && root->data < n2)
    return LCArec(root->right, n1, n2);

  return root;
}

struct node* LCAnonrec(struct node* root, int n1, int n2){
  while(root != NULL){
    if(root->data > n1 && root->data > n2)
      root = root->left;

    if(root->data < n1 && root->data < n2)
      root = root->right;

    else break;
  }
  return root;
}

//M1
bool isBST(struct node* root){
  if(root == NULL)return true;
  if(root->left != NULL && findMaxInt(root->left) > root->data)return false;
  if(root->right != NULL && findMinInt(root->right) < root->data)return false;
  if(!isBST(root->left) || !isBST(root->right))return false;
  return true;
}

//M2 : inorder traversal then the list is sorted
/*
CODE
*/

//Divide and Conquer
struct node* append(struct node* a, struct node* b){
  if(a == NULL)return b;
  if(b == NULL)return a;

  struct node* La, Lb;

  La = a->left;
  Lb = b->left;

  La->right = b;
  b->left = La;

  Lb->right = a;
  a->left = Lb;

  return a;
}

struct node* BSTtoDll(struct node* root){
  struct node* llist, rlist;

  if(root == NULL)return NULL;

  llist = BSTtoDll(root->left);
  rlist = BSTtoDll(root->right);

  root->left = root;
  root->right = root;

  llist = append(llist, root);
  rlist = append(rlist, llist);

  return llist;
}

void DlltoBST(struct node* head){
  struct node *temp, *temp1;
  temp = head;
  temp = head->right;
}
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    int s;
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inoder traversal of the BST
    inorder(root);
    std::cout << '\n';
    // findMax(root);
    // find(root,80);
    // del(root,40);
    // inorder(root);
    // struct node* temp = LCArec(root,20,40);
    // struct node* temp1 = LCAnonrec(root,20,40);
    // std::cout << "LCA recursion: " << temp->data <<'\n';
    // std::cout << "LCA non recursion: " << temp1->data <<'\n';

    if(isBST(root))std::cout << " IT is a BST!" << '\n';
    return 0;
}
