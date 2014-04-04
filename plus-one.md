#[leetcode]plus-one
vector<int> + 1

###思路
往前找到非9的元素，加1即可

---
###solution 1
需要知道 vector是i可以前插的

    class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int n = digits.size();
            int i=n-1;
            //从后往前
            while(digits[i]==9 && i>=0){
                digits[i] = 0;
                i--;            
            }
            
            //break for what?
            if(i<0){ //cases like 99999
                digits.insert(digits.begin(),1);
            }else{ //cases like 8999
                digits[i]++;
            }
            return digits;

        }
    };


---
###solution 2
转化为数字，然后再+1，然后再转化回去。 这实际有点小题大做，因为这一题固定只是+1.
如果是随便+一个数，就可以用这种方法。


###总结
考虑出题意义，这个题目按照这个做法是不是小题大做了？