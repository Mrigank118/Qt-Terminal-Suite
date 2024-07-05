#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
class bluecolouredboard
{
private:
 int r1;
 int c1;
 vector<vector<char>>g1;
public:
 bluecolouredboard()
 {
 r1=6;
 c1=7;
 g1.resize(r1, vector<char>(c1, '.'));
 }
 void display()
 {
 const string bcakgroundcolourforthecodebeblue="\033[44m";
 const string textcolourforthecodebered="\033[31m";
 const string textcolourforthecodebeyellow="\033[33m";
 const string reset="\033[0m";
 for(int i=0;i<r1;i++)
 {
 cout<<"\t\t\t\t\t";
 for(int j=0;j<c1;j++)
 {
 if(g1[i][j]=='X')
 {
 cout<< textcolourforthecodebered << g1[i][j] << " " << reset;
 }
 else if(g1[i][j]=='O')
 {
 cout<< textcolourforthecodebeyellow << g1[i][j] << " " << reset;
 }
 else
 {
 cout<< bcakgroundcolourforthecodebeblue << g1[i][j] << " " << reset;
 }
 }
 cout<<"\n";
 }
 cout<<"\t\t\t\t\t1 2 3 4 5 6 7\n";
 }
 bool placementofdiscdcr(int col,char discccc)
 {
 for(int row=r1-1;row>=0;row--)
 {
 if(g1[row][col]=='.')
 {
 g1[row][col]=discccc;
 return true;
 }
 }
 return false;
 }
 bool checkingwinconditiondcr(char discccc)
 {
 for(int rowsingridr1=0;rowsingridr1<r1;rowsingridr1++)
 {
 for(int j=0;j<c1;j++)
 {
 if(g1[rowsingridr1][j]!=discccc)
 {
 continue;
 }
 if(j<=c1-4&&
 discccc==g1[rowsingridr1][j+1]&&
 discccc==g1[rowsingridr1][j+2]&&
 discccc==g1[rowsingridr1][j+3])
 {
 return true;
 }
 if(rowsingridr1<=r1-4&&
 discccc==g1[rowsingridr1+1][j]&&
 discccc==g1[rowsingridr1+2][j]&&
 discccc==g1[rowsingridr1+3][j])
 {
 return true;
 }
 }
 }
 return false;
 }
};
class playerduringplaydcr
{
private:
 char disc;
public:
 playerduringplaydcr(char d)
 {
 disc=d;
 }
 char togetdiscdcr()const
 {
 return disc;
 }
};
class forcolourgameinarowdcr
{
private:
 bluecolouredboard b;
 playerduringplaydcr p111, p222;
 playerduringplaydcr* ccccppppp;
public:
 forcolourgameinarowdcr() : p111('X'), p222('O'), ccccppppp(&p111) {}
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
 void usedtoswitchplayerduringcoderunforplayerexchange()
 {
 if(ccccppppp==&p111)
 {
 ccccppppp=&p222;
 }
 else
 {
 ccccppppp=&p111;
 }
 }
 void toplaythegameandtoenjoytime()
 {
 int col;
 bool winningcondition=false;
 while(!winningcondition)
 {
 system("cls");
 printFileContent("fourinarow.txt");
 cout<<endl<<endl;
 b.display();
 cout<<endl;
 cout<<"\t\t\tPLAYER "<< ccccppppp->togetdiscdcr() <<" ENTER COLUMN TO DROP YOUR DISC : ";
 cin>>col;
 if(b.placementofdiscdcr(col-1,ccccppppp->togetdiscdcr()))
 {
 winningcondition=b.checkingwinconditiondcr(ccccppppp->togetdiscdcr());
 if(winningcondition)
 {
 system("cls");
 if(ccccppppp->togetdiscdcr()=='X')
 {
 printFileContent("fourgamexwin.txt");
 }
 else
 {
 printFileContent("fourgameowin.txt");
 }
 cout<<"\n\n\n";
 b.display();
 break;
 }
 usedtoswitchplayerduringcoderunforplayerexchange();
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
 char tocheckifsomeonewnatstoplayagain='y';
 while(tocheckifsomeonewnatstoplayagain=='y'||tocheckifsomeonewnatstoplayagain=='Y')
 {
 forcolourgameinarowdcr *g=new forcolourgameinarowdcr;
 g->toplaythegameandtoenjoytime();
 delete g;
 cout<<"\n\n\t\t\t\tRESTART (Y/N):";
 cin>>tocheckifsomeonewnatstoplayagain;
 }
 return 0;
}
