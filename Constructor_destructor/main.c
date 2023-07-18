#include <stdio.h>

void inicio(void) __attribute__((constructor));
void finaliza(void) __attribute__((destructor));

int main()
{
    printf("Executing app\n");
    return 0;
}

void inicio(void)
{
    printf("Beginning app\n");
}

void finaliza(void)
{
    printf("Finishing app\n");
}
