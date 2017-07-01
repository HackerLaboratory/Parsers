/********************************************************************************* 
 * Copyright(C), Xumenger
 * FileName     : cDBF.h
 * Author       : xumenger
 * Version      : V1.0.0 
 * Date         : 2017-06-30
 * Description  : 
     1.Linux平台的DBF文件读写模块
     2.只允许读DBF文件、修改记录、新增记录、不支持从DBF中删除记录
     3.Delete方法只是将标记置为Deleted，并没有从DBF文件中删除记录
**********************************************************************************/  

#include <stdio.h>
#include "cDBFStruct.h"

CDBF* OpenDBF(char* filePath);
int CloseDBF(CDBF* cDBF);

int First(CDBF* cDBF);
int Last(CDBF* cDBF);
int Next(CDBF* cDBF);
int Prior(CDBF* cDBF);
int Go(CDBF* cDBF, int rowNo);
int Eof(CDBF* cDBF);

int Edit(CDBF* cDBF);
int Append(CDBF* cDBF);
int Delete(CDBF* cDBF);
int Post(CDBF* cDBF);
int Zap(CDBF* cDBF);

int Fresh(CDBF* cDBF);
int GetRecNo(CDBF* cDBF);

unsigned char GetFieldAsBoolean(CDBF* cDBF, char* fieldName, unsigned char bDefault);
int GetFieldAsInteger(CDBF* cDBF, char* fieldName, int iDefault);
float GetFieldAsFloat(CDBF* cDBF, char* fieldName, float fDefault);
char GetFieldAsChar(CDBF* cDBF, char* fieldName, char cDefault);
char* GetFieldAsString(CDBF* cDBF, char* fieldName, char* sDefault);

int SetFieldAsBoolean(CDBF* cDBF, char* fieldName, unsigned char value);
int SetFieldAsInteger(CDBF* cDBF, char* fieldName, int value);
int SetFieldAsFloat(CDBF* cDBF, char* fieldName, float value);
int SetFieldAsChar(CDBF* cDBF, char* fieldName, char value);
int SetFieldAsString(CDBF* cDBF, char* fieldName, char* value);
