// 
//  リバーシ
//

#include <iostream>
#include <cstdlib>
using namespace std;

int ReplaceBoard(int col,int row,char koma);
void DisplayBoard();

string board[] =
{
    "********",
    "********",
    "********",
    "***01***",
    "***10***",
    "********",
    "********",
    "********"
};

int main(){
    DisplayBoard();
    while(1){
        int col,row,finish=0;
        while(1){
            cout << "player turn!" << endl;
            cout << "col ,row ,player position input! Let's start!" << endl;
            cin >> col >> row;
            // 強制終了
            if(col < 0 || row < 0){
                finish = 1;
                break;
            }
            if(col < 1 || col > 8 || row < 1 || row > 8){
                cout << "Umm,This position is not exist." << endl << endl;
                continue;
            }
            if(board[col-1][row-1] != '*'){
                cout << "Nooo!!This position is already placed." << endl << endl;
                continue;
            }
            // 置き換え
            if(ReplaceBoard(col,row,'0') == 0){
                cout << "Waoh,This position cannot replace other koma." << endl << endl;
                continue;
            }
            break;
        }
        if(finish == 1) break;
        // 表示
        DisplayBoard();
        
        cout << "enemy turn!" << endl;
        cout << "enemy thinking..." << endl;

        // colとrowを返せる方法が分かれば関数化できるが、今のところわからない
        // ポインタを使えば実現できるか
        // 1000回考えてダメだったら抜けます
        int e = 0;
        while(1){
            if(e >= 1000){
                cout << "Enemy[I'm out of control....]" << endl;
                break;
            }
            e++;
            col = (rand () % 9) + 1;
            row = (rand () % 9) + 1;
            if(col < 1 || col > 8 || row < 1 || row > 8)continue;
            if(board[col-1][row-1] != '*')continue;
            // 置き換え
            if(ReplaceBoard(col,row,'1') == 0)continue;
            break;
        }
        // 表示
        DisplayBoard();
    }
    
    // End
    string str;
    cout << "Press EOF to exit.";
    while(scanf("%s",str)!=EOF){
    }

    return 0;
}
int ReplaceBoard(int col,int row,char koma){
    // 駒を置く
    board[col-1][row-1]=koma;
    int flag = 0;
    int i= col-1,j=row-1;
    // [][]列、行
    /*
    for(int j = 0; j< 8;j++){
        for(int i = 0; i< 8;i++){
            if(i == col-1 && j == row-1 ){
                */
                // 駒をひっくり返す
                // 右
    for(int k = i+1; k< 8 ; k++){
        if(board[k][j]==koma){
            for(int l = i+1; l < k;l++){
                board[l][j] = koma;
                flag = 1;
            }
            break;
        }
        else if(board[k][j]=='*'){
            break;
        }
    }
    // 左
    for(int k = i-1; k> 0 ; k--){
        if(board[k][j]==koma){
            for(int l = i-1; l > k;l--){
                board[l][j] = koma;
                flag = 1;
            }
            break;
        }
        else if(board[k][j]=='*'){
            break;
        }
    }
    // 下
    for(int k = j+1; k< 8 ; k++){
        if(board[i][k]==koma){
            for(int l = j+1; l < k;l++){
                board[i][l] = koma;
                flag = 1;
            }
            break;
        }
        else if(board[i][k]=='*'){
            break;
        }
    }
    // 上
    for(int k = j-1; k> 0 ; k--){
        if(board[i][k]==koma){
            for(int l = j-1; l > k;l--){
                board[i][l] = koma;
                flag = 1;
            }
            break;
        }
        else if(board[i][k]=='*'){
            break;
        }
    }
    // 右下
    for(int k1 = i+1,k2 = j+1 ;k1 < 8 && k2 < 8 ; k1++,k2++){
        if(board[k1][k2]==koma){
            int l1,l2;
            for(int l1 = i+1, l2=j+1 ; l1 < k1 && l2 < k2 ; l1++,l2++){
                board[l1][l2] = koma;
                flag = 1;
            }
            break;
        }
        else if(board[k1][k2]=='*'){
            break;
        }
    }
    // 右上
    for(int k1 = i+1,k2 = j-1 ;k1 < 8 && k2 > 0 ; k1++,k2--){
        if(board[k1][k2]==koma){
            int l1,l2;
            for(int l1 = i+1, l2=j-1 ; l1 < k1 && l2 > k2 ; l1++,l2--){
                board[l1][l2] = koma;
                flag = 1;
            }
            break;
        }
        else if(board[k1][k2]=='*'){
            break;
        }
    }
    // 左下
    for(int k1 = i-1,k2 = j+1 ;k1 > 0 && k2 < 8 ; k1--,k2++){
        if(board[k1][k2]==koma){
            int l1,l2;
            for(int l1 = i-1, l2=j+1 ; l1 > k1 && l2 < k2 ; l1--,l2++){
                board[l1][l2] = koma;
                flag = 1;
            }
            break;
        }
        else if(board[k1][k2]=='*'){
            break;
        }
    }
    // 左上
    for(int k1 = i-1,k2 = j-1 ;k1 > 0 && k2 > 0 ; k1--,k2--){
        if(board[k1][k2]==koma){
            int l1,l2;
            for(int l1 = i-1, l2=j-1 ; l1 > k1 && l2 > k2 ; l1--,l2--){
                board[l1][l2] = koma;
                flag = 1;
            }
            break;
        }
        else if(board[k1][k2]=='*'){
            break;
        }
    }
    // 何も置き換えれなかったら駒を戻す
    if(flag == 0)   board[col-1][row-1]='*';
    return flag;
}

void DisplayBoard(){

    cout << "   ";
    for(int i = 0; i< 8;i++){
        cout << i+1 << " ";
    }
    cout << endl;
    // [][]列、行
    for(int j = 0; j< 8;j++){
        cout << j+1 << "  ";
        for(int i = 0; i< 8;i++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}