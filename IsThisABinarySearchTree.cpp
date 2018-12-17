/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

    bool isBST(Node * node, int maxLeft, int minRight) {
        
        if(node == NULL) {
            return true;
        }
        if(node->data <= maxLeft || node->data >= minRight) {
            return false;
        }
        return isBST(node->left, maxLeft, node->data) 
            && isBST(node->right, node->data, minRight);
    }

	bool checkBST(Node* root) {
        
		return isBST(root, -1, 100001);
	}
