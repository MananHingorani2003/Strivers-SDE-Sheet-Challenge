*****************************************************************/
int length(ListNode *head) {
        //Write your code here
        Node *temp = head;
        int counter = 0;
        
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
int findIntersection(Node *head1, Node *head2)
{
    //Write your code here
    int a = length (head1);
        int b = length (head2);
        int diff = abs (a-b);
        Node *temp1 = head1;
        Node *temp2 = head2;
        
        if (a>b) {
            while (diff--) {
                temp1 = temp1 -> next;
            }
        }
        else {
            while (diff--) {
                temp2 = temp2 -> next;
            }
        }
        while (temp1 != temp2) {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        
        return temp1;
}
