#include <stdio.h>
#include "../src/cDBF.h"

int main()
{
    int i=0;
    printf("test Start\n");

    printf("\nstart OpenDBF\n");
    CDBF* cDBF = OpenDBF("./testDBF.dbf");
    if (NULL == cDBF){
        printf("OpenDBF Error\n");
        return -1;
    }

    printf("\nget DBFHead Message\n");
	printf("cDBF's path:%s\n", cDBF->Path);
	printf("cDBF's reccount=%d\n", cDBF->Head->RecCount);

    printf("\nget DBFField Message\n");
	for(i=0; i<cDBF->FieldCount; i++){
        printf("filed = %d, name = %s\n", i, cDBF->Fields[i].FieldName);
    }

    printf("\nget Data Message\n");
    Go(cDBF, 1);
    for(i=0; i<cDBF->FieldCount; i++){
        printf("filed = %d, name = %s, value=%s\n", i, cDBF->Values[i].Field->FieldName, cDBF->Values[i].ValueBuf);
    }

    printf("\nstart CloseDBF\n");
    CloseDBF(cDBF);

    printf("\ntest Finish\n");
    return 0;
}
