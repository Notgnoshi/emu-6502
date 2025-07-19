#include "emu/add.h"

#include <assert.h>

int main(void)
{
    assert(emu_add(2, 2) == 4);

    return 0;
}
