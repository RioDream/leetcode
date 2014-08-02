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

如何得到一个int的所有bit ? 将int不断往右移然后 &1，或者将1不断左移 & 这个int


####3. 一堆n个相同的数里面找一个落单的
单数记为x

1. 将每个数字拆分成位
2. 统计每一位上的1有多少个
3. 最后，如果有的位数上1的个数不能被n整除，而是余1， 说明x的这一位是1。



##Maximum Depth of Binary Tree

####1. 直接递归
1. 递归左右子树，
   
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
    walker和runner一定会相遇。一旦相遇就 return true


##Binary Tree Preorder Traversal
1. 递归

		class Solution {
		public:
		    vector<int> preorderTraversal(TreeNode *root) {
		        if(!root) return output;
		        
		        output.push_back(root->val);
		        
		        preorderTraversal(root->left);
		        preorderTraversal(root->right);
		        
		        //别忘记这一句
		        return output;
		        
		    }

		private:
		    //这里类内成员的作用和在递归函数中搞一个 传址 类型的参数是一样的。
		    vector<int> output;
		};

2. 通用迭代

		class Solution {
		public:
		    vector<int> preorderTraversal(TreeNode *root) {

		        vector<int> output;
		        if(!root){
		            return output;
		        }
		        
		        /*
		        path的push就代表前进
		        path的pop就代表回退
		        */
		        stack<TreeNode*> path;
		        
		        path.push(root);
		        
		        TreeNode* curNode;
		        TreeNode* lastPopedNode;
		        
		        while(!path.empty()){
		            curNode = path.top();
		            
		            //#1 如果是一个叶子节点，必须要pop
		            if(!curNode->left && !curNode->right){
		                output.push_back(curNode->val);
		                lastPopedNode = path.top();
		                path.pop();
		                continue;
		            }
		            
		            /*
		            #2 如果是从左边回溯回来的，就要在回退的过程中看看右边有没有路
		            1. 右边有路
		                往右走
		            2. 右边没有路
		                继续回退
		            */
		            
		            if(lastPopedNode == curNode->left){
		                if(curNode->right){
		                    path.push(curNode->right);
		                }else{
		                    lastPopedNode = path.top();
		                    path.pop();
		                }
		                continue;
		            }
		            
		            //#3 如果从右边回退回来的， 直接继续回退
		            if(lastPopedNode == curNode->right){
		                lastPopedNode = path.top();
		                path.pop();
		                continue;
		            }
		            
		            
		            //***运行到这里,说明不是回退阶段，要继续探路***
		            
		            //#4 如果左边有路， 直接往里走, 同时将当前节点输出
		            if(curNode->left){
		                output.push_back(curNode->val);
		                path.push(curNode->left);
		                continue;
		            }
		            
		            //运行到这里，说明左边没有路
		            //#5 如果右边有路，继续往右走
		            if(curNode->right){
		                output.push_back(curNode->val);
		                path.push(curNode->right);
		                continue;
		            }
		            
		            // {1,2,3} 分别在 #4 #1 #1 中输出
		            // {1,2,3,4,#,#,5} 1 2 4 3 5 分别在 #4 #4 #1 #5 # # #1 中输出
		            
		        }//while
		        
		    }//function
		        
		};

3. 常见迭代


##Binary Tree Inorder Traversal
1. 递归
	
	参考 Preorder

2. 通用迭代
3. 常见迭代
    
##Search Insert Position    
1.  暴力 线性遍历， 能 Accepted

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
每一个node都多了一个 right 域， 任务就是给这个域赋值。

BFS

遍历的时候要使用两个queue， 有点 swap buffer 的感觉。

##Remove Duplicates from Sorted List
遍历即可，遇到相同的无视即可。

##Roman to Integer


##Climbing Stairs

其实就是一个斐波那契数的问题， 显然使用一维DP要比直接递归好， 直接递归是不行的会 TLE.

具体又能够分成两种

1. 	自底向上法

		class Solution {
		public:
		    int climbStairs(int n) {
		        //dp 递推公式 dp[i] = dp[i-1] + dp[i-2];
		        int* dp = new int[n+1];
		        dp[0] = 1; //注意这里是1， 不是0， 要保证 dp[2]=2
		        dp[1] = 1;
		        for(int i=2;i<=n;i++){
		            dp[i] = dp[i-1] + dp[i-2];
		        }
		        return dp[n];
		        
		    }
		};

2. 	自顶向下，带备忘机制的递归法

		class Solution {
		public:
		    //使用一个map去记录，避免重复计算
		    int climbStairs(int n) {

		        
		        if(n<0){
		            return 0;
		        }else if(n==0){
		            return 1;
		        }else if(map.size()>n && map[n]!=-1){ //the result already exists
		            return map[n];
		        }else{
		            map.resize(n+1,-1);
		            map[n] = climbStairs(n-1)+climbStairs(n-2); //last step is 1 or 2
		            return map[n];
		        }
		    }

		private:
		    vector<int> map;
		};


