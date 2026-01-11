#include "wasteManagement.h"

// IMPLEMENTASI BST
void insertBST(adrBST &root, Kategori X) {
    if (root == NULL) {
        root = new NodeBST;
        root->info = X;
        root->left = root->right = NULL;
    } else {
        if (X.namaKategori < root->info.namaKategori) {
            insertBST(root->left, X);
        } else if (X.namaKategori > root->info.namaKategori) {
            insertBST(root->right, X);
        } else {
            cout << "Kategori sudah ada. Memperbarui tingkat bahaya..." << endl;
            root->info.tingkatBahaya = X.tingkatBahaya;
        }
    }
}

adrBST searchBST(adrBST root, string nama) {
    if (root == NULL || root->info.namaKategori == nama) return root;
    if (nama < root->info.namaKategori) return searchBST(root->left, nama);
    return searchBST(root->right, nama);
}

void viewInorder(adrBST root) {
    if (root != NULL) {
        viewInorder(root->left);
        cout << "Kategori: " << root->info.namaKategori << " | Bahaya: " << root->info.tingkatBahaya << endl;
        viewInorder(root->right);
    }
}

// IMPLEMENTASI MLL
void insertParent(adrParent &L, Pengepul P) {
    adrParent newP = new ElmParent;
    newP->info = P;
    newP->next = L;
    newP->firstChild = NULL;
    L = newP;
}

adrParent searchParent(adrParent L, string id) {
    adrParent p = L;
    while (p != NULL) {
        if (p->info.idPengepul == id) return p;
        p = p->next;
    }
    return NULL;
}

void insertChild(adrParent &L, string idParent, infotypeChild C) {
    adrParent p = searchParent(L, idParent);
    if (p != NULL) {
        adrChild newC = new ElmChild;
        newC->info = C;
        newC->next = p->firstChild;
        p->firstChild = newC;
    } else {
        cout << "Pengepul tidak ditemukan!" << endl;
    }
}

void showAllMLL(adrParent L) {
    adrParent p = L;
    while (p != NULL) {
        cout << "[" << p->info.namaPengepul << "] Melayani: ";
        adrChild c = p->firstChild;
        while (c != NULL) {
            cout << c->info << ", ";
            c = c->next;
        }
        cout << endl;
        p = p->next;
    }
}

