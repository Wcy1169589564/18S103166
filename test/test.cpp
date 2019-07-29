#include "stdafx.h"
#include "CppUnitTest.h"
#include "E:\vs2013\Game\main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(chess_eat_piece_test)
		{
			Game  game;
			Board board1;
			Player p1, p2;
			chessboard bo1;
			board1 = bo1;
			chessplayer play1(1, "first");
			chessplayer play2(-1, "second");
			chessaction ac1(bo1);
			Position pos1(0, 0), pos2(7, 0);
			Assert::AreEqual<int>(1, ac1.eat_piece(play1, pos1, pos2));
		}
		TEST_METHOD(chess_move_piece_test)
		{
			Game  game;
			Board board1;
			Player p1, p2;
			chessboard bo1;
			board1 = bo1;
			chessplayer play1(1, "first");
			chessplayer play2(-1, "second");
			chessaction ac1(bo1);
			Position pos1(0, 0), pos2(5, 0);
			Assert::AreEqual<int>(1, ac1.move_piece(play1, pos1, pos2));
		}
		TEST_METHOD(chess_num_test)
		{
			Game  game;
			Board board1;
			Player p1, p2;
			chessboard bo1;
			board1 = bo1;
			chessplayer play1(1, "first");
			chessplayer play2(-1, "second");
			chessaction ac1(bo1);
			Assert::AreEqual<int>(16, ac1.num(play1));
		}
		TEST_METHOD(chess_search_test)
		{
			Game  game;
			Board board1;
			Player p1, p2;
			chessboard bo1;
			board1 = bo1;
			chessplayer play1(1, "first");
			chessplayer play2(-1, "second");
			chessaction ac1(bo1);
			Position pos(0, 0);
			Assert::AreEqual<int>(1, ac1.search(pos, play1, play2));
		}
		TEST_METHOD(go_put_piece_test)
		{
			Game  game;
			Board board1;
			Player p1, p2;
			goboard bo1;
			board1 = bo1;
			goplayer play1(1, "first");
			goplayer play2(-1, "second");
			goaction ac1(bo1);
			Position pos(0, 0);
			Assert::AreEqual<int>(1, ac1.put_piece(play1, pos));
		}
		TEST_METHOD(go_eat_piece_test)
		{
			Game  game;
			Board board1;
			goboard bo1;
			board1 = bo1;
			goplayer play1(1, "first");
			goplayer play2(-1, "second");
			goaction ac1(bo1);
			Position pos(0, 0);
			ac1.put_piece(play2, pos);
			Assert::AreEqual<int>(1, ac1.eat_piece(play1, pos));
		}
		TEST_METHOD(go_search_test)
		{
			// TODO:  在此输入测试代码
			Game  game;
			Board board1;
			goboard bo1;
			board1 = bo1;
			goplayer play1(1, "first");
			goplayer play2(-1, "second");
			goaction ac1(bo1);
			Position pos(0, 0);
			Assert::AreEqual<int>(1, ac1.search(pos, play1, play2));
		}
		TEST_METHOD(go_num_test)
		{
			Game  game;
			Board board1;
			goboard bo1;
			board1 = bo1;
			goplayer play1(1, "first");
			goplayer play2(-1, "second");
			goaction ac1(bo1);
			Position pos(0, 0);
			Assert::AreEqual<int>(0, ac1.num(play1));
		}

	};
}