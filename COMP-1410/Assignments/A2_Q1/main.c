#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

bool make_move(char board[6][7] , int column , char player);
bool check_win(char board[6][7] , char player);
void print_board(char board[6][7]);
char first_capital(const char str[], int n);
void deepest_substring(const char str[], char out[]);

int main()
{
    char board[6][7] = {
            {' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' '}
    };

    char board_column_win[6][7] = {
            {' ',' ',' ',' ',' ',' ',' '},
            {'X',' ',' ',' ',' ',' ',' '},
            {'X',' ',' ',' ',' ',' ',' '},
            {'X',' ',' ',' ',' ',' ',' '},
            {'X',' ',' ',' ',' ',' ',' '},
            {'O',' ',' ',' ',' ',' ',' '}
    };

    char board_row_win[6][7] = {
            {' ',' ',' ',' ',' ',' ',' '},
            {'X',' ',' ',' ',' ',' ',' '},
            {'X','X','X','X',' ',' ',' '},
            {'O','O','O','X',' ',' ',' '},
            {'X','O','X','O',' ',' ',' '},
            {'O','O','O','X',' ',' ',' '}
    };

    char board_row_false[6][7] = {
            {' ',' ',' ',' ',' ',' ',' '},
            {'X','X',' ',' ',' ',' ',' '},
            {'X','X','X',' ',' ',' ',' '},
            {'O','O','O','X',' ',' ',' '},
            {'X','O','O','O','X',' ',' '},
            {'O','O','O','X','O',' ',' '}
    };

    char board_diagwin[6][7] = {
            {' ',' ','X','O','X',' ',' '},
            {'X','X','O','X','X',' ',' '},
            {'O','X','X','O','X',' ',' '},
            {'X','O','O','X','X',' ',' '},
            {'O','O','O','X','O',' ',' '},
            {'O','O','O','X','O',' ',' '}
    };

    char board_diagwin2[6][7] = {
            {' ',' ','X','O','X',' ',' '},
            {'X','X','O','X','X','X',' '},
            {'O','X','X','O','X',' ',' '},
            {'X','O','O','X','X',' ',' '},
            {'O','X','X','X','O',' ',' '},
            {'O','O','O','X','O',' ',' '}
    };

    char board_test_false[6][7] = {
            {' ',' ',' ',' ',' ',' ',' '},
            {'X',' ',' ',' ',' ',' ',' '},
            {'X','O',' ',' ',' ',' ',' '},
            {'O','X','X','O',' ',' ',' '},
            {'X','O','O','X',' ','X',' '},
            {'O','O','X','X','O','X','O'}
    };

    //check_win asserts using above declared boards;
    assert(check_win(board_test_false,'X') == false);
    assert(check_win(board_test_false,'O') == false);
    assert(check_win(board_diagwin,'O') == true);
    assert(check_win(board_row_win,'X') == true);
    assert(check_win(board_row_false,'O') == false);
    assert(check_win(board_column_win,'X') == true);
    assert(check_win(board_diagwin2,'X') == true);

    puts("Player one is X");
    puts("Player two is O");
    print_board(board);
    while(1)
    {
        puts("Player one (X) enter column: ");
        int input;
        int input_converted = scanf("%d", &input);

        if(input_converted == 0 || input < 0 || input > 7)
        {
            puts("Invalid input, exiting program.");
            break;
        }else
        {
            bool move = make_move(board,input,'X');
            while(move == false)
            {
                puts("Illegal move, please try again: ");
                scanf("%d", &input);
                move = make_move(board,input,'X');
            }

            print_board(board);
            if(check_win(board,'X') == true)
            {
                puts("Player one wins!");
                printf("%c\n", 1); //Have to print a smiley face for the winner!
                break;
            }
            else if(board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' && board[0][3] != ' ' &&
                board[0][4] != ' ' && board[0][5] != ' ' && board[0][6] != ' ') //tie game
            {
                puts("Tie game!");
                break;
            }
        }
        //Player two move
        puts("Player two (O) enter column: ");
        input_converted = scanf("%d", &input);
        if(input_converted == 0 || input < 0 || input > 7)
        {
            puts("Invalid input, exiting program.");
            break;
        }else
        {
            bool move = make_move(board,input,'O');
            while(move == false)
            {
                puts("Illegal move, please try again"); //this needs fixing
                scanf("%d", &input);
                move = make_move(board,input,'O');
            }

            print_board(board);
            if(check_win(board,'O') == true)
            {
                puts("Player two wins!");
                printf("%c\n", 1); //Have to print a smiley face for the winner!
                break;
            }
            else if(board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' && board[0][3] != ' ' &&
                    board[0][4] != ' ' && board[0][5] != ' ' && board[0][6] != ' ') //tie game
            {
                puts("Tie game!");
                break;
            }
        }
    }

    //A2_Q2 first_capital assert
    char arr[] = "djfgAABC";
    char arr2[] = "iuhdqhuhDBC";
    char arr3[] = "egoddrriojGCCKFAR";
    char arr4[] = "";
    char arr5[] = "asO";
    char arr6[] = "ABC";
    char arr7[] = "aaaaaaaaaa";
    assert(first_capital(arr,8) == 'A');
    assert(first_capital(arr2,11) == 'D');
    assert(first_capital(arr3,17) == 'G');
    assert(first_capital(arr4,0) == 0);
    assert(first_capital(arr5,3) == 'O');
    assert(first_capital(arr6,3) == 'A');
    assert(first_capital(arr7,10) == 0);

    //A2_Q3 deepest_substring assert
    char str[] = "asdasd(a=b(a+b))asd(c+e)";
    char str2[] = "asd()()(a+b(c+b))";
    char str3[] = "()()()((x))";
    char str4[] = "";
    char str5[] = "abc+(abc)+(a(b(c+e)d)a)";
    //return arrays for asserts
    char ret[20] = "";
    char ret2[20] = "";
    char ret3[20] = "";
    char ret4[20] = "";
    char ret5[20] = "";
    deepest_substring(str,ret);
    assert(strcmp(ret,"a+b") == 0);
    deepest_substring(str2,ret2);
    assert(strcmp(ret2,"c+b") == 0);
    deepest_substring(str3,ret3);
    assert(strcmp(ret3,"x") == 0);
    deepest_substring(str4,ret4);
    assert(strcmp(ret4,"") == 0);
    deepest_substring(str5,ret5);
    assert(strcmp(ret5,"c+e") == 0);

    return 0;
}
// deepest_substring(str, out) updates out to be the deepest substring of
// str; the first is used if multiple possibilities exist
// requires:
// str is a string with balanced parenthesis
// out points to enough memory to store the deepest substring of str
void deepest_substring(const char str[], char out[])
{
    int counter = 0;
    int max_brackets = 0;
    int max_bracket_loc = 0;

    while(str[counter])
    {
        if(str[counter] == '(')
        {
            int max = 1;
            int x = counter;
            while(str[x] != ')')
            {
                if(str[x] == '(')
                    max++;
                if(max > max_brackets)
                {
                    max_brackets = max;
                    max_bracket_loc = x;
                }
                x++;
            }
        }

        counter++;
    }

    if(max_brackets > 0)
    {
        counter = 0; //reset counter
        max_bracket_loc++; //so we get next char after bracket
        while(str[max_bracket_loc] != ')')
        {
            out[counter] = str[max_bracket_loc];
            max_bracket_loc++;
            counter++;
        }

        out[counter + 1] = '\0';
    }
}

// first_capital(str, n) returns the first capital letter in str;
// returns 0 if str contains no capital letters
// requires: str is a string of length n
// str contains only lower -case and upper -case letters
// all lower -case letters appear before upper -case letters
char first_capital(const char str[], int n)
{
    int min = 0;
    int max = n - 1;

    while(min <= max)
    {
        int mid = (min + max) / 2; //calculate mid point

        if(mid == 0)
            return str[mid];

        if(str[mid] >= 'A' && str[mid] <= 'Z')
        {
            if(str[mid - 1] < 'A' || str[mid - 1] > 'Z') //if mid -1 is not a capital than str[mid] is first capital
                return str[mid];
            else
            {
                //increase max because left side of data contains a capital
                max = mid - 1;
            }
        }
        else
        {
            //since mid has no capital, increase min
            min = mid + 1;
        }

    }

    return 0;
}
//Prints the connect four game board
void print_board(char board[6][7])
{
    for(int x = 0; x < 6; x++)
    {
        printf("|");
        for(int i = 0; i < 7; i++)
        {
            printf(" %c |", board[x][i]);
        }
        printf("\n");
    }
}
// make_move(board , column , player) updates the board following a move
// by the given player in the given column; returns false if the move
// was illegal because the column was full
// requires: 0 <= column < 7
// player is either 'X' or 'O'
bool make_move(char board[6][7] , int column , char player)
{
    //check if column is full
    if(board[0][column - 1] == 'X' || board[0][column - 1] == 'O')
        return false;
    //loop through rows of columns
    for(int x = 6; x >= 0; x--)
    {
        //find first empty slot
        if(board[x][column - 1] == ' ')
        {
            board[x][column - 1] = player;
            break;
        }
    }

    return true;
}

// check_win(board) returns true if the given player has 4 connected
// pieces on the board
bool check_win(char board[6][7] , char player)
{
    //check for horizontal win
    for(int x = 0; x < 7; x++)
    {
        for(int i = 0; i < 4; i++)
        {
            if(board[x][i] == player && board[x][i + 1] == player && board[x][i+2] == player && board[x][i+3] == player)
                return true;
        }
    }
    //check for vertical win
    for(int x = 0;x < 7;x++)
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[i][x] == player && board[i + 1][x] == player && board[i + 2][x] == player &&
             board[i + 3][x] == player)
                return true;
        }
    }

    //diag wins
    for(int x = 3; x < 6;x++)
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[x][i] == player && board[x-1][i+1] == player && board[x-2][i+2] == player &&
             board[x-3][i+3] == player)
                return true;
        }
    }
    for(int x = 3; x < 6; x++)
    {
        for(int i = 3; i < 7; i++)
        {
            if(board[x][i] == player && board[x-1][i-1] == player && board[x-2][i-2] == player &&
             board[x-3][i-3] == player)
                return true;
        }
    }

    return false;
}
