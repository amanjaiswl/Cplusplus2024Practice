#include <iostream>
using namespace std;

class avlNode{
public:
int value;
avlNode *left, *right;
int height;
avlNode(int val) : value(val), left(nullptr), right(nullptr), height(1){}
};

class avlTree{
public:
avlTree() : root(nullptr){}

void insert(int value){
  root = insertToAvl(root, value);
}
void display(){
  preOrderTraversal(root);
  cout << endl;
}

private:
avlNode *root;

avlNode *insertToAvl(avlNode *node, int value){
  if(!node) return new avlNode(value);

  if(value< node->value)
    node->left = insertToAvl(node->left, value);

  else if(value > node->value)
    node->right = insertToAvl(node->right, value);

  else
    return node;

  updateHeight(node);

  return balanceNode(node, value);
}

avlNode *balanceNode(avlNode *node, int value){
  int balFact = getBalFact(node);


   // LL case
  if(balFact > 1 && value < node->left->value)
    return RR(node);

  // RR case
  if(balFact < -1 && value > node->right->value)
    return LR(node);

  // LR case
  if(balFact > 1 && value > node->left->value){
    node->left = LR(node->left);
    return RR(node);}

  // RL case
  if(balFact < -1 && value < node->right->value){
    node->right = RR(node->right);
    return LR(node);
}
  return node;
}

int getHeight(avlNode *node){
  if(!node) return 0;
  return node->height;
}

int getBalFact(avlNode *node){
  if(!node) return 0;
  return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(avlNode *node){
  node->height = max(getHeight(node->left), getHeight(node->right)) +1;
}

avlNode *RR(avlNode *node){
  avlNode *newRoot = node->left;
  avlNode *temp = newRoot->right;

  newRoot->right = node;
  node->left =temp;

  updateHeight(newRoot);
  updateHeight(node);

  return newRoot;
}

avlNode *LR(avlNode *node){
  avlNode *newRoot = node->right;
  avlNode *temp = newRoot->left;

  newRoot->left = node;
  node->right = temp;

  updateHeight(node);
  updateHeight(newRoot);

  return newRoot;
}

void preOrderTraversal(avlNode *node){
  if(node){
    cout << node->value << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
  }
}

};

int main(){
  avlTree avl;

  avl.insert(5);
  avl.insert(-5);
  avl.insert(50);
  avl.insert(-25);
  avl.insert(-15);
  avl.insert(90);

  cout << "preOrder traversal: " <<endl;
  avl.display();

  return 0;
}