##Single Number II    
见 Single Number I

##Maximum Subarray    
最大子串问题 DP

如果直接作为DP问题来求解， 有两个自由度，分别是 子串的 起始位置和结束位置。

可以这样转化成问题（记为问题Q）：
求解，结束位置固定在最后一个元素的最大子串和。 满足最优子结构和子问题重叠的性质？

用一个数组 until[i]表示结束位置是i的子串的最大和。
于是有递推公式：

    until[i+1] = max(until[i]+A[i],A[i])

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
//todo
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
这一题有很详细的分析，在segmentFault 博客上。
//todo

##Linked List Cycle II 
1. 先一个runner，一个walker， 二者相遇的时候， runner步walker多跑了n步， 这个n应该是cycle的长度的整数倍。
证明： 二者相遇的时候， runner一定是套了walker几圈了，不一定是一圈。
2. 如果重新让一个 runner跑n步（一次一步），然后walker才开始跑， 那么最后相遇的时候，一定是在cycle的第一个node。
证明： 因为walker在开始处的时候，runner一定也在开始处， 所以cycle的开始处是一个相遇点。而且在这个点之前不可能相遇，所以这是第一个相遇点，证毕。

另外有种更好理解的方法,需要三步：
[三步法](http://blog.csdn.net/whuwangyi/article/details/14103993)

##Binary Tree Level Order Traversal
BFS
    
##Set Matrix Zeroes    
将Matrix中为0的元素所在的行和列都置为0.
关键是不要在第一次遍历的时候就开始置0， 那样会导致整个Matrix都变成0.


##Spiral Matrix II    
//todo


##Search in Rotated Sorted Array II
//todo

##Remove Duplicates from Sorted Array II
问题1的变种， 每个元素不再只能出现一次， 而是最多可以有两个。

1. 版本1

	    int removeDuplicates(int A[], int n) {
	        const int MAX_DUP = 2;
	        int insertPtr = 0;
	        int lastElem = A[0];
	        int elemCounter = 1; //lastElem已经出现的次数
	        
	        if(n==0) return 0;
	        if(n==1) return 1;
	        
	        for(int i=1;i<n;i++){
	            
	            //lastElem已经出现的次数
	            if(elemCounter<=2){
	                A[insertPtr++] = lastElem;
	            }
	                
	            if(A[i]!=lastElem){
	                elemCounter = 1; //counter==1， 下次循环就 insert
	            }else{
	                elemCounter++; //
	            }
	            
	            lastElem = A[i];
	        }
	        
	         //lastElem已经出现的次数,别忘记最后这个！
	        if(elemCounter<=2){
	            A[insertPtr++] = lastElem;
	        }
	            
	        return insertPtr;
	    }
	    
2. 版本2
//todo

		int removeDuplicates(int A[], int n) {
	        int sameCount = 0;
	        const int MAX_DUP = 2;
	
	        int new_len = 0;
	        int last = A[0]-1;
	        for(int i=0;i<n;i++){
	            int temp = A[i];
				
				//
	            if(temp!=last){
	                A[new_len++] = temp;
	                if(i+1<n&&A[i+1]==temp){
	                    A[new_len++] = temp;
	                    i++;
	                }
	        
	            }
	            last = temp;
	        }
	        return new_len;
	    }
 
   
##Pascal's Triangle II    

##Path Sum    
Binary Tree
DFS和BFS都可以


##Populating Next Right Pointers in Each Node II  


  
##Combinations    

##Remove Nth Node From End of List    


##Sum Root to Leaf Numbers    

基本思路使用DFS

1. 版本1：

		class Solution {
		public:
		    Solution(){
		        sumOfPath =0;
		    }
		    
		    int sumNumbers(TreeNode *root) {
		        stack<int> path;
		        detectAndRember(root,path);
		        return sumOfPath;
		    }
		    
		    void detectAndRember(TreeNode* root, stack<int> path){
		        if(!root) return; //not a leaf
		        
		        path.push(root->val);
		        if(!root->left && !root->right){ //leaf
		            sumOfPath += getStackSum(path);
		            return;
		        }
		        
		        
		        detectAndRember(root->left,path);
		        detectAndRember(root->right,path);
		    }
		    
		    int getStackSum(stack<int> s){
		        int base = 1;
		        int sum =0;
		        while(!s.empty()){
		            int v = s.top();
		            s.pop();
		            sum += v*base;
		            base *= 10;
		        }
		        return sum;
		    }
		
		private:
		    int sumOfPath;
		    
		};
	
2. 版本2

		class Solution {
		public:
		    int sumNumbers(TreeNode *root) {
		        int sum = 0;
		        DFS(root,0,sum);
		        return sum;
		    }
		    
		private:
		    //pathSum表示在到达root这个node之前的path上的sum
		    void DFS(TreeNode* root, int pathSum ,int& sum){
		        if(!root){
		            //sum += pathSum; 不该在这里+
		            return;
		        }
		        
		        int val = root->val;
		        pathSum *= 10;
		        pathSum += val;
		        
		        //在leaf节点处 加到sum
		        if(!root->left && !root->right){
		            sum += pathSum;
		            return;
		        }
		        
		        DFS(root->left,pathSum,sum);
		        DFS(root->right,pathSum,sum);
		        
		    }
		
		};

##Palindrome Number   
检测一个int型的整数， 是不是回文。

 
##Minimum Depth of Binary Tree   

1. DFS

		class Solution {
		public:
		    int minDepth(TreeNode *root) {
		        if(!root) return 0;
		        
		        int minDepth = INT_MAX;
		        
		        DFS(root,1,minDepth);
		        return minDepth;
		    }
		    
		private:
		    void DFS(TreeNode* root, int level, int& minDepth){
		        if(!root) return; //比如 a->left = b a->right=NULL ， a不是一个leaf， b是， DFS(a->right)的过程中会在这里return
		        
		        
		        //这里相当于DFS的visit()函数，功能是判断是否是叶子节点，更新最小深度
		        if(!root->left && !root->right){ 
		            minDepth = min(minDepth,level);
		            return;
		        }
		        
		        DFS(root->left,level+1,minDepth);
		        DFS(root->right,level+1,minDepth);
		        
		    }
		
		};
		
2. BFS

		//todo
		
		
 
##Length of Last Word
##Search in Rotated Sorted Array    
##Trapping Rain Water    
##Valid Parentheses 
使用栈


##Unique Paths II    
##Valid Sudoku    

##Longest Consecutive Sequence    


##Flatten Binary Tree to Linked List    
思路：

子问题： 将左子树塞到右子树中。 有点像在链表中插入节点，关键点就是保存现场， 而且最容易忘记的就是将root的左子树的先序遍历的最后一个节点的右子树置为root的右子树。 

1. 使用一个类内的私有成员 lastNodeOfLeft 来记录左子树的先序遍历的最后一个元素

		class Solution {
		public:
		    //子问题：将左子树塞到右边
		    void flatten(TreeNode *root) {
		        if(!root) return;
		        
		        //先序遍历，每次都记录， 退出的时候就是最后一个
		        lastNodeOfLeft = root;
		        
		        TreeNode* rightChild = root->right;
		        
		        //左子树为空的时候不能处理， 否则会让 root->right = nullptr; 让链中断
		        if(root->left){
		            root->right = root->left;
		            //递归处理左子树
		            flatten(root->left);
		            //令左子树的最后一个元素指向右节点
		            lastNodeOfLeft->right = rightChild;
		            //左子树要置为0
		            root->left=nullptr;
		        }
		        
		        //不需要判断 rightChild是否为空
		        flatten(rightChild);
		        
		        
		    }
		private:
		    //左子树的最后一个元素，其实是最右边一个元素吧。
		    TreeNode* lastNodeOfLeft;
		};

2. 不使用私有成员， 直接找到左子树的最右节点， 这个最右节点就是先序遍历左子树的最后一个元素。

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
		    //子问题：将左子树塞到右边
		    void flatten(TreeNode *root) {
		        if(!root) return;
		        
		        
		        lastNodeOfLeft = root;
		        
		        TreeNode* rightChild = root->right;
		        
		        //左子树为空的时候不能处理， 否则会让 root->right = nullptr; 让链中断
		        if(root->left){
		            root->right = root->left;
		            //递归处理左子树
		            flatten(root->left);
		            
		            //n用来找到左子树的最右节点， 这个最右节点就是先序遍历左子树的最后一个节点。
		            TreeNode* n = root->left;
		            while(n->right){
		                n = n->right;
		            }
		            
		            //令左子树的最后一个元素指向右节点
		            n->right = rightChild;
		            //左子树要置为0
		            root->left=nullptr;
		        }
		        
		        //不需要判断 rightChild是否为空
		        flatten(rightChild);
		        
		        
		    }
		
		};
		
