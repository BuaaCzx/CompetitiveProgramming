#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int l, r;
}node;
node a[100005];
int n;
int cmp(const void *x, const void *y) {
    node *a = (node*)x, *b = (node*)y;
    if (a->l < b -> l) return -1;
    else if (a->l > b -> l) return 1;
    if (a ->r < b -> r) return -1;
    else return 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].l, &a[i].r);
    }
    qsort(a, n, sizeof(a[0]), cmp);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", a[i].l, a[i].r);
        //printf("%d\n", a[i].r);
    }
    return 0;
}
