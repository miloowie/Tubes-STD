
// ============================================================
//  mll.h  -  ADT Multi Linked List (List to List)
//  Studi kasus : Music Album Sales Management
//  Parent      : Grup  (namaGrup, agensi, tahunDebut)
//  Child       : Album (judulAlbum, tahunRilis, totalPenjualan)
// ============================================================
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

struct Grup {                    // info parent
    string namaGrup;             // kunci parent
    string agensi;
};

struct Album {                   // info child
    string judulAlbum;           // kunci child (unik dalam satu grup)
    int    tahunRilis;           // dasar urutan child
    int    totalPenjualan;       // >= 0
};

typedef struct ElmParent *adrParent;
typedef struct ElmChild  *adrChild;

struct ElmChild {                // elemen child (album)
    Album    info;
    adrChild next;
};

struct ListChild {               // list child (milik tiap grup)
    adrChild first;
    adrChild last;
};

struct ElmParent {               // elemen parent (grup)
    Grup      info;
    ListChild child;             // penghubung ke list child miliknya
    adrParent next;
};

struct ListParent {              // list utama
    adrParent first;
};

// ------------------------------------------------------------
//  Inisialisasi dan pengecekan list
// ------------------------------------------------------------
void createListParent(ListParent &L);
void createListChild(ListChild &L);
bool isEmptyParent(ListParent L);
bool isEmptyChild(ListChild L);

// ------------------------------------------------------------
//  Operasi wajib: Parent List
// ------------------------------------------------------------
adrParent createParent(Grup x);
void      insertParent(ListParent &L, adrParent P);   // false jika namaGrup sudah ada
void      deleteParent(ListParent &L, string namaGrup, adrParent &P);
adrParent findParent(ListParent L, string namaGrup);  // NULL jika tidak ditemukan
void      printParent(ListParent L);

// ------------------------------------------------------------
//  Operasi wajib: Child List
// ------------------------------------------------------------
adrChild createChild(Album x);
bool     insertChild(adrParent P, adrChild C);        // sisip terurut tahunRilis; false jika tidak valid
void     deleteChild(adrParent P, string judulAlbum, adrChild &C);
adrChild findChild(adrParent P, string judulAlbum);   // NULL jika tidak ditemukan
void     printChild(adrParent P);

// ------------------------------------------------------------
//  Tampilkan seluruh struktur
// ------------------------------------------------------------
void printAll(ListParent L);
void isiDataDummy(ListParent &L);
// ------------------------------------------------------------
//  Fitur tambahan (opsional) - aktifkan nanti saat implementasi
// ------------------------------------------------------------
// int      countChild(adrParent P);
int      totalPenjualanGrup(adrParent P);
adrChild albumTerlaris(adrParent P);
// void     rankingGrup(ListParent L);
// void     penjualanTertinggiPerTahun(ListParent L, int tahun);
// void     trenPenjualan(adrParent P);
// adrChild findAlbumLintasGrup(ListParent L, string judulAlbum, adrParent &P);
void     updateChild(adrParent P, string judulAlbum, int penjualanBaru);
void     rekapPenjualan(ListParent L);

#endif // MLL_H
