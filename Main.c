#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>
#include <wchar.h>

#pragma warning (disable : 4996)

#include "Files5.h"

#define clear() printf("\033[H\033[J")
//https://stackoverflow.com/questions/26423537/how-to-position-the-input-text-cursor-in-c


int main()
{
	
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);

	
	char Log_Name[100];
	sprintf(Log_Name, "LOG_%d-%d-%d_%d-%d-%d.log", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	Log_init(Log_Name);

	Event_Log("program started");




	char UserRispon=0;

	while (UserRispon != 8) {
	Sleep(2000);
	clear();
	printf("****MENU****\n~ Type Option Number For Execution ~\n1.Take One SnapShot.\n2.Take 20 Seconds SnapShot.\n3.Start Long SnapShot.\n4.Generate HTML Report.\n5.Reset Collections.\n6.Save in File.\n7.Load from File.\n8.Quit\ntype here:");
	UserRispon = getch();
	printf("\n\n\n\n");
	clear();

		switch (UserRispon)
		{
		case '1':
			Error_Log("******************Start SnapShot****************");
			GetProcessesInfo();
			printf("\n\nGood Job: you take one SnapShot successfully!!!\n\n");
			Error_Log("******************End SnapShot******************");
			break;
		case '2':
			Error_Log("******************Start 20_SnapShot**************");
			printf("\nStart to take 20 SnapShots\n\n");
			GetProcessesInfo_20();
			printf("\n\nGood Job: you take 20 SnapShots successfully!!!\n\n");
			Error_Log("******************End 20_SnapShot**************");
			break;
		case '3':
			Error_Log("******************Start Long_SnapShot************");
			printf("\nprese 'E' to End the Long SnapShot\n\n");
			GetProcessesInfo_Long_SnapShot();
			printf("\n\nGood Job: you take Long SnapShots successfully!!!\n\n");
			Error_Log("******************End Long_SnapShot************");
			break;
		case '4':
			Error_Log("***********Start Generate HTML Report**********");
			DllPgaeGeneratorLoop();
			SamplePgaeGeneratorLoop();
			HomePgaeGenerator();
			printf("\n\nGood Job: you Create HTML Report successfully!!!\n\n");
			printf("The Absolut Path To HTML Is:\n");
			printf("C:\level - up\c lesson - level up\source\repos\22.9.2022\Projeckt_SnapShot_Yoni\Projeckt_SnapShot_Yoni\HTML_dist");
			Sleep(5000);
			Error_Log("************End Generate HTML Report***********");
			break;
		case '5':
			Error_Log("*****************Start Reset Collections********");
			ResetCollections();
			printf("\n\nThe Reset was successed!!!\n\n");
			Error_Log("**************End Reset Collections**************");
			break;
		case '6':
			Error_Log("******************Start Save in File******************");
			Save_Collections_In_File("project.bin");
			printf("\n\nGood Job: you Save in File successfully!!!\n\n");
			Error_Log("******************End Save in File******************");
			break;
		case '7':
			Error_Log("**********Start Load_Collections_From_File*************");
			Load_Collections_From_File("project.bin");
			printf("\n\nGood Job: you Loaded the File successfully!!!\n\n");
			Error_Log("********End Load_Collections_From_File***************");
			break;
		case '8':
			return;
		default:
			printf("invalid number");
			printf("\n\n");
			break;
		}
	}
	return 0;
}
