
#include<iostream>
#include<cstdlib>
#include<malloc.h>
using namespace std;
class node
{
    public:
    int info;
    struct node *next;
};
class stack{
    struct node *top;
    public:
        stack();
        void push();
        void pop();
        void display();
};
stack::stack(){
    top = NULL;
}
void stack::push(){
    int data;
     node *p;
    if((p=(node*)malloc(sizeof(node)))==NULL){
        cout<<"Memory Exhausted";
        exit(0);
    }
    cout<<"Enter a Number to insert:";
    cin>>data;
    p = new node;
    p->info = data;
    p->next = NULL;
    if(top!=NULL){
        p->next = top;
    }
    top = p;
    cout<<"\nNew item inserted"<<endl;
}
void stack::pop(){
    node *temp;
    if(top==NULL)
        {
        cout<<"\nThe stack is Empty"<<endl;
        }
    else
        {
        temp = top;
        top = top->next;
        cout<<"\nThe value popped is "<<temp->info<<endl;
        delete temp;
    }
}
void stack::display(){
    node *p = top;
    if(top==NULL)
            {
             cout<<"\nNothing to Display\n";
              }
    else
        {
        cout<<"\nThe contents of Stack\n";
        while(p!=NULL){
            cout<<p->info<<endl;
            p = p->next;
        }
    }
}
int main(){
    stack s;
    int choice;
    do{
        cout<<"\nEnter your choice:";
        cout<<"\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n";
        cin>>choice;
        switch(choice){
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"Invalid Choice";
                break;
        }
    }while(choice);
    return 0;
}
