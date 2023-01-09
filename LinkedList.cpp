#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* next;
    int data;
};                      // Creating a structure with one field containing the data and the other pointing to the next address linked
node* start=NULL;

void insert_at_beginning()
{
    int element;
    cin >> element;
    node* newnode= new node();   // Allocating space in the heap for 'newnode' using new
    newnode -> data = element;
    if(start==NULL)
    {
        newnode -> next = NULL;
        start=newnode;
    }
    else
    {
        newnode -> next = start;
        start=newnode;
    }
}

void insert_at_end()
{
    int element;
    cin >> element;
    node* newnode= new node();
    newnode -> data = element;
    if(start==NULL)
    {
        newnode -> next = NULL;
        start=newnode;
    }
    else 
    {
        node* temp= start;
        while(temp -> next != NULL)   // This loop terminated at the last node(now the temp pointer will be pointing to the last node)
        {
            temp =temp -> next;
        }
        newnode -> next = NULL;
        temp -> next = newnode;
    }
}

void insert_at_any_pos()
{
    int element,pos;
    cin >> element;
    node* newnode = new node();
    newnode -> data = element;
    cout << "The position at which you want to enter the node: ";
    cin >> pos;
    if (pos==1)
    {
        insert_at_beginning();
    }
    else
    {
        node* temp=start;
        pos = pos - 2;
        while(pos--)  // We have to reach at the node position previous to the node position(pos) mentioned by the user to insert the newnode
        {
            temp=temp-> next;                      
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

void delete_at_start()
{
    if(start==NULL)
    {
        cout << "The List is empty" << endl;
    }
    else
    {
        node* temp=start;
        start=start->next;
        delete temp;        // delete helps in deleting the node from the memory space in C++
    }
}

void delete_at_end()
{
    node* temp1=start;
    node* temp2;
    if (start == NULL)
    {
        cout << "The List is empty" << endl;
    }
    while(temp1 -> next != NULL)
    {
        temp2=temp1;
        temp1 = temp1 -> next;
    } // We bring the temp1 pointer to the node we want to delete and the temp2 pointer to one node before temp1 to change the next address of it to NULL in this case
    temp2 -> next=NULL;
    delete temp1;
}

void delete_at_any_pos()
{
    int pos;
    node* temp1=start;
    node* temp2;
    cout << "Enter the position of the node you want to delete: ";
    cin >> pos;
    if(pos == 1)
    {
        delete_at_start();
    }
    else
    {
        pos = pos - 1;
        while(pos--)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2 -> next = temp1 -> next;
        delete temp1;
    }
}

void print()
{
    if(start==NULL)
    {
        cout << "The list is empty"<< endl;
    }
    else 
    {
        cout << "The list is: ";
        node* temp=start;
        while(temp != NULL)
        {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << endl;
    }
}

int main()
{
    while(1)
    {
        int choice;
        cout << "Enter the choice between: \n1.Insert at start \n2.Insert at end \n3.Insert at any position \n4.Delete at start \n5.Delete at end \n6.Delete at any position \n7.Display \n8.Exit"<< endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                insert_at_beginning();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                insert_at_any_pos();
                break;
            case 4:
                delete_at_start();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                delete_at_any_pos();
                break;
            case 7:
                print();
                break;
            case 8:
                exit(0);
        }
    }
}
