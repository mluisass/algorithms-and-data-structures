#include <iostream>
using namespace std;

typedef struct Processo{
    string id;
    int ciclosFeitos;
    Processo *next;
} Processo;

Processo *adicionar (Processo *cursor, string id, int ciclo)
{
    Processo *p = new Processo();
    p->id = id;
    p->ciclosFeitos = ciclo;
    p->next = cursor->next;
    cursor->next = p;
    return cursor->next;
}

void percorrer (Processo *cursor)
{
    while (cursor->next != NULL)
    {
        cout << "id: " << cursor->id << endl << "ciclo atual: " <<  cursor->ciclosFeitos << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << n;
    Processo *head, *tail, *sentinela;
    head = new Processo();
    tail = new Processo();
    sentinela == new Processo();
    head = sentinela;
    tail = sentinela;
    for (int i = 0; i < n; i++)
    {
        string comando, id;
        cin >> comando;
        cin >> id;
        tail = adicionar(tail, id, i);
        //cout << "id: " << tail->id << endl << "ciclo atual: " <<  tail->ciclosFeitos << endl;
    }
    percorrer (head);

    return 0;
}