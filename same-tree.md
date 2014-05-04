#[leetcode]same-tree

比较tree是否相同

##思路
递归走起

---
###Solution 1

    /**
     * Definition for binary tree
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */
    class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            if(p!=nullptr&&q!=nullptr&&p->val==q->val){ //neither null
                //左右子树都相同
                if(isSameTree(p->left,q->left)&&isSameTree(p->right,q->right)){
                    return true;
                }
            }else if(p==nullptr&&q==nullptr){//both null
                return true;
            }else{
                return false;
            }
            
        }
    };