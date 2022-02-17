#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#define N 5
using namespace std;

void minNumInArr (float m [N][N]){
     float min = m[0][0];
	 for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
            if (m[i][j] < min) 
               min = m[i][j] ;
    cout << "The minimum number in the matrix: " << min << endl;
     
}
void maxNumInArr (float m [N][N]){
     float max = m[0][0];
	 for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
            if (m[i][j] > max) 
               max = m[i][j] ;
    cout << "The maximum number in the matrix: " << max << endl;
     
}
void maxNumInArrDownTriangle (float m [N][N]){
     float max = 0;
	 for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
            if (i > j) 
               if (m[i][j] > max) 
                  max = m[i][j] ;
    cout << "Maximum of the lower triangular part of the matrix: " << max << endl;     
}
void maxNumInArrUpTriangle (float m [N][N]){
     float max = 0;
	 for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
            if (i < j) 
               if (m[i][j] > max) 
                  max = m[i][j] ;
    cout << "Maximum of the upper triangular part of the matrix: " << max << endl;     
}
void minNumInArrDownTriangle (float m [N][N]){
     float min = m [N-1][0];
	 for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
            if (i > j) 
               if (m[i][j] < min) 
                  min = m[i][j] ;
    cout << "Minimum of the lower triangular part of the matrix: " << min << endl;     
}
void minNumInArrUpTriangle (float m [N][N]){
     float min = m [0][N-1];
	 for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
            if (i < j) 
               if (m[i][j] < min) 
                  min = m[i][j] ;
    cout << "Minimum of the upper triangular part of the matrix: " << min << endl;     
}
void minNumOfMainDiag (float m [N][N]){
    float min = m [0][0];
	 for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
            if (i == j) 
               if (m[i][j] < min) 
                  min = m[i][j] ;
    cout << "The minimum of the main diagonal of the matrix: " << min << endl;       
}
void maxNumOfMainDiag (float m [N][N]){
    float max = 0;
	 for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
            if (i == j) 
               if (m[i][j] > max) 
                  max = m[i][j] ;
    cout << "The maximum of the main diagonal of the matrix: " << max << endl;       
}
void minNumOfSecDiag (float m [N][N]){
    float min = m [0][N-1];
	 for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
            if (i + j == N - 1) 
               if (m[i][j] < min) 
                  min = m[i][j] ;
    cout << "The minimum of the secondary diagonal of the matrix: " << min << endl;       
}
void maxNumOfSecDiag (float m [N][N]){
    float max = 0;
	 for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
            if (i + j == N - 1) 
               if (m[i][j] > max) 
                  max = m[i][j] ;
    cout << "The maximum of the secondary diagonal of the matrix: " << max << endl;       
}
void arithMeanMatrixElements (float m [N][N]){
     float sum = 0;
     int count = 0;
     for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++){sum += m [i][j]; count++;}
     cout << "The arithmetic mean of the matrix elements: " << sum / count << endl;
}
void arithMeanDownTriangleMatrixElements (float m [N][N]){
     float sum = 0;
     int count = 0;
     for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++){
            if (i > j){
               sum += m [i][j]; count++;
            }
        }
     cout << "The arithmetic mean of the lower triangular part of the matrix elements: " << sum / count << endl;
}
void arithMeanUpTriangleMatrixElements (float m [N][N]){
     float sum = 0;
     int count = 0;
     for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++){
            if (i < j){
               sum += m [i][j]; count++;
            }
        }
     cout << "The arithmetic mean of the upper triangular part of the matrix elements: " << sum / count << endl;
}
void sumRowsMatrix (float m [N][N]){
     float sum = 0;
     float buffArr[N];
     for (int i = 0; i < N; i++){ 
         for (int j = 0; j < N; j++) sum += m [i][j];
         
         buffArr[i] = sum;
         sum = 0;
     }   
     for (int i = 0; i < N; i++) cout << "The sum of the " << i+1 << " row of the matrix: " << buffArr[i] << endl;   
}
void sumColumnsMatrix (float m [N][N]){
     float sum = 0;
     float buffArr[N];
     for (int i = 0; i < N; i++){ 
         for (int j = 0; j < N; j++) sum += m [j][i];
         
         buffArr[i] = sum;
         sum = 0;
     }   
     for (int i = 0; i < N; i++) cout << "The sum of the " << i+1 << " columns of the matrix: " << buffArr[i] << endl;   
}
void minRowValues (float m [N][N]){
     float min = 0;
     for (int i = 0; i < N; i++){
         min = m [i][0];     
         for (int j = 0; j < N; j++)
             if (m [i][j] < min) min = m[i][j];
      
         cout << "Minimal value in " << i+1 << " line: " << min << endl;
     }
}
void minColumnsValues (float m [N][N]){
     float min = 0;
     for (int i = 0; i < N; i++){
         min = m [i][0];     
         for (int j = 0; j < N; j++){
             if (m[j][i] < min) min = m[j][i];
         }
         cout << "Minimal value in " << i+1 << " columns: " << min << endl;
     }
}
void maxRowValues (float m [N][N]){
     float max = m[0][0];
     for (int i = 0; i < N; i++){
         max = m [i][0];     
         for (int j = 0; j < N; j++)
             if (m [i][j] > max) max = m[i][j];
      
         cout << "Maximum value in " << i+1 << " line: " << max << endl;
     }
}
void maxColumnsValues (float m [N][N]){
     float max = m[0][0];
     for (int i = 0; i < N; i++){
         max = m [i][0];     
         for (int j = 0; j < N; j++){
             if (m[j][i] > max) max = m[j][i];
         }
         cout << "Maximum value in " << i+1 << " columns: " << max << endl;
     }
}
void arithMeanRowMatrixElements (float m [N][N]){
     float sum = 0;
     int count = 0;
     float buffArr[N];
     for (int i = 0; i < N; i++){ 
         for (int j = 0; j < N; j++){ sum += m [i][j];}
         
         buffArr[i] = sum;
         sum = 0;
         
     }   
     for (int i = 0; i < N; i++) cout << "The arithmetic mean of the " << i+1 << " row of the matrix: " << buffArr[i]/N << endl;   
}
void arithMeanColumnMatrixElements (float m [N][N]){
     float sum = 0;
     int count = 0;
     float buffArr[N];
     for (int i = 0; i < N; i++){ 
         for (int j = 0; j < N; j++){ sum += m [j][i];}
         
         buffArr[i] = sum;
         sum = 0;
         
     }   
     for (int i = 0; i < N; i++) cout << "The arithmetic mean of the " << i+1 << " column of the matrix: " << buffArr[i]/N << endl;   
}
void sumLowerNupperTrianglePartsMatrix (float m [N][N]){
     float sumUp = 0, sumLow = 0;
	 for (int i = 0; i < N; i++){ 
		for (int j = 0; j < N; j++){
            if (i > j) sumLow += m [i][j];
            else if (i < j) sumUp += m [i][j];
            } 
     }        
     cout << "Sums of the lower and upper triangular parts of the matrix:\nUpper: " << sumUp << endl << "Lower:" << sumLow << endl;     
}
void numCloseToArithMean (float m [N][N]){
     float sum = 0.0, mean = 0.0, buff = 0.0, result = 0.0;
     int count = 0;
     for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++){sum += m [i][j]; count++;}
	 mean = sum/count;
     buff = abs(mean - m[0][0]);
     result = m[0][0];
     for (int i = 0; i < N; i++){ 
		for (int j = 0; j < N; j++){
            if (abs(mean - m[i][j]) < buff)
            {
               buff = abs(mean - m[i][j]);
               result = m[i][j];
            }
        }
     }       	
     cout << "The arithmetic mean of the matrix elements: " << mean << endl <<"a number close to the arithmetic mean: " << result << endl ;
}


