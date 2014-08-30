#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree with next pointer.*/
  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        
        TreeLinkNode* lastLevelHead = root;
        TreeLinkNode* lastChildOfSibling = NULL;
        while(lastLevelHead){
            TreeLinkNode* p = lastLevelHead;
            while(p){
                TreeLinkNode* leftChild = p->left;
                TreeLinkNode* rightChild = p->right;
                
                //link
                if(lastChildOfSibling) lastChildOfSibling->next = leftChild;
                else lastLevelHead = leftChild;
                if(leftChild) leftChild->next = rightChild; //可能已经是null了
                lastChildOfSibling = rightChild;
                
                p = p->next;
            }
                            
            lastLevelHead;
            lastChildOfSibling = NULL;
        }
    }
};

int main(){
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(1);

}