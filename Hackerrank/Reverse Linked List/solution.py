def reverse(head):
    
    #base conditions
    #if head is None or empty return None
    if head is None:
        return None
    #when there is 1 element in list then return head i.e. same list
    if head.next is None:
        return head
        
    #call recursion to next element
    smallOut = reverse(head.next)
    #connect head.next.next = head 
    #or last element in reversed linked list to current element
    head.next.next = head
    
    #last elment.next = None or end of reversed linked list
    head.next = None
    
    #return reversed linked list
    return smallOut
