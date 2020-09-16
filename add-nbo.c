#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
    char f1[4] = { 0, };
    char f2[4] = { 0, };

    FILE* fp = fopen(argv[1], "r");
    fread(f1, 4, 1, fp);
    fclose(fp);

    fp = fopen(argv[2], "r");
    fread(f2, 4, 1, fp);
    fclose(fp);

    uint32_t* n1_ptr = f1;
    uint32_t* n2_ptr = f2;
    uint32_t n1 = ntohl(*n1_ptr);
    uint32_t n2 = ntohl(*n2_ptr);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1 + n2, n1 + n2);

    return 0;
}