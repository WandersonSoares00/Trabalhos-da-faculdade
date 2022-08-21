
def arq_existe(nome):
    try:
        with open(nome, 'r') as arq:
            pass
        return True
    except FileNotFoundError:
        return False


def ler_arquivo(nome, mat, tipo = 'pistas'):
    from pacotes.validacao import repete
    from pacotes.interface import cores, sairJogo
    
    cols = {"A": 0, "B": 1, "C": 2, "D": 3, "E": 4, "F": 5, "G": 6, "H": 7, "I": 8}
    contDicas = 0 #Contador de dicas para verificar se o arquivo possui mais de 1 dica e menos de 80
    try:
        with open(nome, 'r+') as arquivo:
            for l in arquivo:
                try:
                    l = l.strip().replace(':', ',').upper().split(',')
                    col = l[0]
                    l[0] = cols[l[0]]
                    l[1], l[0], l[2] = int(l[1])-1, int(l[0]), int(l[2])
                    contDicas += 1
                    if repete(l[1], l[0], l[2], mat):
                        if tipo == 'pistas':
                            sairJogo('As pistas são inválidas.')
                        elif tipo == 'jogadas':
                            print(f'A jogada {col}, {l[1] + 1}: {l[2]} eh invalida!')
                    else:
                        mat[ l[1] ][ l[0] ] = l[2]
                except:
                    sairJogo('Arquivo com informações inválidas.')
        if contDicas < 1 or contDicas > 80:
            sairJogo('A quantidade de dicas informadas não é esperada pelo jogo.')
        contDicas = 0
    except FileNotFoundError:
        sairJogo('Não foi possível abrir o arquivo.')
