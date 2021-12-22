#include <iostream>
using namespace std;

struct Node
{
    string role;
    string NmPlayer;
    int NuPlayer;
    Node *next, *child;
} * parentHead, *parentTail;

Node *cur;
// deklarasi striker
Node *headStriker = NULL, *tailStriker;

void createParent(Node *temp, string role)
{
    temp = new Node;
    temp->role = role;
    temp->next = NULL;
    temp->child = NULL;
    if (parentHead == NULL)
    {
        parentHead = temp;
        parentTail = parentHead;
    }
    else
    {
        parentTail->next = temp;
        parentTail = temp;
    }
}

void tambahStriker(Node *temp, string NmPlayer, int NuPlayer)
{
    cur = parentHead;
    while (cur != NULL)
    {
        if (cur->role == "striker")
        {
            temp = new Node;
            temp->NmPlayer = NmPlayer;
            temp->NuPlayer = NuPlayer;
            if (headStriker == NULL)
            {
                cur->child = temp;
                temp->child = NULL;
                headStriker = temp;
                tailStriker = headStriker;
            }
            else
            {
                temp->child = NULL;
                tailStriker->child = temp;
                tailStriker = temp;
            }
        }
        cur = cur->next;
    }
}

void printParent(Node *temp)
{
    cout << endl;
    temp = parentHead;
    while (temp != NULL)
    {
        cout << temp->role;
        if (temp->next == NULL)
        {
            break;
        }
        cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
    cout << endl;
}

void printLocalChild(Node *temp, string role)
{
    temp = parentHead;
    while (temp != NULL)
    {
        if (temp->role == role)
        {
            cout << "parent: " << temp->role << endl;
            if (temp->child != NULL)
            {
                cur = temp->child;
                while (cur != NULL)
                {
                    cout << cur->NmPlayer << endl;
                    cur = cur->child;
                }
            }
            else
            {
                cout << "kosong" << endl;
            }
        }
        temp = temp->next;
    }
}

int main()
{
    Node *temp;
    createParent(temp, "head");
    createParent(temp, "striker");
    createParent(temp, "midfielder");
    createParent(temp, "defender");
    createParent(temp, "goalkeeper");

    tambahStriker(temp, "a", 10);
    tambahStriker(temp, "b", 10);

    printLocalChild(temp, "striker");
    return 0;
}