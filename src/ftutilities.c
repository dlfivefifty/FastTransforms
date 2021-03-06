// Utility functions for testing.

#include "ftutilities.h"

#define A(i,j) A[(i)+n*(j)]
#define B(i,j) B[(i)+n*(j)]

void printmat(char * MAT, char * FMT, double * A, int n, int m) {
    printf("%s = \n", MAT);
    if (n > 0 && m > 0) {
        if (signbit(A(0,0))) {printf("[");}
        else {printf("[ ");}
        printf(FMT, A(0,0));
        for (int j = 1; j < m; j++) {
            if (signbit(A(0,j))) {printf("  ");}
            else {printf("   ");}
            printf(FMT, A(0,j));
        }
        for (int i = 1; i < n-1; i++) {
            printf("\n");
            if (signbit(A(i,0))) {printf(" ");}
            else {printf("  ");}
            printf(FMT, A(i,0));
            for (int j = 1; j < m; j++) {
                if (signbit(A(i,j))) {printf("  ");}
                else {printf("   ");}
                printf(FMT, A(i,j));
            }
        }
        if (n > 1) {
            printf("\n");
            if (signbit(A(n-1,0))) {printf(" ");}
            else {printf("  ");}
            printf(FMT, A(n-1,0));
            for (int j = 1; j < m; j++) {
                if (signbit(A(n-1,j))) {printf("  ");}
                else {printf("   ");}
                printf(FMT, A(n-1,j));
            }
        }
        printf("]\n");
    }
}

double * copymat(double * A, int n, int m) {
    double * B = (double *) calloc(n*m, sizeof(double));
    for (int i = 0; i < n*m; i++)
        B[i] = A[i];
    return B;
}

void checktest(double err, int n, int * checksum) {
    if (fabs(err) < n*0x1p-52) printf(GREEN("✓")"\n");
    else {printf(RED("×")"\n"); (*checksum)++;}
}

double norm_1arg(double * A, int n) {
    double ret = 0.0;
    for (int i = 0; i < n; i++)
        ret += pow(A[i], 2);
    return sqrt(ret);
}

double norm_2arg(double * A, double * B, int n) {
    double ret = 0.0;
    for (int i = 0; i < n; i++)
        ret += pow(A[i]-B[i], 2);
    return sqrt(ret);
}

double normInf_1arg(double * A, int n) {
    double ret = 0.0, temp;
    for (int i = 0; i < n; i++) {
        temp = fabs(A[i]);
        if (temp > ret) ret = temp;
    }
    return ret;
}

double normInf_2arg(double * A, double * B, int n) {
    double ret = 0.0, temp;
    for (int i = 0; i < n; i++) {
        temp = fabs(A[i]-B[i]);
        if (temp > ret) ret = temp;
    }
    return ret;
}

double * sphones(int n, int m) {
    double * A  = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-2*i; j++)
            A(i,j) = 1.0;
    return A;
}

double * sphrand(int n, int m) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-2*i; j++)
            A(i,j) = 2.0*(((double) rand())/RAND_MAX)-1.0;
    return A;
}

double * triones(int n, int m) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-i; j++)
            A(i,j) = 1.0;
    return A;
}

double * trirand(int n, int m) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-i; j++)
            A(i,j) = 2.0*(((double) rand())/RAND_MAX)-1.0;
    return A;
}

double * diskones(int n, int m) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-4*i; j++)
            A(i,j) = 1.0;
    return A;
}

double * diskrand(int n, int m) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-4*i; j++)
            A(i,j) = 2.0*(((double) rand())/RAND_MAX)-1.0;
    return A;
}

double * spinsphones(int n, int m, int s) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n-s; i++)
        for (int j = 0; j < m-2*i; j++)
            A(i,j) = 1.0;
    return A;
}

double * spinsphrand(int n, int m, int s) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n-s; i++)
        for (int j = 0; j < m-2*i; j++)
            A(i,j) = 2.0*(((double) rand())/RAND_MAX)-1.0;
    return A;
}

double elapsed(struct timeval * start, struct timeval * end, int N) {
    return ((end->tv_sec  - start->tv_sec) * 1000000u + end->tv_usec - start->tv_usec) / (1.e6 * N);
}
