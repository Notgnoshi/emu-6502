#include "config.h"
#include "emu/add.h"

#include <stdio.h>

int main(void)
{
    printf(PACKAGE_STRING "\n");
    int result = emu_add(2, 2);
    printf("result: %d\n", result);
    return 0;
}
