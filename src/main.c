#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <emulator.h>

int main(int argc, char** argv)
{
    if(argc != 2) { return 1; }

    Emulator* emulator = malloc(sizeof(Emulator) + MEMORY);
    memset(emulator, 0, sizeof(Emulator));
    
    emulator->registers[1] = UINT32_MAX;
    emulator->registers[2] = MEMORY - 1;

    FILE* fd = fopen(argv[1], "rb");

    fseek(fd, 0, SEEK_END);
    size_t size = ftell(fd);
    fseek(fd, 0, SEEK_SET);

    fread(emulator->memory, 1, size, fd);

    fclose(fd);

    emulate(emulator);

    free(emulator);

    return 0;
}