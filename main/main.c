#include <vitasdk.h>
#include <stdio.h>
#include <stdlib.h>

#include "so_util.h"
#include "FalsoJNI.c"

int main(int argc, char *argv[]) {
    sceClibPrintf("Call of Duty: Strike Team Loader Started\n");

    // TODO: Init FalsoJNI and load target .so libraries

    while (1) {
        sceKernelDelayThread(100000);
    }

    return 0;
}
