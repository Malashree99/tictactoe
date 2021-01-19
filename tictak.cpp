#include <iostream.h>
#include <ctime.h>
#include <random>
using namespace std;

char board[9] = {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '};
void show_board();
void get_x_player_choice();

void get_computer_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player();


int main()
{
    int mode;
    cout << "1. Computer VS Player." << endl;
    cout << "2. Player VS Player." << endl;
    cout << "Select Game Mode." << endl;
    cin >> mode;
    
            computer_vs_player();
            
}

void computer_vs_player() {
    string player_name;
    cout << "Enter Your Name: ";
    cin >> player_name;
    while(true) {
        system("cls");
        show_board();
        if(count_board('X') == count_board('O')) {
            cout << player_name << "s Turn." << endl;
            get_x_player_choice();
        }
        else{
            get_computer_choice();
        }
        char winner = check_winner();
        if(winner == 'X') {
            system("cls");
            show_board();
            cout << player_name << " Won The Game." << endl;
            break;
        }
        else if(winner == 'O') {
            system("cls");
            show_board();
            cout << "Computer Won The Game." << endl;
            break;
        }
        else if(winner == 'D') {
            cout << "Game is Draw." << endl;
            break;
        }
    }
}

void get_computer_choice() {
    srand(time(0));
    int choice;
    do{
        choice = rand()%10;
    }while(board[choice] != ' ');
    board[choice] = 'O';
}

void get_x_player_choice() {
    while(true) {
        cout << "Select Your Position (1 – 9): " ;
        int choice;
        cin >> choice;
        choice–;
        if(choice < 0 || choice > 8) {
            cout << "Please Select Your Choice From (1 – 9)." << endl;
        }
        else if(board[choice] != ' ') {
            cout << "Please Select An Empty Position." << endl;
        }
        else {
            board[choice] = 'X';
            break;
        }
    }
}




int count_board(char symbol) {
    int total = 0;
    for(int i=0; i<9; i++) {
        if(board[i] == symbol)
            total += 1;
    }
    return total;
}

char check_winner() {
    // checking winner in horizontal/row
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];
    // checking winner in vertical/column
    if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];
    // checking winner in diagonal
    if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];
    if(count_board('X') + count_board('O') < 9)
        return 'C';
    else
        return 'D';
}

void show_board() {

    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[0] << "  |   " << board[1] << "  |   " << board[2] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "——————–" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[3] << "  |   " << board[4] << "  |   " << board[5] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "——————–" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[6] << "  |   " << board[7] << "  |   " << board[8] << endl;
    cout << "   " << "   |   " << "   |   " << endl;

}