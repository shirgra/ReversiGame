#include <stdio.h>
/* Assignment:1
 * Author: Shir Granit
 * ID: 205531445 */

//function validate the input password//
//input: password from user;
//output: 0 for wrong input, 1 for correct input;
int ValidCheck(char* x);

//Decryption function//
//input: password from user;
//output: print for user his decrypted password;
char Encryption(char* x);

//Reversi VS computer//
//input: none;
//output: 22 for a win of 'O', 11 for a win of 'X';
int ReversiVScomputer();

//Reversi 2 Players//
//input: none;
//output: 22 for a win of 'O', 11 for a win of 'X';
int Reversi2Players();

int main(){
    int choose,gamechoose, i, valid=0,endgame=1;
    int XScoreGame=0, OScoreGame=0, tempgamescore;
    char password[8], YorNrepeatGame;
    do{
        printf("Hello User! Please type the number you want to execute:\n 1.Encryption\n 2.Reversi\n 3.Exit\n");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Welcome to the Encryption program! Please enter your Password:\n");
                do{
                    valid=0;
                    scanf ("%8s", password);
                    while (getchar()!='\n'){
                        valid=1;
                    }
                }
                while((ValidCheck(password)!=1)||(valid==1));
                Encryption(password);
                break;
            case 2:
                while (getchar() != '\n');
                do {
                    printf("Welcome to the Reversi game, Please enter the form in witch you want to play:\n 1. VS computer\n 2. 2 Players\n");
                    scanf("%d", &gamechoose);
                    switch (gamechoose) {
                        case 1:
                            do {
                                //play the game:
                                tempgamescore = ReversiVScomputer();
                                if (tempgamescore == 11)//mark for X won
                                    XScoreGame++;
                                else if (tempgamescore == 22)//mark for O won
                                    OScoreGame++;
                                printf("Total score: the score is %d for player O, and %d for X\n", OScoreGame,
                                       XScoreGame);
                                printf("Would you like to play again? please answer Y/N\n");
                                scanf("%c", &YorNrepeatGame);
                                while (getchar() != '\n');

                                if (YorNrepeatGame == 'N') {
                                    if (OScoreGame > XScoreGame) {
                                        printf("The winner is player O with the score of %d:%d\n", OScoreGame,
                                               XScoreGame);
                                    } else if (XScoreGame > OScoreGame) {
                                        printf("The winner is player X with the score %d:%d\n", XScoreGame, OScoreGame);
                                    }
                                    endgame = 1;
                                    tempgamescore=0;
                                    XScoreGame=0;
                                    OScoreGame=0;
                                }
                                if (YorNrepeatGame == 'Y') {
                                    endgame=0;
                                }
                            }
                            while(endgame==0);
                            break;
                        case 2:
                            do {
                                //play the game:
                                tempgamescore = Reversi2Players();
                                if (tempgamescore == 11)//mark for X won
                                    XScoreGame++;
                                else if (tempgamescore == 22)//mark for O won
                                    OScoreGame++;
                                printf("Total score: the score is %d for player O, and %d for X\n", OScoreGame,
                                       XScoreGame);
                                printf("Would you like to play again? please answer Y/N\n");
                                scanf("%c", &YorNrepeatGame);
                                while (getchar() != '\n');

                                if (YorNrepeatGame == 'N') {
                                    if (OScoreGame > XScoreGame) {
                                        printf("The winner is player O with the score of %d:%d\n", OScoreGame,
                                               XScoreGame);
                                    } else if (XScoreGame > OScoreGame) {
                                        printf("The winner is player X with the score %d:%d\n", XScoreGame, OScoreGame);
                                    }
                                    endgame = 1;
                                    tempgamescore=0;
                                    XScoreGame=0;
                                    OScoreGame=0;
                                }
                                if (YorNrepeatGame == 'Y') {
                                    endgame=0;
                                }

                                }
                            while(endgame==0);
                            break;
                        default:
                            printf("Please enter a valid number.\n");
                            while (getchar() != '\n');
                    }
                }
                while(endgame==0);
                break;
            case 3:
                return 0;
            default:
                printf("Please enter a valid number,\n");
                while (getchar()!='\n');
        }
    }
    while(choose!=3);
}

int ValidCheck(char* x){
    int i=0, countAtoZ=0, count0to9=0;
    for(i;i<=7;i++){
        if((x[i] >= 'A' && x[i] <= 'Z'))
            ++countAtoZ;
        if((x[i] >= '0' && x[i] <= '9'))
            ++count0to9;
    }
    if(countAtoZ<2 || count0to9<2 || (count0to9+countAtoZ)!=8){
        printf("Syntax Error, Please enter a valid Password:\n");
        return 0;
    }
    else
        return 1;
}

