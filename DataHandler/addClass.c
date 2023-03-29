#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "addClass.h"
#include "C:\\Users\\phuon\\Desktop\\C\Project\\Plan\\main.h"
static void makeClass(StPlan *PlanList);
void addClass(){
	//printf("Hello from add class\n");
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
		makeClass(PlanList);
	}
}
static void getDay(char *inputDay){
	while(1){
		printf("School start from monday to firday. Enter day: ");
		fgets(inputDay, DAY_LENGTH, stdin);
		inputDay[strcspn(inputDay, "\n")] = '\0';
		if((strcmp(inputDay, "monday") ==0) || (strcmp(inputDay, "tuesday") ==0) || (strcmp(inputDay, "wednesday") ==0) || (strcmp(inputDay, "thursday") ==0) || (strcmp(inputDay, "firday") ==0)){
			break;
		}
	}
}

static void getClass(char *inputClas){
	printf("Enter class name: ");
	fgets(inputClas, CLASS_LENGTH, stdin);
	inputClas[strcspn(inputClas, "\n")] = '\0';
}

static void getRoom(char *inputRoom){
	printf("Enter class room: ");
	fgets(inputRoom, ROOM_LENGTH, stdin);
	inputRoom[strcspn(inputRoom, "\n")] = '\0';
}
static void getTime(int * inputStartTime, int *inputEndTime){
	char *tmp1, *tmp2;
	tmp1=(char*)malloc(4*sizeof(char));
	tmp2=(char*)malloc(4*sizeof(char));
	while(1){
		printf("School open from 9:00. Enter start time: ");
		fgets(tmp1, 4, stdin);
		tmp1[strcspn(tmp1, "\n")] = '\0';
		sscanf(tmp1, "%d", inputStartTime);
		if(*inputStartTime>=9 && *inputStartTime<=17){
			free(tmp1);
			break;
		}
	}
	while(1){
		printf("School close at 18:00, and this class start from %d. Enter end time: ", *inputStartTime);
		fgets(tmp2, 4, stdin);
		tmp2[strcspn(tmp2, "\n")] = '\0';
		sscanf(tmp2, "%d", inputEndTime);
		if(*inputEndTime>*inputStartTime && *inputEndTime<=18){
			free(tmp2);
			break;
		}
	}
}

static void makeClass(StPlan *PlanList){
	char inputClass[CLASS_LENGTH];
	getClass(inputClass);
	char inputRoom[ROOM_LENGTH];
	getRoom(inputRoom);
	char inputDay[DAY_LENGTH];
	getDay(inputDay); //ok
	int inputStartTime=0;
	int inputEndTime =0;
	getTime(&inputStartTime, &inputEndTime);
	
	printf("%d %d %s %s %s\n", inputStartTime, inputEndTime, inputDay, inputClass, inputRoom);
	
	FILE * addData;
	addData = fopen(DATA_PATH, "wb");
	
	for(int i=0;i<MAX_PLAN;i++){
		if(strcmp(inputDay, PlanList[i].day) ==0 && PlanList[i].time ==inputStartTime){
			strcpy(PlanList[i].clas, inputClass);
			strcpy(PlanList[i].room, inputRoom);
			if(inputStartTime<inputEndTime-1){
				inputStartTime+=1;
			}
		}
		fprintf(addData, "%d;%s;%s;%s\n", PlanList[i].time, PlanList[i].day, PlanList[i].clas, PlanList[i].room);
	}
	printf("New class added successfully!\n");
	fclose(addData);
	free(PlanList);
}