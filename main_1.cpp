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

// ======== STRIKER ==========
void tambah_striker(Node *node, string InPlayer);
void hapus_striker(string OutPlayer);
void subtitusi_striker(Node *node, string OutPlayer, string InPlayer);
void tampil_striker();
// ======== MIDFIELDER ==========
void tambah_midfielder(Node *node, string InPlayer);
void hapus_midfielder(string OutPlayer);
void subtitusi_midfielder(Node *node, string OutPlayer, string InPlayer);
void tampil_midfielder();
// ======== DEFENDER ============
void tambah_defender(Node *node, string InPlayer);
void hapus_defender(string OutPlayer);
void subtitusi_defender(Node *node, string OutPlayer, string InPlayer);
void tampil_defender();
// ======= EXTENSIONS ===========
void tampil_pemain();
void hapus_pemain();
void cari_pemain();

int main()
{
    int option;
    Node *temp;
    createParent(temp, "head");
    createParent(temp, "striker");
    createParent(temp, "midfielder");
    createParent(temp, "defender");
    createParent(temp, "goalkeeper");

    do
    {
        cout << "1.  Tambah striker" << endl;
        cout << "2.  Hapus striker" << endl;
        cout << "3.  Subtitusi striker" << endl;
        cout << "4.  Tampil striker" << endl;
        cout << "5.  Tambah midfielder" << endl;
        cout << "6.  Hapus midfielder" << endl;
        cout << "7.  Subtitusi midfielder" << endl;
        cout << "8.  Tampil midfielder" << endl;
        cout << "9.  Tambah defender" << endl;
        cout << "10. Hapus defender" << endl;
        cout << "11. Subtitusi defender" << endl;
        cout << "12. Tampil defender" << endl;
        cout << "13. Tampil pemain" << endl;
        cout << "14. Hapus pemain" << endl;
        cout << "15. Cari pemain" << endl;
        cout << "Masukan pilihan anda";
        cin >> option;
        switch (option)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 8:
            /* code */
            break;
        case 9:
            /* code */
            break;
        case 10:
            /* code */
            break;
        case 11:
            /* code */
            break;
        case 12:
            /* code */
            break;
        case 13:
            /* code */
            break;
        case 14:
            /* code */
            break;
        case 15:
            /* code */
            break;
        default:
            break;
        }
    } while (option < 16);

    // tambah_striker(temp, "Lucky");
    // tambah_striker(temp, "Alma");
    // tambah_striker(temp, "Aficionado");
    // tambah_striker(temp, "Rigel");

    // tambah_midfielder(temp, "Deniz");
    // tambah_midfielder(temp, "Ghallen");
    // tambah_midfielder(temp, "Putra");
    // tambah_midfielder(temp, "Rachmat");

    // tambah_defender(temp, "Carlota");
    // tambah_defender(temp, "Maccacio");
    // tambah_defender(temp, "Mauren");
    // tambah_defender(temp, "Lota");

    // tambah_goalkeeper(temp, "ASZ");
    // tambah_striker(temp, "Alma");

    // hapus_striker("Lucky");
    // hapus_midfielder("Deniz");
    // hapus_defender("Carlota");
    // subtitusi_striker(temp, "Lucky", "Alma");
    // subtitusi_midfielder(temp, "Rachmat", "Rachmat");
    // subtitusi_defender(temp, "Mauren", "Lota");

    // checkAllPlayer("Rigel");
    // cari_pemain("Lota");
    // hapus_pemain(parentHead);
    // printAll();
    return 0;
}

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

