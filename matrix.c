#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define m 1000
#define n 1000
#define p 1000

int A[m][n];
int B[n][p];
int C[m][p];

int main() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            B[i][j] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
        }
    }


    struct timeval st, et;

    gettimeofday(&st, NULL);
    ////***算法开始***////
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < m; i++) {
            int r = A[i][k];
            for (int j = 0; j < p; j++) {
                C[i][j] += r * B[k][j];
            }
        }
    }
    ////***算法结束***////
    gettimeofday(&et, NULL);
    printf("kij time: %0.6lf sec\n", et.tv_sec + et.tv_usec * 1e-6 - st.tv_sec - st.tv_usec * 1e-6);
    gettimeofday(&st, NULL);
    ////***算法开始***////
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            int r = A[i][k];
            for (int j = 0; j < p; j++) {
                C[i][j] += r * B[k][j];
            }
        }
    }
    ////***算法结束***////
    gettimeofday(&et, NULL);
    printf("ikj time: %0.6lf sec\n", et.tv_sec + et.tv_usec * 1e-6 - st.tv_sec - st.tv_usec * 1e-6);


    gettimeofday(&st, NULL);
    ////***算法开始***////
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] += sum;
        }
    }
    ////***算法结束***////
    gettimeofday(&et, NULL);
    printf("ijk time: %0.6lf sec\n", et.tv_sec + et.tv_usec * 1e-6 - st.tv_sec - st.tv_usec * 1e-6);
    gettimeofday(&st, NULL);
    ////***算法开始***////
    for (int j = 0; j < p; j++) {
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] += sum;
        }
    }
    ////***算法结束***////
    gettimeofday(&et, NULL);
    printf("jik time: %0.6lf sec\n", et.tv_sec + et.tv_usec * 1e-6 - st.tv_sec - st.tv_usec * 1e-6);


    gettimeofday(&st, NULL);
    ////***算法开始***////
    for (int j = 0; j < p; j++) {
        for (int k = 0; k < n; k++) {
            int r = B[k][j];
            for (int i = 0; i < m; i++) {
                C[i][j] += A[i][k] * r;
            }
        }
    }
    ////***算法结束***////
    gettimeofday(&et, NULL);
    printf("jki time: %0.6lf sec\n", et.tv_sec + et.tv_usec * 1e-6 - st.tv_sec - st.tv_usec * 1e-6);
    gettimeofday(&st, NULL);
    ////***算法开始***////
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < p; j++) {
            int r = B[k][j];
            for (int i = 0; i < m; i++) {
                C[i][j] += A[i][k] * r;
            }
        }
    }
    ////***算法结束***////
    gettimeofday(&et, NULL);
    printf("kji time: %0.6lf sec\n", et.tv_sec + et.tv_usec * 1e-6 - st.tv_sec - st.tv_usec * 1e-6);
   
    return 0;
}



//  ~  gcc /Users/qianqian/Desktop/mx.c -o mx             Wed Apr 10 18:16:12 2019
//  ~   ./mx                                      807ms  Wed Apr 10 18:16:18 2019
// kij time: 9.116704 sec
// ikj time: 9.091694 sec
// ijk time: 15.381990 sec
// jik time: 12.905352 sec
// jki time: 37.395260 sec
// kji time: 34.362129 sec

//  ~  ./mx     
// kij time: 8.908832 sec
// ikj time: 9.080675 sec
// ijk time: 13.892830 sec
// jik time: 12.771233 sec
// jki time: 39.090536 sec
// kji time: 35.421174 sec