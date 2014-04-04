#[leetcode]length-of-last-word
RT

##思路：
遇到空格就置计数器为0，遇到非空格就+1，尤其注意“a  ”，这种情况，所以设置一个 trash变量，存取上一次被丢弃的计数，如果最后以“ ”结束，就从trash中取出计数。


---
###solution 1

	class Solution {
	public:
	    int lengthOfLastWord(const char *s) {
	        int lastWordLength = 0;
	        int lastWordLength_trash = lastWordLength; //initialize in case of cases like "   "
	        char last = ' ';
	        int i=0;
	        while(s[i]!='\0'){
	            char temp = s[i];
	            if(temp!=' '){
	                lastWordLength++;    
	            //}else if(last!=' '&&temp==' '){
	            else if(last!=' '){ //比上面这一行更简洁。
	                lastWordLength_trash = lastWordLength;
	                lastWordLength=0;
	            }
	            i++;
	            last = temp;
	        }
	        //avoid cases like "a   "
	        if(last==' '){ //get it back from trash
	            lastWordLength = lastWordLength_trash;
	        }
	        return lastWordLength;
	    }
	};