void cari_pemain(string find_player)
{
    cur = parentHead->next;
    while (cur != NULL)
    {
        temp = cur->child;
        while (temp != NULL)
        {
            if (temp->NmPlayer == find_player)
            {
                cout << temp->NmPlayer << " berada dilapangan dengan role " << cur->role;
            }
            temp = temp->child;
        }
        cur = cur->next;
    }
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

// add defender
void tambah_defender(Node *node, string InName)
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
            if (cur->role == "defender")
            {
                node = new Node;
                node->NmPlayer = InName;
                node->child = NULL;
                if (tailDefender == NULL)
                {
                    cur->child = node;
                    tailDefender = node;
                }
                else
                {
                    tailDefender->child = node;
                    tailDefender = node;
                }
                // cout << InName << " memasuki lapangan" << endl;
            }
            cur = cur->next;
        }
    }
}

// add goalkeeper
void tambah_goalkeeper(Node *node, string InName)
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
            if (cur->role == "goalkeeper")
            {
                node = new Node;
                node->NmPlayer = InName;
                node->child = NULL;
                cur->child = node;
                tailGoalkeeper = node;
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

// hapus midfielder
void hapus_midfielder(string OutPlayer)
{
    if (!checkLocalPlayer(OutPlayer, "midfielder"))
    {
        cout << "pemain tidak ditemukan" << endl;
    }
    else
    {
        cur = parentHead;
        while (cur != NULL)
        {
            if (cur->role == "midfielder")
            {
                temp = cur;
                if (OutPlayer == tailMidfielder->NmPlayer)
                {
                    while (temp->child != tailMidfielder)
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

// hapus midfielder
void hapus_defender(string OutPlayer)
{
    if (!checkLocalPlayer(OutPlayer, "defender"))
    {
        cout << "pemain tidak ditemukan" << endl;
    }
    else
    {
        cur = parentHead;
        while (cur != NULL)
        {
            if (cur->role == "defender")
            {
                temp = cur;
                if (OutPlayer == tailDefender->NmPlayer)
                {
                    while (temp->child != tailDefender)
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
        if (checkAllPlayer(InPlayer))
        {
            cout << "pemain sudah dilapangan" << endl;
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
}

// subtitus midfielder
void subtitusi_midfielder(Node *node, string OutPlayer, string InPlayer)
{
    if (!checkLocalPlayer(OutPlayer, "midfielder"))
    {
        cout << "data tidak ditemukan" << endl;
    }
    else
    {
        if (checkAllPlayer(InPlayer))
        {
            cout << "pemain sudah dilapangan" << endl;
        }
        else
        {
            cur = parentHead;
            while (cur != NULL)
            {
                temp = cur;
                if (cur->role == "midfielder")
                {
                    if (OutPlayer == tailMidfielder->NmPlayer)
                    {
                        while (temp->child != tailMidfielder)
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
}

// subtitus defender
void subtitusi_defender(Node *node, string OutPlayer, string InPlayer)
{
    if (!checkLocalPlayer(OutPlayer, "defender"))
    {
        cout << "data tidak ditemukan" << endl;
    }
    else
    {
        if (checkAllPlayer(InPlayer))
        {
            cout << "Pemain sudah dilapangan" << endl;
        }
        else
        {
            cur = parentHead;
            while (cur != NULL)
            {
                temp = cur;
                if (cur->role == "defender")
                {
                    if (OutPlayer == tailDefender->NmPlayer)
                    {
                        while (temp->child != tailDefender)
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
// tampil striker()
void tampil_midfielder()
{
    cur = parentHead;
    while (cur != NULL)
    {
        if (cur->role == "midfielder")
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
// tampil striker()
void tampil_defender()
{
    cur = parentHead;
    while (cur != NULL)
    {
        if (cur->role == "defender")
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

void hapusAlamat(Node *node)
{
    while (node->child->child != NULL)
    {
        node = node->child;
    }
    del = node->child;
    node->child = NULL;
    delete del;
}

void hapus_pemain(Node *node)
{
    cur = parentHead;
    while (cur != NULL)
    {
        while (cur->child != NULL)
        {
            hapusAlamat(cur);
        }
        cur = cur->next;
    }
}

// Print All
void tampil_pemain()
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
