#include <iostream>
using namespace std;

struct Node
{
    string nama_pemain, role;
    int no_punggung;
    Node *next, *child, *parent;
};

// deklarasi start
Node *start;

// deklarasi Child dan parent
Node *newParent;

// deklarasi HeadRole
Node *headStriker, *headMildfilder, *headDefender, *headGoalkeeper;

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
    return newParent;
}

Node *createChild(Node *node, string nama_pemain, int no_punggung)
{
    newChild = new Node;
    newChild->nama_pemain = nama_pemain;
    newChild->no_punggung = no_punggung;
    node->child = newChild;
    newChild->child = NULL;
    return newChild;
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

void tambahStriker()

    void printLocalChild(Node *node)
{
    cur = node;
    cout << "\nposisi: " << node->role << endl;
    cout << endl;
    while (cur->child != NULL)
    {
        cout << "nama pemain: " << cur->child->nama_pemain << endl;
        cout << "no punggung: " << cur->child->no_punggung << endl;
        cout << endl;
        cur = cur->child;
    }
}

int main()
{
    Node *temp, *Striker, *MidFielder, *Defender, *Goalkeeper;
    Node *P1, *P2, *P3, *P4, *P5, *P6, *P7, *P8, *P9, *P10, *P11;
    createStart("start");
    Striker = createParent(start, "Striker");
    MidFielder = createParent(Striker, "MidFielder");
    Defender = createParent(MidFielder, "Defender");
    Goalkeeper = createParent(Defender, "Goalkeeper");
    printParent();

    P1 = createChild(Striker, "lucky", 10);
    P2 = createChild(P1, "alma", 11);
    printLocalChild(Striker);

    cout << "lmao" << endl;

    return 0;
}