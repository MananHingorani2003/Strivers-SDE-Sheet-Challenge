while (l1 && l2) {
            int value = l1->val+l2->val+carry;
            carry = value/10;
            l3 -> next = new ListNode (value%10);
            l1 = l1 -> next;
            l2 = l2 -> next;
            l3 = l3 -> next;
        }
        while (l1) {
            int value = l1->val+carry;
            carry = value/10;
            l3 -> next = new ListNode (value%10);
            l1 = l1 -> next;
            l3 = l3 -> next;
        }
        while (l2) {
            int value = l2->val+carry;
            carry = value/10;
            l3 -> next = new ListNode (value%10);
            l2 = l2 -> next;
            l3 = l3 -> next;
        }
        if (carry) {
            l3 -> next = new ListNode (carry);
        }
        return head -> next;
