#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <time.h>

#include "util.h"

#define THRESHOLD 100
int main() {
    srand(time(NULL));
    int i;
    char *buf = allocate_shared_buffer();

    while(1){
        i = rand()%1024;
        uint64_t probe_addr = (uint64_t)buf + i * 128;
        clflush(probe_addr);

        for (int j = 0; j < 300; j++);
        uint64_t access_time = measure_one_block_access_time(probe_addr);
        //printf("Address %d access time: %lu\n", i, access_time);
        if (access_time < THRESHOLD)break;
    }
    printf("Flag: %d\n", i);
    deallocate_shared_buffer(buf);
    return 0;
}
