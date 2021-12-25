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

bool checkAllPlayer(string InName)
{
    cur = parentHead->next;
    int a = 0;
    while (cur != NULL)
    {
        temp = cur;
        while (temp != NULL)
        {
            if (InName == temp->NmPlayer)
            {
                a = 1;
                return true;
            }
            temp = temp->child;
        }
        cur = cur->next;
    }
    if (a == 0)
    {
        return false;
    }
    return 0;
}

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
    if (checkAllPlayer(InName))
    {
        cout << "Pemain sudah dilapangan" << endl;
    }
    else
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
                // cout << InName << " memasuki lapangan" << endl;
            }
            cur = cur->next;
        }
    }
}

// add striker
void tambah_midfielder(Node *node, string InName)
{
    if (checkAllPlayer(InName))
    {
        cout << "Pemain sudah dilapangan" << endl;
    }
    else
    {
        cur = parentHead;
        while (cur != NULL)
        {
            if (cur->role == "midfielder")
            {
                node = new Node;
                node->NmPlayer = InName;
                node->child = NULL;
                if (tailMidfielder == NULL)
                {
                    cur->child = node;
                    tailMidfielder = node;
                }
                else
                {
                    tailMidfielder->child = node;
                    tailMidfielder = node;
                }
                // cout << InName << " memasuki lapangan" << endl;
            }
            cur = cur->next;
        }
    }
}

// hapus striker
void hapus_striker(string OutPlayer)
{
    if (!checkLocalPlayer(OutPlayer, "striker"))
    {
        cout << "pemain tidak ditemukan" << endl;
    }
    else
    {
        cur = parentHead;
        while (cur != NULL)
        {
            if (cur->role == "striker")
            {
                temp = cur;
                if (OutPlayer == tailStriker->NmPlayer)
                {
                    while (temp->child != tailStriker)
                    {
                        temp = temp->child;
                    }
                    del = temp->child;
                    temp->child = NULL;
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
                    bef->child = del->child;
                    del->child = NULL;
                    delete del;
                }
            }
            cur = cur->next;
        }
    }
}

// subtitus striker
void subtitusi_striker(Node *node, string OutPlayer, string InPlayer)
{
    if (!checkLocalPlayer(OutPlayer, "striker"))
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

// tampil striker()
void tampil_striker()
{
    cur = parentHead;
    while (cur != NULL)
    {
        if (cur->role == "striker")
        {
            cout << "Role: ";
            temp = cur->child;
            while (temp != NULL)
            {
                cout << temp->NmPlayer;
                if (temp->child == NULL)
                {
                    break;
                }
                cout << " -> ";
                temp = temp->child;
            }
            break;
        }
        cur = cur->next;
    }
}

void printAlamat(Node *node)
{
    while (node->child->child != NULL)
    {
        node = node->child;
    }
    del = node->child;
    node->child = NULL;
    cout << del->NmPlayer << "berhasi dihapus" << endl;
    delete del;
}

void hapus_pemain(Node *node)
{
    cur = parentHead;
    while (cur != NULL)
    {
        temp = cur;
        while (temp->child != NULL)
        {
            printAlamat(cur);
        }
        cur = cur->next;
    }
}

// Print All
void printAll()
{
    cur = parentHead->next;
    while (cur != NULL)
    {
        temp = cur->child;
        cout << cur->role << " : ";
        while (temp != NULL)
        {
            cout << temp->NmPlayer;
            if (temp->child == NULL)
            {
                break;
            }
            cout << " -> ";
            temp = temp->child;
        }
        cout << endl;
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

    tambah_midfielder(temp, "Deniz");
    tambah_midfielder(temp, "Ghallen");
    tambah_midfielder(temp, "Putra");
    tambah_midfielder(temp, "Rachmat");

    // tambah_striker(temp, "Alma");

    // hapus_striker("Rigel");
    // subtitusi_striker(temp, "Rigel", "XXXX");

    // checkAllPlayer("Rigel");
    // tampil_striker();
    hapus_pemain(parentHead);
    printAll();
    return 0;
}
