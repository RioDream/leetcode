#[leetcode]linked-list-cycle-ii

##思路
1. 沿着 [linked-list-cycle]的思路， 但是返回的node* 是指向自己的。List也都被破坏
2. 使用runner

---
###Solution 1 （未通过， Time Limit Exceeded）


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
	    ListNode *detectCycle(ListNode *head) {
	        if(head==nullptr){
	            return head;
	        }
	        
	        while(head!=nullptr){
	            if(head->next==head){
	                return head;
	            }
	            ListNode* nextNode;
	            nextNode = head->next;
	            head->next = head;
	            head = nextNode;
	        }
	        return head;
	    }
	};



---
###Solution 2
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
	    ListNode *detectCycle(ListNode *head) {
	        //start from the head
	        ListNode* walker = head;
	        ListNode* runner = head;
	        
	        //walker and runner, run!
	        int n=0;
	        while(true){
	            if(walker&&runner){
	                //walker goed 1 step a time
	                walker = walker->next;
	                //runner goes 2 steps a time
	                if(runner->next){ 
	                    runner = runner->next->next;
	                }else{
	                    n = -1;
	                    break;
	                }
	                n++;
	            }else{ //one of them get to the end(actually, runner of course), there's no cycle in the list
	                n = -1;
	                break;
	            }
	            
	            //runner and walker meet
	            if(runner==walker){ 
	                break;
	            }
	        }
	        
	        //we can proof that, when the runner and walker meet, the variable 'n' will be the length 
	        //of the cycle , and if we let runner go n steps first and then let them go 1 step each time, they
	        //will meet at the start of the cycle.
	        
	        if(n==-1){ //no cycle
	            return nullptr;
	        }else{
	            walker = head;
	            runner = head;
	            //let runner go n steps first
	            for(int i=0;i<n;i++){
	                runner = runner->next;
	            }
	            //when runner meets walker, the meet point will be the start of the cycle
	            while(runner!=walker){
	                walker = walker->next;
	                runner = runner->next;
	            }
	            return walker;
	        }
	    }
	};