3. 使用一个引用参数代替私有成员
	
		class Solution {
		public:
		    //子问题：将左子树塞到右边
		    void flatten(TreeNode *root) {
		        TreeNode* lastNodeOfLeft;
		        flat(root,lastNodeOfLeft);
		    }
		    
		    void flat(TreeNode* root, TreeNode*& lastNodeOfLeft){
		        if(!root) return;
		        
		        lastNodeOfLeft = root;
		        
		        if(root->left){
		            flat(root->left,lastNodeOfLeft);
		            lastNodeOfLeft->right = root->right;
		            root->right = root->left;
		            root->left=nullptr;
		        }
		        
		        flat(root->right,lastNodeOfLeft);
		    }
		
		};

4. 迭代的方法， NB

	[迭代法的解释](http://blog.csdn.net/sbitswc/article/details/26540269)
	
	
		void flatten(TreeNode *root) {  
	        if(root == NULL) return;  
	        while(root){  
	        	//
	            if(root->left){  
	            	//左子树的最右节点（先序遍历的最后一个）
	                TreeNode *pre = root->left;  
	                while(pre->right)  
	                    pre = pre->right;  
	                
	                //这三步同上面几种方法
	                pre->right = root->right;  
	                root->right = root->left;   //attention !
	                root->left = NULL;  
	            }  
	            //这个程序的关键在这里， 转向右节点
	            //这个右节点是刚刚加入的， 是刚开始的时候 root->left
	            root = root->right;  
        }  

5. 还有一种什么后序遍历的方法， 没看了
	
	[后序遍历的方法](http://www.cnblogs.com/lihaozy/archive/2012/12/31/2840398.html)

#Subsets    

基础的全子集问题（所谓的回溯法)
思路： 一个指针从前往后遍历，遇到一个元素，决定要不要往子集里面加。
子集一共有 2^n 个， n是元素个数


	class Solution {
	public:
	    vector<vector<int> > subsets(vector<int> &S) {
	        vector<int>  oneSubset;
	        sort(S.begin(),S.end()); //别忘记排序
	        subset(S,0,oneSubset);
	        return output;
	        
	    }
	    
	    void subset(vector<int>&s, int idx, vector<int> oneSubset){
	        if(s.size() == idx){
	            output.push_back(oneSubset);
	            return;
	        }
	        
	        //两种选择， 添加 或者 不添加
	        
	        //1. 添加 idx 指向的元素
	        vector<int> oneSubset_ = oneSubset;
	        oneSubset_.push_back(s[idx]);
	        subset(s, idx+1, oneSubset_);
	        
	        //2. 不添加
	        subset(s, idx+1, oneSubset);
	        
	    }
	private:
	    vector<vector<int> > output;
	    
	};

##Path Sum II    
二叉树的字数从root到leaf的sum是否等于target，找到所有等于的路径。
就是一个先序遍历的DFS，

1. 一种不是很好的实践， 有点冗余

		class Solution {
		public:
		    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		        vector<int> path;
		        DFS(root,sum,0,path);
		        return output;
		    }
		
		    void DFS(TreeNode* root, const int sum, int sumPath, vector<int> path){
		        if(!root) return;
		        
		        //leaf
		        if(!root->left && !root->right){
		            sumPath += root->val;
		            path.push_back(root->val);
		            if(sumPath==sum){
		                output.push_back(path);
		            }
		            return;
		        }
		        
		        //提前退出， 因为都是正数, 不成立， 因为有负数
		        //if(sumPath>sum) return;
		        
		        
		        //left + right
		        sumPath += root->val;
		        path.push_back(root->val);
		        
		        //至此， sumPath等于到root节点的sum
		        
		        DFS(root->left,sum,sumPath,path);
		        DFS(root->right,sum,sumPath,path);
		        
		    }
		    
		    
		private:
		    vector<vector<int> > output;
		};

2. 这个形式比较简洁
		
	
		class Solution {
		
		public:
		    //recursive method
		    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		        vector<vector<int>> paths;
		        vector<int> path;
		        detectAndRember(root,path,sum,paths);
		        return paths;
		    }
		    
		    void detectAndRember(TreeNode* root, vector<int> path,int sum,vector<vector<int>>& paths){
		        if(!root) return; //not a leaf
		        
		        //不管怎样， 先push进去就好
		        path.push_back(root->val);
		        
		        if(!root->left && !root->right){ //leaf
		            if(getVectorSum(path)==sum){
		                paths.push_back(path);
		            }
		            return;
		        }
		        
		        
		        detectAndRember(root->left,path,sum,paths);
		        detectAndRember(root->right,path,sum,paths);
		    }
		    
		    int getVectorSum(vector<int> v){
		        int sum =0;
		        int n = v.size();
		        for(int i=0;i<n;i++){
		            sum += v[i];
		        }
		        return sum;
		    }
		
		
		};

