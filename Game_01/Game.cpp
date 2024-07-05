#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
class board
{
private:
    int rows;
    int cols;
    vector<vector<char>>grid;
public:
    board()

    {
        rows=6;
        cols=7;
        grid.resize(rows, vector<char>(cols, '.'));
    }
    void display()
    {
        const string blue_bg="\033[44m";
        const string red_txt="\033[31m";
        const string yellow_txt="\033[33m";
        const string reset="\033[0m";
        for(int i=0;i<rows;i++)
        {
            cout<<"\t\t\t\t\t";
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]=='X')
                {
                    cout<< red_txt << grid[i][j] << " " << reset;
                }
                else if(grid[i][j]=='O')
                {
                    cout<< yellow_txt << grid[i][j] << " " << reset;
                }
                else
                {
                    cout<< blue_bg << grid[i][j] << " " << reset;
                }
            }
            cout<<"\n";
        }
        cout<<"\t\t\t\t\t1 2 3 4 5 6 7\n";
    }
    bool discplace(int col,char disc)
    {
        for(int row=rows-1;row>=0;row--)
        {
            if(grid[row][col]=='.')
            {
                grid[row][col]=disc;
                return true;
            }
        }
        return false;
    }
    bool checkwin(char disc)
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]!=disc)
                {
                     continue;
                }
                if(j<=cols-4&&
                   disc==grid[i][j+1]&&
                   disc==grid[i][j+2]&&
                   disc==grid[i][j+3])
                {
                    return true;
                }
                if(i<=rows-4&&
                   disc==grid[i+1][j]&&
                   disc==grid[i+2][j]&&
                   disc==grid[i+3][j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};
class player
{
private:
   char disc;
public:
    player(char d)
    {
        disc=d;
    }
    char getdisc()const
    {
        return disc;
    }
};
class game
{
private:
    board b;
    player p1, p2;
    player* cp;
public:
    game() : p1('X'), p2('O'), cp(&p1) {}

    void printFileContent(const std::string& fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << fileName << std::endl;
            return;
        }
        char ch;
        while (file.get(ch)) {
            std::cout.put(ch);
        }
    }

    void switchplayer()
    {
        if(cp==&p1)
        {
            cp=&p2;
        }
        else
        {
            cp=&p1;
        }
    }
    void play()
    {
        int col;
        bool win=false;
        while(!win)
        {
            system("cls");
            printFileContent("C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\Game_01\\fourinarow.txt");
            cout<<endl<<endl;
            b.display();
            cout<<endl;
            cout<<"\t\t\tPLAYER "<< cp->getdisc() <<" ENTER COLUMN TO DROP YOUR DISC : ";
            cin>>col;
            if(b.discplace(col-1,cp->getdisc()))
            {
                win=b.checkwin(cp->getdisc());
                if(win)
                {
                    system("cls");
                    if(cp->getdisc()=='X')
                    {
                        printFileContent("C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\Game_01\\fourgamexwin.txt");
                    }
                    else
                    {
                        printFileContent("C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\Game_01\\fourgameowin.txt");
                    }
                    cout<<"\n\n\n";
                    b.display();
                    break;
                }
                switchplayer();
            }
            else
            {
                cout<<"\t\t\t\t\t\tColumn full or invalid.GAME WILL TERMINATE !!";
                break;
            }
        }

    }
};
int main()
{
    char t='y';
    while(t=='y'||t=='Y')
    {
        game *g=new game;
        g->play();
        delete g;
        cout<<"\n\n\t\t\t\tRESTART (Y/N):";
        cin>>t;
    }
    return 0;
}
