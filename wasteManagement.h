#ifndef WASTE_MANAGEMENT_H
#define WASTE_MANAGEMENT_H

#include <iostream>
#include <string>

using namespace std;

// STRUKTUR BST
struct Kategori {
    string namaKategori;   
    int tingkatBahaya;     
    string gudang[5];      
    int jmlGudang;
};

struct NodeBST {
    Kategori info;
    NodeBST *left, *right;
};

// STRUKTUR MLL
typedef string infotypeChild; 

struct Pengepul {
    string idPengepul;    
    string namaPengepul;
    string wilayah;
};

struct ElmChild {
    infotypeChild info;
    ElmChild *next;
};

struct ElmParent {
    Pengepul info;        
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

