
def repete(i, j, valor, m):
    for cont in range(9): #Testa se os valores na linha se repetem
        if str(valor) == str(m[i][cont]) or m[i][j] != ' ':
            return True
    for cont in range(0, 9, +1): #Testa se os valores na coluna se repetem
        if str(valor) == str(m[cont][j]) or m[i][j] != ' ':
            return True

    a = i // 3    #Descobre a submatriz do valor
    b = j // 3
    for l in range(a * 3, a * 3 + 3, +1):
        for c in range(b * 3, b * 3 + 3, +1):
            if str(valor) == str(m[l][c]) or m[i][j] != ' ':
                return True
    return False


def grade_cheia(m):
    for i in range(9):
        for j in range(9):
            if m[i][j] == ' ':
                return False
    return True


def jogada_eh_valida(jog, m):
    from pacotes.interface import cores, titulo
    
    cols = {"A": 0, "B": 1, "C": 2, "D": 3, "E": 4, "F": 5, "G": 6, "H": 7, "I": 8}
    lins_possiveis = (1, 2, 3, 4, 5, 6, 7, 8, 9)    
    jog = jog.replace(":", ",").replace(" ", "").upper().split(",")

    if len(jog) == 3: #Testa se é uma jogada de adicionar valores na grade
        try:
            col = jog[0]         #jog[0]: <coluna>
            lin = int(jog[1])    #jog[1]: <linha>
            val = jog[2]         #jog[2]: <valor>
            
            if (lin in lins_possiveis) and (col in cols) and (int(val) in lins_possiveis):
                col = cols[col]
                if repete(lin-1, col, val, m):
                    return False
                else:
                    m[lin-1][col] = cores('Amarelo') + val + cores('Padrao')
                    return True
            else:
                return True
        except:
            return False
    else:               #Testa se é uma jogada de delete
        try:                                            #jog[1]: <linha>
            del_l = int(jog[1])                         #jog[0][1]: <coluna>
            del_c = jog[0][1]                           #jog[0]: D<coluna>
    
            if ('D' in jog[0]) and (del_c in cols) and (del_l in lins_possiveis):
                del_c = cols[del_c]
                #No modo interativo, por convenção, as pistas foram definidas como string
                #e as jogadas do tipo inteiro para melhor diferenciação.
                if type(m[del_l-1][del_c]) == str:
                    m[del_l-1][del_c] = ' '
                    return True
                else:
                    titulo('Não é possível apagar uma pista.')
                    return False
            else:
                return False
        except:
            return False
