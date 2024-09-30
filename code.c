#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    char nome[50];
    int idade;
    char diagnostico[100];
    struct Psicologo* psicologo;
    struct Paciente* prox;
} Paciente;

typedef struct Psicologo {
    char nome[50];
    char especialidade[50];
    struct Psicologo* prox;
} Psicologo;

typedef struct Sessao {
    char data[20];
    Paciente* paciente;
    Psicologo* psicologo;
    int duracao;  // em minutos
    char observacoes[200];
    struct Sessao* prox;
} Sessao;

Paciente* criarPaciente(char* nome, int idade, char* diagnostico, Psicologo* psicologo) {
    Paciente* novoPaciente = (Paciente*) malloc(sizeof(Paciente));
    strcpy(novoPaciente->nome, nome);
    novoPaciente->idade = idade;
    strcpy(novoPaciente->diagnostico, diagnostico);
    novoPaciente->psicologo = psicologo;
    novoPaciente->prox = NULL;
    return novoPaciente;
}

Psicologo* criarPsicologo(char* nome, char* especialidade) {
    Psicologo* novoPsicologo = (Psicologo*) malloc(sizeof(Psicologo));
    strcpy(novoPsicologo->nome, nome);
    strcpy(novoPsicologo->especialidade, especialidade);
    novoPsicologo->prox = NULL;
    return novoPsicologo;
}

Sessao* criarSessao(char* data, Paciente* paciente, Psicologo* psicologo, int duracao, char* observacoes) {
    Sessao* novaSessao = (Sessao*) malloc(sizeof(Sessao));
    strcpy(novaSessao->data, data);
    novaSessao->paciente = paciente;
    novaSessao->psicologo = psicologo;
    novaSessao->duracao = duracao;
    strcpy(novaSessao->observacoes, observacoes);
    novaSessao->prox = NULL;
    return novaSessao;
}

void adicionarPaciente(Paciente** lista, Paciente* novoPaciente) {
    novoPaciente->prox = *lista;
    *lista = novoPaciente;
}

void adicionarPsicologo(Psicologo** lista, Psicologo* novoPsicologo) {
    novoPsicologo->prox = *lista;
    *lista = novoPsicologo;
}

void adicionarSessao(Sessao** lista, Sessao* novaSessao) {
    novaSessao->prox = *lista;
    *lista = novaSessao;
}

void exibirPacientes(Paciente* lista) {
    Paciente* atual = lista;
    while (atual != NULL) {
        printf("Paciente: %s, Idade: %d, Diagnóstico: %s, Psicólogo: %s\n", 
               atual->nome, atual->idade, atual->diagnostico, atual->psicologo->nome);
        atual = atual->prox;
    }
}

void exibirSessoes(Sessao* lista) {
    Sessao* atual = lista;
    while (atual != NULL) {
        printf("Data: %s, Paciente: %s, Psicólogo: %s, Duração: %d minutos, Observações: %s\n", 
               atual->data, atual->paciente->nome, atual->psicologo->nome, atual->duracao, atual->observacoes);
        atual = atual->prox;
    }
}

int main() {
    Paciente* listaPacientes = NULL;
    Psicologo* listaPsicologos = NULL;
    Sessao* listaSessoes = NULL;

    Psicologo* psicologo1 = criarPsicologo("Dr. João", "Terapia Cognitivo-Comportamental");
    adicionarPsicologo(&listaPsicologos, psicologo1);
    Psicologo* psicologo2 = criarPsicologo("Dra. Maria", "Psicanálise");
    adicionarPsicologo(&listaPsicologos, psicologo2);

    Paciente* paciente1 = criarPaciente("Carlos", 30, "Ansiedade Generalizada", psicologo1);
    adicionarPaciente(&listaPacientes, paciente1);
    Paciente* paciente2 = criarPaciente("Ana", 25, "Depressão", psicologo2);
    adicionarPaciente(&listaPacientes, paciente2);

    Sessao* sessao1 = criarSessao("2024-09-29", paciente1, psicologo1, 60, "Sessão inicial.");
    adicionarSessao(&listaSessoes, sessao1);
    Sessao* sessao2 = criarSessao("2024-09-30", paciente2, psicologo2, 50, "Sessão de acompanhamento.");
    adicionarSessao(&listaSessoes, sessao2);

    printf("=== Pacientes ===\n");
    exibirPacientes(listaPacientes);

    printf("\n=== Sessões ===\n");
    exibirSessoes(listaSessoes);

    
    return 0;
}
