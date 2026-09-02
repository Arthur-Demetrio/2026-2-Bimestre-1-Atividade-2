#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std

void trabalhador(int numero, int tempo_trabalho) {
    cout << "trabalhador " << numero << " começou\n";
    this_thread::sleep_for(chrono::seconds(tempo_trabalho));
    cout << "trabalhador " << numero << "terminou (levou " << tempo_trabalho << "s)";
}

int main() {
    cout << "iniciando 5 trabalhadores...";
    auto inicio = chrono::high_resolution_clock::now();
    vector::<thread> threads;
    for(i=0; i<5; ++i) {
        threads.emplace_back(trabalhador, i, 2);
    }
    for(auto& t : threads){
        if(t.joinable()){
            t.join();
        }
    }
    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> tempo_total = fim - inicio
    cout << "\n" << "Todos os trabalhadores terminaram!" << endl;
    cout << "tempo total: " << tempo_total.count() << "s\n";
    cout << "(Se fosse sequencial, levaria ~10s)";
    return 0;
}