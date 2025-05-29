#include <iostream>
#include <vector>

// Realizado por Alan Alvarez Puma y Jose Zegarra Castillo


int Sultan(int* candidatos, int size) {
    int elem_validos = 0;
    int mayor = 0;
    for (int i = 0;i < size-1;i++) {
        if (mayor + (*(candidatos + i)) < (*(candidatos + i + 1))) {
            mayor += (*(candidatos + i));
            elem_validos++;
        }
    }
    elem_validos++;
    return elem_validos;
}

int main()
{
    int casos;
    int tamano_arr;
    std::cout << "Numero casos " << std::endl;
    std::cin >> casos;
    while (casos!=0) {
        std::cout << "Tamano del array" << std::endl;
        std::cin >> tamano_arr;
        int *input = new int[tamano_arr];
        for (int i = 0;i < tamano_arr;i++) {
            std::cout << "DAME VALOR PARA INDICE " << i << std::endl;
            std::cin >> *(input + i);
        }
        std::cout << " SOLUCION " << Sultan(input, tamano_arr) << std::endl;
        casos--;
    }
}

