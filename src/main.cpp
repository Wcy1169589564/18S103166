#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
#include "windows.h"
using namespace std;
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}
class Position{
public:
	int x, y;
	Position(int posx, int posy)
	{
		x = posx, y = posy;
	}
	Position()
	{

	}
};


class Player{
public :
	string name;
	Player()
	{

	}
	Player(string nam){
		name = nam;
	}
};
class chessplayer:public Player{
public :
	string name;
	int type;
	vector<string> history;
	int l = 0;
	chessplayer()
	{

	}
	chessplayer(int typ)
	{
		type = typ;
	}
	chessplayer(string nam)
	{
		name = nam;
	}
	chessplayer(int typ,string nam)
	{
		type = typ;
		name = nam;
	}
	int gettype()
	{
		return type;
	}
	//吃子
	void eat_piece(Position pos1, Position pos2)
	{
		string tmp = "Use the piece ("; 
		tmp += (pos1.x + '0');
		tmp += ',';
		tmp += (pos1.y + '0');
		tmp += ")to eat the piece (";
		tmp += (pos2.x + '0');
		tmp += ',';
		tmp += (pos2.y + '0');
		tmp += ")";
		tmp += "\n";
		history.push_back(tmp);
		l++;
	}
	//移动棋子
	void move_piece(Position pos1,Position pos2)
	{
		string tmp = "Move a piece from (";
		tmp += (pos1.x + '0');
		tmp += ',';
		tmp += (pos1.y + '0');
		tmp += ") to (";
		tmp += (pos2.x + '0');
		tmp += ",";
		tmp += (pos2.y + '0');
		tmp += ").\n";
		history.push_back(tmp);
		l++;
	}

	void search(Position pos)
	{
		string tmp = "Search the position (";
		tmp += (pos.x + '0');
		tmp += ',';
		tmp += (pos.y + '0');
		tmp += ").\n";
		history.push_back(tmp);
		l++;
	}
	void num()
	{
		string tmp = "Search the num of the pieces.\n";
		history.push_back(tmp);
		l++;
	}
	void skip()
	{
		string tmp = "Choose to skip this turn.\n";
		history.push_back(tmp);
		l++;
	}
	void record()
	{
		//cout << l << endl;
		for (int i = 0; i < l; i++)
		{
			cout << history[i];
		}
	}
	string getname()
	{
		return name;
	}

};

class goplayer:public Player
{
public:
	string name;
	int type;
	vector<string> history;
	int l = 0;
	goplayer()
	{

	}
	goplayer(int typ)
	{
		type = typ;
	}
	goplayer(string nam)
	{
		name = nam;
	}
	goplayer(int typ, string nam)
	{
		type = typ;
		name = nam;
	}
	int gettype()
	{
		return type;
	}
	string getname()
	{
		return name;
	}
	// 落子
	void put_piece(Position pos)
	{
		string tmp = "Put a piece on (";
		tmp += (pos.x + '0');
		tmp += ',';
		tmp += (pos.y + '0');
		tmp += ").\n";
		history.push_back(tmp);
		l++;
	}
	//移动棋子或者吃子
	void carry_piece(Position pos1)
	{

		string tmp = "Carry a piece from (";
		tmp += (pos1.x + '0');
		tmp += ',';
		tmp += (pos1.y + '0');
		tmp += ").\n";
		history.push_back(tmp);
		l++;
	}
	void search(Position pos)
	{
		string tmp = "Search the position (";
		tmp += (pos.x + '0');
		tmp += ',';
		tmp += (pos.y + '0');
		tmp += ").\n";
		history.push_back(tmp);
		l++;
	}
	void num()
	{
		string tmp = "Search the num of the pieces.\n";
		history.push_back(tmp);
		l++;
	}
	void skip()
	{
		string tmp = "Choose to skip this turn.\n";
		history.push_back(tmp);
		l++;
	}
	void record()
	{
		for (int i = 0; i < l; i++)
		{
			cout << history[i];
		}
	}

};

class Piece{
public:
	string type;
	Position pos;
	Piece()
	{

	}
	Piece(string typ, int x, int y)
	{
		type = typ;
		Position pos1(x, y);
		pos = pos1;
	}
};
class gopiece :public Piece{
public: 
	int type;
	Position pos;
	gopiece()
	{

	}
	gopiece(int typ)
	{
		type = typ;
	}
	int gettype()
	{
		return type;
	}
};
class chesspiece :public Piece{
public:
	int type;
	Position pos;
	string name;
	chesspiece()
	{

	}
	chesspiece(int typ)
	{
		type = typ;
	}
	chesspiece(int typ, string nam)
	{
		type = typ;
		name = nam;
	}
	chesspiece(int typ, int x, int y)
	{
		type = typ;
		Position pos1(x, y);
		pos = pos1;
	}
	chesspiece(int typ, string nam, int x, int y)
	{
		type = typ;
		Position pos1(x, y);
		pos = pos1;
		name = nam;
	}
	int gettype()
	{
		return type;
	}
};

