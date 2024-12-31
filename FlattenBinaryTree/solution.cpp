class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;  // nothing to flatten

        // track the last visited node during traversal
        TreeNode* prev = nullptr;

        // helper function to perform reverse post-order traversal
        std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;  // base case for recursion

            // process right subtree first
            dfs(node->right);

            // process left subtree
            dfs(node->left);

            // flatten the current node:
            // current node's right pointer -> 'prev' node (next in the linked list)
            node->right = prev;  // current node -> previous node, in the flattened structure
            node->left = nullptr; // set left to null, as required for the "linked list" format.

            // update 'prev' to be the current node
            prev = node;
        };

        // start DFS from the root
        dfs(root);
    }
};
