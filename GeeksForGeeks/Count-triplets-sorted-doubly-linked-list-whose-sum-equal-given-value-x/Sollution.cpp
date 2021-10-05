void FindTripletOfSum(Node *head,int key)
{

//Intializing the Three Pointer Which Help Us To the Three Values Whose Sum May Give Us the Exact X.
    Node *start=head;
    Node *mid=head;
    Node *end=head;

//Traversing to the Doublly LL.
    while(end->next!=NULL)
    {
//Updateting the Pointer Next Place
        end=end->next;
    }

    while(start!=NULL)
    {
        mid=start->next;
        //cout<<start->data<<" "<<mid->data<<endl;
        while(mid!=end)
        {
            if(start->data + mid->data + end->data==key)
            {
                cout<<start->data<<" "<<mid->data<<" "<<end->data<<endl;
                 mid=mid->next;
                 end=end->back;
            }
            else if(start->data + mid->data + end->data > key)
            {
                end=end->back;
            }
            
            else if(start->data + mid->data + end->data < key)
            {
                mid=mid->next;
            }
        }
        start=start->next;
    }
}
