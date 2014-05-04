#[leetcode]unique-binary-search-trees

给定n, 1:n 这些数字一共可以组成多少BST

##思路
1. 递归 一共n个，root是1个(可能是1:n中的一个)，左边分到比root小的i-1个，右边分到比root大的n-i个，左边的组合数*右边的组合数

---
###Solution 1

    class Solution {
    public:
        int numTrees(int n) {
            if(n==1||n==0){
                return 1;    
            }
            else{
                int num = 0;
                for(int i=1;i<=n;i++){ //i是root的值
                    num += (numTrees(i-1)*numTrees(n-i)); //left*right
                }   
                return num;
            }
        }
    };