#include <iostream>
using namespace std;

struct Node
{
    string nama_pemain, role;
    int no_punggung;
    Node *next, *child, *parent;
};

// deklarasi variable bantu
Node *cur;

// deklarasi start
Node *start;

// deklarasi Child dan parent
Node *newChild, *newParent;

void createStart(string role)
{
    if (start != NULL)
    {
        cout << "start sudah dibuat" << endl;
    }
    else
    {
        start = new Node;
        start->role = role;
        start->next = NULL;
        cout << "start berhasil dibuat" << endl;
    }
}

Node *createParent(Node *node, string role)
{
    newParent = new Node;
    newParent->role = role;
    node->next = newParent;
    newParent->next = NULL;
    newParent->child = NULL;
    cout << "parent berhasil ditambahkan" << endl;
    return newParent;
}

void printParent()
{
    cur = start;
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
    Node *temp, *Striker, *MidFielder, *Defender, *Goalkeeper;
    createStart("start");
    Striker = createParent(start, "Striker");
    MidFielder = createParent(Striker, "MidFielder");
    printParent();

    return 0;
}