class Solution {
    ListNode sorted;
        public ListNode insertionSortList(ListNode head) {
    
        
            // Initialize sorted linked list
       sorted = null;
            ListNode current = head;
            // Traverse the given linked list and insert every
            // node to sorted
            while (current != null)
            {
                // Store next for next iteration
                    ListNode next = current.next;
                // insert current in sorted linked list
                sortedInsert(current);
                // Update current
                current = next;
            }
            // Update head_ref to point to sorted linked list
            head = sorted;
    return head;
        }
     
        /*
         * function to insert a new_node in a list. Note that
         * this function expects a pointer to head_ref as this
         * can modify the head of the input linked list
         * (similar to push())
         */
        void sortedInsert(ListNode newnode)
        {
            /* Special case for the head end */
    
            if (sorted == null || sorted.val >= newnode.val)
            {
                newnode.next = sorted;
                sorted = newnode;
            }
            else
            {
               ListNode current = sorted;
                /* Locate the node before the point of insertion */
                while (current.next != null && current.next.val < newnode.val)
                {
                    current = current.next;
                }
                newnode.next = current.next;
                current.next = newnode;
            }
        }
    }