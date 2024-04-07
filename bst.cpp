#include <iostream>
using namespace std;

class BST{
  private:
struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr){}
};
    Node * root;
    Node *insertIntoBST(Node *node, int val){
      if (node == nullptr)
        return new Node(val);
      if (val < node->data)
        node->left = insertIntoBST(node->left, val);
      
      if (val> node->data)
        node->right = insertIntoBST(node->right, val);
      
      return node;
    }

    bool searchBST(Node *node, int val){
      if(node == nullptr)
        return false;
      if(node->data == val)
        return true;
      else if(val < node->data)
        return searchBST(node->left, val);
      else
        return searchBST(node->right, val);
    }

    Node * deleteBST(Node *root, int val){
      if(root == nullptr)
        return root;
      if(val < root->data){
        root->left = deleteBST(root->left, val);
      }
      else if(val > root->data){
        root->right = deleteBST(root->right, val);
      }
      else{
        if(root->left == nullptr){
          Node *temp = root->right;
          delete root;
          return temp;
        }
        else if(root->right == nullptr){
          Node *temp = root->left;
          delete root;
          return temp;
        }
        Node *temp = root->right;
        while(temp->left != nullptr){
          temp = temp->left;
          
        }
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
        
      }
      return root;
      
      
    }

  public:
    BST(): root(nullptr){}
    void insert(int data){
      root = insertIntoBST(root,data);
    }

  bool search(int val){
    return searchBST(root, val);
  }

  void deleteNode(int val){
    root = deleteBST(root, val);
  }
};


int main(){
  BST bst;
  bst.insert(5);
  bst.insert(3);
  bst.insert(7);

  if(bst.search(5))
    cout << "Found" << endl;
  else
    cout << "Not Found" << endl;

  bst.deleteNode(5);
  if(bst.search(5))
    cout<< "Found" << endl;
  else
    cout << "Not Found" << endl;
}