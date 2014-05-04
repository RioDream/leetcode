#[leetcode]reverse-integer

反转一个数

##Bonus
1. 10000这样的数有什么快速解法？
2. 反转之后如果溢出怎么办？

##思路
1. 最简单的，首先得到每位数，然后再用相反的顺序加起来



---
###Solution 1
    class Solution {
    public:
        int reverse(int x) {
            int n = 1;
            int output=0;

            //得到总共有多少位，n
            while(true){
                int digit = x/(pow10(n));
                if(digit==0){
                    break;
                }
                n++;
            }
            
            
            //get all digits together
            for(int i=1;i<=n;i++){
                int digit = getDigit(x,i);
                output = output + digit*pow10(n-i); //这里其实可以从小到大，采用上一步base的结果*10,更有效率
            }
            return output;
        }
    private:
        //get 10^n
        int pow10(int n){
            int out=1;
            for(int i=0;i<n;i++){
                out *= 10;
            }
            return out;
        }
        
        //得到val的右数第n位数
        int getDigit(int val,int n){ //123,2
            int out = val/pow10(n-1); // 123/(10^1) = 12
            out %= 10; //再取余 12%10 = 2
            return out;
        }
    };