##Jump Game    

##Longest Common Prefix 
给定一堆string，找到他们的最长公共前缀。

   
##Search for a Range 
思路， 由于要求 log(n) 的复杂度，而且是一个已经排序的数组， 所以一定是二分查找

1. 由大到小收缩法：在二分查找的过程中， 记录下来能够包含range的最小二分范围，然后往中间收缩。 貌似不能保证 log(n)的复杂度，比如  0 0 0 0 1 2 2 2 2   left=0 right=9-1=8 mid=4 直接找到target，往中间收缩的复杂度是O(n)， 但是能够 Accepted.
	
2. 由小到大扩散法：先二分查找到一个target ， 然后往两边扩散，复杂度无法保证是 log(n)， 比如全是1的数组，target也是1，扩散的复杂度是O(n)， 没有试能不能 Accepted。

3. 一般的二分法找到target之后就停止，但是其实可以找到之后继续找， 比如找到最左的target， 也可以找到最右边的target。

		class Solution {
		public:
		    vector<int> searchRange(int A[], int n, int target) {
		        int left = 0;
		        int right = n-1;
		        int mid;
		        
		        //找到最左边的target的index
		        while(left<=right){
		            mid = (left+right)/2;
		            if(A[mid]<target){
		                left = mid+1;
		            }else if(A[mid]>target){
		                right = mid-1;
		            }else{
		                //继续在左边找
		                right = mid-1;
		            }
		        }
		        
		        //结束的时候，left是target在？？
		        // left right target
		        int rangeLeft = left;
		        
		        left = 0;
		        right = n-1;
		         //找到最右边的target的index
		        while(left<=right){
		            mid = (left+right)/2;
		            if(A[mid]<target){
		                left = mid+1;
		            }else if(A[mid]>target){
		                right = mid-1;
		            }else{
		                //继续在右边找
		                left = mid+1;
		            }
		        }
		        
		        //结束时？？ 二分查找结束时候的left和right究竟是怎样的。
		        int rangeRight = right;
		        
		        if(A[rangeLeft]!=target || A[rangeRight]!=target){
		            rangeLeft = -1;
		            rangeRight = -1;
		        }
		        
		        vector<int> range;
		        range.push_back(rangeLeft);
		        range.push_back(rangeRight);
		        
		        return range;
		    }
		};


