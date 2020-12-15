// Week 1: Lam quen voi chuong trinh C
#include <stdio.h>
#include <math.h>
const float pi=3.14;
int main()
{
	int a, m, n, p, q;
	printf("Nhap mot so nguyen duong tu ban phim: ");
	scanf("%d",&a);
	m = a % 10;
	n = ((a - m)/10) % 10;
	p = ((a - m - 10*n)/100) % 10;
	q = ((a - m - 10*n - 100*p)/1000) % 10;
	printf("So dao nguoc cua so %d vua nhap la: %d%d%d%d\n", a,m,n,p,q);
	return 0;
}
