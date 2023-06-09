LinkedListNode<int> *getmid(LinkedListNode<int> *head) {

    LinkedListNode<int> *slow = head;

    LinkedListNode<int> *fast = head;

    while(fast->next && fast->next->next) {

        slow = slow->next;

        fast = fast->next->next;

    }

    return slow;

}

LinkedListNode<int> *reverse(LinkedListNode<int> *t) {

    if(t == NULL || t->next == NULL) return t;

    LinkedListNode<int>* newhead = reverse(t->next);

    t->next->next = t;

    t->next = NULL;

    return newhead;

}

bool isPalindrome(LinkedListNode<int> *head) {

    if(head == NULL || head->next == NULL) return true;

    LinkedListNode<int> *mid = getmid(head);

    mid->next = reverse(mid->next);

    LinkedListNode<int> *temp = head;

    mid = mid->next;

    while(mid != NULL) {

        if(mid->data != temp->data) return false;

        mid = mid->next;

        temp = temp->next;

    }

    return true;

}