不管是 
Search Insert Position 
还是
Search Range

采用的二分查找法， 最后都有 

	A[left]>target
	A[right]<target

而且 left=right+1

这个结论还有待证明， 还需要查阅一些资料。


比如， insert position的时候， left正好指向第一个比target大的元素，所以就应该是插入位置。 

search range 的时候， 分为两个阶段
找左边界的时候， left正好指向左边界， right指向left的左边  
找右边界的时候， right正好指向右边界，left指向right的右边



总结， 学会举反例也是一种本事。

##3Sum Closest   
基本思路： 线性的2Sum问题的修改版 + combination问题

1. 一个不是很好的版本
	
		class Solution {
		public:
		    //这个方法不如使用minGap， 因为这里的twoSumClosest函数返回的是 twoSum, 想要进行 minThreeSum的更新， 还要将 twoSum 加成 threeSum, 然后还面临如何选取 minThreeSum初值的问题（这里选择的是INT_MAX， 其实可以选择前三个数的和）
		    int threeSumClosest(vector<int> &num, int target) {
		        sort(num.begin(),num.end());
		        
		        int minThreeSum = INT_MAX; //不够鲁邦
		        //int minThreeSum = num[0]+num[1]+num[2]; 更好
		        
		        for(int i=0;i<num.size()-2;i++){
		            int twoSum = twoSumClosest(num,target-num[i],i+1,num.size()-1);
		            int threeSum = twoSum+num[i];
		            
		            if(threeSum==target){
		                return target;
		            }
		            
		            //注意，如果这里只比较abs(minThreeSum-target)， 当target为-1的时候会溢出，注意INT_MAX这种情况
		            //!其实这里使用 INT_MAX来进行判断是不是第一次。 不是特别靠谱， 因为更新过一次 minThreeSum 之后，minThreeSum的值还是有可能变成INT_MAX， 比如 target=INT_MAX的时候就很有可能
		            if(minThreeSum==INT_MAX || abs(threeSum-target)<abs(minThreeSum-target)) minThreeSum=threeSum;
		        }
		        return minThreeSum;
		    }
		    
		private:
		    //修改的twoSum
		    int twoSumClosest(const vector<int> &num, int target, int fromIdx, int toIdx){
				vector<int> closestTwoSum(2);
		        int lastDiff = INT_MAX; //上一次距离target的差距
				int left = fromIdx;
				int right = toIdx;
				int minDiff = INT_MAX;
				while (left < right){ //不能等于，否则可能会重复
				    int diff = num[left] + num[right] - target;
				    
				    if(lastDiff==INT_MAX) lastDiff=diff;
				    if(minDiff==INT_MAX) minDiff=diff;
				    
				    //如果使用这个， 会造成错误， 即使sum变号，也不能说明最接近target的在附近，比如
				    // [4 8 16 32 64 128],80  4+128->4+64 diff变号了，但是left+2 之后 16+64=80 更接近
				    //if(diff==0 || lastDiff<0&&diff>0 || lastDiff>0&&diff<0){
				    //  if(abs(lastDiff)<abs(diff)){
				    //          return target+lastDiff;
				    //  }else{
				    //        return target+diff;
				    //  }
				    //}
				    if(diff==0){
				        return target; //等于，由题设，只有一对最小，所以直接退出
				    }else if (diff>0){
						right--;
					}else if (diff<0){
						left++;
					}
					
					//更新绝对值最小的diff
					if(abs(diff)<abs(minDiff)){
					    minDiff = diff;
					}
					
					//update last
					lastDiff=diff;
				}
				
				//不如直接返回 minDiff， twoSum的diff， 就是threeSum的diff
				return target+minDiff;
			}
		};

