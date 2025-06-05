#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


// Realizado por Alan Patrizio Alvarez Puma

bool cmp(std::pair<int, int>& a, std::pair<int, int>& b) {
    return a.second > b.second;
}

bool esFactible(std::vector<int> sol, int& select, std::vector<std::pair<int, int>> plazo) {
    for (int i = sol.size(); i > 0; i--) {
        if (plazo[select].second >= i && sol[i - 1] == -1) {
            select = i - 1;
            return true;
        }
    }
    return false;
}

std::vector<int> Tareas(int num_tareas, std::vector<std::pair<int, int>> beneficios, std::vector<std::pair<int, int>> plazos,int &ganacia) {
    std::vector<int> sol(beneficios.size());
    for (int i = 0; i < sol.size(); i++) {
        sol[i] = -1;
    }
    std::sort(beneficios.begin(), beneficios.end(), cmp);
    for (int i = 0; i < beneficios.size(); i++) {
        int select = beneficios[i].first;
        int mandar = plazos[select].second;
        if (esFactible(sol, mandar, plazos)) {
            sol[mandar] = select + 1;
            ganacia += beneficios[mandar].second;
        }
    }
    return sol;
}


int main()
{
    int T;
    std::cout << " Cuantos casos ";
    std::cin >> T;
    int num_array;
    std::cout << " Tam del array " << std::endl;
    std::cin >> num_array;
    int num_tareas;
    std::cout << " Dame numero de tareas " << std::endl;
    std::cin >> num_tareas;
    while (T) {
        std::vector<std::pair<int, int>> beneficios;
        int tmp1 = 0;
        int ganancia = 0;
        std::vector<std::pair<int, int>> plazos;
        std::cout << " Dame la informacion para los beneficios" << std::endl;
        for (int i = 0; i < num_array; i++) {
            std::cout << " Beneficio num " << i << std::endl;
            std::cin >> tmp1;
            beneficios.push_back({ i,tmp1 });
        }
        std::cout << " Dame la informacion para los plazos" << std::endl;
        for (int i = 0; i < num_array; i++) {
            std::cout << " Plazo num " << i << std::endl;
            std::cin >> tmp1;
            plazos.push_back({ i,tmp1 });
        }
        std::vector<int> resul = Tareas(num_tareas, beneficios, plazos,ganancia);
        std::cout << "Ganancia: " << ganancia << std::endl;
        for (auto p : resul) {
            if (p != -1) {
                std::cout << p << " - ";
                
            }

        }
        std::cout << std::endl;
        T--;
    }
}

