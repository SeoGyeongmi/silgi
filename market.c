#include <stdio.h>
#include <string.h>
#include "manager.h"

int main(void){
    
    Product slist[100];
    int curcount=0;
    int count = 0, menu;
    
    count = loadData(slist);
    curcount=count; 

    while (1){
        menu = selectMenu();
        getchar();
        if(menu == 0) break;
        if(menu == 1 || menu ==3 || menu == 4){	
		    if (count==0){ 
                printf(" 데이터가 없습니다!\n");
			    continue;
			}
		}

        if(menu == 1) listProduct(slist,curcount); 
        else if (menu == 2) {
            count+=createProduct(&slist[curcount++]); 
        }
        else if (menu == 3) {
            int no=selectDataNo(slist, curcount);
            if(no==0){
                printf("=>취소됨!");
                continue;
            }
            updateProduct(&slist[no-1]);
        }
        else if (menu == 4) {
            int no=selectDataNo(slist, curcount);
            if(no==0){
                printf("=>취소됐어요! :D");
                continue;
            }
            int deleteok;
            printf("진짜 삭제할 거예요?(삭제:1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteProduct(&slist[no-1])) count --;       
           	 } 
        }
	    else if (menu == 5){
		    if (count==0) printf("아직 데이터가 없어요!\n");
		    else saveData(slist,curcount);
	    }
	}

	printf("\n종료됨! 다음에 또 만나요 :D\n");
   	return 0;
}
