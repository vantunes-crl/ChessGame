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
        const std::pair<char, int> ConvertInput(const std::pair<int, int> &Move) const
        {
            return std::make_pair(Move.first + 'a', abs(Move.second - 8));
        }

        const std::pair<int, int> ConvertInput(const std::pair<char, int> &Move) const
        {
            return std::make_pair(Move.first - 'a', abs(Move.second - 8));
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
                    temp.numberOfPlay = static_cast<int>(splitedStr[0] - 48);
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

