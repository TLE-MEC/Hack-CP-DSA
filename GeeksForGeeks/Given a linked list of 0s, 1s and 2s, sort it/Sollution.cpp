
    Node* segregate(Node *head) {
//Intillizing three Variable with Specific Which We Will Increment When We Get the Exact Number and At last we make the LL with this Updated Variable Which Will
// Easily Sort Our LinkedList        
        int zero=0;
        int one=0;
        int two=0;
        //Need An Pointer to Traverse
        Node *ptr=head;
        
//Started Traversing to the Complete LL.
        while(ptr)
        {
//Updating the Specific Variables When We Are Geting exact Value
            if(ptr->data==0)
            {
              zero++;
              ptr=ptr->next;
            }
            else if(ptr->data==1)
            {
                one++;
                ptr=ptr->next;
            }
            else if(ptr->data==2)
            {
                two++;
                ptr=ptr->next;
            }
        }
        //Reseting the Pointer
        ptr=head;
//Started Making Sorted the LL.
        while(ptr)
        {
            if(zero!=0)
            {
                ptr->data=0;
                ptr=ptr->next;
                zero--;
            }
            else if(one!=0)
            {
                ptr->data=1;
                ptr=ptr->next;
                one--;
            }
            else if(two!=0)
            {
                ptr->data=2;
                ptr=ptr->next;
                two--;
            }
        }
//Return the Starting Address        
        return head;
        }
        
    
};