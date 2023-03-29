#pragma warning(disable:4996)

#ifndef _FILE_NAME_H_
#define _FILE_NAME_H_
	
	#define DATA_PATH "C:\\Users\\phuon\\Desktop\\C\\Project\\Plan\\DataBase\\data.txt"
	#define MAX_PLAN 45
	#define LINESIZE 40
	#define DAY_LENGTH 10
	#define ROOM_LENGTH 20
	#define CLASS_LENGTH 20
	#define TIME_RANGE 9
	#define DAY_RANGE 5
#endif


struct StudyPlan {
	unsigned int time;
	char day[DAY_LENGTH];
	char clas[CLASS_LENGTH];
	char room[ROOM_LENGTH];
};
typedef struct StudyPlan StPlan;