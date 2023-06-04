LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        LinkedListNode<int> *curr = head;
        LinkedListNode<int> *prev = NULL;
        LinkedListNode<int> *temp;

        while (curr) {
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
}
