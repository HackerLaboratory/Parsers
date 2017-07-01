#include <stdio.h>
#include "../src/cDBF.h"

int main()
{
    printf("test Start\n");

    printf("\nstart OpenDBF\n");
    CDBF* cDBF = OpenDBF("./testDBF.dbf");
    if (NULL == cDBF){
        printf("OpenDBF Error\n");
        return -1;
    }

    printf("\nget DBFHead Message\n");

    printf("\nget DBFField Message\n");

    printf("\nget Data Message\n");

    printf("\nstart CloseDBF\n");
    CloseDBF(cDBF);

    printf("\ntest Finish\n");
    return 0;
}
