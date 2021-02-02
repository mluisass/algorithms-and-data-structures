#include <iostream>
using namespace std;

int processadores, slot; //slot é quantos ciclos vai ter um processo
int ciclos = 0, interrompidos = 0, admitidos = 0, despachados = 0;

typedef struct Processo{
    string id;
    int ciclosFeitos;
    Processo *next;
} Processo;

void procurar (Processo cursor, string id, int ciclo);
void adicionar (Processo cursor, string id, int ciclo);
void remover (Processo cursor, string id, int ciclo);

int main()
{
    //fila pra guardar os novos
    //fila pra guardar os terminados
    //fila para fila de execução
    //fila para processos em execução
    
    cin >> processadores >> slot;

    string comando;
    cin >> comando;
    while (comando != "END")
    {
        if (comando == "NEW")
        {
            string id;
            cin >> id;
            //cria novo processo com esse id
            //guardar na fila de tudo digitado
            adicionar (fimNovos, id, 0);
        }
        else if (comando == "TER")
        {
            string id;
            cin >> id;
            //cria novo processo com esse id
            //guardar na fila de tudo digitado
            adicionar (fimTerm, id, 0);
        }
        else if (comando == "SCH")
        {
            cout << ciclos;
            //novo ciclo
            //indica que o escalonador deve entrar em ação nesse instante em CIAD
            //C. olhar se algum processo terminou a execução e retirá-lo do sistema
            //printar a lista de concluídos
            //I. olhar se algum processo em execução que esgotou seu tempo e colocar ele de volta na fila de execução
            //printar quantidade de interrompidos
            //A. se um novo processo foi criado, coloca ele no fim da fila
            //printar a qtd de admitidos
            //D. se há processadores disponíveis, tira da fila de execução e coloca em processamento
            //printar qtd de despachados
            ciclos++;
            interrompidos = 0;
            admitidos = 0;
            despachados = 0;
        }
        cin >> comando;
    }
    return 0;
}

void adicionar (Processo *cursor, string id, int ciclo)
{
    Processo *p = new Processo();
    p->id = id;
    p->ciclosFeitos = ciclo;
    p->next = cursor->next;
    cursor->next = p;
}

/*
FILA DO TIPO FIFO (o primeiro que entra é o primeiro a sair)

1. Um processo só termina sua execução SE a entrada mandar (ou seja, eu receber um TER ID_do_processo)
2. Se um processo está em execução por S ciclos, ele é retirado dessa CPU e colocado de volta na fila de execução com o TEMPO TOTAL DE PROCESSAMENTO atualizado (acrescido deses S ciclos). A CPU passa a estar disponível.
3. Cada processo terá:
	- ID
	- Tempo total de processamento 
	- Ponteiro Next
4. S deverá ser sempre maior que zero
5. Sempre os eventos são processados em ordem C, I, A e D.
6. Em C : O escalonador retira os processos concluídos (TER ID) das CPUs e libera a memória
7. Em I : O escalonador procura processos para interromper de acordo com a regra 2 acima escrita.
8. Em A: Processos são adicionados na fila (sempre na última posição)
9. Em D: Processos são postos para executar, caso tenha processadores livres. (retira-se processos apenas do começo da fila)
10. Repare que um processo pode ser interrompido em I, e imediatamente recolocado em execução, na mesma ou noutra CPU, em D de uma mesma entrada do escalonador.
11. A entrada termina com uma linha END
12. A cada entrada SCH:
	1. 01 linha indicando o ciclo atual
	2. Evento C : lista dos processos concluídos no ATUAL CICLO, 01 por linha, seguidos de seu TEMPO TOTAL DE EXECUÇÃO
	OBS¹:  o tempo total de execução de um processo deve incluir também todos os ciclos desde que o processo foi colocado em processamento pela última vez até o ciclo atual. Ou seja, se um processo ficou em processamento durante 7 ciclos, o tempo total de processamento será 7S ciclos. (o tempo em espera não é contabilizado)
	OBS²: NOTE QUE QUANDO NÃO TIVERAM PROCESSOS CONCLUÍDOS NAQUELE CICLO, NADA É RETORNADO NO PASSO 2
	3. 01 linha indicando a quantidade I de processos interrompidos no ATUAL ciclo
	4. 01 linha indicando a quantidade A de novos processos adicionados na fila no ATUAL ciclo
	5. 01 linha indicando a quantidade D de processos despachados (postos para execução) no ATUAL ciclo
	OBS³: I, A e D sempre são zerados a cada ciclo. 
13. A entrada NEW ID adiciona um processo novo à fila de execução (ID é único) com 0ns de tempo de CPU
14. A entrada TER ID indica que o processo ID concluiu COMPLETAMENTE sua execução. Logo, ele é finalizado e retirado do sistema.
15. Cada P guarda um processo retirado da fila de execução e posto para executar
*/