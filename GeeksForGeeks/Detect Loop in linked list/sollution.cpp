bool detectLoop(Node* head)
    {
 //Here We are Intiallizing Two Pointer Where One Point Will Move Faster and Second Will Move Slow to the LinkedList
// Now One Time Finally Come Where Faster Pointer(ptr) and Solower Pointer(qtr) are at the same node
//then we return that yes this linked list is have loop if not then we will false No Loop Found in this Linked List
       Node *ptr=head; 
       Node *qtr=head;
       
// Using Do-While to traverse to the LL
       do
       {
           ptr=ptr->next;
           
           if(ptr==NULL)
           {
              return false;
           }
           qtr=qtr->next;
           
           if(qtr!=NULL)
           {
               qtr=qtr->next;
           }
       
           
       }while(qtr!=NULL && ptr!=NULL && ptr!=qtr);
       
       return qtr==ptr?true:false;
       
    }
};