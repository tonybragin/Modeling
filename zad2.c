#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double e = 2.718281828;

double func(double r)
{
    return pow(e, r * log(2));
}

double getrand()
{
    return (double)rand() / RAND_MAX;
}

int main()
{
    int n = 10000;
    double r = 0, x = 0, m = 0, d = 0;
    double a[n];
    
    srand(2);
    for (int i = 0; i < n; i++) {
        r = getrand();
        x = func(r);
        if (i < 100) printf("X = %f\n", x);
        a[i] = x;

    }
    
    for (int i = 0; i < n; i++) {
        m += a[i];
    }
    m /= n;
    printf("\nM = %f\n", m);
    
    for (int i = 0; i < n; i++) {
        double s = a[i] - m;
        d += pow(s, 2);
    }
    d /= n;
    printf("D = %f\n", d);

}
