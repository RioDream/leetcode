#Single Number 


##思路：
异或！

	a^b^a = b
	证明：a^b^a = a^a^b = 0^b = b


---
###solution 1
	
	class Solution {
	public:
	    int singleNumber(int A[], int n) {
	        int singleNum = 0;
	        for(int i=0;i<n;i++){
	            singleNum^=A[i];
	        }
	        return singleNum;
	    }
	};


##总结

如果是有两个single number, 要求通过两次扫描获得，这两个数

一次扫描： a^b

分析a,b必然有一位不同，比如 a^b = 0010 ,第二位不同，根据这个线索，相当于把所有的数字分成了两组，一组有a，一组有b,而且每一组都只有a或者b一个 single number。

二次扫描：if(each 属于 第一组) 进行异或， 得到c, c可能是a或者b。

于是： a,b 一个是 c,一个是a^b^c。