/* main.c – Demo menu ADT Non-Binary Tree (array kontigu) */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "nbtrees.h"
#include "menu.h"

int main() {
    Isi_Tree A, B;
    
	/* Awal: kosongkan array */
    int i;
    for (i = 0; i <= jml_maks; ++i) {
        A[i].info = 0;
        A[i].ps_pr = A[i].ps_fs = A[i].ps_nb = nil;
    }
    
	Add(A, 1,  'A', 2, 0, 0);    // A: first son = 2 (B)
	Add(A, 2,  'B', 4, 3, 1);    // B: first son = 4, next bro = 3, parent = 1
	Add(A, 3,  'C', 6, 0, 1);    // C: first son = 6, parent = 1
	Add(A, 4,  'D', 0, 5, 2);    // D: next bro = 5, parent = 2
	Add(A, 5,  'E', 9, 0, 2);    // E: first son = 9, parent = 2
	Add(A, 6,  'F', 0, 7, 3);    // F: next bro = 7, parent = 3
	Add(A, 7,  'G', 0, 8, 3);    // G: next bro = 8, parent = 3
	Add(A, 8,  'H', 0, 0, 3);    // H: parent = 3
	Add(A, 9,  'I', 0, 10, 5);   // I: next bro = 10, parent = 5
	Add(A, 10, 'J', 0, 0, 5);    // J: parent = 5
	
    for (i = 0; i <= jml_maks; ++i) {
        B[i].info = 0;
        B[i].ps_pr = B[i].ps_fs = B[i].ps_nb = nil;
    }
    
	Add(B, 1,  'A', 2, 0, 0);    // A: first son = 2 (B)
	Add(B, 2,  'B', 4, 3, 1);    // B: first son = 4, next bro = 3, parent = 1
	Add(B, 3,  'C', 6, 0, 1);    // C: first son = 6, parent = 1
	Add(B, 4,  'D', 0, 5, 2);    // D: next bro = 5, parent = 2
	Add(B, 5,  'E', 9, 0, 2);    // E: first son = 9, parent = 2
	Add(B, 6,  'F', 0, 7, 3);    // F: next bro = 7, parent = 3
	Add(B, 7,  'G', 0, 8, 3);    // G: next bro = 8, parent = 3
	Add(B, 8,  'H', 0, 0, 3);    // H: parent = 3
	Add(B, 9,  'I', 0, 10, 5);   // I: next bro = 10, parent = 5
	Add(B, 10, 'J', 0, 0, 5);    // J: parent = 5
	
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
        case 1: 
            if (IsEmpty(A))
                puts("Tree masih kosong.");
            else
                puts("\nPreOrder   : "); PreOrder(A);
	        getch();
            break;

        case 2:
            if (IsEmpty(A))
                puts("Tree masih kosong.");
            else
                puts("InOrder    : "); InOrder(A);
	        getch();
            break;

        case 3:
            if (IsEmpty(A)) {
                puts("Tree masih kosong.");
            } else {
                puts("PostOrder  : "); PostOrder(A);
            }
            getch();
            break;

        case 4:
            if (IsEmpty(A)) {
                puts("Tree masih kosong.");
            } else {
                puts("LevelOrder : "); Level_order(A, jml_maks);
            }
            getch();
            break;

        case 5:
            if (IsEmpty(A)) {
                puts("Tree masih kosong.");
            } else {
                PrintTree(A);
            }
            getch();
            break;

        case 6: {
        	char ch;
            if (IsEmpty(A)) {
                puts("Tree masih kosong.");
            } else {
                puts("Ketik info node yan ingin kamu cari:");
            	ch = getch();
                if (Search(A, ch)) {
                	printf("%c ditemukan dalam Tree A.\n", ch);
				} 
				else {
                	printf("%c tidak ditemukan dalam Tree A.\n", ch);
				} 
            }
            getch();
            break;
		}        
            
        case 7:
            if (IsEmpty(A)) {
                puts("Tree masih kosong.");
            } else {
                printf("Total daun  : %d\n", nbDaun(A));
            }
            getch();
            break;
            
        case 8:
            if (IsEmpty(A)) {
                puts("Tree masih kosong.");
            } else {
                char x;
                printf("Masukkan info node yang dicari: ");
                scanf(" %c", &x);
                if (Search(A, x))
                    printf("Node '%c' ditemukan di level %d\n", x, Level(A, x));
                else
                    printf("Node '%c' TIDAK ditemukan\n", x);
            }
            getch();
            break;

        case 9:
            if (IsEmpty(A)) {
                puts("Tree masih kosong.");
            } else {
                printf("Kedalaman tree : %d\n", Depth(A));
            }
            getch();
            break;

        case 10:
            if (IsEmpty(A)) {
                puts("Tree masih kosong.");
            } else {
                if (IsTreeEqual(A, B)) {
                	puts("Tree A dan Tree B SAMA.");
				}
				else {
					puts("Tree A dan Tree B TIDAK SAMA.");
				}
            }
            getch();
            break;

        case 11:
            puts("Keluar. Terima kasih!");
            break;

        default:
            puts("Pilihan tidak valid!");
            getch();
        }
    } while (pilih != 11);

    return 0;
}

