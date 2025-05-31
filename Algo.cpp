#include <iostream>

int Menor(int* pesos,int size,float* resul) {
    int index = -1;
    int peso_menor = INT_MAX;
    for (int i = 0; i < size; i++) {
        if ((*(pesos + i)) < peso_menor && *(resul + i) == 0) {
            peso_menor = *(pesos + i);
            index = i;
        }
    }
    return index;
}


float* Camiones(int size, int* contenedores, int* pesos,int k) {
    float* resul = new float[size];
    int act = 0;
    for (int i = 0; i < size; i++) {
        *(resul + i) = 0;
    }
    while (act < k) {
        int index = Menor(pesos, size,resul);
        if (*(pesos + index) > (k-act)) {
            *(resul + index) = (float)(k-act)/(*(pesos+index));
        }
        else {
            *(resul + index) = 1;
        }
        act += (*(pesos + index));
        
    }
    return resul;
}
int main()
{
    int casos;
    int tamano_arr;
    int toneladas;
    std::cout << "Numero casos " << std::endl;
    std::cin >> casos;
    while (casos != 0) {
        std::cout << "Tamano del array" << std::endl;
        std::cin >> tamano_arr;
        std::cout << "Dame cantidad toneladas " << std::endl;
        std::cin >> toneladas;
        int* contenedores = new int[tamano_arr];
        int* pesos = new int[tamano_arr];
        for (int i = 0; i < tamano_arr; i++) {
            *(contenedores + i) = i;
        }
        std::cout << " Para los pesos " << std::endl;
        for (int i = 0; i < tamano_arr; i++) {
            std::cout << "DAME VALOR PARA INDICE " << i << std::endl;
            std::cin >> *(pesos + i);
        }
        float* resuls = Camiones(tamano_arr, contenedores, pesos, toneladas);
        for (int i = 0; i < 5; i++) {
            std::cout << *(resuls + i) << " ";
        }
        std::cout << std::endl;
        casos--;
    }
}