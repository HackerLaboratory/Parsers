/********************************************************************************* 
 * Copyright(C), Xumenger
 * FileName     : cDBF.h
 * Author       : xumenger
 * Version      : V1.0.0 
 * Date         : 2017-06-30
 * Description  : 定义DBF相关的结构体
     1.DBF文件包括：文件结构说明区、数据区
     2.文件结构说明区包括：数据库参数区、记录结构表区
     3.数据库参数区占32字节
     4.记录结构表取包括各个字段参数，每个字段占32字节
     5.http://www.xumenger.com/dbf-20160703/
     6.http://www.xumenger.com/DBF-DBFViewer-VisualFoxPro-20160802/
**********************************************************************************/  
#ifndef CDBFSTRUCT_H
#define CDBFSTRUCT_H

//DBF中支持的数据类型
#define TYPE_NUMERIC 'N'        //整数、浮点小数
#define TYPE_CHAR 'C'           //字符、字符串
#define TYPE_DATE 'D'           //日期
#define TYPE_LOGICAL 'L'        //逻辑
#define TYPE_FLOAT 'F'          //浮点小数

//DBF中的标记字节
#define DBFEOF = 0x1A           //DBF文件结束
#define HDREND = 0x0D           //头结束
#define FOXPRODBF = 0x03        //FoxPro文件标识
#define SPACE = ' '             //空格字符
#define DELETED = '*'           //删除标记
#define FDARSVLEN = 14          //FDA中的保留字节数
#define HDRRSVLEN = 20          //HDR中的保留字节数

//字段缺省长度
#define DEFLEN_CHAR = 15        //字符串
#define DEFLEN_NUMERIC = 12     //数值
#define DEFLEN_DATE = 8         //日期
#define DEFLEN_LOGICAL = 1      //逻辑
#define DEFLEN_FLOAT = 15       //浮点数总长
#define DEFLEN_PREC = 4         //浮点数小数部分

//字段长度上限
#define LIMLEN_CHAR = 254       //字符串
#define LIMLEN_NUMERIC = 20     //数值
#define LIMLEN_DATE = 8         //日期
#define LIMLEN_LOGICAL = 1      //逻辑
#define LIMLEN_FLOAT = 20       //浮点

//C没有布尔类型，在这里定义
#define TRUE 1
#define FALSE 0

#define NONE 0
#define SUCCESS 1
#define FAIL -1

//强制结构体不对齐，保证内存结构体和DBF文件一致
#pragma pack(1)

//数据库参数区
typedef struct TDBFHead
{
    char Mark;                  //DBF当前版本
    unsigned char Year;         //保存时的年-1900
    unsigned char Month;        //保存时的月
    unsigned char Day;          //保存时的日
    int RecCount;               //DBF中记录个数
    unsigned short DataOffset;  //当前DBF文件头占用字节长度
    unsigned short RecSize;     //一条记录的字节长度，即每行数据所占长度
    char Reserved[20];          //保留字节
}DBFHead;

//记录结构表区
typedef struct TDBFField
{
    char FieldName[11];         //字段名称，ASCII码
    char FieldType;             //字段数据类型：C字符、N数字、D日期、B二进制
    int FieldOffset;            //保留字节
    unsigned char Width;        //字段长度，1Byte=8bit，所以最多有2^8长度
    unsigned char Scale;        //字段的精度
    char Reserved[14];          //保留字节
}DBFField;

//CDBF对象，封装DBF的所有信息
typedef struct TCDBF
{
    DBFHead* Head;               //文件头信息
    DBFField* Field;            //根据DBF实际的列数，动态申请对应个数的DBFField结构体
    int FieldCount;             //列个数
    char* Path;                 //文件路径
    FILE* FHandle;              //文件描述符
    int RecNo;                  //CDBF当前指向的行号
}CDBF;

#endif