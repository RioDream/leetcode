


#LeetCode  Summary (100)

##Single Number	
####1. 一堆对子里面找一个落单的
很经典的异或， 最后结果就是单数。

####2. 一堆对子里面找两个落单的

两个单数记为 x ，y

1. 先异或得到一个数字 z
2. 找到数字z的某一位为1， 说明两个单数这一位不同
3. 再次扫描， 按照这一位是0 还是 1，将所有数字分成两组
4. 两组分别异或得到x和y， 或者先异或一组得到 x，然后y=x^z

如何得到一个int的所有bit ? 将int不断往右移然后 &1，或者将1不断左移 & int


####3. 一堆n个相同的数里面找一个落单的
单数记为x

1. 将每个数字拆分成位
2. 统计每一位上的1有多少个
3. 最后，如果有的位数上1的个数不能被n整除，而是余1， 说明x的这一位是1。



##Maximum Depth of Binary Tree
####1. 递归左右子树，
   
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }

####2. 遍历
1.  DFS

		//level是父节点的level
	    void DFS(TreeNode* root,int level, int& maxLevel){
	        if(!root) return;
	        
	        //preorder
	        level++;
	        //现在，这个level就是root的level
	        
	        maxLevel = max(level, maxLevel);
	        
	        DFS(root->left,level,maxLevel);
	        DFS(root->right,level,maxLevel);
	    }
2. BFS 同样可以

		//to do


##Same Tree

递归

	    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p && q){
            if(p->val!=q->val){
                return false;
            }else{
                return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
            }
        }else{
            if(p==q) return true;
            else return false;
        }
    }



##Reverse Integer	
反转整数，基本思想是如何获得整数的每一位。
比较好的做法是， 将x不断右移 (/10)，移出来的数(%10)放到,y的末尾（+），然后y左移(*10)。

    int reverse(int x) {
        int y = 0;
        int r;
        while(x){
            r=x%10;
            y = y*10+r;
            x = x/10;
        }
        return y;
        
    }



##Best Time to Buy and Sell Stock II
贪心？

//to do
	

##Unique Binary Search Trees
可以构成多少BST

1. 递归

	    int numTrees(int n) {
	        //exit
	        if(n==0) return 1;
	        
	        int num =0;
	        for(int i=1;i<=n;i++){
	            num += (numTrees(i-1)*numTrees(n-i));
	        }
	        return num;
    	}
    	
2. DP
		//to do
		//递推公式？

		

	
##Linked List Cycle	

查找是否有回路

一般思路： 用一个 Hash 记录走过的Node的地址，但是这里要求不用额外空间。
更改链表的值来做标记，会破坏数据。

1. 自我指向法， 也会破坏结构
2. 快慢指针法
	walker和runner一定会相遇。


##Binary Tree Preorder Traversal
1. 递归
2. 通用迭代
3. 常见迭代


##Binary Tree Inorder Traversal
1. 递归
2. 通用迭代
3. 常见迭代
	
##Search Insert Position	
1. 暴力 线性遍历， 能 Accepted
2.  二分查找

	    int searchInsert(int A[], int n, int target) {
	        //二分查找 迭代版本
	        int left=0;
	        int right = n-1;
	        int mid=-1;
	        bool gotCha = false;
	        
	        while(left<=right){
	            mid = (left+right)/2;
	            if(A[mid]>target){
	                right = mid-1;
	            }else if(A[mid]<target){
	                left = mid+1;
	            }else{
	                gotCha = true;
	                break;
	            }
	        }
	        
	        int idx = -1;
	        
	        if(gotCha){
	            idx = mid;
	        }else{
	            /*证明：
            	Loop Invariant:
                	min(left,right) <= target <= max(left,right)
                
                	一般情况下都是 left<=target<=right，最后跳出的时候 left>right，而且， left=right+1， target依然在这个范围内， 应该取其右边的界作为插入点。 
                	要证明left=right+1 ， 就必须证明倒数第二步 left==right, 这可以用折半查找的原理解释，每一次查找范围都是原来的一半范围越来越小，最后就变成1了。
            	*/
	           idx = left;
	        }
	        return idx;
    	}



