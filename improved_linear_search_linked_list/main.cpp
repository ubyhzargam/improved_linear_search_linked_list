//
//  main.cpp
//  improved_linear_search_linked_list
//
//  Created by Uby H on 14/07/23.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*first=NULL;
void create(int A[],int n)
{
    Node *t,*last;
    first=(Node*)malloc(sizeof(Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(Node*)malloc(sizeof(Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
struct Node * search(struct Node *p, int key)
{
    struct Node *q=NULL;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
int main()
{
    int n,key;
    cout<<"Enter the number of elements in the linked list : "<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter the elements in the linked list : "<<endl;
    for(int i=0;i<n;i++)cin>>A[i];
    create(A,n);
    cout<<"Enter the key element to be searched for in the array : "<<endl;
    cin>>key;
    search(first,key);
    display(first);
}
