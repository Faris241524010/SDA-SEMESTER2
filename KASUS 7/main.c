/* main.c – Demo menu ADT Non-Binary Tree (array kontigu) */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "nbtrees.h"
#include "menu.h"

int main() {
    Isi_Tree T;
    
	/* Awal: kosongkan array */
    int i;
    for (i = 0; i <= jml_maks; ++i) {
        T[i].info = 0;
        T[i].ps_pr = T[i].ps_fs = T[i].ps_nb = nil;
    }
    
	Add(T, 1,  'A', 2, 0, 0);    // A: first son = 2 (B)
	Add(T, 2,  'B', 4, 3, 1);    // B: first son = 4, next bro = 3, parent = 1
	Add(T, 3,  'C', 6, 0, 1);    // C: first son = 6, parent = 1
	Add(T, 4,  'D', 0, 5, 2);    // D: next bro = 5, parent = 2
	Add(T, 5,  'E', 9, 0, 2);    // E: first son = 9, parent = 2
	Add(T, 6,  'F', 0, 7, 3);    // F: next bro = 7, parent = 3
	Add(T, 7,  'G', 0, 8, 3);    // G: next bro = 8, parent = 3
	Add(T, 8,  'H', 0, 0, 3);    // H: parent = 3
	Add(T, 9,  'I', 0, 10, 5);   // I: next bro = 10, parent = 5
	Add(T, 10, 'J', 0, 0, 5);    // J: parent = 5

    int pilih;
    do {
        system("cls");        
		tampilMenu();
        if (scanf("%d", &pilih) != 1) {   /* handle input non-angka */
            while (getchar() != '\n');    /* buang sisa buffer       */
            pilih = -1;
        }
        
        system("cls");
        switch (pilih) {
        case 1: {
        	/* Awal: kosongkan array */
		    int i;
		    for (i = 0; i <= jml_maks; ++i) {
		        T[i].info = 0;
		        T[i].ps_pr = T[i].ps_fs = T[i].ps_nb = nil;
		    }
        	
            int jml;
            printf("Masukkan jumlah node (max %d): ", jml_maks);
            scanf("%d", &jml);
            Create_tree(T, jml);
            getch();
            break;
        }

        case 2:
            if (IsEmpty(T))
                puts("Tree masih kosong. Pilih menu 1 dulu.");
            else
                PrintTree(T);
            getch();
            break;

        case 3:
            if (IsEmpty(T)) {
                puts("Tree masih kosong. Pilih menu 1 dulu.");
            } else {
                puts("\nPreOrder   : "); PreOrder(T);
                puts("InOrder    : "); InOrder(T);
                puts("PostOrder  : "); PostOrder(T);
                puts("LevelOrder : "); Level_order(T, jml_maks);
            }
            getch();
            break;

        case 4:
            if (IsEmpty(T)) {
                puts("Tree masih kosong. Pilih menu 1 dulu.");
            } else {
                char x;
                printf("Masukkan info node yang dicari: ");
                scanf(" %c", &x);
                if (Search(T, x))
                    printf("Node '%c' ditemukan di level %d\n", x, Level(T, x));
                else
                    printf("Node '%c' TIDAK ditemukan\n", x);
            }
            getch();
            break;

        case 5:
            if (IsEmpty(T)) {
                puts("Tree masih kosong. Pilih menu 1 dulu.");
            } else {
                printf("Total node  : %d\n", nbElmt(T));
                printf("Total daun  : %d\n", nbDaun(T));
                printf("Tinggi tree : %d\n", Depth(T));
            }
            getch();
            break;

        case 0:
            puts("Keluar. Terima kasih!");
            break;

        default:
            puts("Pilihan tidak valid!");
            getch();
        }
    } while (pilih != 0);

    return 0;
}

