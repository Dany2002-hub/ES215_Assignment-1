#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#define N 512

using namespace std;
 
void MatrixMultiply(double mat1[N][N], double mat2[N][N], double mat3[N][N])
{
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            mat3[i][j] = 0;
            for (k = 0; k < N; k++)
                mat3[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

int main()
{
    double mat1[N][N];
    double mat2[N][N];
    double mat3[N][N];            //Resultant Matrix Multiplication
    
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            
            mat1[i][j] = (double) rand()/RAND_MAX;
            mat2[i][j] = (double) rand()/RAND_MAX;
        }
    }
    timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    MatrixMultiply(mat1, mat2, mat3);

    // cout << "Resultant matrix is \n";
    // for (int i=0; i<N; i++)
    // {
    //     for (int j=0; j<N; j++)
    //         cout << mat3[i][j] << " ";
    //     cout <<endl;
    // }


    clock_gettime(CLOCK_REALTIME, &end);
    long long secs = end.tv_sec - start.tv_sec;
    long long nanosecs = end.tv_nsec - start.tv_nsec;
    long double elapsed = secs + nanosecs*(long double)1e-9;

    cout<<"\nTime taken just for matrix multiplication: "<<elapsed<<" seconds\n";
    return 0;
}
