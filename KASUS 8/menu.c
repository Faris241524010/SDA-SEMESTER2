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
    puts("1.  Traversal PreOrder");
    puts("2.  Traversal InOrder");
    puts("3.  Traversal PostOrder");
    puts("4.  Traversal LevelOrder");
    puts("5.  Print Tree");
    puts("6.  Search Node Tree");
    puts("7.  Jumlah Daun/Leaf");
    puts("8.  Mencari level node tree");
    puts("9.  Kedalaman Tree");
    puts("10. Membandingkan 2 Node Tree");
    puts("11. Exit");
    printf("Pilihan: ");
}