class Board{
public:
	int n = 100;
	Board(){

	}
};
class chessboard:public Board{
public:
	int n = 8;
	chesspiece chess_board[8][8];
	//king = 6,queen =5,bishop=4,knight=3,rook =2,pawn=1
	chessboard(){
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (i == 1)
				{
					chess_board[i][j] = chesspiece(1,"pawn");
				}
				else if (i == 6)
				{
					chess_board[i][j] = chesspiece(-1, "pawn");
				}
				else chess_board[i][j] = chesspiece(0);
			}
		}
		chess_board[0][3] = chesspiece(1, "king");
		chess_board[0][4] = chesspiece(1, "queen");
		chess_board[0][2] = chesspiece(1, "bishop"); chess_board[0][5] = chesspiece(1, "bishop");
		chess_board[0][1] = chesspiece(1, "knight"); chess_board[0][6] = chesspiece(1, "knight");
		chess_board[0][0] = chesspiece(1, "rock"); chess_board[0][7] = chesspiece(1, "rock");
		chess_board[7][3] = chesspiece(-1, "king");
		chess_board[7][4] = chesspiece(-1, "queen");
		chess_board[7][2] = chesspiece(-1, "bishop"); chess_board[7][5] = chesspiece(-1, "bishop");
		chess_board[7][1] = chesspiece(-1, "knight"); chess_board[7][6] = chesspiece(-1, "knight");
		chess_board[7][0] = chesspiece(-1, "rock"); chess_board[7][7] = chesspiece(-1, "rock");
	}
	
};

class Action{
public:
	int n;
	Board bo;
	Action(){

	}
};

class chessaction :public Action{
public:
	int n = 8;
	chessboard bo;

	chessaction(){

	}
	chessaction(chessboard b1)
	{
		bo = b1;
	}
	void move_piece(chessplayer pl,Position pos1, Position pos2)
	{
		if (pos1.x<0 || pos1.y>7 || pos1.x > 7 || pos1.y < 0)
		{
			cout << "The source position you input invalid !\n";
		}
		if (pos2.x<0 || pos2.y>7 || pos2.x > 7 || pos2.y < 0)
		{
			cout << "The target position you input invalid !\n";
		}
		if (bo.chess_board[pos1.x][pos1.y].gettype() == 0)
		{
			cout << "There is no piece on the source position!\n";
		}
		if (bo.chess_board[pos1.x][pos1.y].gettype() != pl.gettype())
		{
			cout << "The piece on the source position doesn't belong to you!\n";
		}
		if (bo.chess_board[pos2.x][pos2.y].gettype() != 0)
		{
			cout << "There is one piece on the target position!\n";
		}
		bo.chess_board[pos2.x][pos2.y] = bo.chess_board[pos1.x][pos1.y];
		//cout << bo.chess_board[pos2.x][pos2.y].name << endl;
		bo.chess_board[pos1.x][pos1.y] = chesspiece(0);
	}
	void eat_piece(chessplayer pl, Position pos1, Position pos2)
	{
		if (pos1.x<0 || pos1.y>7 || pos1.x > 7 || pos1.y < 0)
		{
			cout << "The source position you input invalid !\n";
		}
		else if (pos2.x<0 || pos2.y>7 || pos2.x > 7 || pos2.y < 0)
		{
			cout << "The target position you input invalid !\n";
		}
		else if (bo.chess_board[pos1.x][pos1.y].gettype() == 0)
		{
			cout << "There is no piece on the source position!\n";
		}
		else if (bo.chess_board[pos1.x][pos1.y].gettype() != pl.gettype())
		{
			cout << "The piece on the source position doesn't belong to you!\n";
		}
		else if (bo.chess_board[pos2.x][pos2.y].gettype() == 0)
		{
			cout << "There is no piece on the target position!\n";
		}
		else if (bo.chess_board[pos2.x][pos2.y].gettype() == pl.gettype())
		{
			cout << "There is your piece on the target position!\n";
		}
		bo.chess_board[pos2.x][pos2.y] = bo.chess_board[pos1.x][pos1.y];
		bo.chess_board[pos1.x][pos1.y] = chesspiece(0);
	}

