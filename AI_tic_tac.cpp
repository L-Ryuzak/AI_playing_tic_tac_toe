#include<bits/stdc++.h>
using namespace std;

struct Move{

    int row,col;

};

char ai = 'X' , player = 'O';

bool isboardempty(char b[3][3])
{
 for(int i = 0; i < 3; i++)
     for(int j = 0; j < 3; j++)
         if(b[i][j] == '_')
            return true;

return false;
}



int evaluate_func(char board[3][3])
{
     for(int row = 0; row < 3; row++)
     {
         if(board[row][0] == board[row][1] && board[row][1] == board[row][2])
            {
                if(board[row][0] == ai)
                return 10;
                else if(board[row][0] == player)
                return -10;
            }
     }

     for(int col = 0; col < 3; col++)
     {
         if(board[0][col] == board[1][col] && board[1][col] == board[2][col])
            {
                if(board[0][col] == ai)
                return 10;
                else if(board[0][col] == player)
                return -10;
            }
     }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        {
            if(board[0][0] == ai)
            return 10;
            else if(board[0][0] == player)
            return -10;
        }


    }


    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        {
            if(board[0][2] == ai)
            return 10;
            else if(board[0][2] == player)
            return -10;
        }


    }

    return 0;
}

int minimax(char board[3][3] , int depth , bool ismax)
{
    int score = evaluate_func(board);

    if(score == 10)
        return score;

    if(score == -10)
        return score;

    if(isboardempty(board) == false)
        return 0;

     if(ismax)
     {
         int best = -3453252;

         for(int i = 0; i < 3; i++)
         {
             for(int j = 0; j < 3; j++)
             {
                 if(board[i][j] == '_')
                 {
                     board[i][j] = ai;
                     best = max(best,minimax(board,depth+1,!ismax));

                     board[i][j] = '_';
                }
             }
         }
         return best;
     }

     else
     {
         int best = 4524353;
         for(int i = 0; i < 3; i++)
         {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == '_')
                {
                    board[i][j] = player;

                    best = min(best,minimax(board,depth+1,!ismax));

                    board[i][j] = '_';

                }
            }
         }

         return best;
     }
}

Move findbestmove(char board[3][3])
{
   int bestvalue = -500;
   Move bestmove;
   bestmove.row=-10;
   bestmove.col=-10;

   for(int i = 0; i < 3; i++)
   {
       for(int j = 0; j < 3; j++)
       {
           if(board[i][j] == '_')
           {
               board[i][j] = ai;
               int movevalue = minimax(board,0,false);
               board[i][j] = '_';

               if(movevalue > bestvalue)
               {
                   bestmove.row = i;
                   bestmove.col = j;
                   bestvalue = movevalue;

               }

           }
       }
   }

   return bestmove;
}

int main()
{

    char board[3][3]=
    {
        {'_','_','_'},
        {'_','_','_'},
        {'_','_','_'}
    };
    cout<<"enter the first position of AI"<<endl;
    int i1,j1;
    cin >> i1 >> j1;
    board[i1][j1] = ai;

    while(1)
    {
    int i,j;
    cout<<endl;
    cout<<"enter you value"<<endl;
    cin>>i>>j;
    board[i][j] = player;

    for(int i = 0; i < 3; i++)
    {

        for(int j = 0; j < 3; j++)
        {
            cout<<board[i][j] << "  ";
        }
        cout<<endl;
        cout<<endl;
    }

    int temp = evaluate_func(board);
    if(temp == 10)
    {
        cout << "Artifical intelligence won"<<endl;
        exit(0);
    }
    if(temp == -10)
    {
        cout << "player won the game"<<endl;
        exit(0);
    }


    if(isboardempty(board) == false)
        exit(0);


    Move find_optimal_move = findbestmove(board);
    cout<<"row and column for optimal move is" << find_optimal_move.row << "  "<<find_optimal_move.col<<endl;
    board[find_optimal_move.row][find_optimal_move.col] = ai;
   cout<<endl;
     for(int i = 0; i < 3; i++)
    {

        for(int j = 0; j < 3; j++)
        {
            cout<<board[i][j] << "  ";
        }
        cout<<endl;
        cout<<endl;
    }

    int temp1 = evaluate_func(board);
    if(temp1 == 10)
    {
        cout << "Artifical intelligence won"<<endl;
        exit(0);
    }
    if(temp1 == -10)
    {
        cout << "player won the game"<<endl;
        exit(0);
    }
    if(isboardempty(board) == false)
    {
        cout<<"game tie"<<endl;
        exit(0);

    }
    }

    return 0;
}
