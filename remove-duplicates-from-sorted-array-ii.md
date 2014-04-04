#[leetcode]remove-duplicates-from-sorted-array-ii

---
##solution 1

类似i问题，只是在检出新的数字的时候，继续再往后看一位就可以了

	class Solution {
	public:
	    int removeDuplicates(int A[], int n) {
	        int sameCount = 0;
	        const int MAX_DUP = 2;//这里其实不该这么写，因为其实是不可扩展的。

	        int new_len = 0;
	        int last = A[0]-1;
	        for(int i=0;i<n;i++){
	            int temp = A[i];

	            if(temp!=last){
	                A[new_len++] = temp;
	                if(i+1<n&&A[i+1]==temp){ //如果后一位也相同，就也给赋值
	                    A[new_len++] = temp;
	                }
	        
	            }
	            last = temp;
	        }
	        return new_len;
	    }
	};

---
##solution 2
小改动

	class Solution {
	public:
	    int removeDuplicates(int A[], int n) {
	        int sameCount = 0;
	        const int MAX_DUP = 2; //这里其实不该这么写，因为其实是不可扩展的。

	        int new_len = 0;
	        int last = A[0]-1;
	        for(int i=0;i<n;i++){
	            int temp = A[i];

	            if(temp!=last){
	                A[new_len++] = temp;
	                if(i+1<n&&A[i+1]==temp){
	                    A[new_len++] = temp;
	                    i++; //here！ 由于下一步的temp一定也是等于last的，所以直接跳过。
	                }
	        
	            }
	            last = temp;
	        }
	        return new_len;
	    }
	};