int main() {
    srand (time(0));
	float m[N][N];
	int i = 0, j = 0;
	// Заполнение массива
	for (i = 0; i < N; i++) 
		for (j = 0; j < N; j++) m[i][j] = rand() / 100.;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			cout << setw(8) << setprecision(5) << m[i][j];
		cout << endl;
	}
	
	cout << endl;
	minNumInArr(m);
	cout << endl;
    maxNumInArr(m);
    cout << endl;
    maxNumInArrDownTriangle(m);
    cout << endl;
    maxNumInArrUpTriangle(m);
    cout << endl;
    minNumInArrDownTriangle(m);
    cout << endl;
    minNumInArrUpTriangle(m);
    cout << endl;
    minNumOfMainDiag(m);
    cout << endl;
    maxNumOfMainDiag(m);
    cout << endl;
    minNumOfSecDiag(m);
    cout << endl;
    maxNumOfSecDiag(m);
    cout << endl;
    arithMeanMatrixElements(m);
    cout << endl;
    arithMeanDownTriangleMatrixElements(m);
    cout << endl;
    arithMeanUpTriangleMatrixElements(m);
    cout << endl;
    sumRowsMatrix(m);
    cout << endl;
    sumColumnsMatrix(m);
    cout << endl;
    minRowValues(m);
    cout << endl;
    minColumnsValues(m);
    cout << endl;
    maxRowValues(m);
    cout << endl;
    maxColumnsValues(m);
    cout << endl;
    arithMeanRowMatrixElements(m);
    cout << endl;
    arithMeanColumnMatrixElements(m);
    cout << endl;
    sumLowerNupperTrianglePartsMatrix(m);
    cout << endl;
    numCloseToArithMean(m);
    cout << endl;
    
	getch();
	cin.get();
}

