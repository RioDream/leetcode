#[leetcode]copy-list-with-random-pointer

##思路
链表里面的顺序是个很麻烦的事，如果要复制的时候保留相互关系，以原链表为基础，当做一个模子，
直接在上面弄一份一份副本，就像做一把钥匙，倒个模子。又或者像草履虫，无性繁殖，biaji，生出一个新的。

###Solution 1

    /**
     * Definition for singly-linked list with a random pointer.
     * struct RandomListNode {
     *     int label;
     *     RandomListNode *next, *random;
     *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
     * };
     */
    class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            head = insertAfterNode(head);
            head = copyRandomity(head);
            RandomListNode* head2 = asexualPropagation(head);
            return head2;
        }


    private:
        //在所有的node之后插入一个label相同的node
        RandomListNode* insertAfterNode(RandomListNode *head){
            RandomListNode* tempHead = head;
            while(head){
                RandomListNode *node = new RandomListNode(head->label);
                
                //insert node after head , label it 
                RandomListNode* temp = head->next;
                head->next = node;
                node->next = temp;
                
                head = temp;
            }
            
            return tempHead;
        }
        
        //复制随机关系
        RandomListNode* copyRandomity(RandomListNode* head){
            RandomListNode* tempHead = head;
            while(head){
                //head's random node
                if(head->random){
                    RandomListNode* randomNode = head->random;
                    head->next->random = randomNode->next;
                }
                
                head = head->next->next; //skip one every time， head->next must not be null
            }
            return tempHead;
        }
        
        //分离
        RandomListNode* asexualPropagation(RandomListNode* head){
            //check
            if(!head){
                return head;
            }
            
            RandomListNode* head2 = head->next;    
            while(head->next->next){ //最后到达整个的倒数第二个元素
                RandomListNode* nextOldNode = head->next->next;
                
                //link the new list 
                RandomListNode* thisNewNode = head->next;
                RandomListNode* nextNewNode = head->next->next->next;
                thisNewNode->next = nextNewNode;
                
                //link the old list
                head->next = nextOldNode;
                
                
                head = nextOldNode; //skip one every time， head->next must not be null
            }
            head->next = nullptr; //最后一个oldNode要结尾， 而newNode不用，因为next已经是null
            
            return head2;
            
        }
    };