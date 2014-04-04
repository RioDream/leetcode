#linked-list-cycle
查看一个链表是不是有环

##思路
所谓查看是不是有环，就像是走迷宫的时候查看一条路有没有走过，可以采用做标记的方法。标记怎么做就是一个问题了。我现在有两种思路。

1. 
    使用val标记，给每个走过的node一个独一无二的int值，如果发现访问到这个int值，就是有环
    这个其实很难找到一个独一无二的值，比如设为 I,你怎么能保证原链表中没有I这个值。

2. 
    使用next标记，给每个走过的node一个next值，检验是否符合这个条件。比如吧next指向自己，这样一来，如果检测到
    有这个特征的node，就是有环。和使用val标记不同的是，如果原来的链表中有个这样的node，那它本身也就是有环，检测结果也是对的。



---
###solution 1 (actually it's wrong)
思路1 这实际上是一个错误的解法，只不过用于测试的链表中没有val为100的，所以可以通过。

    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            while(head!=nullptr){
                int tempVal = head->val;
                //head->
                if(tempVal!=100){
                    head->val = 100;
                }else{
                    return true;
                }
                head = head->next;
            }
            return false;
        }
    };

---
###solution 2
思路2

    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(head==nullptr){
                return false;
            }
            
            ListNode* nextTemp;
            //最后一个元素不访问，执行完while之后，head指向最后一个元素（该元素的next是null）
            //肯定不是之前出现过的元素
            while(head->next!=nullptr){ 
                if(head!=head->next){
                    nextTemp = head->next;
                    head->next = head; //指向自身
                    head = nextTemp;
                }else{
                    return true;
                }
            }
            return false;
        }
    };



##总结

如果要检测是否有循环，又没有好的检测标准，就用检测过的元素弄出一个易于检测的循环。。。