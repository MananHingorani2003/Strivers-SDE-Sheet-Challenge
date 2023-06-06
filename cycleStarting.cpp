Node *firstNode(Node *head)
{
    //    Write your code here.
    Node* fast = head;
        Node* slow = head;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow) {
                Node* temp = head;
                while(slow != temp) {
                    slow = slow -> next;
                    temp = temp -> next;
                }
                return slow;
            }
        }
        return NULL;
}
