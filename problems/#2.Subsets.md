##Subsets    

基础的全子集问题（所谓的回溯法)
和 Permutation Combination 一起看
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

