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

Node *ReverseByN(Node *head,int n)
{
    Node *ptr=head;

    for(int i=0;i<n;i++)
    {
        ptr=ptr->next;
    }
    Node *q=ptr->back;
    
    q->next=NULL;
    ptr->back=NULL;

    while(q->back!=NULL)
    {
      q=q->back;
    }
    
    head=ptr;

    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    
    ptr->next=q;

    return head;
    
}

int main()
{
  int A[]={1,2,3,4,5,6};
  int n=sizeof(A)/sizeof(A[0]);
  Node *head=NULL;
  
  head=createDLL(head,A,n);
  
  Display(head);
  int N=1;
  head=ReverseByN(head,N);
  Display(head);

}