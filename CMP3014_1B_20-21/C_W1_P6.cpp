// Week 1: Lam quen voi chuong trinh C
#include <stdio.h>
#include <math.h>
const float pi=3.14;
int main()
{
	float a, b, c, p;
	printf("Nhap ban kinh tu ban phim: ");
	scanf("%f,%f,%f",&a,&b,&c);
	if (a>0 & b>0 & c>0)
	{
		printf("Cac so nhap vao hop le\n");
	}
	else
	{
		printf("Cac so nhap vao khong hop le\n");
	}
	if (a+b>c & b+c>a & c+a>b)
	{
		printf("Ba so %f, %f, %f lap thanh ba canh cua mot tam giac\n", a,b,c);
		printf("Chu vi tam giac: %f\n", a+b+c);
		p = (a+b+c)/2;
		printf("Dien tich tam giac: %f\n", sqrt(p*(p-a)*(p-b)*(p-c)));
	}
	else
	{
		printf("Ba so %f, %f, %f khong lap thanh ba canh cua mot tam giac\n", a,b,c);
	}
	return 0;
}
