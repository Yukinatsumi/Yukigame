#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

#include "Vector2f.hpp"
#include "Mouse.hpp"
#include "Square.hpp"
#include "Board.hpp"
using namespace std;
#define CORRECT_TEXTURE(x) squareTextures[x.getValue()]
#define WRONG_TEXTURE(x) squareTextures[x.getValue() + 9]

Board::Board(Vector2f pStartPoint, vector<SDL_Texture*>& pSquareTextures) // Định nghĩa các tiêu đề cần thiết và macro để thuận tiện truy cập texture cho ô đúng và sai. //
{
    const vector<string> chosenProblem = generateProblem();
    for(int i = 0; i < 81; i++)
    {
        cout << chosenProblem[1].at(i);
        if(i % 3 == 2) cout << " ";
        if(i % 9 == 8) cout << endl;
        if(i % 27 == 26) cout << endl;
    }
    cout << "=================================" << endl;
    startPoint = pStartPoint;
    squareSize = 40;
    squares.resize(81);
    squareTextures.assign(pSquareTextures.begin(), pSquareTextures.end());
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            squares[9 * i + j] = Square(Vector2f(startPoint + Vector2f(j * squareSize, i * squareSize)), i, j, chosenProblem[0].at(9 * i + j) - '0', chosenProblem[1].at(9 * i + j) - '0', squareTextures[chosenProblem[0].at(9 * i + j) - '0']);
        }
    }
    for(Square& s : squares)
    {
        s.generateRelatives(squares);
    }
}

vector<string> Board::generateProblem()// Hàm tạo ra một bài toán Sudoku ngẫu nhiên từ file. //
{
    const int random = (rand() % 1000) + 1;
    string chosenLine;
    vector<string> chosenProblem;
    ifstream problemData("res/dev/sudoku.csv");
    for(int i = 1; getline(problemData, chosenLine); i++)
    {
        if(i == random) break;
    }
    chosenProblem.push_back(chosenLine.substr(0, 81));
    chosenProblem.push_back(chosenLine.substr(82));
    return chosenProblem;
}

void Board::resize(Vector2f pStartPoint, float newSize) // Hàm thay đổi kích thước của bảng Sudoku.//
{
    startPoint = pStartPoint;
    squareSize = newSize;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            squares[9 * i + j].setSize(newSize);
            squares[9 * i + j].setPosition(startPoint.x + j * newSize, startPoint.y + i * newSize);
        }
    }
}

void Board::restart()  // Hàm khởi động lại trò chơi bằng cách tạo một bài toán Sudoku mới. //
{
    const vector<string> chosenProblem = generateProblem();
    for(int i = 0; i < 81; i++)
    {
        cout << chosenProblem[1].at(i);
        if(i % 3 == 2) cout << " ";
        if(i % 9 == 8) cout << endl;
        if(i % 27 == 26) cout << endl;
    }
    cout << "=================================" << endl;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            squares[9 * i + j].updateAnswer(chosenProblem[0].at(9 * i + j) - '0', chosenProblem[1].at(9 * i + j) - '0');
            squares[9 * i + j].setTexture(squareTextures[chosenProblem[0].at(9 * i + j) - '0']);
        }
    }
}

void Board::updateSelected(Mouse& mouse) // Hàm cập nhật ô được chọn dựa trên đầu vào từ chuột. //
{
    bool noSquareSelected = true;
    for(Square& s : squares)
    {
        if(mouse.isInsideEntity(s))
        {
            for(Square& other : squares)
            {
                other.deselect();
            }
            s.select();
            noSquareSelected = false;
        }
    }
    if(noSquareSelected)
    {
        for(Square& s : squares)
        {
            s.deselect();
        }
    }
}

void Board::update(Mouse& mouse)// Hàm cập nhật trạng thái của các ô trên bảng dựa trên đầu vào từ chuột.//
{
    for(Square& s : squares)
    {
        // when mouse is inside a square (cell)
        if(mouse.isInsideEntity(s))
        {
            for(Square* r : s.getRelatives())
            {
                if(r->getColor()[0] != 147 && r->getColor()[0] != 112)
                    r->setColor(200, 200, 200, 255); // Light gray
            }
            if(s.getColor()[0] != 147 && s.getColor()[0] != 112) // s not light blue and not dark blue
                s.setColor(165, 165, 165, 255); // Dark gray
        }

        // when a cell is selected
        if(s.isSelected())
        {
            for(Square* r : s.getRelatives())
            {
                r->setColor(147, 198, 249, 255); // Light blue
            }
            s.setColor(112, 163, 214, 255); // Dark blue
        }

        //when a cell has wrong answer
        s.setTexture(!s.isRedTexture() ? CORRECT_TEXTURE(s) : WRONG_TEXTURE(s));
    }
}

Vector2f& Board::getStartPoint() // Hàm trả về điểm bắt đầu của bảng Sudoku.//
{
    return startPoint;
}

vector<Square>& Board::getSquares()// Hàm trả về vector chứa các ô trên bảng Sudoku.//
{
    return squares;
}

float Board::getSquareSize() // Hàm trả về kích thước của mỗi ô trên bảng Sudoku.//
{
    return squareSize;
}

void Board::setAllSquareColor(int r, int g, int b, int a) // Hàm đặt màu cho tất cả các ô trên bảng Sudoku.//
{
    for(Square& s : squares)
    {
        s.setColor(r, g, b, a);
    }
}

void Board::setSelectedSquareValue(char key) // Hàm đặt giá trị cho ô được chọn dựa trên đầu vào từ bàn phím.//
{
    if(key == '\b' || (key >= '1' && key <= '9'))
    {
        for(Square& s : squares)
        {
            if(s.isSelected()) s.writePen((key == '\b') ? 0 : key - '0');
        }
    }
}