	void print()
	{
		cout << " ";
		for (int i = 0; i < n; i++)
		{
			cout <<setw(6)<< "-------";
		}
		cout << endl;
		
		for (int i = 0; i < n; i++)
		{
			cout << "|";
			for (int j = 0; j < n; j++)
			{
				if (bo.chess_board[i][j].gettype()==1)
				{
					SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					cout << setw(6) << bo.chess_board[i][j].name;
						SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
						cout << "|";

				}
				else if (bo.chess_board[i][j].gettype() == -1)
				{
					SetConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout << setw(6) << bo.chess_board[i][j].name ;

						SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
						cout <<"|";
				}
				else
				{
						SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
						cout << setw(6)<<" " << "|";
				}
		
			}
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << endl;
			cout << " ";
			for (int k = 0; k < n; k++)
			{
				cout << setw(6) << "-------";
			}
			cout << endl;
			
		}

	}
	//返回玩家棋子的个数。
	int num(chessplayer pl)
	{
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (pl.gettype() == bo.chess_board[i][j].gettype())
				{
					res++;
				}
			}
		}
		return res;
	}
	void search(Position p,chessplayer pl1,chessplayer pl2)
	{
		if (bo.chess_board[p.x][p.y].gettype() == pl1.gettype())
		{
			cout << pl1.name <<" "<< bo.chess_board[p.x][p.y].name << endl;;

		}
		else if (bo.chess_board[p.x][p.y].gettype() == pl2.gettype())
		{
			cout << pl2.name <<" "<< bo.chess_board[p.x][p.y].name << endl;
		}
		else
			cout << "empty " << endl;
	}
};

class goboard :public Board{
public:
	int n = 18;
	gopiece go_board[19][19];
	goboard(){
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				gopiece tmp(0);
				go_board[i][j] = tmp;

			}
		}
	}
};
class goaction :public Action{
public:
	int n = 19;
	goboard bo;
	goaction()
	{

	}
	goaction(goboard bo1)
	{
		bo = bo1;
	}
	void put_piece(goplayer pl, Position pos1)
	{
		if (pos1.x<0 || pos1.y>18 || pos1.x > 18 || pos1.y < 0)
		{
			cout << "The position you input invalid !\n";
		}
		if (bo.go_board[pos1.x][pos1.y].gettype() != 0)
		{
			cout << "There is one piece on the position!\n";
		}
		bo.go_board[pos1.x][pos1.y] = gopiece(pl.gettype());
	}
	void eat_piece(goplayer pl, Position pos1)
	{
		if (pos1.x<0 || pos1.y>18 || pos1.x > 18 || pos1.y < 0)
		{
			cout << "The source position you input invalid !\n";
		}
		else if (bo.go_board[pos1.x][pos1.y].gettype() == 0)
		{
			cout << "There is no piece on the position!\n";
		}
		bo.go_board[pos1.x][pos1.y] = gopiece(0);
	}
	//返回玩家棋子的个数。
	int num(goplayer pl)
	{
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (pl.gettype() == bo.go_board[i][j].gettype())
				{
					res++;
				}
			}
		}
		return res;
	}
	void search(Position p,goplayer pl1,goplayer pl2)
	{
		if (bo.go_board[p.x][p.y].gettype() == pl1.gettype())
		{
			cout <<  pl1.name<< endl;;

		}
		else if (bo.go_board[p.x][p.y].gettype() == pl2.gettype())
		{
			cout << pl2.name << endl;
		}
		else
			cout << "empty " << endl;
	}

	void print()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{

				if (j != n - 1)
				{
					if (bo.go_board[i][j].gettype() == 1)
					{
						cout << setw(1) << "*" << "--";

					}
					else if (bo.go_board[i][j].gettype() == -1)
					{
						cout << setw(1) << "&" << "--";

					}
					else
					{
						cout << setw(1) << " " << "--";
					}

				}
				else
				{
					if (bo.go_board[i][j].gettype() == 1)
					{
						cout << setw(1) << "*" ;

					}
					else if (bo.go_board[i][j].gettype() == -1)
					{
						cout << setw(1) << "&" ;

					}
					else
					{
						cout << setw(1) << " " ;
					}

				}
				
			}
			cout << endl;
			if (i != n - 1)
			{
				cout << "|";
				for (int k = 0; k < n; k++)
				{
					if (k != n - 1)
					{
						cout << setw(3) << "|";
					}

				}
				cout << endl;
			}
			

		}

	}

};
class Game{

public:
	Player play1, play2;
	Game()
	{

	}

};

