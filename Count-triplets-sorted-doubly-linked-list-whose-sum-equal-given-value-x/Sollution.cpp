#include<iostream>
using namespace std;

class Node
{
    public:
    Node *back;
    Node *next;
    int data;
};

Node *createDLL(Node *head,int A[],int n)
{
    Node *current=NULL;
    if(head==NULL)
    {
        head=new Node;
        head->data=A[0];
        head->back=NULL;
        head->next=NULL;
        current=head;
    }
            for(int i=1;i<n;i++)
        {
            Node *temp=new Node;
            temp->data=A[i];
            current->next=temp;
            temp->back=current;
            current=current->next;

            temp->next=NULL;
        }
    return head;
}

void Display(Node *head)
{
    Node *ptr=head;
    while(ptr)
    {
        cout<<ptr->data<<"<->";
        ptr=ptr->next;
    }
    cout<<endl;
}

void FindTripletOfSum(Node *head,int key)
{
    Node *start=head;
    Node *mid=head;
    Node *end=head;

    while(end->next!=NULL)
    {
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

int main()
{
  int A[]={1,2,4,5,6,8,9};
  int n=sizeof(A)/sizeof(A[0]);
  Node *head=NULL;
  
  head=createDLL(head,A,n);
  Display(head);
   int key=17;
  FindTripletOfSum(head,key);
}