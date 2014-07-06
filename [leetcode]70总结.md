#leetcode 70题总结

前70题比较容易的。

现在把每一题都过一遍： 大致按照准确率，从高到底

#数字类

##Single Number
##Single Number II

这类问题考虑把数字化成二进制。 
本质上说数的二进制可以看做一个向量，对这些向量进行操作，不会在数字加减的过程中损失一些信息。

Single Number II可以泛化为别的， 比如 任意n个duplicates。

可以学到的基本知识：

1. 如何得到一个int的所有bit，将int不断往右移然后 &1，或者将1不断左移 & int
2. 如何把一个bit移动到第i位，左移i <<i
3. 熟悉了 & | ^(异或) 这些逻辑运算符

##Reverse Integer

##Palindrome Number 
	//判断回文 如 12321
    while(t>0){
        y=y*10+t%10; //y左移并加上t右移 移掉的数
        t=t/10; //t右移
    }


---
#二叉树的递归

##Maximum Depth of Binary Tree
递归获得左子树和右子树的深度，选大的加一。 注意出口条件

##Balanced Binary Tree
递归：先递归获得左右子树的深度， 
然后看根节点处是不是平衡，接着看左右子树是不是平衡

##Same Tree
递归， 左右子树都是same的时候，就是same tree ，注意出口条件

##Unique Binary Search Trees
[1:n]可以组成多少BST？
递归：
[1:n]组成的BST = 所有
使用i in [1:n]作为根
[1:i-1]为左子树组成的BST * [i+1:n]右子树组成的BST =
[1:i-1]为左子树组成的BST * [1:n-i]右子树组成的BST

##Binary Tree Preorder Traversal
##Binary Tree Postorder Traversal
##Binary Tree Inorder Traversal
递归或者使用统一的迭代方法。 ？？

##Symmetric Tree
递归：先递归将 tree mirror， 然后递归比较 isSame

##Path Sum
找到root-leaf的路径满足sum的
递归，
技巧:递归的出口还要检测是不是leaf

    if(!root){ //this node is not from a leaf, otherwise it will reach to next statement
        return false;
    }
    if(root->left==nullptr && root->right==nullptr){ //get to a leaf 
    	;
    }

##Path Sum II 
设置一个vec作为递归参数，记住路径即可


##Minimum Depth of Binary Tree
和getHeight()差不多，不同的地方在于，需要在叶子节点处做判断，而不只是在root==nullptr的时候作为出口。 不然可能计算出某个没有右子树的的二叉树的最小深度是1

##Sum Root to Leaf Numbers
1. 递归：先序遍历，记住路径，到达叶子节点的时候，就算一次。
2. 迭代：采用回溯法即可 ??

##Flatten Binary Tree to Linked List
递归的吧左子树插入root和右子树之间link


##Populating Next Right Pointers in Each Node
BFS: 该题目是完全二叉树，使用一个queue即可，可以通过数目来检测是不是level的最右边
##Populating Next Right Pointers in Each Node II 
BFS: 不是完全二叉树，使用两个queue， 一个存当前的level，一个存下一level的节点

##Binary Tree Zigzag Level Order Traversal
BFS的修改版

---
#数组

##Longest Consecutive Sequence
hashmap的运用

---
#字符串

##Length of Last Word
字符串处理，记录最后一个跳变点（从“ ”到字符），结束的时候看到末尾的距离

##Count and Say 
迭代统计个数 21 is read off as "one 2, then one 1" or 1211.

---
#栈

##Valid Parentheses 
使用栈，遇到左括号就入站，遇到合适的右括号就出栈，否则出错


---
#查找

##Search Insert Position
返回sorted array中elem的index或者可以插入的index： 遇到大于等于elem的，直接返回。
##Remove Duplicates from Sorted List
sorted去重：遍历链表，遇到新的就添加，遇到已有的就漠视
##Remove Element
去elem的重=取不同于elem的元素， 可以in-place
##Remove Duplicates from Sorted Array 
遍历，遇到和last相同的就无视，可以in-place



---
#动态规划

##Climbing Stairs
类似斐波那契，得到递推公式，同时使用一个数组记录已经算过的, 不然复杂度太高。
##Unique Paths
左上角到右下角共多少走法， 数学上是一个排列组合问题，但是用动态规划更好，因为直接套用数学公式可能会溢出。
实际上Cmn问题也是可以通过递推公式用动态规划求解的。
##Unique Paths II
solution1.数学，减去经过障碍的路，经过障碍的路 (r,c), 是（0 0）到（r，c）和（r，c）到右下角的路的乘积
solution2.动归。遇到障碍，的时候，有障碍的一边不参与计数即可

##Minimum Path Sum 
递推公式：dp[j + 1] = min(dp[j + 1], dp[j]) + grid[i][j]; 
小技巧：将地图左边一列的左边设为墙，算地图最左边一列的时候就不会从那边过，同时让地图左上角，再往上一格是一个0， 这样就可以直接开始算了。


---
#分治

##Maximum Subarray
1. kanade
2. 分治法



---
#链表

