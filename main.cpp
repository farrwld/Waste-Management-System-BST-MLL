#include "wasteManagement.h"
#include "wasteManagement.cpp"1

int main() {
    adrBST root = NULL;
    adrParent listPengepul = NULL;
    int pilihan;

    do {
        cout << "\n=== SISTEM PENGELOLAAN DATA SAMPAH ===" << endl;
        cout << "1. Tambah/Update Kategori (BST)" << endl;
        cout << "2. Lihat Semua Kategori (Inorder)" << endl;
        cout << "3. Tambah Pengepul (Parent MLL)" << endl;
        cout << "4. Tambah Jenis Sampah ke Pengepul (Child MLL)" << endl;
        cout << "5. Lihat Semua Pengepul & Jenis Sampah" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: "; cin >> pilihan;

        if (pilihan == 1) {
            Kategori k;
            cout << "Nama Kategori: "; cin >> k.namaKategori;
            cout << "Tingkat Bahaya (1-10): "; cin >> k.tingkatBahaya;
            insertBST(root, k);
        } else if (pilihan == 2) {
            viewInorder(root);
        } else if (pilihan == 3) {
            Pengepul p;
            cout << "ID Pengepul: "; cin >> p.idPengepul;
            cout << "Nama Pengepul: "; cin >> p.namaPengepul;
            insertParent(listPengepul, p);
        } else if (pilihan == 4) {
            string id, jenis;
            cout << "Masukkan ID Pengepul: "; cin >> id;
            cout << "Jenis Sampah: "; cin >> jenis;
            insertChild(listPengepul, id, jenis);
        } else if (pilihan == 5) {
            showAllMLL(listPengepul);
        }
    } while (pilihan != 0);

    return 0;
}
