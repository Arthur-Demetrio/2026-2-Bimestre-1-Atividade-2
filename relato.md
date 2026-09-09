# Relatório de implementação de linha de execução em C++

## Introdução

Este relato faz parte do processo avaliativo da disciplina de sistemas operacionas no curso superior em análise e desenvolvimento de sistemas, ofertado na Diretoria acadêmica de gestão e tecnologia da informação no campus natal-central do instituto federal de educação, ciência e tecnologia do rio grande do norte.

Tem como objetivo principal relatar como implementar linhas de execução na linguagem C++.

O grupo de trabalho foi formado por Artur Lima, Arthur Vinicius e Caio Lucas.

## Implementando múltiplas linhas de execução em C++

### Informações gerais sobre C++

C++ é uma linguagem que tem como paradigmas ser:

Procedural
>Herdando a estrutura base da linguagem C, permitindo organizar o código em funções e sequências lineares de comandos

Orientada a Objetos
>Adiciona conceitos como classes, herança, polimorfismo e encapsulamento para facilitar a reutilização e a organização de grandes

Genérica
>Utiliza recursos chamados templates para criar funções e estruturas de dados que funcionam com qualquer tipo de dado sem reescrever o código.

Objetivos:

Desempenho máximo
>Executar tarefas pesadas com velocidade próxima à de códigos escritos em linguagem de máquina.

Controle de recursos
>Permitir a gestão explícita e direta da memória RAM.

Evolução do C
>Servir como uma extensão da linguagem C, mantendo a compatibilidade e adicionando ferramentas para gerenciar complexidade.

Além disso o C++ está disponível na maioria das principais plataformas, sistemas operacionais e ambientes de desenvolvimento do mundo.

### Criando linhas de execução

No C++, podemos criar linhas de execução utilizando a biblioteca <thread>. Elas permitem que diferentes tarefas sejam executadas de forma independente, podendo ocorrer ao mesmo tempo. Para criar uma linha de execução, utilizamos std::thread, passando a função que será executada.

EXEMPLO:

#include <iostream>
#include <thread>

void tarefa() {
    std::cout << "Executando uma tarefa.\n";
}

int main() {
    std::thread t(tarefa);

    t.join();

    return 0;
}

Nesse exemplo, t representa uma nova linha de execução que executará a função tarefa(). O comando join() faz com que o programa principal aguarde a finalização dessa linha de execução antes de continuar.

### Passando valores para linhas de execução

Também é possível passar valores para uma linha de execução no momento em que ela é criada. Esses valores são enviados como argumentos para a função que será executada pela thread.

EXEMPLO:

#include <iostream>
#include <thread>

void mostrarNumero(int numero) {
    std::cout << "Número: " << numero << "\n";
}

int main() {
    std::thread t(mostrarNumero, 10);

    t.join();

    return 0;
}

Nesse caso, o valor 10 é passado para a função mostrarNumero(). A linha de execução recebe esse valor como parâmetro e realiza a tarefa definida na função.
Dessa forma, o uso de argumentos permite que diferentes linhas de execução trabalhem com diferentes informações, tornando o programa mais flexível.

### Múltiplas linhas de execução

É possível criar várias threads para executar tarefas de forma concorrente. No exemplo, são criadas cinco threads, cada uma representando um trabalhador:

vector<thread> threads;

for (int i = 0; i < 5; ++i) {
    threads.emplace_back(trabalhador, i, 2);
}

Após a criação, o programa aguarda o término das threads utilizando join():

for (auto& t : threads) {
    if (t.joinable()) {
        t.join();
    }
}

Como as tarefas são executadas simultaneamente, o tempo total fica próximo de dois segundos, enquanto uma execução sequencial levaria aproximadamente dez segundos.

## Considerações finais

A atividade permitiu compreender a criação e utilização de threads em C++, além da sincronização por meio de join():

thread t(minha_funcao);
t.join();

Também foi possível observar que múltiplas threads podem executar tarefas de forma concorrente, reduzindo o tempo de execução de tarefas independentes.
