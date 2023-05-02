//EXERCICIO 1
#include <stdio.h>

int main() {
    int n;
    printf("Digite o numero de voltas: ");
    scanf("%d", &n);

    float times[n];
    printf("Digite o tempo de cada volta:");
    for (int i = 0; i < n; i++) {
        scanf("%f", &times[i]);
    }

    float best_time = times[0];
    int best_lap = 1;
    float total_time = 0;
    for (int i = 0; i < n; i++) {
        if (times[i] < best_time) {
            best_time = times[i];
            best_lap = i + 1;
        }
        total_time += times[i];
    }

    printf("Melhor tempo: %.2f\n", best_time);
    printf("Melhor volta: %d\n", best_lap);
    printf("Tempo total: %.2f\n", total_time / n);

    return 0;
}


//EXERCICIO 2
#include <stdio.h>
#include <stdbool.h>

bool validaQuantidade(int qtd) {
    if (qtd >= 0) {
        return true;
    } else {
        return false;
    }
}

float calculaSalario(int qtd) {
    float salario = 600.0;
    if (qtd > 50 && qtd <= 80) {
        salario += (qtd - 50) * 0.5;
    } else if (qtd > 80) {
        salario += (80 - 50) * 0.5 + (qtd - 80) * 0.75;
    }
    return salario;
}

void mostraFinal(float salario) {
    printf("Salario: R$ %.2f\n", salario);
}

int main() {
    int qtd;
    float salario;
    while (true) {
        printf("Digite a quantidade de pecas fabricadas pelo funcionario ou -1 para sair: ");
        scanf("%d", &qtd);
        if (qtd == -1) {
            break;
        }
        if (validaQuantidade(qtd)) {
            salario = calculaSalario(qtd);
            mostraFinal(salario);
        } else {
            printf("Quantidade invalida!\n");
        }
    }
    return 0;
}


//EXERCICIO 3
#include <stdio.h>

int main() {
    int minTimes = 3;
    int maxTimes = 9;
    int minJogadores = 6;
    int maxJogadores = 11;
    int numTimes, numJogadores, idade, peso;
    float mediaIdade, mediaPeso25, totalPeso25, totalJogadores25;
    int totalMenores18 = 0;
    int totalMais80kg = 0;
    float percentualMais80kg;

    printf("Digite o numero de times: ");
    scanf("%d", &numTimes);

    if (numTimes < minTimes || numTimes > maxTimes) {
        printf("Numero de times invalido. Deve ser entre %d e %d.\n", minTimes, maxTimes);
        return 0;
    }

    for (int i = 1; i <= numTimes; i++) {
        printf("Time %d\n", i);
        printf("Digite o numero de jogadores: ");
        scanf("%d", &numJogadores);

        if (numJogadores < minJogadores || numJogadores > maxJogadores) {
            printf("Número de jogadores invalido. Deve ser entre %d e %d.\n", minJogadores, maxJogadores);
            return 0;
        }

        mediaIdade = 0;
        mediaPeso25 = 0;
        totalPeso25 = 0;
        totalJogadores25 = 0;

        for (int j = 1; j <= numJogadores; j++) {
            printf("Jogador %d\n", j);
            printf("Digite a idade: ");
            scanf("%d", &idade);
            printf("Digite o peso: ");
            scanf("%d", &peso);

            mediaIdade += idade;

            if (idade > 25) {
                totalPeso25 += peso;
                totalJogadores25++;
            }

            if (idade < 18) {
                totalMenores18++;
            }

            if (peso > 80) {
                totalMais80kg++;
            }
        }

        mediaIdade /= numJogadores;
        if (totalJogadores25 > 0) {
            mediaPeso25 = totalPeso25 / totalJogadores25;
        }

        printf("Media das idades dos jogadores do time: %.2f\n", mediaIdade);
        printf("Media do peso dos jogadores acima de 25 anos: %.2f\n", mediaPeso25);
    }

    percentualMais80kg = ((float)totalMais80kg / (numTimes * numJogadores)) * 100;

    printf("Quantidade de jogadores menores de idade (18 anos): %d\n", totalMenores18);
    printf("Quantidade e porcentagem de jogadores com mais de 80 quilos: %d (%.2f%%)\n", totalMais80kg, percentualMais80kg);

    return 0;
}


//EXERCICIO 4
#include <stdio.h>
#define SALARIO_MINIMO 1400.00

void classificaSalario(float salario, char *classificacao) {
    if (salario > SALARIO_MINIMO) {
        *classificacao = 'A';
    } else if (salario == SALARIO_MINIMO) {
        *classificacao = 'I';
    } else {
        *classificacao = 'B';
    }
}

void mostraClassifica(float salario, char classificacao, char sexo) {
    printf("Salario: R$%.2f\n", salario);
    printf("Classificaçao: ");
    if (classificacao == 'A') {
        printf("Acima do salario mínimo\n");
    } else if (classificacao == 'I') {
        printf("Igual ao salario mínimo\n");
    } else {
        printf("Abaixo do salario mínimo\n");
    }
    printf("Sexo: ");
    if (sexo == 'M') {
        printf("Masculino\n");
    } else {
        printf("Feminino\n");
    }
}

int main() {
    int n;
    float salario;
    char sexo, classificacao;
    int abaixo = 0, acima = 0;

    printf("Digite o numero de assalariados: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        do {
            printf("\nDigite o sexo do assalariado %d (M/F): ", i + 1);
            scanf(" %c", &sexo);
        } while (sexo != 'M' && sexo != 'F');

        do {
            printf("Digite o salario do assalariado %d: R$", i + 1);
            scanf("%f", &salario);
        } while (salario <= 1.00);

        classificaSalario(salario, &classificacao);
        mostraClassifica(salario, classificacao, sexo);

        if (classificacao == 'A') {
            acima++;
        } else if (classificacao == 'B') {
            abaixo++;
        }
    }

    printf("\nQuantidade de assalariados com salario abaixo do minimo: %d\n", abaixo);
    printf("Quantidade de assalariados com salario acima do minimo: %d\n", acima);

    return 0;
}

