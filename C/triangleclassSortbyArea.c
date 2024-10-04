#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct triangle{
    int a,b,c;
};
typedef struct triangle triangle;
double calculate_area(triangle tr) {
    double p = (tr.a + tr.b + tr.c) / 2.0;
    return sqrt(p * (p - tr.a) * (p - tr.b) * (p - tr.c));
}


int sort_by_area(triangle* tr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (calculate_area(tr[j]) > calculate_area(tr[j + 1])) {
                triangle temp = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp;
            }
        }
    }
    return n;
}
int main(){
    int n,rc;
    scanf("%d",&n);
    triangle *tr = malloc(n*sizeof(triangle));
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&tr[i].a,&tr[i].b,&tr[i].c);
    }
    rc = sort_by_area(tr,n);
    for(int i=0;i<n;i++){
        printf("%d %d %d\n",tr[i].a,tr[i].b,tr[i].c);
    }
    return rc;
}
