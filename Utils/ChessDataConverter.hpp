#pragma once

#include <map>
#include <fstream>
#include <cstring>  

struct Plays
{
    int numberOfPlay;
    std::string WhitePlay;
    std::string BlackPlay;
};


template <class BoardMatrix>
class ChessDataConverter
{
    public:
        std::pair<char, int> matrixToEncode(std::pair<int, int> Move)         
        {
            return std::make_pair(Move.first + 'a', abs(Move.second - 8));
        }

        std::pair<int, int> encodeToMatrix(std::pair<char, int> Move)         
        {
            return std::make_pair(Move.first - 'a', abs(Move.second - 8));
        }

        int encodeToPosNumber(std::string Move)
        {
            std::pair<int, int> coverted;
            std::pair<char, int> temp;

            Move.erase(std::remove(Move.begin(), Move.end(), '+'), Move.end());

            std::size_t end = Move.find('=');
            if (end != std::string::npos)
                Move = Move.substr(0, end);
            
            
            if (Move.size() == 2)
            {
                temp = std::make_pair(Move[0], Move[1] - 48);
                coverted = encodeToMatrix(temp);
                
            }
            else if (Move.size() == 3)
            {
                temp = std::make_pair(Move[1], Move[2] - 48);
                coverted = encodeToMatrix(temp);
            }
            else
            {
                temp = std::make_pair(Move[2], Move[3] - 48);
                coverted = encodeToMatrix(temp);

            }
            return matrixToPosNumber(coverted.second, coverted.first);
        }

        int matrixToPosNumber(int x, int y)
        {
            int count = 0;
            int Matrix[8][8];
            for (int i = 0; i < 8; ++i)
            {
                for (int j = 0; j < 8; ++j)
                    Matrix[i][j] = count++;
            }
            
            return Matrix[x][y];
        }

        std::pair<char, int> posNumberToEncode(int pos)
        {
            int x = pos / 8;
            int y = pos % 8;
            auto pair = std::make_pair(y,x);
            auto encode = matrixToEncode(pair);
            return encode;
        }

        std::array<int, 64> MatrixToEncode(const BoardMatrix &Board);

        BoardMatrix EncodeToMatrix(const std::array<int, 64> &Board);

        std::vector<std::string> parseMovesFile(std::string movesFile)
        {
            std::fstream file(movesFile);
            std::string buff;

            std::vector<std::string> vec;

            while (std::getline(file, buff))
            {
                if (buff.c_str()[0] == '1')
                    vec.push_back(buff);   
            }

            return vec;
        }

        std::vector<Plays> parseMoves(std::string moves)
        {
            std::string gameEndStatus = moves.substr(moves.find('{'), moves.find('}'));
            moves.erase(moves.find('{'), moves.find('}'));
            moves.erase(std::remove(moves.begin(), moves.end(), 'x'), moves.end());
            moves.erase(std::remove(moves.begin(), moves.end(), '#'), moves.end());

            std::vector<Plays> plays;
            Plays temp;

            int count = 0;
            auto splitedStr = std::strtok(const_cast<char *>(moves.c_str()), " ");
            while (splitedStr != NULL)
            {  
                switch (count)
                {
                case 0:
                    temp.numberOfPlay = std::atoi(splitedStr);
                    break;
                case 1:
                    temp.WhitePlay = splitedStr;
                    break;
                case 2:
                    temp.BlackPlay = splitedStr;
                    plays.push_back(temp);
                    break;
                }
                splitedStr = std::strtok(NULL, " ");
                if (count == 2)
                    count = -1;
                ++count;
            }

            return plays;
        }
};

