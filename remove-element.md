#[leetcode]remove-element
原地去元素，类似原地消重


---
###solution 1

    class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            int new_len = 0;
            for(int i=0;i<n;i++){
                int temp = A[i];
                if(temp != elem){
                    A[new_len++] = temp;
                }
            }
            return new_len;
        }
    };

##总结

这种直接原地操作数组的方法要求被改写的元素的index一定要小于等于右值的index
比如，本题中 new_len<=i