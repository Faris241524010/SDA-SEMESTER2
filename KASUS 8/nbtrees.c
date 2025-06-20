/* nbtrees.c
   Implementasi ADT Non-Binary Tree dengan alokasi statik (array kontigu)
   sesuai header nbtrees.h
*/

#include <stdio.h>
#include "nbtrees.h"

/* -----------  FUNGSI/FUNGSI BANTU INTERNAL ------------- */
static void PreOrderRec(Isi_Tree P, int idx);
static void InOrderRec(Isi_Tree P, int idx);
static void PostOrderRec(Isi_Tree P, int idx);
static int  DepthRec(Isi_Tree P, int idx);
static boolean SearchRec(Isi_Tree P, int idx, infotype X);
static boolean IsEqualRec(Isi_Tree A, Isi_Tree B, int idxA, int idxB);

/* ------------------------------------------------------- */
/* Membuat tree kosong (seluruh field di-set 0 / nil).    */
static void _InitTree(Isi_Tree P)
{
	int i;
    for (i = 0; i <= jml_maks; ++i) {
        P[i].info  = 0;
        P[i].ps_fs = nil;
        P[i].ps_nb = nil;
        P[i].ps_pr = nil;
    }
}

/* ------------------------------------------------------- */
/*            P R I M I T I F  P U B L I K                */
/* ------------------------------------------------------- */
void Create_tree(Isi_Tree X, int Jml_Node)
/* Membangun pohon non-biner sebanyak Jml_Node node
   dengan pola input Level-Order.
   IS  : -
   FS  : Seluruh node dan relasi parent/child tersimpan di array X   */
{
    _InitTree(X);

    if (Jml_Node <= 0 || Jml_Node > jml_maks) {
        printf("Jumlah node harus 1..%d\n", jml_maks);
        return;
    }

    /* --- Input interaktif --- */
    printf("Masukkan info (char) untuk akar       : ");
    scanf(" %c", &X[1].info);
    X[1].ps_pr = nil;

    /* Antrean level-order */
    int q[jml_maks + 1];
    int front = 0, rear = 0;
    q[rear++] = 1;

    int node_ctr = 1;
    while (front < rear && node_ctr < Jml_Node) {
        int par = q[front++];

        int n_child;
        printf("Banyak anak node '%c' (idx %d)        : ", X[par].info, par);
        scanf("%d", &n_child);

		int k;
        int prev_child = nil;
        for (k = 0; k < n_child && node_ctr < Jml_Node; ++k) {
            int idx = ++node_ctr;          /* indeks anak baru            */
            printf("  Info anak ke-%d (idx %d)            : ", k + 1, idx);
            scanf(" %c", &X[idx].info);

            /* set relasi */
            X[idx].ps_pr = par;
            X[idx].ps_fs = nil;
            X[idx].ps_nb = nil;

            if (k == 0) {
                X[par].ps_fs = idx;        /* first son                    */
            } else {
                X[prev_child].ps_nb = idx; /* saudara sebelumnya ? saya    */
            }
            prev_child = idx;

            /* masukkan ke antrean untuk proses anak-anaknya kelak        */
            q[rear++] = idx;
        }
    }
}

boolean IsEmpty(Isi_Tree P)
/* Mengirimkan true jika tree kosong */
{
    return (P[1].info == 0);
}

/* ===== Traversal ===== */
void PreOrder(Isi_Tree P)
{
    if (!IsEmpty(P)) {
        PreOrderRec(P, 1);
        printf("\n");
    }
}

static void PreOrderRec(Isi_Tree P, int idx)
{
    if (idx == nil || P[idx].info == 0) return;

    printf("%c ", P[idx].info);             /* Parent */
    int child = P[idx].ps_fs;
    while (child != nil) {                  /* fs, nb … */
        PreOrderRec(P, child);
        child = P[child].ps_nb;
    }
}

/* ----------------------------------------------------- */
void InOrder(Isi_Tree P)
/* Konvensi : fs, Parent, sisa anak */
{
    if (!IsEmpty(P)) {
        InOrderRec(P, 1);
        printf("\n");
    }
}

static void InOrderRec(Isi_Tree P, int idx)
{
    if (idx == nil || P[idx].info == 0) return;

    int first_child = P[idx].ps_fs;
    if (first_child != nil) {
        InOrderRec(P, first_child);         /* fs */
    }

    printf("%c ", P[idx].info);             /* Parent */

    int sib = (first_child != nil) ? P[first_child].ps_nb : nil;
    while (sib != nil) {                    /* sisa anak lain */
        InOrderRec(P, sib);
        sib = P[sib].ps_nb;
    }
}

/* ----------------------------------------------------- */
void PostOrder(Isi_Tree P)
/* Konvensi : fs, nb, Parent */
{
    if (!IsEmpty(P)) {
        PostOrderRec(P, 1);
        printf("\n");
    }
}

static void PostOrderRec(Isi_Tree P, int idx)
{
    if (idx == nil || P[idx].info == 0) return;

    int child = P[idx].ps_fs;
    while (child != nil) {                  /* fs dan nb */
        PostOrderRec(P, child);
        child = P[child].ps_nb;
    }
    printf("%c ", P[idx].info);             /* Parent */
}

