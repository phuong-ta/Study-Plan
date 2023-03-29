#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "removeClass.h"
#include "C:\\Users\\phuon\\Desktop\\C\Project\\Plan\\main.h"
static void deleteClass(StPlan *PlanList);
void removeClass(){
	StPlan *PlanList;
	PlanList = (StPlan *)malloc(MAX_PLAN * sizeof(StPlan));
	char line[LINESIZE];
	int position =0;
	FILE * readDB;
	readDB = fopen(DATA_PATH, "rb");
	if(readDB==NULL){
		printf("Unable to open file %s\n", DATA_PATH);
	}else{
		while (!feof(readDB)) {
			if (fgets(line, LINESIZE, readDB) != NULL) {
				if(sscanf(line, "%d;%[^;];%[^;];%[^\t\n]", &PlanList[position].time, PlanList[position].day, PlanList[position].clas, PlanList[position].room) == 4) {
					position+=1;
				}else{
					printf("Invalid line\n");
					break;
				}
			}
		}
		fclose(readDB);
		deleteClass(PlanList);
	}
}

static void inputHandler(char *inputClas){
	
	printf("Enter Class, what you want to remove: ");
	fgets(inputClas, CLASS_LENGTH, stdin);
	inputClas[strcspn(inputClas, "\n")] = '\0';
}
//done
static void deleteClass(StPlan *PlanList){
	char inputClas[CLASS_LENGTH];
	char *tmp;
	tmp=(char*)malloc(3*sizeof(char));
	
	printf("Are you sure?\n");
	printf("y: Yes\t other:No\n");
	fgets(tmp, 3, stdin);
	tmp[strcspn(tmp, "\n")] = '\0';
	if(strcmp("y", tmp) ==0){
		inputHandler(inputClas);
	}
	free(tmp);
	FILE * removeData;
	removeData = fopen(DATA_PATH, "wb");
	
	for(int i=0;i<MAX_PLAN;i++){
		if(strcmp(inputClas, PlanList[i].clas) ==0){
			strcpy(PlanList[i].clas, "empty");
			strcpy(PlanList[i].room, "empty");
		}
		fprintf(removeData, "%d;%s;%s;%s\n", PlanList[i].time, PlanList[i].day, PlanList[i].clas, PlanList[i].room);
	}
	printf("Class deleted successfully!\n");
	fclose(removeData);
	free(PlanList);
}