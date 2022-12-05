#include<bits/stdc++.h>
#include <numeric>
#define pb push_back
#define pob pop_back()
#define mp make_pair
#define all(v) v.begin(),v.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fin(i,n1,n2);for(ll i=n1;i<n2;i++)
#define fde(i,n1,n2);for(ll i=n1;i>n2;i--)
#define M 1000000007
using ll=long long;
using ld=long double;
using namespace std;
//Arpcoder


bool comp(pair <ll,ll> &a,pair <ll,ll> &b)
{
    if(a.first!=b.first)
    return a.first>b.first;
    else return a.second<b.second;
}

class Node
{
   public:
   ll data;
   Node *next;
   Node *prev;
   
   Node(ll Data)
   {
       data=Data;
       next=NULL;
       prev=NULL;
   }
};

void print(Node *&head)//passing by reference is not necessary as we r not making any changes
{
    Node *temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

void InsertAtHead(Node *&head,ll d)
{
    if(head==NULL)
    {
       Node *NodeToInsert=new Node(d);
       head=NodeToInsert;
       return;
    }
    Node *NodeToInsert=new Node(d);
    NodeToInsert->next=head;
    head->prev=NodeToInsert;
    head=NodeToInsert;
}


void InsertAtTail(Node *&tail,ll d)
{
    if(tail==NULL)
    {
       Node *NodeToInsert=new Node(d);
       tail=NodeToInsert;
       return;
    }
    Node *NodeToInsert=new Node(d);
    tail->next=NodeToInsert;
    NodeToInsert->prev=tail;
    tail=NodeToInsert;
}

void InsertAtPosition(Node *&head,Node *&tail,ll d,ll pos)
{
    if(pos==1)
    {
        InsertAtHead(head,d);
        return;
    }
    
    Node *temp=head;
    ll cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        InsertAtTail(tail,d);
        return;
    }
    Node *NodeToInsert=new Node(d);
    NodeToInsert->next=temp->next;
    NodeToInsert->prev=temp;
    temp->next=NodeToInsert;
    NodeToInsert->next->prev=NodeToInsert;
}

void deleteNode(Node *&head,ll pos)
{
    if(pos==1)
    {
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        return;
    }
    Node *p=head;
    Node *q=head->next;
    ll cnt=1;
    while(cnt<pos-1)
    {
        q=q->next;
        p=p->next;
        cnt++;
    }
    
    p->next=q->next;
    if(q->next!=NULL) //this statement throws error for tail elements ,thats why tail elements are not included via this condition;
    q->next->prev=p;//for tail elements NULL->prev is not defined;
    free(q);
}


int main()
{
    Node *node1=new Node(2);
    Node *head=node1;
    Node *tail=node1;
    InsertAtTail(tail,3);
    print(head);
    InsertAtHead(head,1);
    print(head);
    InsertAtPosition(head,tail,4,2);
    print(head);
    //cout<<tail->data;
    deleteNode(head,2);
    print(head);
    deleteNode(head,3);
    print(head);
    //deleteNode(head,)
}
