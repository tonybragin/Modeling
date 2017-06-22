#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double y, double r)
{
    return -1/y * log(r);
}

double getrand()
{
    return (double)rand() / RAND_MAX;
}

int main()
{
    int n = 10000;
    double r;
    double u = 0.8, t = 2.9;
    double v[n], ti[n];
    int kan[5] = {0};
    
    srand(3);

    v[0] = 0.0;
    for (int i = 1; i < n; i++) {
        r = getrand();
        v[i] = func(u, r);
        if (i > 0) {
            v[i] +=v[i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        r = getrand();
        ti[i] = func(1 / t, r);
    }
    
    for (int i = 0; i < 100; i++) {
        printf("%f %f\n", v[i], ti[i]);
    }
    printf("\n\n");
    
    kan[0] = ti[0];
    double nv = 0, no = 0;
    for (int i = 1; i < n; i++) {
        int f = 0;
        for (int k = 0; k < 5; k++) {
            if (kan[k] <= v[i]) {
                kan[k] = v[i] + ti[i];
                f = 1;
                break;
            }
        }
        if (f == 0) {
            no++;
        }
        else nv++;
    }

    double potk = no / n;
    double pp = potk * 120 / pow(u * t, 5);
    
    printf("Обслужено: %f\nНе обслужено: %f\nВероятность простоя: %f\nВероятноть отказа: %f", nv, no, pp, potk);
    
    
}
