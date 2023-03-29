#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "createDB.h"
#include "C:\\Users\\phuon\\Desktop\\C\Project\\Plan\\main.h"
static void createNewDB();
void createDB(){
	printf("If you want to create new database, old data base will deleted\n");
	printf("Are you sure?\n");
	printf("y: Yes\t other:No\n");
	char *tmp;
	tmp=(char*)malloc(3*sizeof(char));
	fgets(tmp, 3, stdin);
	tmp[strcspn(tmp, "\n")] = '\0';
	if(strcmp("y", tmp) ==0){
		createNewDB();
	}
	free(tmp);
}

static void createNewDB(){
	FILE * createDB;
	char times[TIME_RANGE][4] = { "9", "10", "11", "12", "13", "14", "15", "16", "17"};
	char days[DAY_RANGE][11] = {"monday", "tuesday", "wednesday", "thursday", "firday" };
	createDB = fopen(DATA_PATH, "wb");
	
	if(createDB==NULL){
		printf("Unable to open file %s\n", DATA_PATH);
	}else{
		for(int i =0; i<TIME_RANGE; i++){
			for(int j =0; j<DAY_RANGE; j++){
				fprintf(createDB, "%s;%s;%s;%s\n", times[i], days[j], "empty", "empty");
			}
		}
	}
	printf("New data base created successfully!\n");
	fclose(createDB);
}