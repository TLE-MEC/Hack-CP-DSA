// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        
        vector<int> odd;
        vector<int> even;
        
        Node *ptr=head;
        while(ptr)
        {
          if(ptr->data%2==0)
          {
              even.push_back(ptr->data);
          }
          else
          {
              odd.push_back(ptr->data);
          }
          ptr=ptr->next;
        }
        
        ptr=NULL;
        Node * current=NULL;
        
        for(int i=0;i<even.size();i++)
        {
            Node *temp=new Node(even[i]);
            temp->next=NULL;
            
            if(ptr==NULL)
            {
                ptr=current=temp;
            }
            else
            {
                current->next=temp;
                current=temp;
            }
        }
        
        for(int i=0;i<odd.size();i++)
        {
            Node *temp=new Node(odd[i]);
            temp->next=NULL;
            
            if(ptr==NULL)
            {
                ptr=current=temp;
            }
            else
            {
                current->next=temp;
                current=temp;
            }
        }
        
        
        // code here
        head=ptr;
        return head;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends