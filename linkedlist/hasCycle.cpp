bool hasCycle(ListNode *head) {
    ListNode *temp = head, *temp1 = head;
    if(head != NULL){
        while(temp->next!=NULL && temp1->next!=NULL){
            temp = temp->next;
            temp1 = temp1->next->next;

            if(temp1 == NULL)return false;

            if(temp == temp1)return true;
        }
        return false;
    }
    else
        return false;
}