2. 相对来说有改进的的版本

		class Solution {
		public:
		    //采用 类似于 combination + 修改过的2sum 的方法， 时间复杂度是 O(n^2)
		    
		    int threeSumClosest(vector<int> &num, int target) {
		        if(num.size()<3) return INT_MIN;
		        
		        //别忘记排序
		        sort(num.begin(),num.end());
		        
		        int sum;
		        
		        //minGap 是距离target最近的距离， 定义为 target-tempSum 
		        int minGap = INT_MAX;
		        //整个组合数 同 combination数
		        for(int i=0;i<num.size()-2;i++){ //注意终止点， 一定要留两个(不包括i， 也就是说i最多等于n-3, 后面是 n-2 n-1)
		            int minGapTemp = INT_MAX;
		            twoSumClosest(num,target-num[i],i+1,minGapTemp);
		            if(abs(minGapTemp)<abs(minGap)){
		                minGap = minGapTemp;
		            }
		        }
		        
		        sum = target-minGap;
		        return sum;
		    }
		    
		private:
		    
		    void twoSumClosest(vector<int>& num, int target, int from, int& minGap){
		        int left = from;
		        int right = num.size()-1;
		        
		        while(left<right){
		            
		            int tempSum = num[left]+num[right];
		            if(abs(target-tempSum)< abs(minGap)){
		                minGap = target-tempSum;
		            }
		            
		            if(tempSum > target){
		                right--;
		            }else if(tempSum < target){
		                left++;
		            }else{
		                //此时 minGap=0 ，不用再找
		                return;
		            }
		            
		            
		        }
		        
		    }
		    
		};


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
思路：
最naive的思路就是一个while，乘n次， 复杂度是 O(n) 。 这种方法每次都乘以一个x，  向目标逼近的太慢。
可以利用中间结果，同时加快逼近速度。
比如 x的5次方
naive解法：
x5 = x4*x = x3*x*x = x2*x*x*x = x*x*x*x*x;
依赖树： x5 - x4 - x3-x2-x1
折半：
x5 = x2*x2*x = (x*x)*(x*x)*x,  这样下来，算出的x2就可以复用。
依赖树： x5-x2-x1
幅度变成了O(logN)

1. 	递归版本
	注意对n=-2147483648的特殊处理
	
		class Solution {
		public:
		    double pow(double x, int n) {
		        
		        //处理 x=-1.0 n=-2147483648这种边界情况。
		        /*
		        int n = -2147483648;
		        int m = -1*n;
		        m还是等于-2147483648
		        为什么???
		        */
		        if(x==1.0) return x;
		        if(x==-1.0){
		            if(n%2==0) return 1.0;
		            else return -1.0;
		        }
		        
		        if(n<0){
		            n = -n;
		            return 1/powHelper(x,n);
		        }else{
		            return powHelper(x,n);
		        }
		    }
		    
		private:
		    double powHelper(double x,int n){
		        //递归出口
		    	if(n==0) return 1.0;
		    
		    	if(n%2==0){ //偶数
		    		return powHelper(x*x,n/2);	
		    	}else{
		    		return x*powHelper(x*x,(n-1)/2);
		    	}
		    }

		    
		};

2. 	迭代版本
	这里不知道为什么就没有n的正负号的问题了???

	class Solution {
	public:
	//迭代版本 ， 使用栈
	double pow(double x,int n){
	    int raw_n = n;
		stack<int> re; //stack里面保存着每次除法的余数
		while(n!=0){
			if(n%2==0){ //使用 n&1会出错???
				re.push(0);
			}else{
				re.push(1);
			}

			n = n/2;
		}

		/*
		如果是 pow(x，5)


		stack里面的是：
		从 5得到0 一共经历了三步（包括5四个结果）：
		1
		0
		1
		*/

		double res = 1.0; //注意要从1开始， 因为上一步的时候n是最后除到0的， 也就是x的0次方
		/*如果上一步n除到1（这是必然的，因为n最后必然等于0， 0之前一步必然是1） 就可以令res等于x
		那时候的stack里面应该是这样：
		0
		1
		同样可以得到结果
		*/

		while(!re.empty()){
			int r = re.top();
			re.pop();
			if(r){
				res = res*res*x;
			}else{
				res = res*res;
			}

		}
		
		if(raw_n<0) res = 1.0/res;

		return res;

	}
	};


##Construct Binary Tree from Preorder and Inorder Traversal    
##Reverse Linked List II    
##Palindrome Partitioning  





