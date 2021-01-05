#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX 20
#define VOCUC 1000
int LuuVet[MAX];
int ChuaXet[MAX];
int DoDaiDuongDiToi[MAX];
typedef struct GRAPH
{
	int n;
	int a[MAX][MAX];
}DOTHI;
//============================ CAU A =====================
int DocMaTranKe(const char* TenFile,DOTHI &g)
{	FILE* f;
	f = fopen(TenFile,"rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i=0;i<g.n;i++)
		for(int j=0;j<g.n;j++)
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
	return 1;
}
//============================ CAU B =====================
void XuatMaTranKe(DOTHI g)
{	printf("So dinh cua do thi = %d\n",g.n);
	printf("Ma tran ke cua do thi la:\n");
	for(int i=0;i<g.n;i++)
	{	for(int j=0;j<g.n;j++)
			printf("%4d",g.a[i][j]);
		printf("\n");
	}
}
//============================ CAU C =====================
void DiTimCacDinhLienThong(DOTHI g, int Nhan[], int i)
{
	for(int j=0;j<g.n;j++)
		if(g.a[i][j] !=0 && Nhan[j] != Nhan[i])
		{
			Nhan[j] = Nhan[i];
			DiTimCacDinhLienThong(g, Nhan, j);
		}
}

int XetLienThong(DOTHI g)
{
	int Nhan[MAX];
	for(int i=0;i<g.n;i++)
		Nhan[i] = 0;
	
	int SoThanhPhanLT = 0;
	for(int i=0;i<g.n;i++)
		if(Nhan[i] ==0)
		{
			SoThanhPhanLT++;
			Nhan[i] = SoThanhPhanLT;
			DiTimCacDinhLienThong(g, Nhan, i);
		}
	return (SoThanhPhanLT == 1);
}

void KQLT(DOTHI g)
{
	if(XetLienThong(g) ==0)
	{
		printf("\nDo thi khong lien thong");
		return;
	}
	else
	{
			printf("\nDo thi  lien thong\n\n");
	}
}


//============================ CAU D =====================
int TimDuongDiNhoNhat(DOTHI g)
{	
	int li = -1;
	float p = VOCUC;
	for(int i=0; i<g.n; i++)
	{	if(ChuaXet[i] == 0 && DoDaiDuongDiToi[i] < p)
		{	p = DoDaiDuongDiToi[i];
			li = i;
		}
	}
	return li; 
}

void CapNhatDuongDi(int u, DOTHI g)
{	
	ChuaXet[u] = 1; 
	for(int v=0; v<g.n; v++)
	{   if(ChuaXet[v] == 0 && g.a[u][v] > 0 && g.a[u][v] < VOCUC) 
			if(DoDaiDuongDiToi[v] > DoDaiDuongDiToi[u] + g.a[u][v]) 
			{	DoDaiDuongDiToi[v] = DoDaiDuongDiToi[u] + g.a[u][v];
				LuuVet[v] = u;
			}
	}
}

void KetQua_DQ(int F, int S)
{
	if(F != S)	KetQua_DQ(LuuVet[F], S);
	printf("%d -> ",F);
}

void Dijkstra(int S,int F,DOTHI g)
{

	for(int i=0; i<g.n; i++)
	{
		ChuaXet[i] = 0;
		DoDaiDuongDiToi[i] = VOCUC;
		LuuVet[i] = -1;
	}

	DoDaiDuongDiToi[S] = 0;
	while(ChuaXet[F] == 0)
	{	
		int u = TimDuongDiNhoNhat(g);
		if(u == -1) break;
		CapNhatDuongDi(u, g);
	}

	if(ChuaXet[F] == 1) 
	{	
		printf("Duong di ngan nhat tu %d den %d:\n",S,F);
		KetQua_DQ(F, S);
		printf("\b\b\b\b.  Do dai = %d",DoDaiDuongDiToi[F]);
	}
	else
		printf("\n Khong co duong di tu %d den %d",S,F);
}
//============================== MAIN =======================
int main()
{                                 
	DOTHI g;
	
	char inputfile[100];
	char ch;
	int S, F;	
	do
	{
		printf("\n\nNhap ten file do thi: ");
		gets(inputfile);
		if(DocMaTranKe(inputfile, g)==1) 
		{
			printf("Da lay thong tin do thi tu file thanh cong.\n\n");
			XuatMaTranKe(g);
		
			printf("\n\n LIEN THONG: ");
			KQLT(g);
			printf("\n Nhap dinh A: ");  scanf("%d", &S);
			printf("\n Nhap dinh B: "); scanf("%d", &F);			
			
			printf("\n\n Dijkstra: ");
			Dijkstra(S,F,g);
			printf("\n\n================================================\n\n");
		}
		printf("\n\n-----------------------\n");
		printf("Ban tiep tuc nua khong[Y/N]: ");
		ch=getche();
	}while(ch=='Y'||ch=='y');
	return 0;
}

