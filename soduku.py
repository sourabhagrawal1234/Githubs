import random

def print_board(board):
    for row in board:
        print(" ".join(str(num) if num != 0 else '.' for num in row))

def is_valid(board, row, col, num):
    # Check if num is not in the current row
    if num in board[row]:
        return False
    # Check if num is not in the current column
    if num in (board[i][col] for i in range(9)):
        return False
    # Check if num is not in the current 3x3 grid
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    if num in (board[r][c] for r in range(start_row, start_row + 3) for c in range(start_col, start_col + 3)):
        return False
    return True

def solve(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                for num in range(1, 10):
                    if is_valid(board, row, col, num):
                        board[row][col] = num
                        if solve(board):
                            return True
                        board[row][col] = 0
                return False
    return True

def generate_board():
    board = [[0] * 9 for _ in range(9)]
    numbers = list(range(1, 10))
    
    def fill_grid():
        for row in range(9):
            random.shuffle(numbers)
            for num in numbers:
                if is_valid(board, row, row % 9, num):
                    board[row][row % 9] = num
                    if solve(board):
                        return True
                    board[row][row % 9] = 0
        return False

    fill_grid()
    return board

def remove_elements(board, num_remove=40):
    positions = [(r, c) for r in range(9) for c in range(9)]
    random.shuffle(positions)
    for r, c in positions[:num_remove]:
        board[r][c] = 0

if __name__ == "__main__":
    sudoku_board = generate_board()
    print("Generated Sudoku Puzzle:")
    print_board(sudoku_board)
    
    # Optionally, remove some elements to create a puzzle
    remove_elements(sudoku_board, num_remove=40)
    
    print("\nSudoku Puzzle with Some Numbers Removed:")
    print_board(sudoku_board)

    # Solve the puzzle
    print("\nSolving the Puzzle...")
    solved_board = [row[:] for row in sudoku_board]  # Copy the board
    solve(solved_board)
    
    print("\nSolved Sudoku Puzzle:")
    print_board(solved_board)
