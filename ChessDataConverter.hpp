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
        std::pair<char, int> ConvertInput(std::pair<int, int> &Move)         
        {
            return std::make_pair(Move.first + 'a', abs(Move.second - 8));
        }

        std::pair<int, int> ConvertInput(std::pair<char, int> &Move)         
        {
            return std::make_pair(Move.first - 'a', abs(Move.second - 8));
        }

        int parseMove(std::string &Move)
        {
            Move.erase(std::remove(Move.begin(), Move.end(), 'x'), Move.end());

            if (Move.size() == 2)
            {
                auto pair = std::make_pair(Move[0], Move[1] - 48);
                auto coverted = ConvertInput(pair);
                auto final = ConvertInput(coverted.second, coverted.first);
                return final;
            }
            else
            {
                auto pair = std::make_pair(Move[1], Move[2] - 48);
                auto coverted = ConvertInput(pair);
                auto final = ConvertInput(coverted.second, coverted.first);
                return final;
            }
            return 0;
        }

        int ConvertInput(int x, int y)
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
                    std::cout << splitedStr << std::endl;
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

