#[leetcode]remove-duplicates-from-sorted-array
有序数组原地消重

##思路：
所谓消重，有两种方式：

1. 字面意思：消去重复的。
2. 检出不重复的，这里采用这一种方法。


---
###solution 1
一旦遇到不同的数字，就存到A的前面即可。

	class Solution {
	public:
		int removeDuplicates(int A[], int n) {
			//特殊处理n=0的情况
		    if(n==0){
		        return 0;
		    }
		    //初始化，相当于手动处理了第一个，接下来从A[1]开始存
		    int last = A[0];
		    int new_len=1;

		    for(int i=0;i<n;i++){
		        int temp = A[i];
		        if(temp!=last){ //遇到不一样的，存下来
		            A[new_len] = temp;
		            new_len++;
		        }
		        last = temp;
		    }
		    return new_len;
		}

	};


---
###solution 2
类似于1，但是不用处理n=0的情况

	class Solution {
	public:
		int removeDuplicates(int A[], int n) {
			//使得A[0]和last必然不同，接下来从A[0]开始存
		    int last = A[0]-1; 
		    int new_len=0;

		    for(int i=0;i<n;i++){
		        int temp = A[i];
		        if(temp!=last){
		            A[new_len] = temp;
		            new_len++;
		        }
		        last = temp;
		    }
		    return new_len;
		}

	};

---
###soulution 3

这个方法陷入了题目的字面意思,也就是第一种思路，消重，效率很低。没有通过。

但是也有能学到东西的地方。

	
	class Solution {
	public:
		//检测相同的数目，sameCount,往前移动 sameCount-1
		int removeDuplicates(int A[], int n) {
			int last = A[0];
			int sameCount = 0;
			int new_len = n;
			for (int i = 0; i < new_len; i++){ //new_len不停在变化
				int temp = A[i];
				if (temp == last && i!=new_len-1){ //看是不是最后
					sameCount += 1;
				}
				else if (temp == last && i == new_len - 1){ //如果是最后，就返回 
					sameCount += 1;
					int dis = sameCount - 1;
					new_len -= dis;
					return new_len;
				}
				else if (sameCount != 1){ //如果遇到新的数字，而且之前一个数目不为1，就往前挪。
					int dis = sameCount - 1;
					
					int dest = i - dis;
					moveForward(A, n, i, dest);
					new_len -= dis;
					i -= dis; //注意这里 i也要往随着A前挪，不然就乱了
					sameCount = 1;
				}
				last = temp;
			}

			return new_len;

		}

	private:
		//将A数组的[start,:]移动到[dest,:]
		void moveForward(int A[], const int n, const int start, int dest){
			for (int i = start; i < n; i++){
				A[dest] = A[i];
				dest++;
			}
		}
	};


##总结

为什么有序数组可以这么干，无序数组呢？

对于该题目来说，有序数组的相重的数字都在一起，所以如果把题目换成：相重的数字都在一起的数组原地消重 是一样的。