class chess : public Game{
public:
	chessplayer play1, play2;
	chessboard bo;
    chessaction ac;
	chess(chessplayer pl1,chessplayer pl2,chessboard bo1){
		play1 = pl1;
		play2 = pl2;
		bo = bo1;
		chessaction ac1(bo1);
		ac = ac1;
	}
	bool play(chessplayer &play,chessplayer play2)
	{
		cout << "Please player " << play.name << " choose action ! If move please input m , if eat please input e , input k Skip this round of games, input n get the number of your pieces, input s search for position, input d to end the game\n";
		char act;
		cin >> act;
		if (act == 'm')
		{
			Position pos1, pos2;
			cout << "Please input the position of the piece \n";
			cin >> pos1.x >> pos1.y >> pos2.x >> pos2.y;
			ac.move_piece(play, pos1, pos2);
			play.move_piece(pos1, pos2);
		}
		else if (act == 'e')
		{
			Position pos1, pos2;
			cout << "Please input the position of the piece \n";
			cin >> pos1.x >> pos1.y >> pos2.x >> pos2.y;
			ac.eat_piece(play1, pos1, pos2);
			play.eat_piece(pos1, pos2);
		}
		else if (act == 'n')
		{
			cout << "The number of your pieces is " << ac.num(play1) << endl;
			play.num();
		}
		else if (act == 's')
		{
			cout << "Please input the position you want search " << endl;
			Position pos;
			cin >> pos.x >> pos.y;
			ac.search(pos,play,play2);
			play.search(pos);

		}
		else if (act == 'd')
		{
			return true;
		}
		else if (act == 'k')
		{
			cout << "You have chosen to skip\n ";
			play.skip();
		}
		ac.print();
		return false;
	}
	void play_game()
	{
		ac.print();
		while (true)
		{
			bool con = play(play1,play2);
			if (con)break;
			bool con1=play(play2,play1);
			if (con1)break;
		}
	}
	void print()
	{
		cout << "This the action of player " << play1.getname() << ":" << endl;
		play1.record();
		cout << "This the action of player " << play2.getname() << ":" << endl;
		play2.record();
	}
};

class go :public Game{
public:
	goplayer play1, play2;
	goboard bo;
	goaction ac;
	go(){

	}
	go(goplayer pl1, goplayer pl2, goboard bo1){
		play1 = pl1;
		play2 = pl2;
		bo = bo1;
		goaction ac1(bo1);
		ac = ac1;
	}
	bool play(goplayer &play,goplayer play2)
	{
		cout << "Please player " << play.name << " choose action ! If put please input p , if eat please input e , input k Skip this round of games, input n get the number of your pieces, input s search for position, input d to end the game\n";
		char act;
		cin >> act;
		if (act == 'p')
		{
			Position pos1;
			cout << "Please input the position of the piece \n";
			cin >> pos1.x >> pos1.y ;
			ac.put_piece(play, pos1);
			play.put_piece(pos1);
		}
		else if (act == 'e')
		{
			Position pos1;
			cout << "Please input the position of the piece \n";
			cin >> pos1.x >> pos1.y ;
			ac.eat_piece(play1, pos1);
			play.carry_piece(pos1);
		}
		else if (act == 'n')
		{
			cout << "The number of your pieces is " << ac.num(play1) << endl;
			play.num();
		}
		else if (act == 's')
		{
			cout << "Please input the position you want search " << endl;
			Position pos;
			cin >> pos.x >> pos.y;
			ac.search(pos,play,play2);
			play.search(pos);

		}
		else if (act == 'd')
		{
			return true;
		}
		else if (act == 'k')
		{
			cout << "You have chosen to skip\n ";
			play.skip();

		}
		ac.print();
		return false;
	}
	void play_game()
	{
		ac.print();
		while (true)
		{
			bool con = play(play1,play2);
			if (con)break;
			bool con1 = play(play2,play1);
			if (con1)break;
		}
	}
	void print()
	{
		cout << "This the action of player1 " << play1.name << ":" << endl;
		play1.record();
		cout << "This the action of player2 " << play2.name << ":" << endl;
		play2.record();
	}
};

int main()
{
	cout << "Please input the game you want to play : chess or go " << endl;
	string s,name1,name2;
	Game  game;
	Board board1;
	Player p1, p2;
	getline(cin, s);
	cout << "Please input the name of first player:\n";
	getline(cin, name1);
	cout << "Please input the name of the second player:\n";
	getline(cin, name2);
	if (s=="chess")
	{
		cout << "chess" << endl;

		chessboard bo1;
		board1 = bo1;
		chessplayer play1(1,name1);
		chessplayer play2(-1,name2);
		p1 = play1;
		p2 = play2;
		//bool con = true;
		//chess gam(play1, play2, bo1);
		chess  gam(play1, play2, bo1);
		game = gam;
		gam.play_game();
		gam.print();
	}
	else if (s == "go")
	{
		go go1;
		game = go1;
		goboard bo1;
		board1 = bo1;
		goplayer play1(1,name1);
		goplayer play2(-1,name2);
		p1 = play1;
		p2 = play2;
		go gam(play1, play2, bo1);
		game = gam;
		gam.play_game();
		gam.print();

	}
	else
	{
		cout << "Invalid cgoice!" << endl;
	}

	system("pause");
	return 0;
}
