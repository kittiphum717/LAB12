#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum = 0;
    double avg,SD,mSD = 0,mGM = 0,GM,mHM = 0,HM;
    for(int i = 0;i < N;i++){
        sum += A[i];
    }
    avg = sum/N;
    B[0] = avg;
    for(int j = 0;j < N;j++){
        mSD += pow(A[j]-avg,2);
    }
    SD = sqrt(mSD/N);
    B[1] = SD;
    for(int k = 0;k < N;k++){
        mGM += log10(A[k]);
    }
    GM = pow(10,(mGM/N));
    B[2] = GM;
    for(int q = 0;q < N;q++){
        mHM += 1/A[q];
    }
    HM = N/mHM;
    B[3] = HM;
    double max = A[0],min = A[0];
    for(int e = 1;e < N;e++){
        if(A[e] > max){
            max = A[e];
        }
        if(A[e] < min){
            min = A[e];
        }
    }
    B[4] = max;
    B[5] = min;
}