##Add Binary    
##N-Queens   
N后问题， 回溯法的经典使用案例


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

思路：
中心扩展法， 注意可以从两个元素开始扩展， 这样就包含了奇数和偶数的情况，
这种方法相对来说比较容易， 时间复杂度是 O(n^2)

1. 	中心扩展法版本一

		class Solution {
		public:
		    //中心扩展法
		    string longestPalindrome(string s) {
		        int longestLength = 0;
		        int region[2] = {0,0};
		        for(int i=0;i<s.size();i++){
		            //中心为i
		            int len = expandFromCenter(s,i,i);
		            if(len>longestLength){
		                longestLength=len;
		                region[0] = i - len/2;
		                region[1] = i + len/2;
		            }
		            
		            //中心在 i i+1之间
		            if(i!=s.size()-1){
		                int len = expandFromCenter(s,i,i+1);
		                if(len>longestLength){
		                    longestLength=len;
		                    region[0] = i - (len/2 - 1);
		                    region[1] = i+1 + (len/2 - 1);
		                }
		            }
		        }
		        return s.substr(region[0],region[1]-region[0]+1); //注意substr的用法
		    }

		private:
		    //注意扩展的时候中心可以在一个元素上， 也可以在两个元素中间， 对应改子串是奇数和偶数的情况
		    int expandFromCenter(string str, int center_l, int center_r){
		        int l = center_l;
		        int r = center_r;
		        
		        int len;
		        if(l==r) len=-1; //奇数, 不必担心，奇数一定会在while中 +2
		        else len=0; //偶数
		        
		        while(str[l]==str[r] && l>=0 && r<str.size()){ //避免越界
		            l--;
		            r++;
		            len += 2;
		        }
		        return len;
		    }
		};

2. 	中心扩展法版本二
		
		class Solution {
		public:
		    string longestPalindrome(string s) {
		        const int N = s.size();
		        
		        int max_pali_len = -1;
		        int max_pali_left = -1;
		        int max_pali_right = -1;
		        
		        for(int i=0;i<N;i++){
		            int l1=i;
		            int r1=i;
		            int l2=-1;
		            int r2=-1;
		        	int pali_len1 = expandFromCenter(l1,r1,s,N);
		        	int pali_len2 = -1;
		        	if(i!=N-1){
		        	    l2 = i;
		        	    r2 = i+1;
		        		pali_len2 = expandFromCenter(l2,r2,s,N);
		        	}
		        
		            //update max_len 、left and right
		            //如果把len， left和right封装成为一个类， 结果会比较简洁
		            int pali_len = -1;
		            int l,r;
		        	if(pali_len1 > pali_len2){
		                pali_len = pali_len1;
		                l = l1;
		                r = r1;
		        	}else{
		        	    pali_len = pali_len2;
		                l = l2;
		                r = r2;
		        	}
		        	if(pali_len>max_pali_len){
		        	    max_pali_len = pali_len;
		        	    max_pali_left = l;
		        	    max_pali_right = r;
		        	}
		        	
		        }
		        
		        return s.substr(max_pali_left,max_pali_len);
		    }

		private:

		    int expandFromCenter(int& l, int& r, const string S,const int N){
		    	int pali_len=0;
		    
		    	while(l>=0 && r<N){
		    		if(S[l]==S[r]){
		    			pali_len = r-l+1;
		    		}else{
		    			break;
		    		}
		    
		    		l--;
		    		r++;
		    	}
		    	
		    	//注意！！！把 l和r变回去
		    	//这一步不放在上面 while处的break处， break的时候是因为 S[l]!=S[r]这个时候需要这一步操作，同时如果是因为没有满足while的条件而推出，得到的比如 l<0了， 同样要进行这一步操作
		    	l++;
		    	r--;
		    
		    	return pali_len;
		    }
		};

		

##Word Break    

DP

下一次i的循环，就可以踩着第一步走过的脚印往前

	class Solution {
	public:
	    bool wordBreak(string s, unordered_set<string> &dict) {
	        const int n = s.size();
	        vector<bool> dp(n+1,false);
	        dp[0] = true;
	        
	        //i代表第几个字符
	        for(int i=1;i<=n;i++){ //i是起始点
	            int idx = i-1; //第i个字符的idx
	            if(dp[idx]){ //如果第idx个字符（也就是第i-1个字符）可以到达， 就往下推
	                for(int j=idx;j<n;j++){
	                    //以第idx个字符开始，到s中index为j结束的字串，是不是在dict中， 如果是， 就能将dp[j+1]=true， 因为index为j的字符是第j+1个字符
	                    string subStr = s.substr(idx,j-idx+1);//注意 substr函数的用法
	                    if(dict.count(subStr)>0){ //in dict 
	                        dp[j+1] = true;
	                    }
	                }
	                
	                //以idx等于0的时候为例， 如果经过这个for循环, dp[j]=true说明 [0,j-1]这个字串在dict中，
	                //如果 dp[j]=false 说明 [0,j-1]的字串不在 dict 中， 但是不能说明j-1就不可以到达。只不过不能一步到达
	                
	            }
	        }   
	        return dp[n];
	    }
	};

