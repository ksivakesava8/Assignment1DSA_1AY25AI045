#include<stdio.h>

typedef struct {
    int degree;
    float coef[101];
} polynomial;

polynomial add(polynomial a,polynomial b) {
    polynomial c;
    int i,exp;
    c.degree=a.degree>b.degree?a.degree:b.degree;

    for(i=0;i<=c.degree;i++) {
        exp=c.degree-i;
        c.coef[i]=(exp<=a.degree?a.coef[a.degree-exp]:0)+(exp<=b.degree?b.coef[b.degree-exp]:0);
    }

    while(c.degree>0&&c.coef[0]==0) {
        for(i=0;i<c.degree;i++)
            c.coef[i]=c.coef[i+1];
        c.degree--;
    }
    return c;
}

void display(polynomial p) {
    int i,exp,first=1;
    float c;

    for(i=0;i<=p.degree;i++) {
        c=p.coef[i];
        exp=p.degree-i;
        if(c==0) continue;

        if(!first)
            printf(c>0?" + ":" - ");
        else if(c<0)
            printf("-");

        if(c<0) c=-c;

        if(exp==0)
            printf("%g",c);
        else if(exp==1) {
            if(c==1) printf("x");
            else printf("%gx",c);
        }
        else {
            if(c==1) printf("x^%d",exp);
            else printf("%gx^%d",c,exp);
        }
        first=0;
    }

    if(first) printf("0");
    printf("\n");
}

polynomial readPolynomial() {
    polynomial p;
    int i;

    printf("Enter the polynomial degree (0-100): ");
    scanf("%d",&p.degree);

    if(p.degree<0||p.degree>100) {
        p.degree=-1;
        return p;
    }

    printf("Enter coefficients from highest power to lowest:\n");
    for(i=0;i<=p.degree;i++)
        scanf("%f",&p.coef[i]);

    return p;
}

int main() {
    polynomial a,b,c;

    printf("Enter the first polynomial:\n");
    a=readPolynomial();
    if(a.degree<0) return 1;

    printf("Enter the second polynomial:\n");
    b=readPolynomial();
    if(b.degree<0) return 1;

    c=add(a,b);

    printf("Polynomial 1: ");
    display(a);
    printf("Polynomial 2: ");
    display(b);
    printf("Result after addition: ");
    display(c);

    return 0;
}