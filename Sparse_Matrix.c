/*
A matrix is a two-dimensional data object made of m rows and n columns, therefore having total m x n values. 
If most of the elements of the matrix have 0 value, then it is called a sparse matrix.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct { //structure of sparse matrix
	int row,col,value;
}sp;

typedef struct fasttranspose //structure for fast transpose
{
    int row_ele,row_start;
}fast;

void accept(int arr[][10],int m, int n) //function for acepting regular matrix from user
{
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("Enter element arr[%d][%d]: ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
}

void display(int arr[][10],int m,int n) //function to display the regular entered matrix
{
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}

void convert(int arr[][10],int m,int n,sp s[]) //function to convert regular matrix to sparse matrix
{
	int i,j;
	s[0].row = m;
	s[0].col = n;
	int r=1;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(arr[i][j]!=0){
				s[r].row = i;
				s[r].col = j;
				s[r].value = arr[i][j];
				r++;
			}
		}
	}
	s[0].value = r-1;
}

void displaysparse(sp s[]) //function to display sparse matrix
{
	int i,j;
	printf("\n\tROW\tCOLUMN\tVALUE\n");
	for(i=0;i<=s[0].value;i++){
		printf("s[%d]\t%d\t%d\t%d\n",i,s[i].row,s[i].col,s[i].value);
	}
	printf("\n");
}

void addition(sp s1[],sp s2[],sp s3[]){ //function to perform addition of two sparse matrices
	int i=1,j=1,k=1;
	while(i<=s1[0].value && j<=s2[0].value)
	{
		if(s1[i].row<s2[j].row)
		{
			s3[k].row = s1[i].row;
			s3[k].col = s1[i].col;
			s3[i].value = s1[i].value;
			k++;
			i++;
		}
		else if(s2[j].row<s1[i].row)
		{
			s3[k].row = s2[j].row;
			s3[k].col = s2[j].col;
			s3[k].value = s2[j].value;
			k++;
			j++;
		}
		else if(s1[i].col<s2[j].col)
		{
			s3[k].row = s1[i].row;
			s3[k].col = s1[i].col;
			s3[k].value = s1[i].value;
			k++;
			i++;
		}
		else if(s1[i].col>s2[j].col)
		{
			s3[k].row = s2[j].row;
			s3[k].col = s2[j].col;
			s3[k].value = s2[j].value;
			k++;
			j++;
		}
		else
		{
			s3[k].row = s1[i].row;
			s3[k].col = s1[i].col;
			s3[k].value = s1[i].value + s2[j].value;
			k++;
			i++;
			j++;
		}
	}
	while(i<s1[0].value)
	{
		s3[k].row = s1[i].row;
		s3[k].col = s1[i].col;
		s3[k].value = s1[i].value;
		k++;
		i++;
	}
	while(j<s2[0].value)
	{
		s3[k].row = s2[j].row;
		s3[k].col = s2[j].col;
		s3[k].value = s2[j].value;
		k++;
		j++;
	}
	s3[0].row = s1[0].row;
	s3[0].col = s1[0].col;
	s3[0].value = k-1;
}

void stranspose(sp s[]) //function to calculate simple transpose of sparse matrix
{
	sp temp[20];
	temp[0].row = s[0].row;
	temp[0].col = s[0].col;
	temp[0].value = s[0].value;
	int k=1;
	int total_columns = s[0].col;
	int total_terms = s[0].value;
	int i,j;
	for(i=0;i<total_columns;i++)
	{
		for(j=0;j<total_terms;j++)
		{
			if(s[j].col==i)
			{
				temp[k].row = s[j].col;
				temp[k].col = s[j].row;
				temp[k].value = s[j].value;
				k++;
			}
		}
	}
	displaysparse(temp);
}

void fast_transpose(sp s[]) //function to calculate fast transpose of sparse matrix
{
	int i,j;
	fast f[s[0].col];
	sp temp[20];
	temp[0].row = s[0].row;
	temp[0].col = s[0].col;
	temp[0].value = s[0].value;
	for(i=0;i<s[0].col;i++)
	{
		f[i].row_ele = 0;
	}
	for(i=1;i<=s[0].value;i++)
	{
		f[s[i].col].row_ele =  f[s[i].col].row_ele + 1;
	}
	f[0].row_start = 0;
	for(i=1;i<s[0].col;i++)
	{
		f[i].row_start = f[i-1].row_start + f[i-1].row_ele;
	}
	printf("Element position start: \n");
	for(int i=0;i<s[0].col;i++)
   {
       printf("%d\t %d\n",f[i].row_ele,f[i].row_start);
   }
   for(int i=1;i<=s[0].value;i++)
   {
       temp[f[s[i].col].row_start].row=s[i].col;
       temp[f[s[i].col].row_start].col=s[i].row;
       temp[f[s[i].col].row_start].value=s[i].value;
       f[s[i].col].row_start+=1;
   }
   printf("Transpose=>\n");
   displaysparse(temp);
}



int main()
{
	int m1,n1,m2,n2,i,j,size1,size2,choice;
	int a1[10][10],a2[10][10];
	printf("Enter row and column of matrix 1: ");
	scanf("%d %d",&m1,&n1);
	accept(a1,m1,n1);
	printf("\nEnter row and column of matrix 2: ");
	scanf("%d %d",&m2,&n2);
	accept(a2,m2,n2);
	sp s1[20],s2[20],s3[40];
	do{
		printf("\n1:Display Conversion\n2:Addition\n3:Simple Transpose\n4:Fast transpose\n5:Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				convert(a1,m1,n1,s1);
				printf("Converted Matrix 1:\n");
				displaysparse(s1);
				convert(a2,m2,n2,s2);
				printf("Converted Matrix 2:\n");
				displaysparse(s2);
				break;
			case 2:
				if(s1[0].col==s2[0].col && s1[0].row==s2[0].row){
					addition(s1,s2,s3);
					printf("Addition matrix:\n");
					displaysparse(s3);
				}
				else{
					printf("Cannot add different dimension\n");
				}
				break;
			case 3:
				printf(" Transpose of Matrix1=>\n");
             	stranspose(s1);
             	printf(" Transpose of Matrix2=>\n");
             	stranspose(s2);
             	break;
            case 4:
            	fast_transpose(s1);
            	fast_transpose(s2);
            	break;
            case 5:
            	printf("Thank you for using the program :)\n");
            	exit(1);
            default:
            	printf("Invalid choice\n");
		}
	}while(choice!=5);
	return 0;
}
