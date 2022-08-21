from sys import argv
from pacotes.interface import *
from Modos_Jogo import *

user_args = argv[1:]
if len(user_args) == 2: #Se a entrada for 2 arquivos, modo batch
    
    arqDicas = user_args[0]
    arqJogs = user_args[1]    
    Modo_Batch(arqDicas, arqJogs)
elif len(user_args) == 1: #Se a entrada for 1 arquivo, modo interativo
    
    arqDicas = user_args[0]
    Modo_Interativo(arqDicas)
elif len(user_args) == 0: #Tenta abrir o arquivo padrão para o modo interativo
    
    arqDicas = 'arq_01_cfg.txt'
    Modo_Interativo(arqDicas)
else:
    sairJogo('Arquivos inválidos.')
