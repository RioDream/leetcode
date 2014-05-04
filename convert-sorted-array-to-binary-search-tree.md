#[leetcode]convert-sorted-array-to-binary-search-tree

RT


##思路
a height balanced BST 
BST的中序遍历是一个sorted-array，再构造回去成一个BST,先将中间的元素作为根节点，这个节点的左右分别是左子树和右子树。如此递归地进行即可。

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
		 TreeNode *sortedArrayToBST(vector<int> &num) {
			 if (num.size() == 0){
				 return nullptr;
			 }
			 TreeNode* root = new TreeNode(0);
			 sortedArray2BST(num, root); //不被初始化的指针不能用来赋值，编译不通过
			 return root;
		 }

		 void sortedArray2BST(vector<int> &num, TreeNode* node){
			 //cout<<num.size()<<endl;

			 int mid = num.size() / 2;
			 int val = num[mid];
			 vector<int>::iterator it_begin = num.begin();
			 vector<int>::iterator it_end = num.end();
			 node->val = val;
			 //cout<<"val:"<<val<<endl;
			 if (mid > 0){ //防止切分之后的vec为空
				 vector<int> left_vec(it_begin, it_begin + mid); //attention the index
				 node->left = new TreeNode(0);
				 sortedArray2BST(left_vec, node->left);
			 }
			 if (mid != num.size() - 1){ //防止切分之后的vec为空
				 vector<int> right_vec(it_begin + mid+1, it_end); //attention the index
				 node->right = new TreeNode(0);
				 sortedArray2BST(right_vec, node->right);
			 }
		 }
	    
	    ~Solution(){
	        //delete the tree nodes
	    }
	 };