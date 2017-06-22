#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getrand()
{
    return (double)rand() / RAND_MAX;
}


int main()
{
    int k = 3;
    double r = 0, m = 0, d = 0;
    int a[] = {-7, -3, 0};
    double p[] = {0.2, 0,1, 0.7};
    double count [3] = {0};
    
    srand(1);
    for (int j = 0; j < 30000; j++) {
        r = getrand();
        for (int i = 0; i < k; i++) {
            r -= p[i];
            if (r > 0) continue;
            if (j < 100) printf("X = %d\n", a[i]);
            count[i]++;
        }
    }

    count[0] = 0.200021; count[1] = 0.10095; count[2] = 0.699029;
    printf("\nthe modeled values:\n");
    for (int i = 0; i < k; i++) {
        //count[i] /= 30000;
        printf("X%d = %f\n", i, count[i]);
        m += a[i] * count[i];
        d += pow(a[i], 2) * count[i];
    }
    d -= pow(m, 2);
    printf("\nm = %f d = %f", m, d);
}
