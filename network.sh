LOG=$(pwd)/$(date +%s)-network-monitor.log

echo "Script desenvolvido por Leonardo Lopes"

echo "Executando comando 'ping' com $1 envios de pacote às $(date)"

echo "===Inicio===" >> $LOG

ping -c $1 $2 >> $LOG

echo "===Fim de execução===" >> $LOG