char Encryption(char* x){
    int i=0;
    char temp, temparr[8];
    //Step #1: reverse Plus 3//
    for (i; i <= 7; i++) {
        if('0'<=x[i] && x[i]<='2')
            x[i]=x[i]+7;
        else if('A'<=x[i] && x[i]<='C')
            x[i]=x[i]+23;
        else
            x[i]=x[i]-3;
    }
    //Step #2: reverse Encryption table//

    for (i=0; i <= 7; i++) {
        switch (x[i]){
            case 'S':
                x[i]='A';
                break;
            case '5':
                x[i]='B';
                break;
            case 'P':
                x[i]='C';
                break;
            case 'W':
                x[i]='D';
                break;
            case 'A':
                x[i]='E';
                break;
            case 'R':
                x[i]='F';
                break;
            case '8':
                x[i]='G';
                break;
            case 'Q':
                x[i]='H';
                break;
            case 'I':
                x[i]='I';
                break;
            case 'V':
                x[i]='J';
                break;
            case 'B':
                x[i]='K';
                break;
            case '0':
                x[i]='L';
                break;
            case 'D':
                x[i]='M';
                break;
            case 'Z':
                x[i]='N';
                break;
            case '3':
                x[i]='O';
                break;
            case 'C':
                x[i]='P';
                break;
            case '2':
                x[i]='Q';
                break;
            case 'H':
                x[i]='R';
                break;
            case '4':
                x[i]='S';
                break;
            case '1':
                x[i]='T';
                break;
            case 'K':
                x[i]='U';
                break;
            case '7':
                x[i]='V';
                break;
            case 'G':
                x[i]='W';
                break;
            case 'Y':
                x[i]='X';
                break;
            case '6':
                x[i]='Y';
                break;
            case 'O':
                x[i]='Z';
                break;
            case 'J':
                x[i]='0';
                break;
            case 'E':
                x[i]='1';
                break;
            case 'U':
                x[i]='2';
                break;
            case 'N':
                x[i]='3';
                break;
            case 'F':
                x[i]='4';
                break;
            case '9':
                x[i]='5';
                break;
            case 'M':
                x[i]='6';
                break;
            case 'L':
                x[i]='7';
                break;
            case 'T':
                x[i]='8';
                break;
            case 'X':
                x[i]='9';
                break;
        }
    }
    //Step #3: reverse Swap//
    for (i=0; i <= 7; i++) {
        if(i%2==0){
            temp=x[i];
            x[i]=x[i+1];
            x[i+1]=temp;
        }
    }
    //Step #4: reverse Reverse//
    for (i=0; i <= 7; i++) {
        temparr[7-i]=x[i];
    }
    for (i=0; i <= 7; i++) {
        x[i]=temparr[i];
    }
    //Step #5: reverse ROL left 2//
    temparr[0]=x[6];
    temparr[1]=x[7];
    temparr[2]=x[0];
    temparr[3]=x[1];
    temparr[4]=x[2];
    temparr[5]=x[3];
    temparr[6]=x[4];
    temparr[7]=x[5];
    for (i=0; i <= 7; i++) {
        x[i]=temparr[i];
    }
    //Print Encryption for user//
    printf("Your Original Password was: ");
    for (i=0; i <= 7; i++) {
        printf("%c",x[i]);
    }
    printf("\n\n");
}

