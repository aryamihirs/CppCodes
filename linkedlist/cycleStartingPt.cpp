ListNode *detectCycle(ListNode *head) {
        ListNode *temp = head, *temp1 = head, *notCir = NULL;
        bool isCycle = false;
        if(head != NULL){
            while(temp->next!=NULL && temp1->next!=NULL){
                temp = temp->next;
                temp1 = temp1->next->next;

                if(temp1 == NULL)return notCir;

                if(temp == temp1){
                    isCycle = true;
                    if(temp == head)
                        return head;
                    else{
                        break;
                    }
                }
            }

            if(isCycle){
                temp = head;
                while(temp != temp1)
                {
                    temp = temp->next;
                    temp1 = temp1->next;
                }
                if(temp == temp1)
                    return temp;
            }
            // if(temp->next == temp && temp1->next->next == temp1)
            //     return temp;
            // else
            return notCir;
        }
        else
            return notCir;
    }
