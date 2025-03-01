package main

import (
    "fmt"
)

func countBattleships(board [][]byte) int {
    row := len(board);
    col := len(board[0]);
    ships := 0;

    for  i := 0; i < row; i++ {
        for  j := 0; j < col; j++ {
            if board[i][j] != 'X' {
                continue
            }

            ships++;         
            k := j;
            for k < col && board[i][k] == 'X' {
                board[i][k] = '.';
                k++;
            }
            k = i;
            for k < row && board[k][j] == 'X' {
                board[k][j] = '.';
                k++;
            }
        }
    }
 
    return ships;
}

func main()  {
    fmt.Println(countBattleships([][]byte{{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}}))
}