稍加变形

	class Solution {

	public:
	    bool wordBreak(string s, unordered_set<string> &dict) {
	        // Note: The Solution object is instantiated only once and is reused by each test case.
	        int n = (int)s.size();
	        vector<bool> dp(n + 1, false);
	        dp[0] = true;
	        for (int i = 0; i < n; i++) {
	            if (dp[i]) {
	                for (int len = 1; i + len - 1 < n; len++) {
	                    if (dict.count(s.substr(i, len)) > 0)
	                        dp[i + len] = true;
	                }
	            }
	        }
	        return dp[n];
	    }
	};

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
思路： 
这是一个局部约束问题（自己起的名字）， 对于每个小孩而言， 只要满足局部约束就可以
这里的意思就是每个小孩和左右两边比，能够满足约束就可以。

1. 先满足左边
2. 再满足右边， 并且确定在满足右边约束的过程中，左边没有受影响。




##Two Sum    



##Palindrome Partitioning II    
##Minimum Window Substring    
##Substring with Concatenation of All Words    
##Word Ladder    
##Median of Two Sorted Arrays    
##3Sum    
##Divide Two Integers  

思路：

x/y = N

目的就是找到一个数N,使得:

	y*N     >= x
	y*(N-1)  < x

问题就是要如何试出来这个N?
 
 1. 最naive的方法：
 	使用加法或者减法一个一个地试。
 	尝试顺序是 1 2 3 4 5 。。。。N

 2. 得寸进尺法：
 	尝试顺序是 1 2 4 8 。。。M(M>n) 1 2 4 ... L(L>n) 1 2 ... N

		class Solution {
		public:
		    int divide(int dividend, int divisor) {
		        
		        //除数不等于0
		        assert(divisor != 0);
		        
		        int count = 0, result = 0;
		        
		        //判断最后结果是不是负数
		        bool isNeg = false;
		        if((dividend<0 && divisor>0)||(dividend>0 && divisor<0))
		            isNeg = true;
		            
		        
		        unsigned int tDividend = abs(dividend);
		        const unsigned int tDivisor = abs(divisor);
		        unsigned int sum = 0;
		        
		        //这里不能加上 = 号， 会造成死循环
		        while(tDividend > tDivisor)
		        {
		            count = 1;
		            
		            //sum是 Divisor的 1 2 4 8 ... 倍
		            sum = tDivisor;
		            
		            //如果 sum*2 如果小于被除数， 就一直乘以2，直到大于等于被除数为止
		            /*
		            用一个例子来解释：
		            Dend = 10 
		            Dor = 3
		            sum = 3
		            count = 1
		            
		            sum = sum*2 //sum=6 < 10
		            count = count*2 //2
		            sum = sum*2 //sum=12 > 10
		            
		            Dend -= sum/2 //4  剩下的继续从头开始
		            
		            result += count //2
		            */
		            while((sum<<=1) < tDividend)
		            {
		                //count*2
		                count<<=1;
		            }
		            
		            //将被除数减去 sum/2
		            tDividend -= (sum>>=1);
		            
		            result += count;
		        }
		        
		        //最后
		        if(tDivisor == tDividend)
		            result++;
		        return isNeg ?  -result : result;
		    }
		};

3. 自己写的得寸进尺法 （TLE）

		class Solution {
		public:
		    int divide(int dividend, int divisor) {
		        bool isNeg = false;
		        if ((dividend>0&&divisor<0) || (dividend<0&&divisor>0))
		            isNeg = true;
		        dividend = abs(dividend);
		        divisor= abs(divisor);
		        
		        //处理特殊情况
		        if(dividend<divisor) return 0;
		        if(dividend==divisor){
		            if(isNeg) return 1;
		            else return -1;
		        }
		        
		        
		        int res = multi(divisor,dividend,0); 
		        
		        //符号矫正
		        if(isNeg){
		            res = -res;
		        }
		        return res;
		    }
		    
		private:
		    // x/y //已知除数比N大，往后找
		    int multi(const int y,const int x,int N){
		    	int temp = y*N;
		    	int add = y;
		    	int count = 1;
		    	
		    	int last_N=N;
		    
		        //得寸进尺地增加y， 直到超出x
		    	//at least once
		    	while(temp<=x){
		    		
		    		temp += add;
		    		last_N = N;
		    		N = N + count;
		    		
		    		add = add<<1;
		    		count = count<<1;
		    	}
		    
		    	if((temp-y)<=x){ 
		    		return N-1;
		    	}else{ 
		    		return multi(y,x,last_N);
		    	}
		    
		    }
		};

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