##Populating Next Right Pointers in Each Node
BFS
遍历的时候要使用两个queue， 有点 swap buffer 的感觉。

##Remove Duplicates from Sorted List
遍历即可

##Roman to Integer


##Climbing Stairs
很典型的DP问题
1. 比较普通的是使用一个矩阵的空间
2. 可以使用一个数组，逐行移动

##Single Number II	
同 Single Number I

##Maximum Subarray	
最大子串问题 DP

如果直接作为DP问题来求解， 有两个自由度，分别是 子串的 起始位置和结束位置。

可以这样转化成问题（记为问题Q）：
求解，结束位置固定在最后一个元素的最大子串和。 满足最优子结构和子问题重叠的性质？

用一个数组 dp[i]表示结束位置是i的子串的最大和。
于是有递推公式：

	dp[i+1] = max(dp[i]+A[i],A[i])

这里面一定包含有A的最大子串和。

可以看到Q问题是P问题的一个特例，而其求解过程则是一个总的问题的分解。 比如世界杯吧， 谁是冠军就是问题P， 小组赛谁出线就相当于Q， 最后P的解一定在Q的解中寻找。



##Integer to Roman	
//todo

##Remove Element	
原地删除数组中所有的某一个value。
两个指针， 一个指向遍历的位置， 一个指向下一个节点要插入的位置。

##Merge Two Sorted Lists	
原地合并两个list（原地的意思就是不能新建 listNode）

##N-Queens II	
回溯法的经典应用
//todo

##Balanced Binary Tree	
判断一个 tree是不是balance 的

两个递归函数：
1. getHeight()
	用来得到两边的高度
2. isBalanced() 
	用来判断是不是balance


##Swap Nodes in Pairs	
链表， 两两交换
//todo

##Convert Sorted Array to Binary Search Tree
递归
//todo

##Remove Duplicates from Sorted Array
原地的， 使用两个指针
一个指针指向遍历到的元素， 另一个指针指向下一次要插入的位置。
	
##Merge Sorted Array	
将数组B merge到数组A中。
1. 暴力插入， A中元素往后挪
2. 额外一个数组， 插入之后每个元素的位置，最后一次性插入
//todo

##Symmetric Tree	
递归， 两个递归函数
1. mirror() 将一个 tree进行镜像
2. isSame() 判断是不是一样

##Pascal's Triangle

##Gray Code	

##Sort Colors	
已知一个数组只有  0 1 2， 排序，要求 one-pass 同时 使用 constant space。
首先可以肯定的是，需要四个指针，k0 k1 k2指向下一个要插入0 1 2的位置， i指向当前遍历到的元素， 具体有两种方法。
1. one-pass，但是不是constant-space
	新建一个大小为n的数组， k1 k2先指向头， 将k3指向尾
	如果来 0， k0++， 同时k1++, （在增加k0 k1之前，将其指向的位置置为0 1）， 相当于先插入k1处，然后交换
	如果来 1， 直接加入k1处, k1++
	如果来 2， 直接加入k2处，k2--
	