/* ----------------------------------------------------- */
void Level_order(Isi_Tree X, int Maks_node)
/* Maks_node disediakan agar traversal dapat dipotong bila diinginkan */
{
    if (IsEmpty(X)) return;

    int q[jml_maks + 1];
    int front = 0, rear = 0;
    q[rear++] = 1;
    int visited = 0;

    while (front < rear && visited < Maks_node) {
        int idx = q[front++];
        printf("%c ", X[idx].info);
        ++visited;

        int child = X[idx].ps_fs;
        while (child != nil) {
            q[rear++] = child;
            child = X[child].ps_nb;
        }
    }
    printf("\n");
}

/* ----------------------------------------------------- */
void PrintTree(Isi_Tree P)
/* Menampilkan tabel array tree apa adanya               */
{
    int i;
    for (i = 1; i <= jml_maks; ++i) {
        if (P[i].info != 0) {
            printf("--> Indeks ke-%d\n", i);
            printf("------------------------------------------\n");
            printf("Info array ke-%d:	%c\n", i, P[i].info);
            printf("First son ke-%d:		%d\n", i, P[i].ps_fs);
            printf("Next brother ke-%d:	%d\n", i, P[i].ps_nb);
            printf("Parent array ke-%d:	%d\n", i, P[i].ps_pr);
            printf("------------------------------------------\n");
            printf("\n");
        }
    }
}

/* ===== Pencarian ===== */
boolean Search(Isi_Tree P, infotype X)
{
    if (IsEmpty(P)) return false;
    return SearchRec(P, 1, X);
}

static boolean SearchRec(Isi_Tree P, int idx, infotype X)
{
    if (idx == nil || P[idx].info == 0) return false;
    if (P[idx].info == X) return true;

    int child = P[idx].ps_fs;
    while (child != nil) {
        if (SearchRec(P, child, X)) return true;
        child = P[child].ps_nb;
    }
    return false;
}

/* ===== Utility / Fungsi Lain ===== */
int nbElmt(Isi_Tree P)
/* Banyaknya node berisi */
{
    int cnt = 0;
    int i;
    for (i = 1; i <= jml_maks; ++i) {
        if (P[i].info != 0) ++cnt;
    }
    return cnt;
}

int nbDaun(Isi_Tree P)
/* Banyak daun (node tanpa anak) */
{
    int cnt = 0;
    int i;
    for (i = 1; i <= jml_maks; ++i) {
        if (P[i].info != 0 && P[i].ps_fs == nil) ++cnt;
    }
    return cnt;
}

int Level(Isi_Tree P, infotype X)
/* Level akar = 0, -1 jika tidak ditemukan               */
{
    if (IsEmpty(P)) return -1;

    int idx = -1;
    int i;
    for (i = 1; i <= jml_maks; ++i) {
        if (P[i].info == X) { idx = i; break; }
    }
    if (idx == -1) return -1;

    int lvl = 0;
    int par = P[idx].ps_pr;
    while (par != nil) {
        ++lvl;
        par = P[par].ps_pr;
    }
    return lvl;
}

int Depth(Isi_Tree P)
/* Tinggi pohon = banyak level dari akar ke daun terdalam */
{
    if (IsEmpty(P)) return 0;
    return DepthRec(P, 1);
}

static int DepthRec(Isi_Tree P, int idx)
{
    if (idx == nil || P[idx].info == 0) return 0;

    if (P[idx].ps_fs == nil) return 1;      /* daun */
    int max = 0;
    int child = P[idx].ps_fs;
    while (child != nil) {
        int d = DepthRec(P, child);
        if (d > max) max = d;
        child = P[child].ps_nb;
    }
    return max + 1;
}

int Max(infotype Data1, infotype Data2)
/* Data terbesar secara ASCII (atau numerik jika infotype int) */
{
    return (Data1 > Data2) ? Data1 : Data2;
}

/*  FUNGSI UNTUK MENAMBAHKAN 1 NODE SECARA MANUAL   */
void Add(Isi_Tree X, int idx, infotype info, int fs, int nb, int pr)
/*
   Mengisi slot array ke-idx dengan info & relasi.
   — idx harus 1..jml_maks
   — Jika fs/nb/pr tidak ada, isi dengan nil (0).
   Fungsi TIDAK memperbaiki pointer balikan (mis. parent->fs). Itu
   menjadi tanggung jawab pemanggil untuk konsisten.
*/
{
    if (idx < 1 || idx > jml_maks) {
        printf("Add: indeks %d di luar batas 1..%d\n", idx, jml_maks);
        return;
    }
    X[idx].info  = info;
    X[idx].ps_fs = fs;
    X[idx].ps_nb = nb;
    X[idx].ps_pr = pr;
}

boolean IsTreeEqual(Isi_Tree A, Isi_Tree B) {
    if (IsEmpty(A) && IsEmpty(B)) return true;
    if (IsEmpty(A) || IsEmpty(B)) return false;
    return IsEqualRec(A, B, 1, 1);
}

static boolean IsEqualRec(Isi_Tree A, Isi_Tree B, int idxA, int idxB) {
    if (idxA == nil && idxB == nil) return true;
    if (idxA == nil || idxB == nil) return false;

    if (A[idxA].info != B[idxB].info) return false;

    // Cek anak pertama
    if (!IsEqualRec(A, B, A[idxA].ps_fs, B[idxB].ps_fs)) return false;

    // Cek saudara berikutnya
    if (!IsEqualRec(A, B, A[idxA].ps_nb, B[idxB].ps_nb)) return false;

    return true;
}
