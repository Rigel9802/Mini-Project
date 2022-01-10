#include <iostream>
using namespace std;

struct node
{
    string role, namaPemain;
    node *next, *bot;
} * head, *tail;

node *helpRole;

void addRole(node *newNode, string role)
{
    newNode = new node;
    newNode->role = role;
    newNode->next = nullptr;
    newNode->bot = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// void addPemain(node *newBot, string role, string nama)
// {
//     helpRole = head;
//     while (helpRole != NULL)
//     {
//         // Cek role
//         if (helpRole->role == role)
//         {
//             newBot = new node;
//             newBot->namaPemain = nama;
//             newBot->bot = NULL;
//             newBot->next = NULL;
//             // cout << "pemain masuk sini" << endl;
//             if (helpRole->bot == NULL)
//             {
//                 helpRole->bot = newBot;
//                 // cout << "Pemain sudah ditambahkan" << endl;
//             }
//             else
//             {
//                 node *helpBot = helpRole;
//                 while (helpBot->bot != NULL)
//                 {
//                     helpBot = helpBot->bot;
//                 }
//                 helpBot->bot = newBot;
//                 // cout << "pemain sudah ditambahkan" << endl;
//             }
//         }
//         helpRole = helpRole->next;
//     }
// }

// void delPemain(node *del, string posisi, string nama){
//     del = head;
//     node *bef;
//     while (del != NULL){
//         if (del->role == posisi){
//             node *temp = del;
//             while (temp != NULL){
//                 if (temp->bot->namaPemain == nama){
//                     bef = temp;
//                     del = bef->bot;
//                     break;
//                 }
//                 temp = temp->bot;
//             }
//             // cout << "bef: " << bef->role <<bef->namaPemain << endl;
//             // cout << "del: " << del->namaPemain << endl;
//             bef->bot = del->bot;
//             del->bot = nullptr;
//             del->next = nullptr;
//             delete del;
//         }
//         del = del->next;
//     }
// }

void addST(node *add, string nama)
{
    helpRole = head;
    while (helpRole != nullptr)
    {
        // Cek role
        if (helpRole->role == "ST")
        {
            add = new node;
            add->namaPemain = nama;
            add->bot = nullptr;
            add->next = nullptr;
            if (helpRole->bot == nullptr)
            {
                helpRole->bot = add;
            }
            else
            {
                node *temp = helpRole;
                while (temp->bot != nullptr)
                {
                    temp = temp->bot;
                }
                temp->bot = add;
            }
        }
        helpRole = helpRole->next;
    }
}

void delST(node *del, string nama)
{
    del = head;
    node *temp = del, *bef;
    while (temp != nullptr)
    {
        if (temp->bot->namaPemain == nama)
        {
            bef = temp;
            del = bef->bot;
            break;
        }
        temp = temp->bot;
    }
    bef->bot = del->bot;
    del->bot = nullptr;
    del->next = nullptr;
    free(del);
}

void cektakST(node *cetak)
{
    cetak = head;
    while (cetak != nullptr)
    {
        if (cetak->role == "ST")
        {
            node *temp = cetak;
            cout << cetak->role << " :";
            while (temp != nullptr)
            {
                cout << temp->namaPemain << " ";
                temp = temp->bot;
            }
            break;
        }
        cetak = cetak->next;
    }
    cout << endl;
}

void addMD(node *add, string nama)
{
    helpRole = head;
    while (helpRole != nullptr)
    {
        // Cek role
        if (helpRole->role == "MD")
        {
            add = new node;
            add->namaPemain = nama;
            add->bot = nullptr;
            add->next = nullptr;
            if (helpRole->bot == nullptr)
            {
                helpRole->bot = add;
            }
            else
            {
                node *temp = helpRole;
                while (temp->bot != nullptr)
                {
                    temp = temp->bot;
                }
                temp->bot = add;
            }
        }
        helpRole = helpRole->next;
    }
}

void delMD(node *del, string nama)
{
    del = head;
    while (del != nullptr)
    {
        if (del->role == "MD")
        {
            node *temp = del, *bef;
            while (temp != nullptr)
            {
                if (temp->bot->namaPemain == nama)
                {
                    bef = temp;
                    del = bef->bot;
                    break;
                }
                temp = temp->bot;
            }
            bef->bot = del->bot;
            del->bot = nullptr;
            del->next = nullptr;
            free(del);
        }
        del = del->next;
    }
}

void cektakMD(node *cetak)
{
    cetak = head;
    while (cetak != nullptr)
    {
        if (cetak->role == "MD")
        {
            node *temp = cetak;
            cout << cetak->role << " :";
            while (temp != nullptr)
            {
                cout << temp->namaPemain << " ";
                temp = temp->bot;
            }
            break;
        }
        cetak = cetak->next;
    }
    cout << endl;
}

void addDF(node *add, string nama)
{
    helpRole = head;
    while (helpRole != nullptr)
    {
        // Cek role
        if (helpRole->role == "DF")
        {
            add = new node;
            add->namaPemain = nama;
            add->bot = nullptr;
            add->next = nullptr;
            if (helpRole->bot == nullptr)
            {
                helpRole->bot = add;
            }
            else
            {
                node *temp = helpRole;
                while (temp->bot != nullptr)
                {
                    temp = temp->bot;
                }
                temp->bot = add;
            }
        }
        helpRole = helpRole->next;
    }
}

void delDF(node *del, string nama)
{
    del = head;
    while (del != nullptr)
    {
        if (del->role == "DF")
        {
            node *temp = del, *bef;
            while (temp != nullptr)
            {
                if (temp->bot->namaPemain == nama)
                {
                    bef = temp;
                    del = bef->bot;
                    break;
                }
                temp = temp->bot;
            }
            bef->bot = del->bot;
            del->bot = nullptr;
            del->next = nullptr;
            free(del);
        }
        del = del->next;
    }
}

void cektakDF(node *cetak)
{
    cetak = head;
    while (cetak != nullptr)
    {
        if (cetak->role == "DF")
        {
            node *temp = cetak;
            cout << cetak->role << " :";
            while (temp != nullptr)
            {
                cout << temp->namaPemain << " ";
                temp = temp->bot;
            }
            break;
        }
        cetak = cetak->next;
    }
    cout << endl;
}

void addGK(node *add, string nama)
{
    helpRole = head;
    while (helpRole != nullptr)
    {
        // Cek role
        if (helpRole->role == "GK")
        {
            add = new node;
            add->namaPemain = nama;
            add->bot = nullptr;
            add->next = nullptr;
            if (helpRole->bot == nullptr)
            {
                helpRole->bot = add;
            }
            else
            {
                node *temp = helpRole;
                while (temp->bot != nullptr)
                {
                    temp = temp->bot;
                }
                temp->bot = add;
            }
        }
        helpRole = helpRole->next;
    }
}

void delGK(node *del, string nama)
{
    del = tail;
    node *bef;
    while (del != nullptr)
    {
        if (del->bot->namaPemain == nama)
        {
            bef = del;
            del = bef->bot;
            break;
        }
        del = del->bot;
    }
    bef->bot = del->bot;
    del->bot = nullptr;
    del->next = nullptr;
    free(del);
}

void cektakGK(node *cetak)
{
    cetak = tail;
    node *temp = cetak;
    cout << cetak->role << " :";
    while (temp != nullptr)
    {
        cout << temp->namaPemain << " ";
        temp = temp->bot;
    }
    cout << endl;
}

void cariPemain(node *cari, string nama)
{
    cari = head;
    while (cari != nullptr)
    {
        node *temp = cari;
        if (cari->role == "ST")
        {
            while (temp != nullptr)
            {
                if (temp->namaPemain == nama)
                {
                    cout << "Nama : " << temp->namaPemain << endl;
                    cout << "Posisi : " << cari->role << endl;
                    break;
                }
                temp = temp->bot;
            }
        }
        if (cari->role == "MD")
        {
            while (temp != nullptr)
            {
                if (temp->namaPemain == nama)
                {
                    cout << "Nama : " << temp->namaPemain << endl;
                    cout << "Posisi : " << cari->role << endl;
                    break;
                }
                temp = temp->bot;
            }
        }
        if (cari->role == "DF")
        {
            while (temp != nullptr)
            {
                if (temp->namaPemain == nama)
                {
                    cout << "Nama : " << temp->namaPemain << endl;
                    cout << "Posisi : " << cari->role << endl;
                    break;
                }
                temp = temp->bot;
            }
        }
        if (cari->role == "GK")
        {
            while (temp != nullptr)
            {
                if (temp->namaPemain == nama)
                {
                    cout << "Nama : " << temp->namaPemain << endl;
                    cout << "Posisi : " << cari->role << endl;
                    break;
                }
                temp = temp->bot;
            }
        }
        cari = cari->next;
    }
}

void subtitusiDF(node *del, string hapusNama, string namaBaru)
{
    del = head;
    node *baru;
    while (del != nullptr)
    {
        if (del->role == "DF")
        {
            node *temp = del, *bef;
            while (temp != nullptr)
            {
                if (temp->bot->namaPemain == hapusNama)
                {
                    bef = temp;
                    del = bef->bot;
                    break;
                }
                temp = temp->bot;
            }
            baru = new node;
            baru->namaPemain = namaBaru;
            baru->next = nullptr;
            baru->bot = del->bot;
            bef->bot = baru;
            del->bot = nullptr;
            del->next = nullptr;
            free(del);
        }
        del = del->next;
    }
}

void hapusPemain(node *del)
{
    del = head;
    while (del != nullptr)
    {
        node *help, *temp;
        help = del->bot;
        del->bot = nullptr;
        while (help != nullptr)
        {
            temp = help;
            help = help->bot;
            temp->bot = nullptr;
            free(temp);
        }
        del = del->next;
    }
}

void cetakPemain(node *cetak)
{
    cetak = head;
    while (cetak != nullptr)
    {
        node *cetakPemain = cetak;
        cout << cetak->role << " :";
        while (cetakPemain != nullptr)
        {
            cout << cetakPemain->namaPemain << " ";
            cetakPemain = cetakPemain->bot;
        }
        cout << endl;
        cetak = cetak->next;
    }
}

int main()
{
    node *temp;
    addRole(temp, "ST");
    addRole(temp, "MD");
    addRole(temp, "DF");
    addRole(temp, "GK");
    // addPemain(temp, "ST", "1");
    // addPemain(temp, "ST", "2");
    // addPemain(temp, "ST", "3");
    // addPemain(temp, "MD", "4");
    // addPemain(temp, "MD", "5");
    // addPemain(temp, "MD", "6");
    // addPemain(temp, "DF", "7");
    // addPemain(temp, "DF", "8");
    // addPemain(temp, "DF", "9");
    // addPemain(temp, "DF", "10");
    // addPemain(temp, "GK", "11");
    // delPemain(temp, "ST", "2");
    addST(temp, "1");
    addST(temp, "2");
    addST(temp, "3");
    addMD(temp, "4");
    addMD(temp, "5");
    addMD(temp, "6");
    addDF(temp, "7");
    addDF(temp, "8");
    addDF(temp, "9");
    addDF(temp, "10");
    addGK(temp, "11");
    // delGK(temp, "11");

    // hapusPemain(temp);
    cariPemain(temp, "2");
    cektakST(temp);
    cektakMD(temp);
    cektakDF(temp);
    cektakGK(temp);
    subtitusiDF(temp, "9", "20");
    cetakPemain(temp);
    // cetakPemain(temp);
    return 0;
}