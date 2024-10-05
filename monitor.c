#include <stdio.h>
#include <unistd.h> // biblioteca necessária para utilizar a função sleep

// Adiciona uma série de caracteres a uma string com o objetivo de 
// criar um separador visível durante a execução do código e apresenta em tela
void printSeparador(char data[]) {
	printf("=====%s=====\n\n", data);
}

/* Com base nos dois parâmetros passados, verifica se um novo
   tempo de execução é menor do que o menor tempo já registrado

   retorna o menor tempo
*/
float verificaMenorTempo(float menorTempo, float tempoDeExecucao) {
	if (menorTempo < tempoDeExecucao) {
		return menorTempo;
	} else {
		return tempoDeExecucao;
	}
}


/* Com base nos dois parâmetros passados, verifica se um novo
   tempo de execução é maior do que o maior tempo já registrado

   retorna o maior tempo
*/
float verificaMaiorTempo(float maiorTempo, float tempoDeExecucao) {
	if (maiorTempo > tempoDeExecucao) {
		return maiorTempo;
	} else {
		return tempoDeExecucao;
	}
}

// Apresenta em tela dados do comando ipconfig
void printIpconfig() {
    char ipv4[] = "192.168.2.120";
    char ipv6[] = "2804:60:367:9c00:e6cb:b67:47aa:9526";
    
    printSeparador("Informações IP");
    printf("Dados coletados a partir da exeucão do comando ipconfig:\n");
    printf("IPv4: %s\n", ipv4);
    printf("IPv6: %s\n", ipv6);
    printSeparador("");
}

// Apresenta em tela dados do comando ping
void printPing() {
	// Cria um array de 3 posições, onde cada posição comporta 62 caracteres
	// para salvar os dados do comando ping
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
	
	int contador = 0;
	float menorTempo = 36000;
	float maiorTempo;
	float mediaDeTempo;
	float tempoTotalDeExecucao;
	
	printSeparador("Comando 'ping'");
	printf("Dados coletados a partir da execução do comando 'ping www.google.com.br':\n");

	for (int i = 0; i < array_length; i++) {
		printf("%s\n", dadosColetados[i]);
	}

	printSeparador("");

	printf("%d pacotes transmitidos\n", pacotesTransmitidos);
	printf("%d pacotes recebidos\n", pacotesRecebidos);
	printf("%.2f%% pacotes perdidos\n", pacotesPerdidos);

	while (contador < array_length) {
		tempoTotalDeExecucao += temposDeExecucao[contador];

		menorTempo = verificaMenorTempo(menorTempo, temposDeExecucao[contador]);
		maiorTempo = verificaMaiorTempo(maiorTempo, temposDeExecucao[contador]);

		contador++;
	}

	printSeparador("");
	
	printf("Tempo mínimo: %.3fms\n", menorTempo);
	printf("Tempo máximo: %.3fms\n", maiorTempo);
	printf("Tempo médio: %.3fms\n", (tempoTotalDeExecucao/array_length));
	printf("Tempo total: %.3fms\n", tempoTotalDeExecucao);
	
	printSeparador("");
}

// Apresenta em tela dados do comando tracert
void printTracert() {
    char tracertInfo[13][55] = {
        "*    	*    	* 	Esgotado o tempo limite do pedido.",
        "54 ms	31 ms	13 ms  2804:60:6000:171::2",
        " 5 ms	57 ms	26 ms  2804:60:6000:171::1",
        "13 ms 	5 ms 	8 ms  fc00::12",
        "11 ms	22 ms	10 ms  2804:d50:8c:7001::1",
        "*    	*    	* 	Esgotado o tempo limite do pedido.",
        "*   	31 ms	29 ms  2001:4860:1:1::f72",
        "32 ms	32 ms	31 ms  2800:3f0:8073::1",
        "41 ms	27 ms	31 ms  2001:4860:0:1::2062",
        "30 ms	33 ms	33 ms  2001:4860:0:1::12e0",
        "32 ms 	*   	30 ms  2001:4860:0:1::7c85",
        "34 ms	36 ms	36 ms  2001:4860:0:1::67d1",
        "30 ms	27 ms	27 ms  2800:3f0:4001:81a::2003"
    };
    
    printSeparador("Comando tracert");
    printf("Dados coletados a partir do comando 'tracert www.google.com.br':\n\n");

    for(int i = 0; i < 13; i++) {
        printf("%d %s\n", i+1, tracertInfo[i]);
    }
}

// Chama três funções para apresentar dados de rede
int main() {
	printSeparador("Monitor de redes do Leonardo");
	
	printIpconfig();
	sleep(2);
	printPing();
	sleep(2);
	printTracert();

	printSeparador("Fim de execução");

	return 0;
}