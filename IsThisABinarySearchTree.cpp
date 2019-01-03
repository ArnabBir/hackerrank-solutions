/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    bool checkBSTUtil(Node * node, int minVal, int maxVal) {
        
        if(node == NULL)    return true;
        if(node->data <= minVal || node->data >= maxVal)  return false;
        return checkBSTUtil(node->right, node->data, maxVal)
            && checkBSTUtil(node->left, minVal, node->data);
    }

	bool checkBST(Node* root) {
        
        return checkBSTUtil(root, 0, 10001);
	}
