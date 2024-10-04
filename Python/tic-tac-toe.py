# Function to print the Tic Tac Toe board
def print_board(board):
    print("\n")
    for row in board:
        print("|".join(row))
        print("-" * 5)
    print("\n")

# Function to check if a player has won
def check_win(board, player):
    # Check rows, columns and diagonals for a win
    for i in range(3):
        if all([spot == player for spot in board[i]]) or all([board[j][i] == player for j in range(3)]):
            return True
    if board[0][0] == board[1][1] == board[2][2] == player or board[0][2] == board[1][1] == board[2][0] == player:
        return True
    return False

# Function to check if the board is full (draw)
def check_draw(board):
    return all([spot != " " for row in board for spot in row])

# Function to play Tic Tac Toe
def play_tic_tac_toe():
    # Initialize the game board
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X"
    
    while True:
        print_board(board)
        print(f"Player {current_player}'s turn. Enter your move (row and column number from 1-3): ")
        
        # Get user input for row and column
        try:
            row, col = map(int, input("Enter row and column: ").split())
            if board[row-1][col-1] != " ":
                print("This spot is already taken. Try again.")
                continue
        except (ValueError, IndexError):
            print("Invalid input. Please enter row and column as two numbers between 1 and 3.")
            continue

        # Place the player's move
        board[row-1][col-1] = current_player

        # Check for a win or draw
        if check_win(board, current_player):
            print_board(board)
            print(f"Player {current_player} wins!")
            break
        elif check_draw(board):
            print_board(board)
            print("It's a draw!")
            break

        # Switch players
        current_player = "O" if current_player == "X" else "X"

# Run the game
play_tic_tac_toe()
