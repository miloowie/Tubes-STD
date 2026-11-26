#include "MLL.h"

void createListParent(ListParent &L) {
    L.first = NULL;
}

void createListChild(ListChild &L) {
    L.first = NULL;
    L.last  = NULL;
}

bool isEmptyParent(ListParent L) {
    return L.first == NULL;
}

bool isEmptyChild(ListChild L) {
    return L.first == NULL;
}

adrParent createParent(Grup x){
    adrParent P = new ElmParent;
    P->info = x;
    P->next = NULL;
    createListChild(P->child);
    return P;
}

adrParent findParent(ListParent L, string namaGrup){
    adrParent P = L.first;
    while (P != NULL && P->info.namaGrup != namaGrup) {
        P = P->next;
    }
    return P;
}

void insertParent(ListParent &L, adrParent P){
    if (P != NULL) {
        if (findParent(L, P->info.namaGrup) != NULL) {
            cout << "Grup " << P->info.namaGrup << " sudah ada, ditolak" << endl;
            delete P;
        } else {
            if (isEmptyParent(L)) {
                L.first = P;
            } else {
                adrParent Q = L.first;
                while (Q->next != NULL) {
                    Q = Q->next;
                }
                Q->next = P;
            }
        }
    }
}

void deleteParent(ListParent &L, string namaGrup, adrParent &P){
    P = NULL;
    if (isEmptyParent(L)) {
        cout << "List parent kosong, tidak ada yang dihapus" << endl;
    } else {
        // cari node + node sebelumnya
        adrParent Prev = NULL;
        P = L.first;
        while (P != NULL && P->info.namaGrup != namaGrup) {
            Prev = P;
            P = P->next;
        }

        if (P == NULL) {
            cout << "Grup " << namaGrup << " tidak ditemukan" << endl;
        } else {
            // lepas dari list
            if (Prev == NULL) {
                L.first = P->next;        // hapus elemen pertama
            } else {
                Prev->next = P->next;     // hapus tengah / terakhir
            }
            P->next = NULL;
            // bebaskan semua child
            adrChild C = P->child.first;
            while (C != NULL) {
                adrChild hapus = C;
                C = C->next;              // simpan next DULU sebelum delete
                delete hapus;
            }
            P->child.first = NULL;
            P->child.last  = NULL;
            // bebaskan parent
            cout << "Grup " << P->info.namaGrup << " dihapus" << endl;
            delete P;
            P = NULL;
        }
    }
}

void printParent(ListParent L){
    if (isEmptyParent(L)) {
        cout << "List parent kosong" << endl;
        return;
    }
    adrParent P = L.first;
    int no = 1;
    while (P != NULL) {
        cout << no << ". " << P->info.namaGrup
             << " | " << P->info.agensi
        P = P->next;
        no++;
    }
}

