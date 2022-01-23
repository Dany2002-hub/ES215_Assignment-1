#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#define N 512

using namespace std;
 
void MatrixMultiply(int mat1[N][N], int mat2[N][N], int mat3[N][N])
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
    int mat1[N][N];
    int mat2[N][N];
    int mat3[N][N];
    
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            
            mat1[i][j] = rand()%10;
            mat2[i][j] = rand()%10;
        }
    }
    timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    MatrixMultiply(mat1, mat2,mat3);

    clock_gettime(CLOCK_REALTIME, &end);
    long long secs = end.tv_sec - start.tv_sec;
    long long nanosecs = end.tv_nsec - start.tv_nsec;
    long double elapsed = secs + nanosecs*(long double)1e-9;
    

    //cout << "Resultant matrix is \n";
    //for (int i = 0; i < N; i++){
    //     for (int j = 0; j < N; j++){
    //        cout << mat3[i][j] << " ";
    //  }
    //     cout <<endl;
    // }

    cout<<"\nTime taken just for matrix multiplication: "<<elapsed<<" seconds\n";
    return 0;
}
