SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    if(!head1) return head2;
    if(!head2) return head1;
    
    SinglyLinkedListNode *mergedhead=NULL;
    
    if(head1->data<head2->data){
        mergedhead=head1;
        head1=head1->next;
    }else{
        mergedhead=head2;
        head2=head2->next;
    }
    
    SinglyLinkedListNode* current=mergedhead;
    
    while(head1&&head2){
        if(head1->data<head2->data){
            current->next=head1;
            head1=head1->next;
        }
        else{
            current->next=head2;
            head2=head2->next;
        }
        current=current->next;
    }
    
    if(head1)current->next=head1;
    if(head2)current->next=head2;
    
    return mergedhead;

}