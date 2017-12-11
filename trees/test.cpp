#include <bits/stdc++.h>

using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left, *right;
};

/* Function protoypes */
void printGivenLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);

/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

vector<int> postorderTraversal(struct node *root)
{
    stack<struct node*> nodeStack;
    vector<int> result;
    //base case
    if(root==NULL)
        return result;
    nodeStack.push(root);
    while(!nodeStack.empty()) {
        struct node *node= nodeStack.top();
        result.push_back(node->data);
        nodeStack.pop();
        if(node->left)
            nodeStack.push(node->left);
        if(node->right)
            nodeStack.push(node->right);
    }
    reverse(result.begin(),result.end());
    return result;
}

vector<int> levelOrder(struct node *root){
  struct node *temp = root;
  vector<int> ans;
  queue<struct node*> q;
  q.push(root);
  while(!q.empty()){
    temp = q.front();
    q.pop();
    ans.push_back(temp->data);
    if(temp->left)
      q.push(temp->left);
    if(temp->right)
      q.push(temp->right);
  }
  return ans;
}

int findMax(struct node* root){
  struct node* temp = root;
  int a, b, c, maxa;

  if(temp == NULL)
    return 0;

  a = findMax(temp->left);
  b = temp->data;
  c = findMax(temp->right);

  maxa = a;
  if(b > maxa) maxa = b;
  if(c > maxa) maxa = c;
  return maxa;
}

void insert(struct node* root, int x){
  struct node *new_node = newNode(x), *temp;
  queue<struct node*> q;
  q.push(root);
  while(!q.empty()){
    temp = q.front();
    q.pop();
    if(temp->left != NULL)
      q.push(temp->left);
    else{
      temp->left = new_node;
      return;
    }

    if(temp->right != NULL)
      q.push(temp->right);

    else{
        temp->left = new_node;
        return;
      }
  }
}

int numberOfNodes(struct node* root){
  struct node* temp = root;
  if(temp == NULL)return 0;
  return numberOfNodes(temp->left) + numberOfNodes(temp->right) + 1;
}

int findHeight(struct node* root){
  struct node* temp = root;
  if(temp == NULL){
    return 0;
  }
  return 1 + max(findHeight(temp->left),findHeight(temp->right));
}

struct node* deepestNode(struct node* root){
  queue<struct node*> q;
  struct node* temp = root;
  q.push(root);
  while(!q.empty()){
    temp = q.front();
    q.pop();

    if(temp->left)q.push(temp->left);
    if(temp->right)q.push(temp->right);
  }
  return temp;
}
//using level order traversal
int findHeightNonRec(struct node* root){
  queue<struct node*> q;
  struct node* temp = root;
  int level = 0;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    temp = q.front();
    q.pop();

    if(temp == NULL){
      if(!q.empty())
        q.push(temp);
      level++;
    }

    else{
      if(temp->left)q.push(temp->left);
      if(temp->right)q.push(temp->right);
    }
  }
  return level;
}

//should be post-order
void deleteTree(struct node* root){
  if(root==NULL)return;
  deleteTree(root->left);
  deleteTree(root->right);
  free(root);
}

bool areIdentical(struct node* root, struct node* root1){
  if(root == NULL){
    if(root1 == NULL)
      return true;
    else
      return false;
  }
  if(root1 == NULL){
    if(root == NULL)
      return true;
    else
      return false;
  }

  if(root->data == root1->data){
    return (areIdentical(root->left,root1->left) && areIdentical(root->right,root1->right));
  }
  else{
    return false;
  }
}

int diameter(struct node* root){
  if(root == NULL)return 0;
  return max(findHeight(root->left) + findHeight(root->right) + 1, max(diameter(root->left),diameter(root->right)));
}

void printpath(vector<int> v){
  std::cout << "Path: ";
  for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';
}


//Pass By Value, the values in the vactor at that particular level of recursion are retained.
void rootToleaf(struct node* root, vector<int> v){
  // The function will never goto NULLA. So no need for this!!!
  // if(root==NULL)
  // {
  //   std::cout << "Yess I am in NULLaaaa :D XD" << '\n';
  //   return;
  // }

  v.push_back(root->data);

  if(root->left == NULL && root->right == NULL)printpath(v);
  else{
    rootToleaf(root->left, v);
    rootToleaf(root->right, v);
  }
}

struct node* findLCA(vector<struct node*> v1, vector<struct node*> v2){
  int i;
  for (i = 0; i < v1.size() && i < v2.size(); i++) {
    if(v1[i] != v2[i]){
      return v1[i-1];
    }
  }
}

