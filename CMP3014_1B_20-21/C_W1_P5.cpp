// Week 1: Lam quen voi chuong trinh C
#include<stdio.h>
int main()
{
	int x, y, max;
	printf("- Nhap hai so nguyen tu ban phim (cach nhau dau ,): ");
	scanf("%d,%d", &x, &y);
    if (x >= y)
    {
        max = x;
    }
    else
    {
        max = y;
    }
    printf("So lon nhat trong hai so %d va %d la: %d\n", x, y, max);
    int a, b, c, maxx;
	printf("- Nhap ba so nguyen tu ban phim (cach nhau dau ,): ");
	scanf("%d,%d,%d", &a, &b, &c);
    maxx = a;
    if (b >= maxx)
    {
        maxx = b;
    }
    if (c >= maxx)
    {
        maxx = c;
    }
    printf("So lon nhat trong ba so %d, %d, %d la: %d\n", a, b, c, maxx);
	return 0;
}
