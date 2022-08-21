from pacotes.interface import *
from pacotes.arquivo import *
from pacotes.validacao import *

def Modo_Interativo(dicas):
    if not arq_existe(dicas):
        sairJogo('Arquivo não encontrado.')
    else:
        matriz = gera_matriz(9, 9)
        ler_arquivo(dicas, matriz)        

    while not grade_cheia(matriz):
        grade(matriz)
        titulo('Jogada: <col>, <lin>: <val>   Deletar: D<col>,<lin>', 'Verde')
        jogada = input('Informe sua jogada -> ')
        limpaTela()
        if not jogada_eh_valida(jogada, matriz):
            titulo('Sua jogada é inválida, tente novamente.')
            limpaTela()
    else:
        grade(matriz)
        titulo('Parábens! Você completou o jogo com sucesso! Fim de Jogo!!', 'Azul')


def Modo_Batch(dicas, jogs):
    if not arq_existe(dicas) or not arq_existe(jogs):
        sairJogo('Arquivos inválidos.')
    else:
        matriz = gera_matriz(9, 9)
        ler_arquivo(dicas, matriz)
        ler_arquivo(jogs, matriz, 'jogadas')
        if grade_cheia(matriz):
            titulo('Parabéns! A grade foi preenchida com sucesso!!!', 'Azul')
        else:
            titulo('A grade não foi preenchida.', 'Amarelo')
