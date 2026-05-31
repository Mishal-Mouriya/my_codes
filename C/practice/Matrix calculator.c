//Matrix calculator
//supports addition multiplication and subraction

#include <stdio.h>

int* add(int*,int*);
int* multiply(int*,int*);


int main()
{
    int rowA,colA,i,j,k,rowb,colb,rowc,colc;
    char cmd;

    //getting Matrix A
    printf("enter the rows and cols of matrix A>\n");
    scanf("%d%d",&rowA,colA);
    printf("enter the matrix row wise");
    int A[rowA][colA];
    for(i=0;i<rowA;i++)
    {
        for(j=0;j<colA;j++)
        {
            scanf("%d",A[i][j]);
        }
    }

    printf("\n\n");

     //getting Matrix b
    printf("enter the rows and cols of matrix B>\n");
    scanf("%d%d",&rowb,colb);
    printf("enter the matrix row wise");
    int B[rowb][colb];
    for(i=0;i<rowb;i++)
    {
        for(j=0;j<colb;j++)
        {
            scanf("%d",B[i][j]);
        }
    }
    int end=0;

    while (end==0)
    {      

        printf("press a for addition m for multiplication and s for subraction,1 to end");
        scanf("%c",&cmd);

        switch(cmd)
        {
            case 'a':
                if(rowA==rowb && colA==colb)
                {
                    add(A,B);
                    break;
                }
                else
                {
                    printf("These matrices cannot be added");
                }
                break;

            
            case 's':
                if(rowA==rowb && colA==colb)
                {
                    sub(A,B);               
                }
                else
                {
                    printf("These matrices cannot be subreacted ");
                }
                break;
            
        }
    }
}


