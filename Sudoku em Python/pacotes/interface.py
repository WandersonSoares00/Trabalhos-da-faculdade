def grade(m):
    print('\n\t\t    A   B   C    D   E   F    G   H   I')
    print('\t\t ++---+---+---++---+---+---++---+---+---++')
    print(f'\t\t1|| {m[0][0]} | {m[0][1]} | {m[0][2]} || { m[0][3]} | {m[0][4]} | {m[0][5]} || {m[0][6]} | {m[0][7]} | {m[0][8]} ||1')
    print('\t\t ++---+---+---++---+---+---++---+---+---++')
    print(f'\t\t2|| {m[1][0]} | {m[1][1]} | {m[1][2]} || {m[1][3]} | {m[1][4]} | {m[1][5]} || {m[1][6]} | {m[1][7]} | {m[1][8]} ||2')
    print('\t\t ++---+---+---++---+---+---++---+---+---++')
    print(f'\t\t3|| {m[2][0]} | {m[2][1]} | {m[2][2]} || {m[2][3]} | {m[2][4]} | {m[2][5]} || {m[2][6]} | {m[2][7]} | {m[2][8]} ||3')
    print('\t\t ++===+===+===++===+===+===++===+===+===++')
    print(f'\t\t4|| {m[3][0]} | {m[3][1]} | {m[3][2]} || {m[3][3]} | {m[3][4]} | {m[3][5]} || {m[3][6]} | {m[3][7]} | {m[3][8]} ||4')
    print('\t\t ++---+---+---++---+---+---++---+---+---++')                                                                     
    print(f'\t\t5|| {m[4][0]} | {m[4][1]} | {m[4][2]} || {m[4][3]} | {m[4][4]} | {m[4][5]} || {m[4][6]} | {m[4][7]} | {m[4][8]} ||5')
    print('\t\t ++---+---+---++---+---+---++---+---+---++')                                                                     
    print(f'\t\t6|| {m[5][0]} | {m[5][1]} | {m[5][2]} || {m[5][3]} | {m[5][4]} | {m[5][5]} || {m[5][6]} | {m[5][7]} | {m[5][8]} ||6')
    print('\t\t ++===+===+===++===+===+===++===+===+===++')                                                                     
    print(f'\t\t7|| {m[6][0]} | {m[6][1]} | {m[6][2]} || {m[6][3]} | {m[6][4]} | {m[6][5]} || {m[6][6]} | {m[6][7]} | {m[6][8]} ||7')
    print('\t\t ++---+---+---++---+---+---++---+---+---++')                                                                     
    print(f'\t\t8|| {m[7][0]} | {m[7][1]} | {m[7][2]} || {m[7][3]} | {m[7][4]} | {m[7][5]} || {m[7][6]} | {m[7][7]} | {m[7][8]} ||8')
    print('\t\t ++---+---+---++---+---+---++---+---+---++')                                                                     
    print(f'\t\t9|| {m[8][0]} | {m[8][1]} | {m[8][2]} || {m[8][3]} | {m[8][4]} | {m[8][5]} || {m[8][6]} | {m[8][7]} | {m[8][8]} ||9')
    print('\t\t ++---+---+---++---+---+---++---+---+---++')
    print('\t\t    A   B   C    D   E   F    G   H   I')
    print()


def gera_matriz(i, j):
    ma = []
    for i in range(i):
        ma = ma + [[' '] * j]
    return ma

    
def limpaTela():
    from sys import platform
    from os import system
    try:
        if "win" in platform:
            system('cls')
        elif "linux" in platform:
            system('clear')
    except:
        print('\n' * 100)


def linha(car = '=-', tam = 26):
    print(f'  {car * tam}')


def titulo(txt = '', cor = 'Vermelho'):
    from time import sleep
    comp = int(len(txt) / 2) + 2
    
    linha(tam = comp)
    print(cores(cor), end='')
    print(txt.center(int(comp*2.2)), end='')
    print(cores('Padrao'))
    linha(tam = comp)
    sleep(2)


def sairJogo(msg='Arquivo não encontrado.'):
    from sys import exit
    titulo(msg)
    exit()


def cores(cor):
    from sys import platform
    if platform in 'linux win32':
        c = {'Amarelo': "\033[1;33m",
             'Vermelho': "\033[1;31m",
             'Padrao': "\033[0;0m",
             'Verde': "\033[1;92m",
             'Azul': "\033[1;94m"}
        return c[cor]
    else:
        return ''
