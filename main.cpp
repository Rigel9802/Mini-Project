#include <iostream>
using namespace std;

struct Node
{
    string nama_pemain, role;
    int no_punggung;
    Node *next, *child;
};

// deklarasi variable bantu
Node *cur;

// deklarasi Root
Node *newParent, *headParent, *tailParent;

void createRoot(Node *temp, string role)
{
    temp = new Node;
    temp->role = role;
    temp->next = NULL;
    temp->child = NULL;
    if (headParent == NULL)
    {
        headParent = temp;
        tailParent = temp;
    }
    else
    {
        tailParent->next = temp;
        tailParent = temp;
    }
}

void addChild(string InRole, string nama_pemain, int no_punggung)
{
    cur = headParent;
    while (cur != NULL)
    {
        if (cur->role == InRole)
        {
            // check apakah punya node child
            if (cur->child == NULL)
            {
                cout << "null nih" << endl;
            }
        }
        cur = cur->next;
    }
}

void printParent()
{
    cur = headParent;
    while (cur != NULL)
    {
        cout << cur->role;
        if (cur->next == NULL)
        {
            break;
        }
        cout << " -> ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    Node *temp;
    createRoot(temp, "start");
    createRoot(temp, "mildfilder");
    createRoot(temp, "keeper");
    printParent();

    addChild("mildfilder", "ibrahimovic", 18);
    return 0;
}