##Linked List Cycle 
检测链表环 
1. 破坏链表的情况， 令每一个 node->指向自身
2. 不破坏链表， 一个runner(每次两步) 一个walker， 二者会在环内相遇

##Linked List Cycle II
破坏链表的情况不能通过
不破坏链表
runner的路程 2x 
walker的路程 x
2x - x = x 是环的大小
链表总长是l，则l-x就是环的起点，就是倒数第x个节点， 再次利用runner

##Merge Two Sorted Lists 
1 一般做法，直接像Merge Sorted Array一样
2
要求第二个链表往第一个里面插的话，两个指针，一个在第一个链表里面，一个在第二个，记为 p1 p2
如果 p1< p2， 
	挪动p1到合适位置,把p2插入p1后面， p2往后走
如果 p1> p2
	p2插入p1前面, p2往后走
	更新

链表的操作很容易出错，注意。

##Swap Nodes in Pairs
两两交换，细心

##Remove Nth Node From End of List 
你懂的

##Partition List
将链表中比x大的放到比x小的node的后面
//碰到比x大于等于的node，就略过，碰到比x小的node往前插就可以了

##Insertion Sort List 
使用插入排序去排序一个链表

##Add Two Numbers 
将两个链表表示的数相加
3-2-1 + 4-3-2 = 123 + 234
记录进位即可

##Copy List with Random Pointer 
链表的奇技淫巧


##Convert Sorted Array to Binary Search Tree 
递归，找到中间点，用左边的array做左子树，右边的做右子树
不被初始化的指针不能用来赋值给别人，编译不通过，


##Merge Sorted Array
将B合并到A中
简单做法， 直接选B中的元素，插入排序 ？？？
##Sort Colors
近朱者赤，同色相吸问题
O(n)
保留三个数组指针，指向最后一个红色，白色和蓝色
来了一个颜色，就将其和相应的指针后面的元素交换
为什么可以这样：可以交换的基础是所有同色的球视为一样


##Pow(x, n) 
1. 递归 ， 注意效率形式
2. 迭代，使用一个栈去存储过程中的幂次的余数

##Combination Sum 
由于允许重复，所以从当前的和之后的元素中选出sum为target-candidates[i]的

##Combination Sum II
？？

##Add Binary
将两个string表示的二进制数相加


##Gas Station
计算每一个机油站和后面的一段路的差，免得每次都要计算， 然后暴力开找

##Letter Combinations of a Phone Number
1. 不同于全排列，因为每一位上就几种可能，所以迭代更加简单的
2. 也可以递归

##Pascal's Triangle
一层一层迭代就好
##Pascal's Triangle II 
只用一个vector的话，将上一层的vector在原基础上改，最后在push_back(1)即可。




##Gray Code
00 - 0
01 - 1
11 - 3
10 - 2
规律是，这一波把之前的给倒过来，然后再在最前面+1

这种题目要找规律，尤其是递推规律
##Plus One
找9，往前进位
##Rotate Image 
首位相接，in-place旋转


---
#回溯法

##N-Queens
##N-Queens II
回溯法的应用，递归和迭代 ??
这两题几乎一样

##Generate Parentheses
栈
压栈输出 ‘（’ 出栈输出“）”
n个括号， 什么所有压栈出栈的组合 比如 2, push-pop-push-pop  push-push-pop-pop
???


##Permutations
两种思路： 
1. 迭代：1 -> 1,2  2,1 -> 将3插入所有的空隙！ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
2. 递归： 

2.1
// 求nums以left为左边开始的所有排列
perm(nums,left,oneSolution) = 将 num[left] 插入到 perm(nums,left+1,oneSolution)所生成vec的所有空隙
或者使用 right，就更容易看出，其实很容易转换递归为1中的迭代， 换上了递归的外衣而已。

2.2 
perm(left,mid-1,mid+1,right,list):
	//任取一个在前，然后对其余的做全排列
	for each in list： 
		each + perm(left,each前面的,each后面的,right,list)


？？

##Combinations
计算Cmn中的各个组合, 类似Permutations， 只不过Permutations是Ann
递归 Combinations(m,n) = 从m个中选一个index为i的 + 从i往后的数字中选n-1个

可以看到递归过程和 Permutation的过程的主要区别是， Combinations是在i之后选n-1个， 而Permutation是在
除去i之外的元素中选 n-1 个。

##Subsets 
递归 全子集问题，回溯法
每次在第i个元素的时候有两种选择。 1 将A[i]算上 2 不要A[i]， 然后再对后面的做选择


##Jump Game
从后往前，last 始终指向最靠前一个能够到达的index， 前面的元素只要能到这里，必然可以到终点
##Jump Game II
??


##Search in Rotated Sorted Array
##Search in Rotated Sorted Array II
完全不知道干啥



##Binary Tree Level Order Traversal
##Binary Tree Level Order Traversal II
使用两个队列即可


##Search a 2D Matrix
行列各进行二分查找，找到距离目标最近的行，然后在行内进行二分查找

二分查找 ？？


##Set Matrix Zeroes 
要两边扫描，使用两个数组记录zero出现的行和列









