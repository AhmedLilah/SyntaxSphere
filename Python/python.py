def check_Winner_Row(game):
    x = 'x'
    o = 'o'
    row_counter_o = 0
    row_counter_x = 0
    for i in range(3):
        for j in range(3):
            if game[i][j] == x:
                row_counter_x += 1
            if game[i][j] == o:
                row_counter_o += 1
        if row_counter_x == 3:
            print('x is the winner at row: ',i+1)
            break
        elif row_counter_o == 3:
            print('o is the winner at row: ',i+1)
            break
        row_counter_o = 0
        row_counter_x = 0

def check_Winner_Col(game):
    x = 'x'
    o = 'o'
    row_counter_o = 0
    row_counter_x = 0
    for j in range(3):
        for i in range(3):
            if game[i][j] == x:
                row_counter_x += 1
            if game[i][j] == o:
                row_counter_o += 1
        if row_counter_x == 3:
            print('x is the winner at col: ',j+1)
        elif row_counter_o == 3:
            print('o is the winner at col: ',j+1)
        row_counter_o = 0
        row_counter_x = 0

game= [[0 for i in range(3)] for j in range(3)]


for i in range(3):
    print(game[i])
print()

game[0][0] = 'o'
game[1][0] = 'o'
game[2][0] = 'o'

for i in range(3):
    print(game[i])

check_Winner_Row(game)
check_Winner_Col(game)
