#[leetcode]partition-list

将list中比x小的node都放左边， 比x大的都放右边

##思路
一次遍历，遇小前叉，关键是要维护一个指向要插入位置的node*

###Solution 1


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
        ListNode *partition(ListNode *head, int x) {
            ListNode* hair = new ListNode(0);
            hair->next = head;
            ListNode* insertPoint = hair; //insert after this pointer
            ListNode* last = hair;
            while(head){
                if(head->val < x){
                    if(insertPoint->next != head){//要是没有这句，如果第一个就比x小，会先delete再insert回原样
                        //backup 
                        ListNode* nextNode = head->next;
                        
                        //do delete , last不用动
                        last->next = head->next;
                            
                        //do insert
                        ListNode* temp = insertPoint->next;
                        insertPoint->next = head;
                        head->next = temp;
                        
                        //update head
                        insertPoint = head;
                        head = nextNode; 
                        //last不用动
                        
                    }else{ //insertPoint->next == head
                        //update insert point
                        insertPoint = head;
                        head = head->next;
                        last = last->next;
                    }
                }else{
                    head = head->next;  //head 一定比insertPoint跑的远，因为本身就起点靠前，跑的又快
                    last = last->next;
                }
                
            }
            return hair->next;
        }
    };