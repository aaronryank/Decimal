#include <stdio.h>

int main(int argc, char **argv)
{
    argv++;
    printf("%c: %.3d",**argv,**argv);
}
