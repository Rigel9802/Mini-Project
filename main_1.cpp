#include <iostream>
using namespace std;

struct Node
{
    string role;
    string NmPlayer;
    string card;
    Node *next, *child;
} * parentHead, *parentTail;

struct Temp
{
    string data;
    Temp *next;
} * tempHead, *tempTail;

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
// deklarasi menambah role sesuai formasi
int formasi_striker = 3, count_striker = 0;
int formasi_midfielder = 3, count_midfielder = 0;
int formasi_defender = 3, count_defender = 0;

// ======== HEAD ===========
void createParent(Node *node, string Role);
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
// ======== GOALKEEPER ==========
void tambah_goalkeeper(Node *node, string InPlayer);
void subtitusi_goalkeeper(Node *node, string OutPlayer, string InPlayer);
// ======= EXTENSIONS ===========
void tampil_pemain();
void hapus_pemain(Node *node);
void cari_pemain(string FindPlayer);
void kartu_merah(string playerName);
void hapus_role(string role);

int main()
{
    int option;
    string InPlayer, OutPlayer, FindPlayer, role;
    Node *temp;
    createParent(temp, "head");
    createParent(temp, "striker");
    createParent(temp, "midfielder");
    createParent(temp, "defender");
    createParent(temp, "goalkeeper");
    tambah_goalkeeper(temp, "keeper");

    do
    {
        cout << endl;
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
        cout << "16. Masukan formasi pemain" << endl;
        cout << "17. Kartu Merah" << endl;
        cout << "18. Subtitusi Keeper" << endl;
        cout << "19. Hapus Role" << endl;
        cout << "20. EXIT" << endl;
        cout << "Masukan pilihan anda: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Masukan nama pemain: ";
            cin >> InPlayer;
            tambah_striker(temp, InPlayer);
            break;
        case 2:
            cout << "Masukan nama yang ingin keluar: ";
            cin >> OutPlayer;
            hapus_striker(OutPlayer);
            break;
        case 3:
            cout << "Masukan nama yang ingin keluar: ";
            cin >> OutPlayer;
            cout << "Masukan nama yang ingin main: ";
            cin >> InPlayer;
            subtitusi_striker(temp, OutPlayer, InPlayer);
            break;
        case 4:
            tampil_striker();
            break;
        case 5:
            cout << "Masukan nama pemain: ";
            cin >> InPlayer;
            tambah_midfielder(temp, InPlayer);
            break;
        case 6:
            cout << "Masukan nama yang ingin keluar: ";
            cin >> OutPlayer;
            hapus_midfielder(OutPlayer);
            break;
        case 7:
            cout << "Masukan nama yang ingin keluar: ";
            cin >> OutPlayer;
            cout << "Masukan nama yang ingin main: ";
            cin >> InPlayer;
            subtitusi_midfielder(temp, OutPlayer, InPlayer);
            break;
        case 8:
            tampil_midfielder();
            break;
        case 9:
            cout << "Masukan nama pemain: ";
            cin >> InPlayer;
            tambah_defender(temp, InPlayer);
            break;
        case 10:
            cout << "Masukan nama yang ingin keluar: ";
            cin >> OutPlayer;
            hapus_defender(OutPlayer);
            break;
        case 11:
            cout << "Masukan nama yang ingin keluar: ";
            cin >> OutPlayer;
            cout << "Masukan nama yang ingin main: ";
            cin >> InPlayer;
            subtitusi_defender(temp, OutPlayer, InPlayer);
            break;
        case 12:
            tampil_defender();
            break;
        case 13:
            tampil_pemain();
            break;
        case 14:
            hapus_pemain(temp);
            break;
        case 15:
            cout << "Cari pemain: ";
            cin >> FindPlayer;
            cari_pemain(FindPlayer);
            break;
        case 16:
            cout << "Formasi Striker: ";
            cin >> formasi_striker;
            cout << "Formasi Midfielder: ";
            cin >> formasi_midfielder;
            cout << "Formasi Defender :";
            cin >> formasi_defender;
            if (formasi_striker > 4 || formasi_midfielder > 4 || formasi_defender > 4)
            {
                cout << "formasi tidak dapat digunakan" << endl;
                formasi_defender = 0;
                formasi_midfielder = 0;
                formasi_striker = 0;
            }
            break;
        case 17:
            cout << "Pemain yang mendapatkan kartu merah:";
            cin >> InPlayer;
            kartu_merah(InPlayer);
            break;
        case 18:
            cout << "pemain yang ingin diganti: ";
            cin >> OutPlayer;
            cout << "Pemain yang ini masuk: ";
            cin >> InPlayer;
            subtitusi_goalkeeper(temp, OutPlayer, InPlayer);
            break;
        case 19:
            cout << "Role yang ingin dihapus: ";
            cin >> role;
            hapus_role(role);
            break;
        default:
            break;
        }
    } while (option < 20);

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
    int a = 0;
    while (cur != NULL)
    {
        temp = cur->child;
        while (temp != NULL)
        {
            if (temp->NmPlayer == find_player)
            {
                cout << temp->NmPlayer << " berada dilapangan dengan role " << cur->role;
                a = 1;
                break;
            }
            temp = temp->child;
        }
        cur = cur->next;
    }
    if (a == 0)
    {
        cout << "Pemain tidak berada dilapangan" << endl;
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
    else if (count_striker == formasi_striker)
    {
        cout << "Pemain sudah penuh" << endl;
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
                node->next = NULL;
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
                count_striker += 1;
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
    else if (count_midfielder == formasi_midfielder)
    {
        cout << "Pemain sudah penuh" << endl;
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
                node->next = NULL;
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
                count_midfielder += 1;
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
    else if (count_defender == formasi_defender)
    {
        cout << "Pemain sudah penuh" << endl;
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
                node->next = NULL;
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
                count_defender += 1;
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
                node->next = NULL;
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
                    count_striker -= 1;
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
                    count_striker -= 1;
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
                    count_midfielder -= 1;
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
                    count_midfielder -= 1;
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
                    count_defender -= 1;
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
                    count_defender -= 1;
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
                        node->next = NULL;
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
                        node->next = NULL;
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
                        node->next = NULL;
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
                        node->next = NULL;
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
                        node->next = NULL;
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
                        node->next = NULL;
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
            cout << cur->role << " : ";
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
            cout << cur->role << " : ";
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
            cout << cur->role << " : ";
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

void tampungHapus(string data)
{
    Temp *newNode = new Temp;
    newNode->data = data;
    newNode->next = NULL;
    if (tempHead == NULL)
    {
        tempHead = newNode;
        tempTail = tempHead;
    }
    else
    {
        tempTail->next = newNode;
        tempTail = newNode;
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
    tampungHapus(del->NmPlayer);
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

void subtitusi_goalkeeper(Node *node, string OutPlayer, string InPlayer)
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
            if (cur->role == "goalkeeper")
            {
                del = cur->child;
                node = new Node;
                node->NmPlayer = InPlayer;
                node->next = NULL;
                node->child = NULL;
                cur->child = node;
                node->child = del->child;
                tailGoalkeeper = node;
                delete del;
            }
            cur = cur->next;
        }
    }
}

void kartu_merah(string getCard)
{
    if (!checkAllPlayer(getCard))
    {
        cout << "pemain tidak ditemukan" << endl;
    }
    else if (getCard == tailGoalkeeper->NmPlayer)
    {
        temp = tailGoalkeeper;
        if (temp->card == "")
        {
            temp->card = "kuning";
        }
        else
        {
            string InPlayer;
            cout << "player yang menggantikan : ";
            cin >> InPlayer;
            subtitusi_goalkeeper(temp, getCard, InPlayer);
        }
    }
    else
    {
        cur = parentHead;
        while (cur != NULL)
        {
            temp = cur->child;
            while (temp != NULL)
            {
                if (temp->NmPlayer == getCard)
                {
                    if (temp->card == "")
                    {
                        temp->card = "kuning";
                    }
                    else if (temp->card == "kuning")
                    {
                        cout << cur->role << endl;
                        while (cur != NULL)
                        {
                            if (cur->child->NmPlayer == getCard)
                            {
                                bef = cur;
                                del = bef->child;
                                break;
                            }
                            cur = cur->child;
                        }
                        bef->child = del->child;
                        del->child = NULL;
                        delete del;
                    }
                }
                temp = temp->child;
            }
            cur = cur->next;
        }
    }
}

void print_card()
{
    cur = parentHead;
    while (cur != NULL)
    {
        temp = cur;
        while (temp != NULL)
        {
            cout << temp->NmPlayer << " " << temp->card << endl;
            temp = temp->child;
        }
        cur = cur->next;
        /* code */
    }
}

void hapus_role(string role)
{
    if (role == "goalkeeper")
    {
        cout << "Goalkeeper tidak dapat dihapus" << endl;
    }
    else
    {
        cur = parentHead;
        while (cur != NULL)
        {
            if (cur->next->role == role)
            {
                bef = cur;
            }
            if (cur->role == role)
            {
                del = cur;
                break;
            }
            cur = cur->next;
        }
        bef->next = del->next;
        del->next = NULL;
        delete del;
    }
}

void tampilHapus()
{
    Temp *cur = tempHead;
    while (cur != NULL)
    {
        cout << cur->data;
        cur = cur->next;
    }
    cout << "endl" << endl;
}