int ReversiVScomputer(){
    //here O is the computer and X is the Player:
    int i, j, itemp, jtemp, itemp2, jtemp2, rowcheck, columncheck;
    int Boardfull=0;
    int Xresult=0, Oresult=0;
    int randfirst;
    int oktoflip=0, validflip=0;
    int flips=0, flipstemp=0, row=0, column=0;
    char GameBoard[8][8], turn;
    while (getchar() != '\n');

    //resat Board
    for (i = 0; i <= 7; i++) {
        for (j = 0; j <= 7; j++)
            if ((i == 3 && j == 3) || (i == 4 && j == 4))
                GameBoard[i][j] = 'O';
            else if ((i == 3 && j == 4) || (i == 4 && j == 3))
                GameBoard[i][j] = 'X';
            else
                GameBoard[i][j] = '-';
    }
    //Print GameBoard:
    for (i = 0; i <= 7; i++) {
        for (j = 0; j <= 7; j++)
            printf(" %c", GameBoard[i][j]);
        printf("\n");
    }

    //random first player:
    srand(time(0));
    randfirst=rand()%2;
    if(randfirst)
        turn='X';
    else
        turn='O';

    //play the game:
    do {
        if (turn == 'X') {
            //Take coordinates from user:
            printf("It's %c turn, Please enter your I J coordinates:\n", turn);
            scanf("%d %d", &i, &j);
            while (!(i <= 7 && i >= 0 && j <= 7 && j >= 0) //check I J in range
                   || GameBoard[i][j] != '-' //check I J spot is free
                   || (GameBoard[i - 1][j - 1] == '-' && GameBoard[i - 1][j] == '-' && GameBoard[i - 1][j + 1] == '-' &&
                       GameBoard[i][j - 1] == '-' && GameBoard[i][j + 1] == '-' && GameBoard[i + 1][j - 1] == '-' &&
                       GameBoard[i + 1][j] == '-' && GameBoard[i + 1][j + 1] == '-')
                   || ((i == 7) && (GameBoard[6][j] == '-' && GameBoard[6][j - 1] == '-' && GameBoard[6][j + 1] == '-' && GameBoard[7][j + 1]=='-' && GameBoard[7][j - 1]=='-'))
                   || ((i == 0) && (GameBoard[1][j] == '-' && GameBoard[1][j - 1] == '-' && GameBoard[1][j + 1] == '-' && GameBoard[0][j + 1]=='-' && GameBoard[0][j - 1]=='-'))
                   || ((j == 7) && (GameBoard[i][6] == '-' && GameBoard[i - 1][6] == '-' && GameBoard[i + 1][6] == '-' && GameBoard[i - 1][7]=='-' && GameBoard[i + 1][7]=='-'))
                   || ((j == 0) && (GameBoard[i][1] == '-' && GameBoard[i - 1][1] == '-' && GameBoard[i + 1][1] == '-' && GameBoard[i - 1][0]=='-' && GameBoard[i + 1][0]=='-'))
                   || ((i==0)&&(j==0)&&(GameBoard[0][1] == '-')&&(GameBoard[1][0] == '-')&&(GameBoard[1][1] == '-'))
                   || ((i==7)&&(j==7)&&(GameBoard[7][6] == '-')&&(GameBoard[7][6] == '-')&&(GameBoard[6][6] == '-'))
                   //check at least one I J neighbor exist
                    ) {
                if (!(i <= 7 && i >= 0 && j <= 7 && j >= 0)) {
                    while (getchar() != '\n');
                    printf("Syntax Error, Please enter valid coordinates:\n");
                    scanf("%d %d", &i, &j);
                } else {
                    while (getchar() != '\n');
                    printf("Game rules do not allow such move, Please enter valid coordinates:\n");
                    scanf("%d %d", &i, &j);
                }
            }

            //Place a piece on the board and flip pieces:
                GameBoard[i][j] = 'X';
                //CHECK AND FLIP:
                //check flips for x left side:
                oktoflip = 0;
                for (jtemp = j; jtemp >= 0; jtemp--) {
                    if (GameBoard[i][jtemp] == '-') {
                        oktoflip = (-1);
                    }
                    if (GameBoard[i][jtemp] == 'X' && (oktoflip != (-1))) {
                        for (jtemp2 = jtemp+1; jtemp2 <= j; jtemp2++) {
                            GameBoard[i][jtemp2] = 'X';
                            oktoflip = 1;
                        }
                    }
                }
                //check flips for x right side:
                oktoflip = 0;
                for (jtemp = j; jtemp <= 7; jtemp++) {
                    if (GameBoard[i][jtemp] == '-') {
                        oktoflip = (-1);
                    }
                    if (GameBoard[i][jtemp] == 'X' && (oktoflip != (-1))) {
                        for (jtemp2 = jtemp-1; jtemp2 >= j; jtemp2--) {
                            GameBoard[i][jtemp2] = 'X';
                            oktoflip = 1;
                        }
                    }
                }
                //check flips for y up:
                oktoflip = 0;
                for (itemp = i; itemp >= 0; itemp--) {
                    if (GameBoard[itemp][j] == '-') {
                        oktoflip = (-1);
                    }
                    if (GameBoard[itemp][j] == 'X' && (oktoflip != (-1))) {
                        for (itemp2 = itemp; itemp2 <= i; itemp2++) {
                            GameBoard[itemp2][j] = 'X';
                            oktoflip = 1;
                        }
                    }
                }
                //check flips for y down:
                oktoflip = 0;
                for (itemp = i; itemp <= 7; itemp++) {
                    if (GameBoard[itemp][j] == '-') {
                        oktoflip = (-1);
                    }
                    if (GameBoard[itemp][j] == 'X' && (oktoflip != (-1))) {
                        for (itemp2 = itemp; itemp2 >= i; itemp2--) {
                            GameBoard[itemp][j] = 'X';
                            oktoflip = 1;
                        }
                    }
                }
                //check flips on diagonals top to bottom:
                oktoflip = 0;
                for (itemp = i, jtemp = j; itemp <= 7 && jtemp <= 7; itemp++, jtemp++) {
                    if (GameBoard[itemp][jtemp] == '-') {
                        oktoflip = (-1);
                    }
                    if (GameBoard[itemp][jtemp] == 'X' && (oktoflip != (-1))) {
                        for (itemp2 = itemp, jtemp2 = jtemp; itemp2 >= i||jtemp2 >= j; itemp2--, jtemp2--) {
                            GameBoard[itemp2][jtemp2] = 'X';
                            oktoflip = 1;
                        }
                    }
                }
                //check flips on diagonals bottom to top:
                oktoflip=0;
                for (itemp = i, jtemp = j; itemp >=0 && jtemp <=7; itemp--, jtemp++) {
                    if (GameBoard[itemp][jtemp] == '-') {
                        oktoflip = (-1);
                    }
                    if (GameBoard[itemp][jtemp] == 'X' && (oktoflip != (-1))) {
                        for (itemp2 = itemp, jtemp2 = jtemp; ((itemp2 <= i)||(jtemp2 >= j)); itemp2++, jtemp2--) {
                            GameBoard[itemp2][jtemp2] = 'X';
                            oktoflip = 1;
                        }
                    }
                }

            turn='O';
        }
        else if (turn == 'O') {
            i=0;j=0;
            itemp=0; jtemp=0; flips=0; flipstemp=0;
            //Choosing (I,J) for computer player:
            //default choosing:
            for(i=0;i<=7;i++){
                for(j=0;j<=7;j++){
                    //the first legal spot you find:
                    if((GameBoard[i][j]=='-')&&(
                            ((GameBoard[i-1][j]=='O')||(GameBoard[i-1][j-1]=='O')||(GameBoard[i-1][j+1]=='O')||(GameBoard[i][j-1]=='O')||(GameBoard[i][j+1]=='O')||(GameBoard[i+1][j]=='O')||(GameBoard[i+1][j-1]=='O')||(GameBoard[i+1][j+1]=='O'))
                            ||
                            (GameBoard[i-1][j]=='X')||(GameBoard[i-1][j-1]=='X')||(GameBoard[i-1][j+1]=='X')||(GameBoard[i][j-1]=='X')||(GameBoard[i][j+1]=='X')||(GameBoard[i+1][j]=='X')||(GameBoard[i+1][j-1]=='X')||(GameBoard[i+1][j+1]=='X'))
                        ){
                        flips=(-1);
                        break;
                    }
                }
                if(flips==(-1)) {
                    break;
                }
            }
            flips=0;

            //calc computer options and set choice:
            //check axis y down side:
            for(jtemp=0;jtemp<=7;jtemp++) {
                for (itemp = 0; itemp <=7; itemp++) {
                    if (GameBoard[itemp][jtemp] == 'O') {
                        oktoflip = 0;
                        flipstemp = 0;
                        for (itemp2 = itemp; itemp2 <= 7; itemp2++) {
                            if (GameBoard[itemp2][jtemp] == '-') {
                                oktoflip = (-1);
                            }
                            if ((GameBoard[itemp2][jtemp] != '-') && (oktoflip != (-1))) {
                                if (GameBoard[itemp2][jtemp] == 'X') {
                                    flipstemp++;
                                }
                                if ((flipstemp >= flips) && (GameBoard[itemp2+1][jtemp] == '-')  && (itemp2!=0)) {
                                    i = itemp2+1;
                                    j = jtemp;
                                    flips = flipstemp;
                                }
                            }
                        }
                    }
                }
            }
            //check axis y up side:
            for(jtemp=0;jtemp<=7;jtemp++) {
                for (itemp = 0; itemp <=7; itemp++) {
                    if (GameBoard[itemp][jtemp] == 'O') {
                        oktoflip = 0;
                        flipstemp = 0;
                        for (itemp2 = itemp; itemp2 >= 0; itemp2--) {
                            if (GameBoard[itemp2][jtemp] == '-') {
                                oktoflip = (-1);
                            }
                            if ((GameBoard[itemp2][jtemp] != '-') && (oktoflip != (-1))) {
                                if (GameBoard[itemp2][jtemp] == 'X') {
                                    flipstemp++;
                                }
                                if ((flipstemp >= flips) && (GameBoard[itemp2-1][jtemp] == '-') && (itemp2!=0)) {
                                    i = itemp2-1;
                                    j = jtemp;
                                    flips = flipstemp;
                                }
                            }
                        }
                    }
                }
            }
            //check axis x right side:
            for(itemp=0;itemp<=7;itemp++) {
                for (jtemp = 0; jtemp <=7; jtemp++) {
                    if (GameBoard[itemp][jtemp] == 'O') {
                        oktoflip = 0;
                        flipstemp = 0;
                        for (jtemp2 = jtemp; jtemp2 <=7; jtemp2++) {
                            if (GameBoard[itemp][jtemp2] == '-') {
                                oktoflip = (-1);
                            }
                            if ((GameBoard[itemp][jtemp2] != '-') && (oktoflip != (-1))) {
                                if (GameBoard[itemp][jtemp2] == 'X') {
                                    flipstemp++;
                                }
                                if ((flipstemp >= flips) && (GameBoard[itemp][jtemp2 + 1] == '-') && (jtemp2!=0)) {
                                    i = itemp;
                                    j = jtemp2 + 1;
                                    flips = flipstemp;
                                }
                            }
                        }
                    }
                }
            }
            //check axis x left side:
            for(itemp=0;itemp<=7;itemp++) {
                for (jtemp = 0; jtemp <=7; jtemp++) {
                    if (GameBoard[itemp][jtemp] == 'O') {
                        oktoflip = 0;
                        flipstemp = 0;
                        for (jtemp2 = jtemp; jtemp2 >=0; jtemp2--) {
                            if (GameBoard[itemp][jtemp2] == '-') {
                                oktoflip = (-1);
                            }
                            if ((GameBoard[itemp][jtemp2] != '-') && (oktoflip != (-1))) {
                                if (GameBoard[itemp][jtemp2] == 'X') {
                                    flipstemp++;
                                }
                                if ((flipstemp >= flips) && (GameBoard[itemp][jtemp2 - 1] == '-') && (jtemp2!=0)) {
                                    i = itemp;
                                    j = jtemp2 - 1;
                                    flips = flipstemp;
                                }
                            }
                        }
                    }
                }
            }
            //check diagonals axis top to bottom:
            for(columncheck=0;columncheck<=7;columncheck++) {
                for (itemp=columncheck, jtemp = 0; ((itemp <= 7) && (jtemp <= 7)); itemp++, jtemp++) {
                    if (GameBoard[itemp][jtemp] == 'O') {
                        oktoflip = 0;
                        flipstemp = 0;
                        for (itemp2=itemp, jtemp2 = jtemp; jtemp2 >= 0 || itemp2>=0; itemp2--,jtemp2--) {
                            if (GameBoard[itemp2][jtemp2] == '-') {
                                oktoflip = (-1);
                            }
                            if ((GameBoard[itemp2][jtemp2] != '-') && (oktoflip != (-1))) {
                                if (GameBoard[itemp2][jtemp2] == 'X') {
                                    flipstemp++;
                                }
                                if ((flipstemp >= flips) && (GameBoard[itemp2-1][jtemp2 - 1] == '-') && (itemp2!=0&&jtemp2!=0)) {
                                    i = itemp2 - 1;
                                    j = jtemp2 - 1;
                                    flips = flipstemp;
                                }
                            }
                        }
                    }
                }
            }
            //check diagonals axis top to bottom:
            for(rowcheck=0;rowcheck<=7;rowcheck++) {
                for (jtemp=rowcheck, itemp = 0; ((itemp <= 7) && (jtemp <= 7)); itemp++, jtemp++) {
                    if (GameBoard[itemp][jtemp] == 'O') {
                        oktoflip = 0;
                        flipstemp = 0;
                        for (itemp2=itemp, jtemp2 = jtemp; jtemp2 >= 0 || itemp2>=0; itemp2--,jtemp2--) {
                            if (GameBoard[itemp2][jtemp2] == '-') {
                                oktoflip = (-1);
                            }
                            if ((GameBoard[itemp2][jtemp2] != '-') && (oktoflip != (-1))) {
                                if (GameBoard[itemp2][jtemp2] == 'X') {
                                    flipstemp++;
                                }
                                if ((flipstemp >= flips) && (GameBoard[itemp2-1][jtemp2 - 1] == '-') && (itemp2!=0&&jtemp2!=0)) {
                                    i = itemp2 - 1;
                                    j = jtemp2 - 1;
                                    flips = flipstemp;
                                }
                            }
                        }
                    }
                }
            }

            printf("The computer chose: (%d,%d)\n", i, j);

            //change the Gameboard:
            GameBoard[i][j] = 'O';
            //CHECK AND FLIP:
            //check flips for x left side:
            oktoflip = 0;
            for (jtemp = j; jtemp >= 0; jtemp--) {
                if (GameBoard[i][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[i][jtemp] == 'O' && (oktoflip != (-1))) {
                    for (jtemp2 = jtemp+1; jtemp2 <= j; jtemp2++) {
                        GameBoard[i][jtemp2] = 'O';
                        oktoflip = 1;
                    }
                }
            }
            //check flips for x right side:
            oktoflip = 0;
            for (jtemp = j; jtemp <= 7; jtemp++) {
                if (GameBoard[i][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[i][jtemp] == 'O' && (oktoflip != (-1))) {
                    for (jtemp2 = jtemp-1; jtemp2 >= j; jtemp2--) {
                        GameBoard[i][jtemp2] = 'O';
                        oktoflip = 1;
                    }
                }
            }
            //check flips for y up:
            oktoflip = 0;
            for (itemp = i; itemp >= 0; itemp--) {
                if (GameBoard[itemp][j] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][j] == 'O' && (oktoflip != (-1))) {
                    for (itemp2 = itemp; itemp2 <= i; itemp2++) {
                        GameBoard[itemp2][j] = 'O';
                        oktoflip = 1;
                    }
                }
            }
            //check flips for y down:
            oktoflip = 0;
            for (itemp = i; itemp <= 7; itemp++) {
                if (GameBoard[itemp][j] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][j] == 'O' && (oktoflip != (-1))) {
                    for (itemp2 = itemp; itemp2 >= i; itemp2--) {
                        GameBoard[itemp][j] = 'O';
                        oktoflip = 1;
                    }
                }
            }
            //check flips on diagonals top to bottom:
            oktoflip = 0;
            for (itemp = i, jtemp = j; itemp <= 7 && jtemp <= 7; itemp++, jtemp++) {
                if (GameBoard[itemp][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][jtemp] == 'O' && (oktoflip != (-1))) {
                    for (itemp2 = itemp, jtemp2 = jtemp; itemp2 >= i||jtemp2 >= j; itemp2--, jtemp2--) {
                        GameBoard[itemp2][jtemp2] = 'O';
                        oktoflip = 1;
                    }
                }
            }
            //check flips on diagonals bottom to top:
            oktoflip=0;
            for (itemp = i, jtemp = j; itemp >=0 && jtemp <=7; itemp--, jtemp++) {
                if (GameBoard[itemp][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][jtemp] == 'O' && (oktoflip != (-1))) {
                    for (itemp2 = itemp, jtemp2 = jtemp; ((itemp2 <= i)||(jtemp2 >= j)); itemp2++, jtemp2--) {
                        GameBoard[itemp2][jtemp2] = 'O';
                        oktoflip = 1;
                    }
                }
            }

            turn='X';
        }//end computer turn


        //Print GameBoard:
        Boardfull=1;
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                printf(" %c", GameBoard[i][j]);
                if (GameBoard[i][j] == '-') {
                    Boardfull = 0;
                }
            }
            printf("\n");
        }
    }
    while(Boardfull==0);

    //calc result and print:
    for (i = 0; i <= 7; i++) {
        for (j = 0; j <= 7; j++)
            if(GameBoard[i][j]=='X')
                Xresult++;
            else if(GameBoard[i][j]=='O')
                Oresult++;
    }
    if(Xresult>Oresult){
        printf("Player X won: %d:%d\n",Xresult,Oresult);
        turn='X';
        return 11; //mark for X won
    }
    else if(Oresult>Xresult){
        printf("Player O won: %d:%d\n",Oresult,Xresult);
        turn='O';
        return 22; //mark for O won
    }
    else if(Oresult==Xresult){
        printf("It's a tie %d:%d\n",Xresult,Oresult);
    }
}

