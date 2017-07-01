/********************************************************************************* 
 * Copyright(C), Xumenger
 * FileName     : cDBF.h
 * Author       : xumenger
 * Version      : V1.0.0 
 * Date         : 2017-06-30
 * Description  : cDBF.h对外方法接口实现
**********************************************************************************/  

#include "cDBF.h"

int LockRow(CDBF* cDBF);
int UnLockRow(CDBF* cDBF);

/*******************************************************************************
* Function   : OpenDBF
* Description: 打开DBF文件; 供外部调用的Public方法
* Input      :
    * filePath, DBF文件目录  
* Output     :
* Return     : 该DBF文件对应的CDBF文件指针
* Others     : 
*******************************************************************************/  
CDBF* OpenDBF(char* filePath)
{
    return NULL;
}

/******************************************************************************* 
* Function   : CloseDBF
* Description: 关闭DBF文件; 供外部调用的Public方法
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 是否关闭成功, 0:关闭成功; 1:关闭失败
* Others     : 


*******************************************************************************/ 
int CloseDBF(CDBF* cDBF)
{
    return 0;
}

/******************************************************************************* 
* Function   : First
* Description: 切换到DBF文件的第一条记录
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 当前指向记录的序号, -1:切换失败; 0:DBF中没有记录，无法切换到第一条; 1:第一条记录的序号 
* Others     : 
*******************************************************************************/ 
int First(CDBF* cDBF)
{
    return NONE;
}

/******************************************************************************* 
* Function   : Last
* Description: 切换到DBF文件的最后一条记录
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 当前指向记录的序号, -1:切换失败; 0:DBF中没有记录，无法切换到第一条; >0:最后一条记录的序号 
* Others     : 
*******************************************************************************/ 
int Last(CDBF* cDBF)
{
    return NONE;
}

/******************************************************************************* 
* Function   : Next
* Description: 切换到DBF文件的下一条记录
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 当前指向记录的序号, -1:切换失败; 0:下一条是Eof，无法切换到第一条; >0:切换成功，返回切换后的序号
* Others     : 
*******************************************************************************/
int Next(CDBF* cDBF)
{
    return NONE;
}

/******************************************************************************* 
* Function   : Prior
* Description: 切换到DBF文件的上一条记录
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 当前指向记录的序号, -1:切换失败; 0:当前已是第一条，无法向上; >0:切换成功，返回切换后的序号
* Others     : 
*******************************************************************************/
int Prior(CDBF* cDBF)
{
    return NONE;
}

/******************************************************************************* 
* Function   : Go
* Description: 切换到DBF文件的第rowNo条记录
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针
    * rowNo, 将要切换的记录的行号
* Output     :
* Return     : 当前指向记录的序号, -1:切换失败; >0:切换成功，返回切换后的序号
* Others     : 
*******************************************************************************/
int Go(CDBF* cDBF, int rowNo)
{
    return FAIL;
}

/******************************************************************************* 
* Function   : Eof
* Description: 如果指向最后一行的下一行就返回Eof为True
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 是否Eof, 0:Not Eof; 1:Eof
* Others     :
*******************************************************************************/
int Eof(CDBF* cDBF)
{
    return TRUE;
}

/******************************************************************************* 
* Function   : Edit
* Description: 编译当前CDBF所指向的行
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 是否允许编辑, -1:不允许编辑; 1:允许编辑
* Others     :  编辑成功后需调用Post方法从内存更新到磁盘
*******************************************************************************/
int Edit(CDBF* cDBF)
{
    return FAIL;
}

/******************************************************************************* 
* Function   : Append
* Description: 新增一行
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 新增记录后的行号, -1:新增失败; >0:新增记录后DBF文件记录数
* Others     : 新增成功后需调用Post方法从内存更新到磁盘
*******************************************************************************/
int Append(CDBF* cDBF)
{
    return FAIL;
}

/******************************************************************************* 
* Function   : Delete
* Description: 将当前行设置为Deleted
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 是否删除成功, -1:删除失败; 1:删除成功
* Others     : 删除成功后需调用Post方法从内存更新到磁盘
*******************************************************************************/
int Delete(CDBF* cDBF);
{
    return FAIL;
}

/******************************************************************************* 
* Function   : Post
* Description: 将修改更新到磁盘
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 是否更新成功, -1:更新失败; 1:更新成功
* Others     : 
*******************************************************************************/
int Post(CDBF* cDBF)
{
    return FAIL;
}

/******************************************************************************* 
* Function   : Zap
* Description: 清空DBF中的数据
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 是否清空成功, -1:清空失败; 1:清空成功
* Others     :
    * OpenDBF成功后，就可以直接调用Zap清空DBF文件了 
*******************************************************************************/
int Zap(CDBF* cDBF)
{
    return FAIL;
}

/******************************************************************************* 
* Function   : Fresh
* Description: 将DBF信息从磁盘更新到内存，刷新记录数等信息
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     : 是否清空成功, -1:刷新失败; 1:刷新成功
* Others     :
*******************************************************************************/
int Fresh(CDBF* cDBF)
{
    return FAIL;
}

