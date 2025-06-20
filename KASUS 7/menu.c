//////////////////////////////////////////////////////
//	Name: menu.c 									//
//	Copyright: Politeknik Negeri Bandung			//
//	Author: Faris Ichsan Alyawa						//
//	Date: 14/05/25 07:12							//
//	Description: Program untuk menu NBT				//
//////////////////////////////////////////////////////

#include <stdio.h>
#include "menu.h"

void tampilMenu() {
    puts("\n========== MENU NBTREE ==========");
    puts("1.  Create Tree (level-order input)");
    puts("2.  Cetak array Tree");
    puts("3.  Traversal  - Pre, In, Post, Level");
    puts("4.  Cari node & tampilkan level");
    puts("5.  Hitung total node / daun / depth");
    puts("0.  Keluar");
    printf("Pilihan: ");
}