2. one-pass constant-space
	constant-space , 也就是说要在数组A的原地开搞。
	将k0 k1 k2都指向0
	如果来0， 直接和k0处的元素进行交换， 同时，为了防出现 120->021的状况，还要检测交换过来的是什么， 如果是1， 就要和k1处的元素再交换一次。 k0++ k1++ k2++
	如果来1， 直接和k1处的元素进行交换 k1++ k2++
	如果来2， 和k2处的元素进行交换 k2++
	
	如果来0， 放到k0处， 如果k1==k0 说明还没有1被覆盖， k1 k2 直接往后挪就好，不用干啥；否则， 就应该将k1处置为1，同时检查是否k1==k2,做类似操作
	如果来1， 放到k1处，检查是否有k1==k2
	如果来2 直接放到k2处 （按理说，在0 1 2 都出现了的情况下，k2应该和i指向同一个位置，所以可以省去一个指针，这种想法是错误的，因为刚开始的时候 0 1 2并没有都出现）
	
		void sortColors(int A[], int n) {
	        //int* temp = new int[n];
	        int k0=0;
	        int k1=0;
	        int k2=0;
	        for(int i=0;i<n;i++){
	            if(A[i]==0){
	                A[k0]=0;
	                
	                if(k0!=k1){ //说明刚才 A[k0]=0 占掉了一个1
	                    A[k1]=1;
	                }
	                if(k1!=k2){ 
	                    //说明刚才 被A[k0]==0 或者 A[k1]=1 占掉了一个2
	                    //如果刚才是 k0==k1, 说明没有1呢， 被A[k0]=0占了
	                    //如果刚才是 k0!=k1, 说明有1， 一定是被 A[k1]=1占了
	                    A[k2]=2;
	                }
	                
	                k0++;
	                k1++;
	                k2++;
	                
	            }else if(A[i]==1){
	                A[k1]=1;
	                if(k1!=k2){
	                    A[k2]=2;
	                }
	                k1++;
	                k2++;
	            }else{
	                A[k2]=2;
	                k2++;
	            }
	        }
	    }


##Plus One
将一个字符串加1。
1. 最先想到的是做类型转换： 先将 string转换成int，加1，再将int转换为string。 但是这种方法的速度慢，而且最重要的是会溢出
2. 直接利用加法的原理  从后向前，找到一个不是9的，加1，就得到了和， 注意 “9999” 这种情况

##Generate Parentheses	
基本思路是使用回溯法，决定要出栈还是入栈。 
比如《数据结构》里面有一道题，123这几个数，在不同的出栈入栈次序下，有几种输出：
入栈用#表示 出栈用~表示
1#1~2#2~3#3~ =>123
1#2#2~1~3#3~ =>213
1#2#2~3#3~1~ =>231
1#2#3#3~2~1~ =>321

其实是有一些约束的排列组合问题。


//todo

##Rotate Image	
细心
//todo

##Best Time to Buy and Sell Stock
//todo

##Binary Tree Level Order Traversal II
BFS但是要求从最后一个level开始输出，从左往右， 目前有两种思路
1. 使用 swap buffer技术（呵呵），将新得到的level的queue insert到 output vector的头部
2. 使用 stack， 像往常一样添加进去， 不过要先push该level最右边节点的右孩子，然后左孩子。
//todo


#Unique Paths	
经典的DP问题
递推公式：

	pathNum[i][j] = pathNum[i-1][j]+pathNum[i][j-1];
		
1. 直接方法， 需要m*n的矩阵空间
2. 使用一个数组

##Binary Tree Postorder Traversal
//todo
	
##Permutations
1. 递归
2. 迭代
	比如所有的 i-1个元素得到的 permutation， 在每一个permutation的每一个可以插入的位置插入第i个元素，就得到了 i个元素的permutation

##Minimum Path Sum	
简单版的最短路问题， 限制只能左上到右下, 很类似于机器人走路的那个 Unique Paths
递推公式：
	
	minSum[i][j] = min(minSum[i-1][j],minSum[i][j-1])+A[i][j]

####扩展：

《待字闺中》收集苹果

1. 从左上到右下，如何拿到最多苹果
和之前一样，简单DP

2. 从左上到右下，再返回左上，如何拿到最多苹果
//todo

3. 两次从左上到右下， 如何拿到最多苹果
	三维DP
	比如 dp[4，1，2] 表示走了四步， 目前在第一行， 可能由如下几种转换而来
		dp[3,0,1]
		dp[3,0,2]
		dp[3,1,1]
		dp[3,1,2]
		
		递推公式：
		dp[n][i][j] 代表走了n步，第一次走的在第i行（开始在第0行），说明往下走了 i 步， 往右走了n-i步，第一次现在在 A[i][n-i]处， 同理，第二次在 A[j][n-j]处。
		dp[n][i][j] =  max(①dp[n-1][i-1][j-1],
							②dp[n-1][i-1][j],
							③dp[n-1][i][j-1],
							④dp[n-1][i][j])
						+ 
						A[i][n-i]
						+
						A[j][n-j];
		
					


