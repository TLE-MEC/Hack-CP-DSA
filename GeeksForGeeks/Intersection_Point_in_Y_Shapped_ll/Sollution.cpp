int length(Node * ptr)
{//This I have Just Created For the Calculate The Length of LL
    int len=0;
    while(ptr)
    {
        len++;
        ptr=ptr->next;
    }
    return len;
}

//Here We Reseting the Pointer Address
Node * reset(Node *ptr,int point)
{
    for(int i=0;i<point;i++)
    {
        ptr=ptr->next;
    }
    return ptr;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
//First We Callculate the Legnth from the both head
    int len1=length(head1);
    int len2=length(head2);
    
//Now Subracting the Lengths from greater legnth to smaller one (So, thats y using some Condition)
    if(len1>len2)
    {
        int mainLen=len1-len2;
        Node *strPtrOfHead1=reset(head1,mainLen);
        Node *strPtrOfHead2=head2;
        
        while(strPtrOfHead1!=strPtrOfHead2)
        {
            strPtrOfHead1=strPtrOfHead1->next;
            strPtrOfHead2=strPtrOfHead2->next;
        }
        
        return strPtrOfHead1->data;
    }
    
    else
    {
        int mainLen=len2-len1;
        Node *strPtrOfHead2=reset(head2,mainLen);
        Node *strPtrOfHead1=head1;
        
        while(strPtrOfHead1!=strPtrOfHead2)
        {
            strPtrOfHead1=strPtrOfHead1->next;
            strPtrOfHead2=strPtrOfHead2->next;
        }
        
        return strPtrOfHead2->data;
    }
}