SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newnode=malloc(sizeof(SinglyLinkedListNode));
    newnode->data=data;
    newnode->next=NULL;
    
    if(position == 0){
        newnode->next = llist;
        return newnode;
    }
    
    SinglyLinkedListNode *temp = llist;
    for(int i=0;i<position-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    
    newnode->next = temp->next;
    temp->next=newnode;
    
    return llist;

}