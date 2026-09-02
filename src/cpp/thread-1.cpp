#include <thread>
#include <iostream>
#include <chrono>

using namespace std;

void minha_funcao() {
    cout << "thread inciciada!" << endl;
    this_thread::sleep_for(chrono::seconds(2)); // Durma por dois segundos
    cout << "Thread finalizada!" << endl;
}

int main() {
    //Criar a thread e iniciar
    thread thread(minha_funcao);

    thread.join(); // aguardar o termino da thread

    cout << "programa principal finalizado!" << endl;
    return 0;
}