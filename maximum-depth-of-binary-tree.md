#[leetcode]maximum-depth-of-binary-tree


##思路
1. 递归， 左子树和右子树的高度比较大的那一个加1，就得到树的最大高度
2. 第二种当时怎么写的我自己也弄不清楚了，也是递归。。。


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
	    int maxDepth(TreeNode *root) {
	        if(root!=nullptr){
	            int left_h = maxDepth(root->left); //左子树高度
	            int right_h = maxDepth(root->right); //右子树高度
	            int max_h = left_h>right_h?left_h:right_h;
	            return max_h+1;
	            //写成这样就会超时了，时间复杂度从 O(2^n) -> O(4^n)
	            //return maxDepth(root->left)>maxDepth(root->right)?maxDepth(root->left)+1:maxDepth(root->right)+1;
	        }else{
	            return 0;
	        }
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
	    Solution(){depth=0;lastDepth=0;}
	    int depth; //应该为private
	    int lastDepth; //应该为private
	    int maxDepth(TreeNode *root) {
	        if(root!=nullptr){
	            depth++; //到达新的节点，深度+1 
	            //dep当前层的深度，先保存一下，便于从左子树回来或者右子树回来的时候直接将depth置为dep
	            int dep=depth; 
	            
	            //遍历左子树，更新depth为往左子树走能达到的深度
	            maxDepth(root->left);
	            

	            //走到深度更深的位置，替换
	            if(depth>lastDepth){
	                lastDepth = depth;
	            }
	            
	            //如果从左子树回溯回来，要将depth-- ,回到depth
	            if(root->left){
	            	//这两句是一样的， 左子树回来的时候depth-1即可，但是右子树回来的时候就要利用到dep了。
	                depth--;
	                //depth = dep;
	            }
	            
	            //看右子树的深度
	            maxDepth(root->right);

	            //从右子树回来，depth回到当前层的深度
	            if(root->right){
	                depth = dep;
	            }
	      
	        }
	        return lastDepth;
	    }
	};