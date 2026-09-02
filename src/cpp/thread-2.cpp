#include <thread>
#include <iostream>
#include <string>
void  saudar(std::string nome, int vezes)
{
    for (int i=0; i < vezes; i++)
    {
        std::cout <<"Olá, " << nome << std::endl;
    }
}

int main()
{
    std::thread thread(saudar, "Maria", 3);
    thread.join();

    return 0;
}