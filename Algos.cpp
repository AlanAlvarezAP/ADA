#include <iostream>
#include <cstdlib>
#include <ctime>

// Tarea Analisis y Diseño de Algoritmos
// Por Alan Alvarez Puma y Jose Miguel Valdivia


void PrintDivision(int* ini, int* fin) {
    for (; ini <= fin; ini++) {
        std::cout << *ini << " - ";
    }
    std::cout << std::endl;
}


int MergeSort(int* ini, int* fin,int conta=0) {
    if (ini >= fin) {
        return 0;
    }
    int calculo_ptr = (fin - ini) / 2;
    int conta_izq=MergeSort(ini, ini + calculo_ptr,conta);
    int conta_der= MergeSort(ini + calculo_ptr + 1, fin,conta);
    int* copia = new int[fin - ini];
    int* idx = copia;
    int* left = ini;
    int* right = ini + calculo_ptr + 1;
    while (left <= ini + calculo_ptr && right <= fin) {
        if (*left < *right) {
            *idx = *left;
            left++;
        }
        else {
            *idx = *right;
            right++;
            conta+=(ini+calculo_ptr+1)-left;
        }
        idx++;
    }
    while (left <= ini + calculo_ptr) {
        *idx = *left;
        left++;
        idx++;
    }
    while (right <= fin) {
        *idx = *right;
        right++;
        idx++;
    }

    for (int* p = copia, *copia_ini = ini; p <= copia + (fin - ini); p++, copia_ini++) {
        *copia_ini = *p;
    }
    return conta + conta_der + conta_izq;
}
int main()
{
    int arr[12] = { 4,8,10,21,5,12,11,3,7,6,9,1 };
    std::cout << std::endl;
    std::cout << "RESULTADO FINAL " << " -> " << MergeSort(arr, arr + 11);
}