##Search a 2D Matrix
搜索一个从左到右 从上到下都已经排序好的2d matrix
1. 可以先将matrix按行展开， 然后再使用普通的二分查找
2. 先在第一列进行二分查找，而后在找到的行中进行二分查找
	
		具体讨论参看 Insert Position 问题


##Container With Most Water	
##Linked List Cycle II	
##Binary Tree Level Order Traversal	
##Set Matrix Zeroes	
##Spiral Matrix II	
##Search in Rotated Sorted Array II	
##Remove Duplicates from Sorted Array II	
##Pascal's Triangle II	
##Path Sum	
##Populating Next Right Pointers in Each Node II	
##Combinations	
##Remove Nth Node From End of List	
##Sum Root to Leaf Numbers	
##Palindrome Number	
##Minimum Depth of Binary Tree	
##Length of Last Word	
##Search in Rotated Sorted Array	
##Trapping Rain Water	
##Valid Parentheses	
##Unique Paths II	
##Valid Sudoku	
##Longest Consecutive Sequence	
##Flatten Binary Tree to Linked List	
##Subsets	
##Path Sum II	
##Jump Game	
##Longest Common Prefix	
##Search for a Range	
##3Sum Closest	
##Convert Sorted List to Binary Search Tree	
##Unique Binary Search Trees II	
##Count and Say	
##Triangle	
##Subsets II	
##Binary Tree Zigzag Level Order Traversal	
##Partition List	
##Combination Sum	
##Construct Binary Tree from Inorder and Postorder Traversal	
##Letter Combinations of a Phone Number	
##Pow(x, n)	
##Construct Binary Tree from Preorder and Inorder Traversal	
##Reverse Linked List II	
##Palindrome Partitioning	
##Add Binary	
##N-Queens	
##Validate Binary Search Tree	
##Next Permutation	
##Edit Distance	
##Reverse Nodes in k-Group	
##Insertion Sort List	
##Remove Duplicates from Sorted List II	
##Gas Station	
##Permutations II	
##Distinct Subsequences	
##Combination Sum II	
##Jump Game II	
##ZigZag Conversion	
##Anagrams	
##Recover Binary Search Tree	
##Copy List with Random Pointer	
##Add Two Numbers	
##Valid Palindrome	
##Merge k Sorted Lists	
##Clone Graph	
##First Missing Positive	
##Scramble String	
##Best Time to Buy and Sell Stock III	
##Longest Substring Without Repeating Characters	
##Sqrt(x)	
##Rotate List	
##Maximal Rectangle	
##Permutation Sequence	
##Implement strStr()	
##4Sum	
##Largest Rectangle in Histogram	
##Sudoku Solver	
##Longest Palindromic Substring	
##Word Break	
##Merge Intervals	
##Spiral Matrix	
##Multiply Strings	
##Restore IP Addresses	
##Sort List	
##Insert Interval	
##Reorder List	
##Regular Expression Matching	
##Evaluate Reverse Polish Notation	
##Binary Tree Maximum Path Sum	
##Simplify Path	
##Word Search	
##Longest Valid Parentheses	
##Interleaving String	
##Candy	
##Two Sum	
##Palindrome Partitioning II	
##Minimum Window Substring	
##Substring with Concatenation of All Words	
##Word Ladder	
##Median of Two Sorted Arrays	
##3Sum	
##Divide Two Integers	
##Word Break II	
##Decode Ways	
##String to Integer (atoi)	
##Text Justification	
##Reverse Words in a String	
##Surrounded Regions	
##LRU Cache	
##Wildcard Matching	
##Word Ladder II	
##Valid Number	
##Max Points on a Line	
