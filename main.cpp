#include <stdint.h>
#include <netinet/in.h>
#include <cstdio>

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("syntax :  add-nbo <file1> <file2>\n");
        printf("sample :  add-nbo a.bin b.bin\n");
        return -1;
    }

    FILE * file1 = fopen(argv[1], "rb");
    FILE * file2 = fopen(argv[2], "rb");

    uint32_t f1, f2;

    fread(&f1, sizeof(uint32_t), 1, file1);
    fread(&f2, sizeof(uint32_t), 1, file2);

    f1 = ntohl(f1);
    f2 = ntohl(f2);

    uint32_t result = f1 + f2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", f1, f1, f2, f2, result, result);

    fclose(file1);
    fclose(file2);
}
