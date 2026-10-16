#include<stdio.h>
#include<stdlib.h>

struct Student {
    int roll_no;
    char name[20];
    float marks;
};

int main() {
    struct Student *ptr,*temp,*topper;
    int n,i,choice;
    float sum=0;

    printf("Enter total number of students: ");
    scanf("%d",&n);
    if(n<=0)return 1;

    ptr=(struct Student*)malloc(n*sizeof(struct Student));
    if(ptr==NULL)return 1;

    for(i=0;i<n;i++){
        printf("\nDetails of Student %d\n",i+1);
        printf("Roll number: ");
        scanf("%d",&(ptr+i)->roll_no);
        printf("Student name: ");
        scanf("%19s",(ptr+i)->name);
        printf("Enter marks obtained: ");
        scanf("%f",&(ptr+i)->marks);
    }

    topper=ptr;
    for(i=0;i<n;i++){
        sum+=(ptr+i)->marks;
        if((ptr+i)->marks>topper->marks)
            topper=ptr+i;
    }

    printf("\nClass average: %.2f\n",sum/n);
    printf("Highest scorer: %s (Roll No: %d, Marks: %.2f)\n",topper->name,topper->roll_no,topper->marks);

    printf("\nDo you want to enter 2 additional students? (1=Yes, 0=No): ");
    scanf("%d",&choice);

    if(choice==1) {
        temp=(struct Student*)realloc(ptr,(n+2)*sizeof(struct Student));
        if(temp==NULL) {
            free(ptr);
            return 1;
        }
        ptr=temp;

        for(i=n;i<n+2;i++){
            printf("\nDetails of Student %d\n",i+1);
            printf("Roll number: ");
            scanf("%d",&(ptr+i)->roll_no);
            printf("Student name: ");
            scanf("%19s",(ptr+i)->name);
            printf("Enter marks obtained: ");
            scanf("%f",&(ptr+i)->marks);
        }

        n+=2;
        sum=0;
        topper=ptr;

        for(i=0;i<n;i++){
            sum+=(ptr+i)->marks;
            if((ptr+i)->marks>topper->marks)
                topper=ptr+i;
        }

        printf("\nRevised class average: %.2f\n",sum/n);
        printf("Highest scorer after update: %s (Roll No: %d, Marks: %.2f)\n",topper->name,topper->roll_no,topper->marks);
    }

    free(ptr);
    return 0;
}