void PathTill(struct node* root, vector<struct node*> v, struct node* node, vector<struct node*> &v1){
  if(root==NULL)return;

  v.push_back(root);

  if(root == node){
      v1 = v;
  }
  else{
    PathTill(root->left, v, node, v1);
    PathTill(root->right, v, node, v1);
  }
}

// Finding LCA one pass
bool hasNode(struct node* root, struct node* n)
{
  if(root == n)
    return true;

  if(hasNode(root->left, n) || hasNode(root->right, n))
    return true;

  else
  return false;
}

// My one pass method, Gotta debug
struct node* findLCAOnePass(struct node* root, struct node* n1, struct node* n2){
  struct node* temp;
  if((hasNode(root->left,n1) && hasNode(root->right,n2)))
    return root;
  else if(hasNode(root->left,n2) && hasNode(root->right,n1))
    return root;

  // debug these two conditions
  else if(hasNode(root->left,n2) && hasNode(root->left,n1)){
    temp = findLCAOnePass(root->left, n1, n2);
    return temp;
  }
  else if(hasNode(root->right,n2) && hasNode(root->right,n1)){
    temp = findLCAOnePass(root->right, n1, n2);
    return temp;
  }
}
 //Remember this, KM and GfG !!!!!!!
struct node* onePassLCA(struct node* root, struct node* n1, struct node* n2){
  if(root == NULL)return NULL;
  if(root == n1 || root == n2)return root;

  struct node* left = onePassLCA(root->left,n1,n2);
  struct node* right = onePassLCA(root->right,n1,n2);

  if(left && right)return root;

  return (left != NULL)?left:right;
}

vector<int> zigzag(struct node* root){
  vector<int> v;
  stack<struct node*> curr, nxt;
  int leftToRight = 1;
  struct node* temp;
  curr.push(root);
  while(!curr.empty()){
    temp = curr.top();
    curr.pop();

    if(temp){
      v.push_back(temp->data);
      if(leftToRight){
        nxt.push(temp->left);
        nxt.push(temp->right);
      }
      else{
        nxt.push(temp->right);
        nxt.push(temp->left);
      }
    }

    if(curr.empty()){
      leftToRight = 1 - leftToRight;
      swap(nxt, curr);
    }
  }
  return v;
}

void verticalSum(struct node* root, int vertLevel, map<int, int> &map){
  if(root == NULL) return;

  verticalSum(root->left, vertLevel - 1, map);
  map[vertLevel] += root->data;
  verticalSum(root->right, vertLevel + 1, map);
}
/* Driver program to test above functions*/
int main()
{
    // vector<struct node*> v1,v2,v;
    std::map<int, int> map;
    struct node *root = newNode(1), *deepest_node;
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    struct node *root1 = newNode(1);
    root1->left        = newNode(2);
    root1->right       = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);
    // insert(root1, 6);
    vector<int> v;
    // int maxa = findMax(root);
    // std::cout << "max: " << maxa <<'\n';
    // // insert(root, 6);
    // cout << "Level Order traversal of binary tree is" << '\n';
    // // // printLevelOrder(root);
    // v = levelOrder(root);
    // vector<int>::iterator it;
    // for(it = v.begin(); it!=v.end(); ++it){
    //   std::cout << *it << ' ';
    // }
    // std::cout << '\n';
    // std::cout << "numberOfNodes: " << numberOfNodes(root) << '\n';
    // std::cout << "height of the tree->left: " << findHeight(root1->left) << '\n';
    // std::cout << "height of the tree: " << findHeight(root) << '\n';
    // std::cout << "height of the tree->right: " << findHeight(root1->right) << '\n';
    // deepest_node = deepestNode(root);
    // std::cout << "deepestNode: " << deepest_node->data <<'\n';

    // std::cout << "Diameter of the tree: " << diameter(root1)<<'\n';
    // deleteTree(root);
    // std::cout << "numberOfNodes: " << numberOfNodes(root) << '\n';

    // rootToleaf(root, v);
    // std::cout << "Are trees identical?" << '\n';
    // (areIdentical(root,root1))?std::cout << "YESS!": std::cout << "NOOO";
    // PathTill(root, v, root->left->left, v1);
    // PathTill(root, v, root->left->right, v2);


    // struct node* lca = findLCAOnePass(root, root->left->left, root->left->right);
    // std::cout << "LCA is: " << lca->data << '\n';

    // v = zigzag(root);
    // printpath(v);

    // verticalSum(root, 0, map);
    // std::map<int, int>::iterator it;
    // for(it = map.begin(); it != map.end(); ++it){
    //   std::cout << (it->second) << ' ';
    // }


    return 0;
}
