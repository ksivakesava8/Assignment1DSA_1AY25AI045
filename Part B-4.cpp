#include<stdio.h>
#define MAX 100

typedef struct {
    int row,col,value;
} term;

void fast_transpose(term a[],term b[]) {
    int row_terms[MAX]={0},starting_pos[MAX]={0};
    int i,j,num_cols=a[0].col,num_terms=a[0].value;

    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].value=num_terms;

    for(i=1;i<=num_terms;i++)
        row_terms[a[i].col]++;

    starting_pos[0]=1;
    for(i=1;i<num_cols;i++)
        starting_pos[i]=starting_pos[i-1]+row_terms[i-1];

    printf("\nNumber of terms in each column:\n");
    for(i=0;i<num_cols;i++)
        printf("%d ",row_terms[i]);

    printf("\nPosition of each column:\n");
    for(i=0;i<num_cols;i++)
        printf("%d ",starting_pos[i]);
    printf("\n");

    for(i=1;i<=num_terms;i++) {
        j=starting_pos[a[i].col]++;
        b[j].row=a[i].col;
        b[j].col=a[i].row;
        b[j].value=a[i].value;
    }
}

void display(term a[]) {
    int i;
    printf("Row Col Value\n");
    for(i=0;i<=a[0].value;i++)
        printf("%3d %3d %5d\n",a[i].row,a[i].col,a[i].value);
}

int main() {
    term a[MAX],b[MAX];
    int rows,cols,i,j,count=0,value;

    printf("Enter the matrix size (rows and columns): ");
    scanf("%d %d",&rows,&cols);

    if(rows<=0||cols<=0||rows>=MAX||cols>=MAX) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    printf("Enter the matrix values row by row:\n");
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            scanf("%d",&value);
            if(value!=0) {
                count++;
                a[count].row=i;
                a[count].col=j;
                a[count].value=value;
            }
        }
    }

    a[0].row=rows;
    a[0].col=cols;
    a[0].value=count;

    printf("\nSparse matrix in triplet form:\n");
    display(a);

    fast_transpose(a,b);

    printf("\nTriplet form after transpose:\n");
    display(b);
    printf("Transpose completed successfully.\n");

    return 0;
}