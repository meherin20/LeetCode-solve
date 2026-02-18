
class Solution {
public:
    unordered_map<int, int> pos;  // value -> index in inorder
    int postIndex;                // current index in postorder (moving backwards)

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inL, int inR) {
        if (inL > inR) return nullptr;  // no elements => empty subtree

        int rootVal = postorder[postIndex--];  // last unused postorder item is root
        TreeNode* root = new TreeNode(rootVal);

        int k = pos[rootVal];  // root index in inorder

        // Build right first because postorder is consumed from the end
        root->right = build(inorder, postorder, k + 1, inR);
        root->left  = build(inorder, postorder, inL, k - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pos.clear();
        for (int i = 0; i < (int)inorder.size(); i++) {
            pos[inorder[i]] = i;  // store inorder positions for O(1) lookup
        }

        postIndex = (int)postorder.size() - 1; // start from the last element
        return build(inorder, postorder, 0, (int)inorder.size() - 1);
    }
};
