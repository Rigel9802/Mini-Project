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
// deklarasi midfielder
Node *headMidfielder = NULL, *tailMidfielder;
// deklarasi defender
Node *headDefender = NULL, *tailDefender;
// deklarasi goalkeeper
Node *headGoalkeeper = NULL, *tailGoalkeeper;

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

// start functions checkChild
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
// end functions check child

// striker functions
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

// midfielder functions
void tambahMidfielder(Node *temp, string NmPlayer, int NuPlayer)
{
    cur = parentHead;
    while (cur != NULL)
    {
        if (cur->role == "midfielder")
        {
            temp = new Node;
            temp->NmPlayer = NmPlayer;
            temp->NuPlayer = NuPlayer;
            if (headMidfielder == NULL)
            {
                cur->child = temp;
                temp->child = NULL;
                headMidfielder = temp;
                tailMidfielder = headMidfielder;
            }
            else
            {
                temp->child = NULL;
                tailMidfielder->child = temp;
                tailMidfielder = temp;
            }
        }
        cur = cur->next;
    }
}

// defender functions
void tambahDefender(Node *temp, string NmPlayer, int NuPlayer)
{
    cur = parentHead;
    while (cur != NULL)
    {
        if (cur->role == "defender")
        {
            temp = new Node;
            temp->NmPlayer = NmPlayer;
            temp->NuPlayer = NuPlayer;
            if (headDefender == NULL)
            {
                cur->child = temp;
                temp->child = NULL;
                headDefender = temp;
                tailDefender = headDefender;
            }
            else
            {
                temp->child = NULL;
                tailDefender->child = temp;
                tailDefender = temp;
            }
        }
        cur = cur->next;
    }
}

// defender functions
void tambahGoalkeeper(Node *temp, string NmPlayer, int NuPlayer)
{
    cur = parentHead;
    while (cur != NULL)
    {
        if (cur->role == "goalkeeper")
        {
            temp = new Node;
            temp->NmPlayer = NmPlayer;
            temp->NuPlayer = NuPlayer;
            cur->child = temp;
            temp->child = NULL;
            headGoalkeeper = temp;
            tailGoalkeeper = tailGoalkeeper;
        }
        cur = cur->next;
    }
}

// data terahkir
void subtitusi_striker(Node *temp, string OutPlayer, string InPlayer, int NuPlayer)
{
    // cek apakah data memiliki nama anak yang dicari
    if (!checkChild(temp, OutPlayer, "striker"))
    {
        cout << "data tidak ditemukan" << endl;
    }
    else
    {
        // cek apakah data yang ingin di subtitusi data terahir
        if (OutPlayer == tailStriker->NmPlayer)
        {
            cur = headStriker;
            while (cur->child != tailStriker)
            {
                cur = cur->child;
            }
            temp = new Node;
            temp->NmPlayer = InPlayer;
            temp->NuPlayer = NuPlayer;
            cur->child = temp;
            temp->child = NULL;
            tailStriker = temp;
        }
        // jika tidak lakukan ini
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
    cout << "\n";
    while (temp != NULL)
    {
        if (temp->role == role)
        {
            cout << "Posisi: " << temp->role << endl;
            if (temp->child != NULL)
            {
                cur = temp->child;
                while (cur != NULL)
                {
                    cout << "(" << cur->NuPlayer << ") " << cur->NmPlayer << endl;
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

    tambahStriker(temp, "Del Pino", 11);
    tambahStriker(temp, "Marti", 9);

    tambahMidfielder(temp, "Gassama", 8);
    tambahMidfielder(temp, "Gaspar", 12);
    tambahMidfielder(temp, "Camacho", 10);
    tambahMidfielder(temp, "Ros", 6);

    tambahDefender(temp, "Galves", 12);
    tambahDefender(temp, "Alvarez", 2);
    tambahDefender(temp, "Morillas", 3);
    tambahDefender(temp, "Garcia", 5);

    tambahGoalkeeper(temp, "Jiminez", 1);

    printLocalChild(temp, "striker");
    printLocalChild(temp, "midfielder");
    printLocalChild(temp, "defender");
    printLocalChild(temp, "goalkeeper");

    cout << endl;

    return 0;
}