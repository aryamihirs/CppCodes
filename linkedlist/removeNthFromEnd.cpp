void removeNthNode(int n, ListNode **head){
        ListNode *temp = *head, *prev;
        if(n >= 0){
            while(n--){
                temp = temp->next;
            }
            prev = temp;
            temp = temp->next;
            prev->next = temp->next;

            free(temp);
        }
        else{
            temp = temp->next;
            *head = temp;
            // free(temp);
        }
    }

   ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 1, idx;
        while(temp->next != NULL)
        {
            temp = temp->next;
            len++;
        }
        idx = len - n - 1;

        cout << "idx " << idx <<'\n';
        cout << "len " << len <<'\n';
        cout << "n " << n <<'\n';

        // temp = head;
        // while(idx--){
        //     temp = temp->next;
        // }
        // if(idx < 0){
        //     temp = NULL;
        //     return temp;
        // }
        // else{
            removeNthNode(idx,&head);
            return head;
        // }
    }
