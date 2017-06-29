/**
 * http://www.xumenger.com/dbf-20160703/
 */
#include <stdio.h>

//DBF中支持的数据类型
#define TYPE_NUMERIC 'N'        //整数、浮点小数
#define TYPE_CHAR 'C'           //字符、字符串
#define TYPE_DATE 'D'           //日期
#define TYPE_LOGICAL 'L'        //逻辑
#define TYPE_FLOAT 'F'          //浮点小数

//DBF中的标记字节

//字段缺省长度

//字段长度上限

//DBF文件包括：文件结构说明区、数据区
//文件结构说明区包括：数据库参数区、记录结构表区
//数据库参数区占32字节
//记录结构表取包括各个字段参数，每个字段占32字节

//强制结构体不对齐，保证内存结构体和DBF文件一致
#pragma pack(1)

//数据库参数区
typedef struct TDBFHead
{
    char Mark;                //DBF当前版本
    unsigned char Year;       //保存时的年-1900
    unsigned char Month;      //保存时的月
    unsigned char Day;        //保存时的日
    int RecCount;             //DBF中记录个数
    unsigned short DataOffset;//当前DBF文件头占用字节长度
    unsigned short RecSize;   //一条记录的字节长度，即每行数据所占长度
    char Reserved[20];        //保留字节
}DBFHead;

//记录结构表区
typedef struct TDBFField
{
    char FieldName[11];       //字段名称，ASCII码
    char FieldType;           //字段数据类型：C字符、N数字、D日期、B二进制
    int FieldOffset;          //保留字节
    unsigned char Width;      //字段长度，1Byte=8bit，所以最多有2^8长度
    unsigned char Scale;      //字段你的精度
    char Reserved[14];
}DBFFiled;

typedef struct TDBF
{
    DBFHead: head;
    //列信息
    //句柄
    //文件锁
}CDBF;


//打开DBF
CDBF* OpenDBFFile(char* filePath);
//关闭DBF
int CloseDBFFile(CDBF* cDBF);
//切换到第一行
int First(CDBF* cDBF);
//切换到