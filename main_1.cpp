#include <iostream>
using namespace std;

struct Node
{
    string role;
    string NmPlayer;
    Node *next, *child;
} * parentHead, *parentTail;

// deklarasi var bantu
Node *cur, *temp, *bef, *del;
// deklarasi striker
Node *tailStriker;
// deklarasi midfielder
Node *tailMidfielder;
// deklarasi defender
Node *tailDefender;
// deklarasi goalkeeper
Node *tailGoalkeeper;

bool checkLocalPlayer(string OutPlayer, string role)
{
    cur = parentHead;
    int a = 0;
    while (cur != NULL)
    {
        if (cur->role == role)
        {
            temp = cur->child;
            while (temp != NULL)
            {
                if (temp->NmPlayer == OutPlayer)
                {
                    return true;
                    a = 1;
                }
                temp = temp->child;
            }
        }
        cur = cur->next;
    }
    if (a == 0)
    {
        return false;
    }
    return 0;
}

// create parent
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
// end functions create parent

// add striker
void tambah_striker(Node *node, string InName)
{
    cur = parentHead;
    while (cur != NULL)
    {
        if (cur->role == "striker")
        {
            node = new Node;
            node->NmPlayer = InName;
            node->child = NULL;
            if (tailStriker == NULL)
            {
                cur->child = node;
                tailStriker = node;
            }
            else
            {
                tailStriker->child = node;
                tailStriker = node;
            }
        }
        cur = cur->next;
    }
}

void subtitusi_striker(Node *node, string OutPlayer, string InPlayer)
{
    if (!checkLocalPlayer(OutPlayer, "striker"))
    {
        cout << "Data tidak ditemukan" << endl;
    }
    else
    {
        cur = parentHead;
        while (cur != NULL)
        {
            temp = cur;
            if (cur->role == "striker")
            {
                if (OutPlayer == tailStriker->NmPlayer)
                {
                    while (temp->child != tailStriker)
                    {
                        temp = temp->child;
                    }
                    del = temp->child;
                    node = new Node;
                    node->NmPlayer = InPlayer;
                    node->child = NULL;
                    temp->child = node;
                    delete del;
                }
                else
                {
                    while (temp != NULL)
                    {
                        if (temp->child->NmPlayer == OutPlayer)
                        {
                            bef = temp;
                        }
                        if (temp->NmPlayer == OutPlayer)
                        {
                            del = temp;
                            break;
                        }
                        temp = temp->child;
                    }
                    node = new Node;
                    node->NmPlayer = InPlayer;
                    bef->child = node;
                    node->child = del->child;
                    del->child = NULL;
                    delete del;
                }
            }
            cur = cur->next;
        }
    }
}

// Print All
void printAll()
{
    cur = parentHead->next;
    while (cur != NULL)
    {
        temp = cur->child;
        cout << "Parent: " << cur->role << endl;
        while (temp != NULL)
        {
            cout << temp->NmPlayer << endl;
            temp = temp->child;
        }
        cur = cur->next;
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

    tambah_striker(temp, "Lucky");
    tambah_striker(temp, "Alma");
    tambah_striker(temp, "Aficionado");
    tambah_striker(temp, "Rigel");

    subtitusi_striker(temp, "Rigel", "XXXX");

    printAll();
    return 0;
}
