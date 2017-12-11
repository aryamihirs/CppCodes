ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode*,int> mp;
    ListNode *tempA = headA, *tempB = headB, *NoIntersection = NULL;

    if(headA == NULL || headB == NULL)
        return NoIntersection;

    else
    {
        while(tempA != NULL){
            mp[tempA] = 1;
            tempA = tempA->next;
        }

        while(tempB != NULL)
        {
            if(mp.find(tempB) != mp.end())
                return tempB;
            tempB = tempB->next;
        }
        return NoIntersection;
    }
}
