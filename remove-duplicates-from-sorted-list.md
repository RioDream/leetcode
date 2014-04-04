#[leetcode]remove-duplicates-from-sorted-list

##思路
有点类似于有序数组原地消重，但是由于是链表，所以有点不一样，主要是体现在表尾元素的赋值上。
原理是一样的，想象成两个人，一个runner，一个walker，
runner在前面找新元素（这个过程中重复元素直接扔掉delete），找到了就对walker说，我找到了！然后walker就捡起runner所在的元素，并且跟上runner，然后runner继续跑，如此。

和有序数组原地消重一样，每次循环开始的时候，runner始终在walker前面（至少一步），所以不会产生数据覆盖。

##小技巧：
新建一个头指针，作为walker的起始点，可以统一化操作

---
###solution 1

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
        ListNode *deleteDuplicates(ListNode *head) {
            //check validity
            if(head==nullptr){
                return head;
            }
            
            ListNode* runner = head;
            int lastVal = head->val-1; //ensure it's different from the first val
            ListNode* walker = new ListNode(lastVal); //trick: add a new head node
            ListNode* startPoint = walker; //rember where we started for deleting the head node we created
            
            while(runner!=nullptr){
                int tempVal = runner->val;
                if(lastVal == tempVal){
                    //发现一样的，扔了
                    ListNode* tempNode = runner;
                    runner = runner->next; 
                    //这里delete的都是walker之后的，不可能delete掉walker，因为runner至少在walker前面一步。
                    delete tempNode; 
                }else{//发现新的，walker赶紧捡起来，然后跟上，runner继续跑
                    walker->next = runner;
                    walker = runner;
                    runner = runner->next;
                }
                lastVal = tempVal;
            }
            walker->next = nullptr;
            delete startPoint; //delete新创建的头结点。
            return head;
        }
    };