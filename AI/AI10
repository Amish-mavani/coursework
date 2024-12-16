# TIC – TAC –TOE game using min-max algorithm.
import math


board = [' ' for _ in range(9)]
#board = [[ '', '', '' ], [ '', '', '' ], [ '', '', '' ]]
def print_board():
    for row in [board[i*3:(i+1)*3] for i in range(3)]:
        print('| ' + ' | '.join(row) + ' |')


def available_moves():
    return [i for i, spot in enumerate(board) if spot == ' ']


def check_winner(player):
    win_combinations = [[0, 1, 2], [3, 4, 5], [6, 7, 8], # Rows
                        [0, 3, 6], [1, 4, 7], [2, 5, 8], # Columns
                        [0, 4, 8], [2, 4, 6]             # Diagonals
                       ]
    for comb in win_combinations:
        if board[comb[0]] == board[comb[1]] == board[comb[2]] == player:
            return True
    return False


def is_board_full():
    return ' ' not in board


def minimax(maxi):
    if check_winner('O'):
        return 1  # AI
    elif check_winner('X'):
        return -1  # Human
    elif is_board_full():
        return 0  # Tie


    if maxi:
        best_score = -math.inf
        for move in available_moves():
            board[move] = 'O'
            score = minimax(False)
            board[move] = ' '
            best_score = max(score, best_score)
        return best_score
    else:
        best_score = math.inf
        for move in available_moves():
            board[move] = 'X'
            score = minimax(True)
            board[move] = ' '
            best_score = min(score, best_score)
        return best_score


def ai_move():
    best_score = -math.inf
    best_move = None
    for move in available_moves():
        board[move] = 'O'
        score = minimax(False)
        board[move] = ' '
        if score > best_score:
            best_score = score
            best_move = move
    board[best_move] = 'O'


print("\nWelcome to Tic-Tac-Toe!")
print_board()  


while True:
    while True:
        try:
            human_move = int(input("\nEnter your move (1-9): ")) - 1
            if board[human_move] == ' ':
                board[human_move] = 'X'
                break
            else:
                print("\nSpot already taken.")
        except (ValueError, IndexError):
            print("\nInvalid move. Try again.")


    print_board()


    if check_winner('X'):
        print("\nCongratulations! You win!")
        break
    elif is_board_full():
        print("\nIt's a tie!")
        break
       
    print("\nAI's turn...")
    ai_move()
    print_board()
       
    if check_winner('O'):
        print("\nAI wins! Better luck next time.")
        break
    elif is_board_full():
        print("\nIt's a tie!")
        break
