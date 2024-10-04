#include <stdio.h>

void printSeparador(char data[]) {
	printf("=====%s=====\n", data);
}

float verificaMenorTempo(float menorTempo, float tempoDeExecucao) {
	if(menorTempo < tempoDeExecucao) {
		return menorTempo;
	} else {
		return tempoDeExecucao;
	}
}

float verificaMaiorTempo(float maiorTempo, float tempoDeExecucao) {
	if(maiorTempo > tempoDeExecucao) {
		return maiorTempo;
	} else {
		return tempoDeExecucao;
	}
}

int main() {

	char dadosColetados[3][62] = {
		"64 bytes from 172.217.29.46: icmp_seq=0 ttl=51 time=27.156 ms",
		"64 bytes from 172.217.29.46: icmp_seq=1 ttl=51 time=27.259 ms",
		"64 bytes from 172.217.29.46: icmp_seq=2 ttl=51 time=29.779 ms",
	};

	// Calcula o tamanho do array de strings para utilizar no for
	int array_length = (sizeof(dadosColetados) / sizeof(dadosColetados[0]));

	float temposDeExecucao[3] = { 27.156, 27.259, 29.779 };

	int pacotesRecebidos = 3;
	int pacotesTransmitidos = 3;
	float pacotesPerdidos = 0;

	printSeparador("Monitor de redes do Leonardo");

	printf("Comando 'ping www.google.com.br'\n");
	printf("Dados coletados:\n");

	for (int i = 0; i < array_length; i++) {
		printf("%s\n", dadosColetados[i]);
	}

	printSeparador("");

	printf("%d pacotes transmitidos\n", pacotesTransmitidos);
	printf("%d pacotes recebidos\n", pacotesRecebidos);
	printf("%.2f%% pacotes perdidos\n", pacotesPerdidos);

	int contador = 0;
	float menorTempo = 36000;
	float maiorTempo;
	float mediaDeTempo;
	float tempoTotalDeExecucao;

	while (contador < array_length) {
		tempoTotalDeExecucao += temposDeExecucao[contador];

		menorTempo = verificaMenorTempo(menorTempo, temposDeExecucao[contador]);
		maiorTempo = verificaMaiorTempo(maiorTempo, temposDeExecucao[contador]);

		contador++;
	}

	printSeparador("");
	printf("Tempo total: %.3fms\n", tempoTotalDeExecucao);
	printf("Tempo mC-nimo: %.3fms\n", menorTempo);
	printf("Tempo mC!ximo: %.3fms\n", maiorTempo);
	printf("Tempo mC)dio: %.3fms\n", (tempoTotalDeExecucao/array_length));

	printSeparador("Fim de execuC'C#o");

	return 0;
}
