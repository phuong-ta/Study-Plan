#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "showClass.h"
#include "C:\\Users\\phuon\\Desktop\\C\Project\\Plan\\main.h"
static void showInfo(StPlan *PlanList);
void showClass(){
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
				if(sscanf(line, "%d;%[^;];%[^\t\n;];%[^\t\n]", &PlanList[position].time, PlanList[position].day, PlanList[position].clas, PlanList[position].room) == 4) {
					position+=1;
				}else{
					printf("Invalid line\n");
					break;
				}
			}
		}
		fclose(readDB);
		showInfo(PlanList);
	}
}

static void showInfo(StPlan *PlanList){
	int time =9;
	printf("%4s %10s %10s %10s %10s %10s", "Time", "Monday", "Tuesday", "Wednesday", "Thursday", "Firday\n");
	for(int i =0; i<TIME_RANGE; i++){
		printf("%02d:00", time+i);
		for(int j =0; j<DAY_RANGE; j++){
			if(strcmp("empty", PlanList[(i*5)+j].clas) ==0){
				strcpy(PlanList[(i*5)+j].clas, " ");
			}
			printf("%10s ", PlanList[(i*5)+j].clas);
		}
		printf("\n");
		printf("%5s", "");
		for(int j =0; j<DAY_RANGE; j++){
			if(strcmp("empty", PlanList[(i*5)+j].room) ==0){
				strcpy(PlanList[(i*5)+j].room, " ");
			}
			printf("%10s ", PlanList[(i*5)+j].room);
		}
		printf("\n");
	}
	free(PlanList);		
}
