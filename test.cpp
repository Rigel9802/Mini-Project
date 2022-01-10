#include <iostream>
using namespace std;

struct Node
{
    string a;
    Node *next;
}*head, *tail;

void input(string a)
{
    head = new Node;
    head->a = a;
    head->next = NULL;
    if (head != NULL)
    {
        head = tail;
    }else{
        tail->next = head;
        
    }
    
}

int main()
{
    input("a")
}