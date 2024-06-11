#include <iostream>
using namespace std;

/// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data_2311102039;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;

// Inisialisasi
void init()
{
    root = NULL;
}

// Cek Node
int isEmpty()
{
    return root == NULL;
}

// Buat Node Baru
void buatNode(char data_2311102039)
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data_2311102039 = data_2311102039;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data_2311102039 << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\n Pohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data_2311102039, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kiri ada atau tidak
        if (node->left != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data_2311102039 << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data_2311102039 = data_2311102039;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data_2311102039 << " berhasil ditambahkan ke child kiri " << baru->parent->data_2311102039 << endl;
            return baru;
        }
    }
}

// Tambah Kanan
Pohon *insertRight(char data_2311102039, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kanan ada atau tidak
        if (node->right != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data_2311102039 << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data_2311102039 = data_2311102039;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data_2311102039 << " berhasil ditambahkan ke child kanan " << baru->parent->data_2311102039 << endl;
            return baru;
        }
    }
}

// Ubah Data Tree
void update(char data_2311102039, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data_2311102039;
            node->data_2311102039 = data_2311102039;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data_2311102039 << endl;
        }
    }
}

// Lihat Isi Data Tree
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data node : " << node->data_2311102039 << endl;
        }
    }
}

// Cari Data Tree
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data Node : " << node->data_2311102039 << endl;
            cout << " Root : " << root->data_2311102039 << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data_2311102039 << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data_2311102039 << endl;
            else if (node->parent != NULL && node->parent->right != node &&
                     node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data_2311102039 << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data_2311102039 << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data_2311102039 << endl;
        }
    }
}

// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (isEmpty())
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data_2311102039 << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node = root)
{
    if (isEmpty())
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data_2311102039 << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root)
{
    if (isEmpty())
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data_2311102039 << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data_2311102039 << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void charateristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

void menu()
{
    int pilihan;
    char data;
    Pohon *node = NULL;

    do
    {
        cout << "\n\nMenu:\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Ubah Data Node\n";
        cout << "5. Lihat Isi Data Node\n";
        cout << "6. Cari Data Node\n";
        cout << "7. Traversal Pre-Order\n";
        cout << "8. Traversal In-Order\n";
        cout << "9. Traversal Post-Order\n";
        cout << "10. Hapus SubTree\n";
        cout << "11. Hapus Seluruh Tree\n";
        cout << "12. Lihat Karakteristik Tree\n";
        cout << "13. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan data root: ";
            cin >> data;
            buatNode(data);
            break;
        case 2:
            cout << "Masukkan data node kiri: ";
            cin >> data;
            if (root)
            {
                node = insertLeft(data, root);
            }
            else
            {
                cout << "Root tidak ada, buat node root terlebih dahulu.\n";
            }
            break;
        case 3:
            cout << "Masukkan data node kanan: ";
            cin >> data;
            if (root)
            {
                node = insertRight(data, root);
            }
            else
            {
                cout << "Root tidak ada, buat node root terlebih dahulu.\n";
            }
            break;
        case 4:
            cout << "Masukkan data node yang ingin diubah: ";
            cin >> data;
            update(data, root);
            break;
        case 5:
            cout << "Masukkan data node yang ingin dilihat: ";
            cin >> data;
            retrieve(root);
            break;
        case 6:
            cout << "Masukkan data node yang ingin dicari: ";
            cin >> data;
            find(root);
            break;
        case 7:
            cout << "\nPreOrder Traversal: ";
            preOrder(root);
            cout << endl;
            break;
        case 8:
            cout << "\nInOrder Traversal: ";
            inOrder(root);
            cout << endl;
            break;
        case 9:
            cout << "\nPostOrder Traversal: ";
            postOrder(root);
            cout << endl;
            break;
        case 10:
            cout << "Masukkan data node subtree yang ingin dihapus: ";
            cin >> data;
            deleteSub(root);
            break;
        case 11:
            clear();
            break;
        case 12:
            charateristic();
            break;
        case 13:
            cout << "Keluar program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 13);
}

int main()
{
    init();
    menu();
    return 0;
}
