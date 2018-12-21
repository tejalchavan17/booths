#include<stdio.h>
#include<math.h>
void twocomp(int M2[],int A[],int multiplicand,int p);
void main()
{
	int M[100],M2[100],Q[100],R[100],A[]=		{0,0,0,0},count=4,i,qminus=0,multiplicand=-7,multiplier=3,p=0,Rd=0,re,Md=0,Ad=0,multi,it=1,multip;
	Q[0]=Q[1]=Q[2]=Q[3]=0;
	if(multiplier<0)
	{
		multip=multiplier*(-1);
		for(i=3;multip>0&&i>=0;i--)
		{
			Q[i]=multip%2;
			multip=multip/2;
		}
	}
	for(i=3;multiplier>0&&i>=0;i--)
	{
		Q[i]=multiplier%2;
		multiplier=multiplier/2;
	}
	if(multiplicand<0)
		multi=multiplicand*(-1);
	else
		multi=multiplicand;
	while(count>0)
	{
		printf("\nIteration%d",it);
		if(Q[3]==1&&qminus==0)
		{
			printf("\nState:10 A=A-M");
			for(i=3;i>=0;i--)
			{
				Ad=Ad+(A[i]*pow(2,p));
				p++;
			}
			Ad=Ad+multi;
			A[0]=A[1]=A[2]=A[3]=0;
			for(i=3;Ad>0&&i>=0;i--)
			{
				A[i]=Ad%2;
				Ad=Ad/2;
			}
			Ad=0;
			printf("\nA=");
			for(i=0;i<4;i++)
				printf("%d\t",A[i]);
			printf("\nQ=");
			for(i=0;i<4;i++)
					printf("%d\t",Q[i]);
			printf("\nqminus=%d",qminus);
		}
		if(Q[3]==0&&qminus==1)
		{
			printf("\nState:01 A=A+M");
			twocomp(M2,A,multiplicand,p);
			printf("\nA=");
			for(i=0;i<4;i++)
				printf("%d\t",A[i]);
			printf("\nQ=");
			for(i=0;i<4;i++)
				printf("%d\t",Q[i]);
			printf("\nqminus=%d",qminus);
		}
		printf("\nState:Right Shift");
		qminus=Q[3];
		for(i=3;i>=1;i--)
			Q[i]=Q[i-1];
		Q[0]=A[3];
		for(i=3;i>=1;i--)
			A[i]=A[i-1]; 
		printf("\nA=");
		for(i=0;i<4;i++)
			printf("%d\t",A[i]);
		printf("\nQ=");
		for(i=0;i<4;i++)
			printf("%d\t",Q[i]);
		printf("\nqminus=%d",qminus);
		count=count-1;
		it++;
	}
	if(count==0)
	{  	
		for(i=0;i<4;i++)
			R[i]=A[i];
		re=4;
		for(i=0;i<4;i++)
		{
			R[re]=Q[i];
			re++;
		}	
		for(i=0;i<8;i++)
		{
			if(R[i]==1)
				R[i]=0;
			else
				R[i]=1;
		}
		Rd=0;p=0;
		for(i=7;i>=0;i--)
		{
			Rd=Rd+(R[i]*pow(2,p));
			p++;
		}
		Rd=Rd+1;
		if(multiplicand<0&&multiplier<0)
			Rd=Rd;
		else if(multiplicand<0||multiplier<0)
		{
			Rd=Rd*(-1);
		}
		else
			Rd=Rd;
		printf("\n Result=%d",Rd);
	}
}
void twocomp(int M2[],int A[],int multiplicand,int p)
{
	int i,Md=0,pd=0;
	if(multiplicand<0)
		multiplicand=multiplicand*(-1);
	else
		multiplicand=multiplicand;
	M2[0]=M2[1]=M2[2]=M2[3]=0;
	for(i=3;multiplicand>0&&i>=0;i--)
	{
		M2[i]=multiplicand%2;
		multiplicand=multiplicand/2;
	}
	for(i=0;i<4;i++)
	{
		if(M2[i]==1)
			M2[i]=0;
		else
			M2[i]=1;
	}
	Md=0;p=0;
	for(i=3;i>=0;i--)
	{
		Md=Md+(M2[i]*pow(2,p));
		p++;
	}
	Md=Md+1;
	pd=0;p=0;
	for(i=3;i>=0;i--)
	{
		pd=pd+(A[i]*pow(2,p));
		p++;
	}
	pd=pd+Md;
	A[0]=A[1]=A[2]=A[3]=0;
	for(i=3;pd>0&&i>=0;i--)
	{
		A[i]=pd%2;
		pd=pd/2;
	}
	pd=0;
}
/*Output:
tejal@ubuntu:~/Desktop$ gcc booths.c -lm
tejal@ubuntu:~/Desktop$ ./a.out

Iteration1
State:10 A=A-M
A=0	1	1	1	
Q=0	0	1	1	
qminus=0
State:Right Shift
A=0	0	1	1	
Q=1	0	0	1	
qminus=1
Iteration2
State:Right Shift
A=0	0	0	1	
Q=1	1	0	0	
qminus=1
Iteration3
State:01 A=A+M
A=1	0	1	0	
Q=1	1	0	0	
qminus=1
State:Right Shift
A=1	1	0	1	
Q=0	1	1	0	
qminus=0
Iteration4
State:Right Shift
A=1	1	1	0	
Q=1	0	1	1	
qminus=0
 Result=-21*/
