#ifndef WASTE_MANAGEMENT_H
#define WASTE_MANAGEMENT_H

#include <iostream>
#include <string>

using namespace std;

// --- STRUKTUR BST (Kategori Sampah) ---
struct Kategori {
    string namaKategori;   // Unique Key
    int tingkatBahaya;     // Skala 1-10
    string gudang[5];      // Array of tipe dasar (maks 5 gudang)
    int jmlGudang;
};

struct NodeBST {
    Kategori info;
    NodeBST *left, *right;
};

// --- STRUKTUR MLL (Pengepul & Jenis Sampah) ---
typedef string infotypeChild; // Nama Sampah (Tipe Dasar)

struct Pengepul {
    string idPengepul;     // Unique
    string namaPengepul;
    string wilayah;
};

struct ElmChild {
    infotypeChild info;
    ElmChild *next;
};

struct ElmParent {
    Pengepul info;         // Record (Tipe Bentukan)
    ElmParent *next;
    ElmChild *firstChild;
};

typedef NodeBST* adrBST;
typedef ElmParent* adrParent;
typedef ElmChild* adrChild;

// Fungsi BST
void insertBST(adrBST &root, Kategori X);
adrBST searchBST(adrBST root, string nama);
void deleteBST(adrBST &root, string nama);
void viewInorder(adrBST root);
int countTotalKategori(adrBST root);
adrBST findMaxGudang(adrBST root);

// Fungsi MLL
void insertParent(adrParent &L, Pengepul P);
void insertChild(adrParent &L, string idParent, infotypeChild C);
void deleteChild(adrParent &L, string idParent, string namaSampah);
void showAllMLL(adrParent L);
adrParent searchParent(adrParent L, string id);

#endif

