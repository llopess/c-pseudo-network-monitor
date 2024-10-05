DISCLAIMER: THIS CODE DOES NOT IMPLEMENT A NETWORK MONITOR, IT IS USED FOR ACADEMIC PURPOSES

# Monitor de redes

- Executou-se o script `network.sh` da seguinte forma

```bash
$ sh network.sh 3 www.google.com.br
```

O primeiro parâmetro é a quantidade de pacotes que deseja-se enviar;  
O segundo parâmetro é o endereço da página que deseja-se enviar o pacote;

O arquivo de registro da execução do script gerou-se no mesmo diretório onde o script estava; arquivo este que pode ser facilmente encontrado, dado seu padrão de criação, que se segue:  
- `XXXXXX-network-monitor.log`  

Onde: `XXXXXX` é a data da execução do script em milisegundos decorridos desde 1 de Janeiro de 1970 UTC.

Deste arquivo `.log` extraiu-se os dados mostrados no código escrito no arquivo `monitor.c`.