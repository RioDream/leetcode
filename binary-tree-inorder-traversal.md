#[leetcode]binary-tree-inorder-traversal

##思路
1. 递归
2. 非递归-回溯

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
	    vector<int> outputVec;
	    vector<int> inorderTraversal(TreeNode *root) {
	        if(root!=nullptr){
	            inorderTraversal(root->left);
	            outputVec.push_back(root->val);
	            inorderTraversal(root->right);
	        }
	        return outputVec;
	    }
	};

---
###Solution 2

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
	    vector<int> inorderTraversal(TreeNode *root) {
	          vector<int> output;
	        if(!root){
	            return output;
	        }
	        
	        vector<TreeNode*> s;
	        s.push_back(root);
	        TreeNode* currNode;
	        TreeNode* lastPopedNode;
	        while(!s.empty()){
	            currNode = s.back();
	            //leaf node, just pop
	            if(!currNode->left && !currNode->right){
	                //output.push_back(currNode->val);//post
	                output.push_back(currNode->val);//mid
	                //output.push_back(currNode->val);//pre
	                lastPopedNode = s.back();
	                s.pop_back();
	                continue;
	            }
	            
	            //from left. check right
	            if(lastPopedNode == currNode->left){
	                output.push_back(currNode->val);//mid
	                if(currNode->right){
	                    s.push_back(currNode->right);
	                }else{
	                    //output.push_back(currNode->val);//post
	                    lastPopedNode = s.back();
	                    s.pop_back();
	                }
	                continue;
	            }
	            
	            //from right, just pop
	            if(lastPopedNode == currNode->right){
	                //output.push_back(currNode->val);//post
	                lastPopedNode = s.back();
	                s.pop_back();
	                continue;
	            }
	            
	            //this node is pushed into stack just now 
	            if(currNode->left){
	                //output.push_back(currNode->val);//pre
	                s.push_back(currNode->left);
	                continue;
	            }
	            
	            //no left , but has right
	            if(currNode->right){
	                //output.push_back(currNode->val);//pre
	                output.push_back(currNode->val);//mid
	                s.push_back(currNode->right);
	                continue;
	            }
	            
	        }
	    }
	};