#include<conio.h>
#include<stdio.h>
int d,n;
void tao_File(){
	int i,x;
	FILE *fl;
	fl=fopen("f:\\btl\\day.int","wb");
	printf("So phan tu la : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		fprintf(fl,"%3d",x);
	}
	fclose(fl);
}
void xuat_File(){
	int x;
	FILE*fl;
	fl=fopen("f:\\btl\\day.int","rb");
	int i = 0 ;
	while(i<n){
		fscanf(fl,"%d",&x);
		printf("%3d",x);
		i++;
	}
	fclose(fl);
}
void chia(FILE*a,FILE*b,FILE*c,int d){
	int dem;
	int x ;
	a=fopen("f:\\btl\\day.int","rb");
	b=fopen("f:\\btl\\day1.int","wb");
	c=fopen("f:\\btl\\day2.int","wb");
	while(!feof(a)){
		// chia d phan tu cho b
		dem=0;
		while((dem<d) && (!feof(a))){
			fscanf(a,"%5d",&x);
			fprintf(b,"%5d",x);
			dem++;
		}
		dem=0;
		while((dem<d) && (!feof(a))){
			fscanf(a,"%5d",&x);
			fprintf(c,"%5d",x);
			dem++;
		}
		}
	fclose(a);
	fclose(b);
	fclose(c);
}
void tron(FILE*a,FILE*b,FILE*c,int d){
	/*
Tron p phan tu tren b voi p phan tu tren c thanh 2*p phan tu tren a
cho den khi file b hoac c het.
*/
	int x , y;
	int l , r ;
	int stop;
	a=fopen("f:\\btl\\day.int","wb");
	b=fopen("f:\\btl\\day1.int","rb");
	c=fopen("f:\\btl\\day2.int","rb");
	while((!feof(b)) && (!feof(c))){
		l=0;// so phan tu cua b da ghi len a
		r=0;// so phan tu cua c da ghi len a
		fscanf(b,"%5d",&x);
		fscanf(c,"%5d",&y);
		stop=0;
		while((l!=d) && (r!=d) &&(!stop)){
			if(x<y){
				fprintf(a,"%5d",x);
				l++;
				if((l<d) && (!feof(b)))/* chua du d phan tu va chua het file b */
				fscanf(b,"%5d",&x);
				else{
					fprintf(a,"%5d",y);
					r++;
				if(feof(b))
					stop = 1 ;
				}
				}
			else{
				fprintf(a,"%5d",y);
				r++;
				if((r<d) && (!feof(c)))
				/*chua du p phan tu va chua het file c*/
				fscanf(c,"%5d",&y);
				else{
				fprintf(a,"%5d",x);
				l++;
				if(feof(c))
				stop=1;
			}
		}
	}
}		
/*
Chep phan con lai cua p phan tu tren b len a
*/
while((!feof(b)) && (l<d)){
	fscanf(b,"%5d",&x);
	fprintf(a,"%5d",x);
	l++;
}
while((!feof(c)) && (r<d)){
	fscanf(c,"%5d",&y);
	fprintf(a,"%5d",y);
	l++;
}

if (!feof(b)){
/*chep phan con lai cua b len a*/
	while (!feof(b)){
		fscanf(b,"%5d",&x);
		fprintf(a,"%5d",x);
}
}
if (!feof(c))
{
/*chep phan con lai cua c len a*/
	while (!feof(c)){
		fscanf(c,"%5d",&x);
		fprintf(a,"%5d",x);
}
}
fclose(a); fclose(b); fclose(c);
}
main(){
	FILE*a,*b,*c;
	tao_File();
	xuat_File();
	d=1;
	while (d < n){
	chia(a,b,c,d);
	tron(b,c,a,d);
	d=2*d;
	}
	printf("\n");
	xuat_File();
	return 0 ;
	
}
