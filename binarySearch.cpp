#include <iostream>
#include <queue>

struct BstNode
{
  /* data */
  int data;
  BstNode* left;
  BstNode* right;
};

BstNode* createNode(int data);
BstNode* insert(BstNode* root, int data);
bool search(BstNode* root, int data);
BstNode* findMin(BstNode* root);
BstNode* findMax(BstNode* root);
int maxHeight(BstNode* root);
void levelOrderTraversal(BstNode* root);
void preOrder(BstNode* root);
void inOrder(BstNode* root);
void postOrder(BstNode* root);
bool isLesserTree(BstNode* root, int data);
bool isGreaterTree(BstNode* root, int data);
bool isBST(BstNode* root);
BstNode* deleteNode(BstNode* root, int data);

int main() {
  BstNode* root = nullptr;
  root = insert(root, 6);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 3);
  root = insert(root, 10);
  root = insert(root, 7);
  preOrder(root);  // 5 4 3 6 7 10
  std::cout << "\n";
  inOrder(root); // 3 4 5 6 7 10
  std::cout << "\n";
  root = deleteNode(root, 7);
  std::cout << "\n";
  inOrder(root); // 3 4 5 6  10
  // postOrder(root);
  // std::cout << "\n";

  // std::cout << isBST(root) << "\n";
  // std::cout << search(root, 7) << "\n";
  // std::cout << findMin(root) << "\n";
  // std::cout << findMax(root) << "\n";
  return 0;
}

BstNode* createNode(int data) {
  BstNode* newNode = new BstNode();
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

BstNode* insert(BstNode* root, int data) {
  if(root == NULL) {
    root = createNode(data);
    return root;
  }
  else if (root->data >= data) {
    // BstNode* temp = root;
    // BstNode* prev = NULL;
    // while (temp)
    // {
    //   // std::cout << "inside loop\n";
    //   /* code */
    //   if(temp->data > data) {
    //     prev = temp;
    //     temp = temp->left;
    //   }
    //   else {
    //     std::cout << "else---\n";
    //     prev = temp;
    //     std::cout << prev->right << "\n";
    //     temp = temp->right;
    //   }

    // }
    // if(prev->data > data) {
    //   std::cout << data << "\n";
    //   prev->left = createNode(data);
    // }
    // else {
    //   std::cout << data << "\n";
    //   prev->right = createNode(data);
    // }

    root->left = insert(root->left, data); // using recursion
    return root;
  }
  else  {
    BstNode* temp = root;
    // while (temp->right != NULL)
    // {
    //   /* code */
    //   temp = temp->right;
    //   if(temp->data >= data) {
    //     temp = temp->left;
    //   }
    //   else {
    //     temp = temp->right;
    //   }

    // }
    // temp->right = createNode(data);
    root->right = insert(root->right, data);
    return root;
  }
}

bool search(BstNode* root, int data) {
  if(root == NULL) {
    return false;
  }
  else if (root->data == data) {
    return true;
  }
  else if (root->data >= data) {
    return search(root->left, data);
  }
  else {
    return search(root->right, data);
  }
}

BstNode* findMin(BstNode* root) {
  if(root == NULL) {
    std::cout << "there are no element in the tree\n";
    return 0;
  }
  // BstNode* current = root;
  // while(root->left != NULL) { // because we pass in a copy we can use root
  //   root = root->left;
  // }
  if(root->left != NULL) {
    root = findMin(root->left);
  }
  return root;
}

BstNode* findMax(BstNode* root) {
  if(root == NULL) {
    std::cout << "there are no element in the tree\n";
    return 0;
  }
  // using iterative loops
  // while(root->right != NULL) { // because we pass in a copy we can use root
  //   root = root->right;
  // }

  // using recursions
  if(root->right != NULL) {
    root = findMax(root->right);
  }
  return root;
}

// int maxHeight(BstNode* root) {

// }

void preOrder(BstNode* root) {
  if(root == NULL) {
    return;
  }
  std::cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(BstNode* root) {
  if(root == NULL) {
    return;
  }
  inOrder(root->left);
  std::cout << root->data << " ";
  inOrder(root->right);
}

void postOrder(BstNode* root) {
  if(root == NULL) {
    return;
  }
  inOrder(root->left);
  inOrder(root->right);
  std::cout << root->data << " ";
}

bool isBST(BstNode* root) {
  if(root == NULL) {
    return true;
  }
  if(isLesserTree(root->left, root->data) && isGreaterTree(root->right, root->data) && isBST(root->left) && isBST(root->right)) {
    return true;
  }
  return false;
}

bool isGreaterTree(BstNode* root, int data) {
  if(root == NULL) {
    return true;
  }
  if(root->data > data && isGreaterTree(root->right, data) && isGreaterTree(root->left, data)) {
    return true;
  }
  return false;
}

bool isLesserTree(BstNode* root, int data) {
if(root == NULL) {
    return true;
  }
  if(root->data < data && isLesserTree(root->left, data) && isLesserTree(root->right, data)) {
    return true;
  }
  return false;
}

BstNode* deleteNode(BstNode* root, int data) {
  if(root == NULL) {
    return NULL;
  }
  else if(data > root->data) root->right = deleteNode(root->right, data);
  else if(data < root->data) root->left = deleteNode(root->left, data);
  else {
    if(root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
      
    }
    else if (root->left == NULL) {
      std::cout << "in left-----";
       BstNode* temp = root;
       root = root->right;
       delete temp;
    }
    else if(root->right == NULL) {
      BstNode* temp = root;
      root = root->left;
      delete temp;
    }
    else {
      BstNode* minNode = findMin(root->right);
      root->data = minNode->data;
      root->right = deleteNode(root->right, minNode->data);
    }
  }
    return root;
}