#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <conio.h>

#include "struct.h"
#include "protype.h"
#pragma warning(disable : 6031)
#pragma warning(disable : 6386)
#pragma warning(disable : 6385)
#pragma warning(disable : 6011)
//#pragma warning(disable : 4996) 




//----------------------------------------------------------------
//                   데이터 읽고,쓰기 1 , 2
//----------------------------------------------------------------
void file_write_read(const int* a)
{
	Data2 d2;
	FILE* fp1;


	if(*a == 1)
	{
		fp1 = fopen("data.bin", "ab");
		scanf_s("%s %hd %hd %hd", d2.string, 10, &d2.year, &d2.mounth, &d2.day);
		fwrite(&d2, sizeof(d2), 1, fp1);
		fclose(fp1);
	}
	else if (*a == 2)
	{
		int num1 = 0;
		fp1 = fopen("data.bin", "rb");

		while (fread(&d2, sizeof(d2), 1, fp1)){

			printf("도서 명: %s  입고일자 %hd년 %hd월 %hd일\n", d2.string, d2.year, d2.mounth, d2.day);

		}

		fclose(fp1);
	}
	_getch();

	system("pause");
	system("cls");
}

//----------------------------------------------------------------
//                        데이터 검색 3
//----------------------------------------------------------------
void search_string(const char* string)
{
double start, end;
start = (double)clock() / CLOCKS_PER_SEC;

	Data2 d2;
	FILE* fp1 = fopen("data.bin", "rb");
	while (fread(&d2, sizeof(d2), 1, fp1))
	{
		if (!strcmp(d2.string, string))
		{
			//size = ftell(fp1) - sizeof(d2);
			//fseek(fp1, size, SEEK_SET);
			printf("검색 완료 :%s 입고일자 %hd년 %hd월 %hd일\n", d2.string, d2.year, d2.mounth, d2.day);
			//size = ftell(fp1) + sizeof(d2);

			//fseek(fp1, size, SEEK_CUR);
			//break;
		}
	}
	fclose(fp1);
	end = (((double)clock()) / CLOCKS_PER_SEC);
	printf("프로그램 수행 시간 :%lf\n", (end - start));

	system("pause");
	system("cls");

}





//----------------------------------------------------------------
//                        데이터 수정 4
//----------------------------------------------------------------
void change_data(const char* string)
{
	Data2 d2;
	int size;
	FILE* fp1 = fopen("data.bin", "rb+");
	short check_num;


	while (fread(&d2, sizeof(d2), 1, fp1))
	{
		if (!strcmp(d2.string, string))
		{
			printf("%s를 수정 하시겠습니까? 입고일자 %hd년 %hd월 %hd일\n", d2.string, d2.year, d2.mounth, d2.day);
			printf("현재 검색된 데이터 수정  F1, 다음 데이터 검색 F2\n");

			scanf("%hd", &check_num);
			if (check_num == 1) {
				size = ftell(fp1) - sizeof(d2);
				fseek(fp1, size, SEEK_SET);
				scanf_s("%s %hd %hd %hd", d2.string, 10, &d2.year, &d2.mounth, &d2.day);
				fwrite(&d2, sizeof(d2), 1, fp1);
				size = ftell(fp1) + sizeof(d2);
				break;
			}
			else if (check_num == 2) {
				continue;
			}
		}
	}
	fclose(fp1);

	system("pause");
	system("cls");

}


//----------------------------------------------------------------
//                        데이터 초기화 5
//----------------------------------------------------------------

void data_rest(){
	Data2 d2;
	FILE* fp1 = fopen("data.bin", "wb");
	printf("초기화 값 입력\n");
	scanf_s("%s %hd %hd %hd", d2.string, 10, &d2.year, &d2.mounth, &d2.day);
	fwrite(&d2, sizeof(d2), 1,fp1);

	
	
	
	fclose(fp1);
	printf("초기화 완료\n");
	system("pause");
	system("cls");
}


//----------------------------------------------------------------
//                    기능 선택 번호
//----------------------------------------------------------------
void number_check_function(void(*file_rw)(void*), void(*file_serch)(char*), void(*file_dchnage)(char*),void(*file_drest)())
{
	int num1;
	char name[10] = {0,};
	
	printf("데이터 추가 1\n");
	printf("전체 목록보기 2\n");
	printf("이름으로 검색 3\n");
	printf("데이터 수정 4\n");
	printf("데이터 리셋 (주의 데이터 초기화됨)5\n");

	scanf("%d", &num1);
	system("cls");
	if (num1 == 1 || num1 == 2){
		file_rw(&num1);
	}
	else if (num1 == 3) {
		scanf("%s", name);
		file_serch(name);
	}
	else if (num1 == 4) {
		scanf("%s", name);
		file_dchnage(name);
	}
	else if (num1 == 5) {
		file_drest();
	}
}