int Reversi2Players() {
    int i, j, itemp, jtemp,itemp2, jtemp2, Boardfull=0;
    int oktoflip;
    int Xresult=0, Oresult=0;
    int randfirst;
    char GameBoard[8][8], turn;
    while (getchar() != '\n');
    //resat Board
    for (i = 0; i <= 7; i++) {
        for (j = 0; j <= 7; j++)
            if ((i == 3 && j == 3) || (i == 4 && j == 4))
                GameBoard[i][j] = 'O';
            else if ((i == 3 && j == 4) || (i == 4 && j == 3))
                GameBoard[i][j] = 'X';
            else
                GameBoard[i][j] = '-';
    }
    //random first player:
    srand(time(0));
    randfirst=rand()%2;
    if(randfirst)
        turn='X';
    else
        turn='O';

    //Print GameBoard:
    for (i = 0; i <= 7; i++) {
        for (j = 0; j <= 7; j++)
            printf(" %c", GameBoard[i][j]);
        printf("\n");
    }

    //play the game:
    do {
        //Take coordinates from user:
        printf("It's %c turn, Please enter your I J coordinates:\n", turn);
        scanf("%d %d", &i, &j);
        while (!(i <= 7 && i >= 0 && j <= 7 && j >= 0) //check I J in range
               || GameBoard[i][j] != '-' //check I J spot is free
               || (GameBoard[i - 1][j - 1] == '-' && GameBoard[i - 1][j] == '-' && GameBoard[i - 1][j + 1] == '-' &&
                   GameBoard[i][j - 1] == '-' && GameBoard[i][j + 1] == '-' && GameBoard[i + 1][j - 1] == '-' &&
                   GameBoard[i + 1][j] == '-' && GameBoard[i + 1][j + 1] == '-')
               || ((i == 7) && (GameBoard[6][j] == '-' && GameBoard[6][j - 1] == '-' && GameBoard[6][j + 1] == '-' && GameBoard[7][j + 1]=='-' && GameBoard[7][j - 1]=='-'))
               || ((i == 0) && (GameBoard[1][j] == '-' && GameBoard[1][j - 1] == '-' && GameBoard[1][j + 1] == '-' && GameBoard[0][j + 1]=='-' && GameBoard[0][j - 1]=='-'))
               || ((j == 7) && (GameBoard[i][6] == '-' && GameBoard[i - 1][6] == '-' && GameBoard[i + 1][6] == '-' && GameBoard[i - 1][7]=='-' && GameBoard[i + 1][7]=='-'))
               || ((j == 0) && (GameBoard[i][1] == '-' && GameBoard[i - 1][1] == '-' && GameBoard[i + 1][1] == '-' && GameBoard[i - 1][0]=='-' && GameBoard[i + 1][0]=='-'))
               || ((i==0)&&(j==0)&&(GameBoard[0][1] == '-')&&(GameBoard[1][0] == '-')&&(GameBoard[1][1] == '-'))
               || ((i==7)&&(j==7)&&(GameBoard[7][6] == '-')&&(GameBoard[7][6] == '-')&&(GameBoard[6][6] == '-'))
               //check at least one I J neighbor exist
                ) {
            if (!(i <= 7 && i >= 0 && j <= 7 && j >= 0)) {
                while (getchar() != '\n');
                printf("Syntax Error, Please enter valid coordinates:\n");
                scanf("%d %d", &i, &j);
            } else {
                while (getchar() != '\n');
                printf("Game rules do not allow such move, Please enter valid coordinates:\n");
                scanf("%d %d", &i, &j);
            }
        }

        //Place a piece on the board and flip pieces:
        if (turn == 'X') {
            GameBoard[i][j] = 'X';
            //CHECK AND FLIP:
            //check flips for x left side:
            oktoflip = 0;
            for (jtemp = j; jtemp >= 0; jtemp--) {
                if (GameBoard[i][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[i][jtemp] == 'X' && (oktoflip != (-1))) {
                    for (jtemp2 = jtemp+1; jtemp2 <= j; jtemp2++) {
                        GameBoard[i][jtemp2] = 'X';
                        oktoflip = 1;
                    }
                }
            }
            //check flips for x right side:
            oktoflip = 0;
            for (jtemp = j; jtemp <= 7; jtemp++) {
                if (GameBoard[i][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[i][jtemp] == 'X' && (oktoflip != (-1))) {
                    for (jtemp2 = jtemp-1; jtemp2 >= j; jtemp2--) {
                        GameBoard[i][jtemp2] = 'X';
                        oktoflip = 1;
                    }
                }
            }
            //check flips for y up:
            oktoflip = 0;
            for (itemp = i; itemp >= 0; itemp--) {
                if (GameBoard[itemp][j] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][j] == 'X' && (oktoflip != (-1))) {
                    for (itemp2 = itemp; itemp2 <= i; itemp2++) {
                        GameBoard[itemp2][j] = 'X';
                        oktoflip = 1;
                    }
                }
            }
            //check flips for y down:
            oktoflip = 0;
            for (itemp = i; itemp <= 7; itemp++) {
                if (GameBoard[itemp][j] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][j] == 'X' && (oktoflip != (-1))) {
                    for (itemp2 = itemp; itemp2 >= i; itemp2--) {
                        GameBoard[itemp][j] = 'X';
                        oktoflip = 1;
                    }
                }
            }
            //check flips on diagonals top to bottom:
            oktoflip = 0;
            for (itemp = i, jtemp = j; itemp <= 7 && jtemp <= 7; itemp++, jtemp++) {
                if (GameBoard[itemp][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][jtemp] == 'X' && (oktoflip != (-1))) {
                    for (itemp2 = itemp, jtemp2 = jtemp; itemp2 >= i||jtemp2 >= j; itemp2--, jtemp2--) {
                        GameBoard[itemp2][jtemp2] = 'X';
                        oktoflip = 1;
                    }
                }
            }
            //check flips on diagonals bottom to top:
            oktoflip=0;
            for (itemp = i, jtemp = j; itemp >=0 && jtemp <=7; itemp--, jtemp++) {
                if (GameBoard[itemp][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][jtemp] == 'X' && (oktoflip != (-1))) {
                    for (itemp2 = itemp, jtemp2 = jtemp; ((itemp2 <= i)||(jtemp2 >= j)); itemp2++, jtemp2--) {
                        GameBoard[itemp2][jtemp2] = 'X';
                        oktoflip = 1;
                    }
                }
            }

            turn='O';
        }
        else if (turn == 'O') {
            GameBoard[i][j] = 'O';
            //CHECK AND FLIP:
            //check flips for x left side:
            oktoflip = 0;
            for (jtemp = j; jtemp >= 0; jtemp--) {
                if (GameBoard[i][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[i][jtemp] == 'O' && (oktoflip != (-1))) {
                    for (jtemp2 = jtemp+1; jtemp2 <= j; jtemp2++) {
                        GameBoard[i][jtemp2] = 'O';
                        oktoflip = 1;
                    }
                }
            }
            //check flips for x right side:
            oktoflip = 0;
            for (jtemp = j; jtemp <= 7; jtemp++) {
                if (GameBoard[i][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[i][jtemp] == 'O' && (oktoflip != (-1))) {
                    for (jtemp2 = jtemp-1; jtemp2 >= j; jtemp2--) {
                        GameBoard[i][jtemp2] = 'O';
                        oktoflip = 1;
                    }
                }
            }
            //check flips for y up:
            oktoflip = 0;
            for (itemp = i; itemp >= 0; itemp--) {
                if (GameBoard[itemp][j] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][j] == 'O' && (oktoflip != (-1))) {
                    for (itemp2 = itemp; itemp2 <= i; itemp2++) {
                        GameBoard[itemp2][j] = 'O';
                        oktoflip = 1;
                    }
                }
            }
            //check flips for y down:
            oktoflip = 0;
            for (itemp = i; itemp <= 7; itemp++) {
                if (GameBoard[itemp][j] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][j] == 'O' && (oktoflip != (-1))) {
                    for (itemp2 = itemp; itemp2 >= i; itemp2--) {
                        GameBoard[itemp][j] = 'O';
                        oktoflip = 1;
                    }
                }
            }
            //check flips on diagonals top to bottom:
            oktoflip = 0;
            for (itemp = i, jtemp = j; itemp <= 7 && jtemp <= 7; itemp++, jtemp++) {
                if (GameBoard[itemp][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][jtemp] == 'O' && (oktoflip != (-1))) {
                    for (itemp2 = itemp, jtemp2 = jtemp; itemp2 >= i||jtemp2 >= j; itemp2--, jtemp2--) {
                        GameBoard[itemp2][jtemp2] = 'O';
                        oktoflip = 1;
                    }
                }
            }
            //check flips on diagonals bottom to top:
            oktoflip=0;
            for (itemp = i, jtemp = j; itemp >=0 && jtemp <=7; itemp--, jtemp++) {
                if (GameBoard[itemp][jtemp] == '-') {
                    oktoflip = (-1);
                }
                if (GameBoard[itemp][jtemp] == 'O' && (oktoflip != (-1))) {
                    for (itemp2 = itemp, jtemp2 = jtemp; ((itemp2 <= i)||(jtemp2 >= j)); itemp2++, jtemp2--) {
                        GameBoard[itemp2][jtemp2] = 'O';
                        oktoflip = 1;
                    }
                }
            }
            turn='X';
        }

        //Print GameBoard:
        Boardfull=1;
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                printf(" %c", GameBoard[i][j]);
                if (GameBoard[i][j] == '-') {
                    Boardfull = 0;
                }
            }
            printf("\n");
        }
    }
    while(Boardfull==0);

    //calc result and print:
    for (i = 0; i <= 7; i++) {
        for (j = 0; j <= 7; j++)
            if(GameBoard[i][j]=='X')
                Xresult++;
            else if(GameBoard[i][j]=='O')
                Oresult++;
    }
    if(Xresult>Oresult){
        printf("Player X won: %d:%d\n",Xresult,Oresult);
        turn='X';
        return 11; //mark for X won
    }
    else if(Oresult>Xresult){
        printf("Player O won: %d:%d\n",Oresult,Xresult);
        turn='O';
        return 22; //mark for O won
    }
    else if(Oresult==Xresult){
        printf("It's a tie %d:%d\n",Xresult,Oresult);
    }
}