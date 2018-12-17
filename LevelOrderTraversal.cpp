#include <bits/stdc++.h>

using namespace std;
	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {
        
        if(root == NULL)    return;
        queue<Node *> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            Node * curr = nodes.front();
            cout<<curr->data<<" ";
            nodes.pop();
            if(curr->left != NULL)  nodes.push(curr->left);
            if(curr->right != NULL)  nodes.push(curr->right);
        }
        cout<<endl;
    }

}; //End of Solution
