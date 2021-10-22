public class TicTacToe {
    public static final char EMPTY = '\u0000';
    private final char[][] board;
    private int moves;
    private static final int diagonals = 2;
    private static final int MINOR = 1;
    private static final int PRINCIPAL = 0;
    private final int gridSize;
    private final int[] rowTotal;
    private final int[] colTotal;
    private final int[] diagonalTotal;

    public TicTacToe(int size) {
        if (size < 3) throw new IllegalArgumentException("minimum 3x3 grid");
        board = new char[size][size];
        gridSize = size;
        rowTotal = new int[size];
        colTotal = new int[size];
        diagonalTotal = new int[diagonals];
    }

    public char[][] showBoard() {
        return board.clone();
    }

    public String move(int x, int y) {
        if (board[x][y] != EMPTY)
            return "(" + x + "," + y + ") is already occupied";
        board[x][y] = xOrO();
        return isThisLastMove(x, y, board[x][y], ++moves);
    }

    private char xOrO() {
        return moves % 2 == 0 ? 'X' : 'O';
    }

    private String isThisLastMove(int x, int y, char symbol, int moveCount) {
        if (isWinning(x, y, symbol))
            return symbol + " won the game!";
        if (isBoardFull(moveCount))
            return "Draw!";
        return "continue";
    }

    private boolean isBoardFull(int moveCount) {
        return moveCount == gridSize * gridSize;
    }

    private boolean isWinning(int x, int y, char symbol) {
        if (isPrincipalDiagonal(x, y) && allSymbolsMatch(symbol, diagonalTotal, PRINCIPAL))
            return true;
        if (isMinorDiagonal(x, y) && allSymbolsMatch(symbol, diagonalTotal, MINOR))
            return true;
        return allSymbolsMatch(symbol, rowTotal, x) || allSymbolsMatch(symbol, colTotal, y);
    }

    private boolean allSymbolsMatch(char symbol, int[] total, int index) {
        total[index] += symbol;
        return total[index] / gridSize == symbol;
    }

    private boolean isPrincipalDiagonal(int x, int y) {
        return x == y;
    }

    private boolean isMinorDiagonal(int x, int y) {
        return x + y == gridSize - 1;
    }
}