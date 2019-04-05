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
        int carry = 0;
        int unit = 0;
        int sum = 0;
        ListNode *head, *l, *previous;
        
        head = new ListNode(0);
        l = head;
        
        while(l1 != NULL && l2 != NULL)
        {
            sum = l1->val + l2->val + carry;
            unit = sum % 10;
            l->val = unit;
            carry = sum / 10;
            
            l->next = new ListNode(0);
            previous = l;
            l = l->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL)
        {
            while(l2 != NULL)
            {
                sum = l2->val + carry;
                unit = sum % 10;
                l->val = unit;
                carry = sum / 10;
            
                l->next = new ListNode(0);
                previous = l;
                l = l->next;
                l2 = l2->next;
            }
            if(carry > 0)
            {
                l->val = carry;
                l->next = NULL;
            }
            else
            {
                delete l;
                previous->next = NULL;
            }
        }
        else if(l2 == NULL)
        {
            while(l1 != NULL)
            {
                sum = l1->val + carry;
                unit = sum % 10;
                l->val = unit;
                carry = sum / 10;
            
                l->next = new ListNode(0);
                previous = l;
                l = l->next;
                l1 = l1->next;
            }
            if(carry > 0)
            {
                l->val = carry;
                l->next = NULL;
            }
            else
            {
                delete l;
                previous->next = NULL;
            }
        }
        
        return head;
    }
};