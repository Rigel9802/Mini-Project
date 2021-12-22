#include <iostream>
using namespace std;

struct Node
{
    string role;
    string NmPlayer;
    int NuPlayer;
    Node *next, *child;
} * parentHead, *parentTail;

// deklarasi var bantu
Node *cur, *temp, *bef, *del;
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

bool checkChild(Node *temp, string checkPlayer, string role)
{
    temp = parentHead;
    int a = 0;
    while (temp != NULL)
    {
        if (temp->role == role)
        {
            if (temp->child != NULL)
            {
                cur = temp->child;
                while (cur != NULL)
                {
                    if (cur->NmPlayer == checkPlayer)
                    {
                        return true;
                        a = 1;
                        break;
                    }
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
    if (a == 0)
    {
        return false;
    }
    return 0;
}

// data terahkir
void subtitusi_striker(Node *temp, string OutPlayer, string InPlayer, int NuPlayer)
{
    if (!checkChild(temp, OutPlayer, "striker"))
    {
        cout << "data tidak ditemukan" << endl;
    }
    else
    {
        cur = parentHead;
        while (cur != NULL)
        {
            temp = cur;
            if (cur->role == "striker")
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
                cout << "bef : " << bef->NmPlayer << endl;
                cout << "del : " << del->NmPlayer << endl;
                temp = new Node;
                temp->NmPlayer = InPlayer;
                temp->NuPlayer = NuPlayer;
                bef->child = temp;
                temp->child = del->child;
                del->child = NULL;
                delete del;
            }
            cur = cur->next;
        }
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

    printParent(temp);
    tambahStriker(temp, "a", 10);
    tambahStriker(temp, "b", 20);
    tambahStriker(temp, "c", 30);
    tambahStriker(temp, "d", 40);

    printLocalChild(temp, "striker");

    subtitusi_striker(temp, "ca", "z", 100);

    printLocalChild(temp, "striker");

    cout << "kalo ini di cetak data no bug" << endl;

    return 0;
}