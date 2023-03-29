#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "DataHandler\\createDB.h"
#include "DataHandler\\addClass.h"
#include "DataHandler\\showClass.h"
#include "DataHandler\\removeClass.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	char *tmp;
	tmp=(char*)malloc(3*sizeof(char));
	int userChoise;
	
	while(1){
		printf(" 1: Add new class\n 2: Remove a class\n 3: Show your list\n 4: Create new data base\n 5:quit\n");
		fgets(tmp, 3, stdin);
		tmp[strcspn(tmp, "\n")] = '\0';
		sscanf(tmp, "%d", &userChoise);
		if(userChoise == 1){
			addClass();
		}else if(userChoise==2){
			removeClass();
		}else if(userChoise==3){
			showClass();
		}else if(userChoise==4){
			createDB();
		}else if(userChoise==5){
			printf("See you again!\n");
			free(tmp);
			break;
		}else{
			printf("Please choose 1-5!\n");
		}
	}
	system("pause");
	return 0;
	
}