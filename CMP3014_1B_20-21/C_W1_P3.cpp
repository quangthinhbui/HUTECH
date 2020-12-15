// Week 1: Lam quen voi chuong trinh C
#include<stdio.h>
int main()
{
	int x;
	printf("-Nhap so thuc tu ban phim: ");
	scanf("%d",&x);
	float y;
	printf("So thuc vua nhap la: %d\n", x);
	printf("-Nhap so thuc tu ban phim: ");
	scanf("%f",&y);
	printf("So thuc vua nhap la: %f\n", y);
	char z;
	printf("-Nhap mot ky tu tu ban phim: ");
	fflush(stdin);
	scanf("%c",&z);
	printf("Ky tu vua nhap la: %c\n", z);
	int a, b;
	printf("-Nhap hai so nguyen tu ban phim (cach nhau dau ,): ");
	scanf("%d,%d", &a, &b);
	printf("Hai so nguyen vua vua nhap la: %d va %d\n", a, b);
	printf("Tong cua hai so nguyen %d va %d la: %d\n", a, b, a + b);
	printf("Hieu cua hai so nguyen %d va %d la: %d\n", a, b, a - b);
	printf("Tich cua hai so nguyen %d va %d la: %d\n", a, b, a * b);
	printf("Thuong cua hai so nguyen %d va %d la: %d\n", a, b, a / b);
	return 0;
}