/******************************************************************************* 
* Function   : GetFieldAsBoolean
* Description: 获取cDBF指向的当前行的fieldName列的值，并作为布尔值返回
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针
    * fieldName, 列名
    * default, 返回失败时的默认值
* Output     :
* Return     : 布尔值, 0-False; 1-True; default-读取失败返回默认值
* Others     :
*******************************************************************************/
unsigned char GetFieldAsBoolean(CDBF* cDBF, char* fieldName, unsigned char bDefault);
{
    return TRUE;
}

/******************************************************************************* 
* Function   : GetFieldAsInteger
* Description: 获取cDBF指向的当前行的fieldName列的值，并作为整型值返回
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针
    * fieldName, 列名
    * default, 返回失败时的默认值
* Output     :
* Return     : 返回的整型值
* Others     :
*******************************************************************************/
int GetFieldAsInteger(CDBF* cDBF, char* fieldName, int iDefault);
{
    return 0;
}

/******************************************************************************* 
* Function   : GetFieldAsInteger
* Description: 获取cDBF指向的当前行的fieldName列的值，并作为浮点值返回
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针
    * fieldName, 列名
    * default, 返回失败时的默认值
* Output     :
* Return     : 返回的浮点值
* Others     :
*******************************************************************************/
float GetFieldAsFloat(CDBF* cDBF, char* fieldName, float fDefault);
{
    return 0.0;
}

/******************************************************************************* 
* Function   : GetFieldAsChar
* Description: 获取cDBF指向的当前行的fieldName列的值，并作为字符值返回
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针
    * fieldName, 列名
    * default, 返回失败时的默认值
* Output     :
* Return     : 返回的字符值
* Others     :
*******************************************************************************/
char GetFieldAsChar(CDBF* cDBF, char* fieldName, char cDefault);
{
    return ' ';
}

/******************************************************************************* 
* Function   : GetFieldAsString
* Description: 获取cDBF指向的当前行的fieldName列的值，并作为字符串返回
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针
    * fieldName, 列名
    * default, 返回失败时的默认值
* Output     :
* Return     : 返回的字符串
* Others     :
*******************************************************************************/
char* GetFieldAsString(CDBF* cDBF, char* fieldName, char* sDefault);
{
    return "";
}

/******************************************************************************* 
* Function   : SetFieldAsBoolean
* Description: 设置cDBF指向的当前行的fieldName列的值
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针
    * fieldName, 列名
    * value, 设置的值
* Output     :
* Return     : -1, 设置失败; 1-设置成功
* Others     :
*******************************************************************************/
int SetFieldAsBoolean(CDBF* cDBF, char* fieldName, unsigned char value)
{
    return SUCCESS;
}

/******************************************************************************* 
* Function   : SetFieldAsInteger
* Description: 设置cDBF指向的当前行的fieldName列的值
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针
    * fieldName, 列名
    * default, 设置的值
* Output     :
* Return     : -1, 设置失败; 1-设置成功
* Others     :
*******************************************************************************/
int SetFieldAsInteger(CDBF* cDBF, char* fieldName, int value)
{
    return SUCCESS;
}

/******************************************************************************* 
* Function   : SetFieldAsFloat
* Description: 设置cDBF指向的当前行的fieldName列的值
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针
    * fieldName, 列名
    * default, 设置的值
* Output     :
* Return     : -1, 设置失败; 1-设置成功
* Others     :
*******************************************************************************/
int SetFieldAsFloat(CDBF* cDBF, char* fieldName, float value)
{
    return SUCCESS;
}

/******************************************************************************* 
* Function   : SetFieldAsChar
* Description: 设置cDBF指向的当前行的fieldName列的值
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针
    * fieldName, 列名
    * default, 设置的值
* Output     :
* Return     : -1, 设置失败; 1-设置成功
* Others     :
*******************************************************************************/
int SetFieldAsChar(CDBF* cDBF, char* fieldName, char value)
{
    return SUCCESS;
}

/******************************************************************************* 
* Function   : SetFieldAsString
* Description: 设置cDBF指向的当前行的fieldName列的值
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针
    * fieldName, 列名
    * default, 设置的值
* Output     :
* Return     : -1, 设置失败; 1-设置成功
* Others     :
*******************************************************************************/
int SetFieldAsString(CDBF* cDBF, char* fieldName, char* value)
{
    return SUCCESS;
}

/*----------------------------------------------------------------------------
* Function   : Lock
* Description: 
    * 通过文件锁将cDBF当前行锁住，保证在多进程/多线程并发情况下的数据一致性
    * 该方法是cDBF的私有方法，不提供接口给外部调用
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     :
    * 是否锁定成功, -1:锁定失败; 1:锁定成功
* Others     :
----------------------------------------------------------------------------*/
int LockRow(CDBF* cDBF)
{
    return SUCCESS;
}

/*----------------------------------------------------------------------------
* Function   : UnLock
* Description: 
    * 给cDBF当前指向的行解文件锁
    * 该方法是cDBF的私有方法，不提供接口给外部调用
* Input      :
    * cDBF, OpenDBF返回的CDBF结构体指针  
* Output     :
* Return     :
    * 是否解锁成功, -1:解锁失败; 1:解锁成功
* Others     :
----------------------------------------------------------------------------*/
int UnLockRow(CDBF* cDBF)
{
    return SUCCESS;
}
