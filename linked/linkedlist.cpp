#include <iostream>
#include "node.cpp"
using namespace std;

node * inputll()
{
    int num;
    cin>>num;
    node*head=NULL;
    node*tail=NULL;
    while(num!=-1){
        node * current=new node(num);
        if(head==NULL){
            head=current;
            tail=head;
        }
        else{
            tail->next=current;
            tail=current;
        }
        cin>>num;
    }
    return head;
}

node*reverseitr(node*head)
{
    if(head==NULL){
        return NULL;
    }
    node*prev=NULL;
    node*curr=head;
    while(curr!=NULL){
            node*nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    return prev;
}


bool findelement(node*head,int element)
{
    if(head==NULL){
        return false;
    }
    if(head->data==element){
        return true;
    }
    return findelement(head->next,element);
}

node*reverserec(node*head)
{
    if(head==NULL||head->next==NULL){
        return head;
    }
    node*smallans=reverserec(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallans;
}

void printll(node*head)
{
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<endl;
}

node*swap2nodes(node*head,int i,int j)
{
    node*previ=NULL;
    node*curri=NULL;
    node*prevj=NULL;
    node*currj=NULL;
    node*temp=head;
    int curr=0;
    while(temp!=NULL){
            if(i-curr==1){
                previ=temp;
            }
            if(i-curr==0){
                curri=temp;
            }
            if(j-curr==1){
                prevj=temp;
            }
            if(j-curr==0){
                currj=temp;
            }
            curr++;
        temp=temp->next;
    }
    if(previ!=NULL){
        previ->next=currj;
    }
    else{
        head=currj;
    }
    if(prevj!=NULL){
        prevj->next=curri;
    }
    else{
        head=curri;
    }
    node*temparary=currj->next;
    currj->next=curri->next;
    curri->next=temparary;

    return head;

    }
int main()
{
    node*head=inputll();
    printll(head);
   // node*head2=reverserec(head);
   // printll(head2);
  //  int num;
    //cout<<"ENTER NO TO BE FOUND"<<endl;
    //cin>>num;
    //cout<<findelement(head,num);
    node*head3=swap2nodes(head,0,5);
    printll(head3);
}
