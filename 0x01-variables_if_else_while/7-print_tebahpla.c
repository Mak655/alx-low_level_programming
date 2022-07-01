#include<stdio.h>
/**
 * main - main block
 * Description: program that prints the lowercase alphabet in reverse
 * Return:0
 */
int main(void)
{
char c = 'z';
while (c >= 'a')
{
putchar(c);
c--;
}
putchar('\n');
return (0);}
