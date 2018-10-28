/**
* Leet Code Challenge
* You are given two non-empty linked lists representing two non-negative integers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* 
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
**/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* head = new ListNode(0);
        ListNode* curr = new ListNode(0);      
        int val1, val2;
        
        //Set current next to solution head
        curr->next = head;
        
        //iterate while both l1 and l2 have some value
        while(l1 || l2){
            
            //if none exists there was no carried one
            //but enetered loop so more digits exist
            //need to initialize next and iterate
            if(curr->next==NULL){
                curr->next = new ListNode(0); 
            }
            curr = curr->next;
            
            //set vals and iterate depending on state
            if(l1==NULL){
                //set addition vals
                val1 = 0;
                val2 = l2->val;
                
                //iterate to next node
                l1 = NULL;
                l2 = l2->next;
            }
            else if(l2==NULL){
                //set addition vals
                val2 = 0;
                val1 = l1->val;
                
                //iterate to next node
                l2 = NULL;
                l1 = l1->next;
            }
            else{
                //set addition vals
                val1 = l1->val;
                val2 = l2->val;
                
                //iterate to next node
                l1 = l1->next;
                l2 = l2->next;
            }
            
            //test if addition is greater than 10
            //pass 1 to next node if it is
            if((curr->val + val1 + val2)>9){
                curr->next = new ListNode(1);
            }
            
            //set current digit to remainder
            curr->val = (curr->val+val1+val2)%10;
        }
        
        return head;
        
    }
};
