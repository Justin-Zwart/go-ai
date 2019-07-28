// 
// destroy cells after new one placed
// find valid moves
// delete past_positions[-1] and points in minmax
// test case ko
//

#include <iostream>
#include <vector>
#include <array>

using namespace std;

array<array<bool, 9>, 9> find_valid_positions(array<array<int, 9>, 9>& position, bool black_to_move);
pair<int, array<array<int, 9>, 9>> find_new_position(array<array<int, 9>, 9>& position, bool destroy_black_stones);
float minmax(array<array<int, 9>, 9>& position, bool black_to_move, int depth, int max_depth);
float static_evaluation(array<array<int, 9>, 9>& position);


vector<array<array<int, 9>, 9>> past_positions;

int main()
{
    array<array<int, 9>, 9> position = { {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 0 for empty, 1 for black, and 2 for white
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0} };

}


float static_evaluation (array<array<int, 9>, 9> &position, int points)
{

}


float minmax (array<array<int, 9>, 9> &position, bool black_to_move, int depth, int max_depth)
{
    array<array<bool, 9>, 9> valid_positions = find_valid_positions(position, black_to_move);
    float best_evaluation;
    float current_evaluation;
    pair<int, array<array<int, 9>, 9>> new_position;

    // return static evaluation if at max_depth
    if (depth == max_depth)
    {
        return static_evaluation(position);
    }

    if (black_to_move)
    {
        // set it to current value, as passing is an option
        best_evaluation = static_evaluation(position);

        // loop through all children of the current position, find the best move
        for (int x = 0; x < 9; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                if (valid_positions[x][y])  // ensure a legal move
                {
                    position[x][y] = 1;
                    new_position = find_new_position(position, false);
                    current_evaluation = minmax(position, false, depth + 1, max_depth);
                    position[x][y] = 0;

                    // set it to the max of the position being considered, and the previous best choice
                    if (best_evaluation < current_evaluation)
                        best_evaluation = current_evaluation;
                }
            }
        }
    }
    else
    {
        // set it to current value, as passing is an option
        best_evaluation = static_evaluation(position);

        // loop through all children of the current position, find the best move
        for (int x = 0; x < 9; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                if (valid_positions[x][y])  // ensure a legal move
                {
                    position[x][y] = 2;
                    current_evaluation = minmax(position, true, depth + 1, max_depth);
                    position[x][y] = 0;

                    // set it to the max of the position being considered, and the previous best choice
                    if (best_evaluation > current_evaluation)
                        best_evaluation = current_evaluation;
                }
            }
        }
    }
}


array<array<bool, 9>, 9> find_valid_positions(array<array<int, 9>, 9> &position, bool black_to_move)
{
    // ko <---
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {

        }
    }
}


pair<int, array<array<int, 9>, 9>> find_new_position(array<array<int, 9>, 9>& position, bool destroy_black_stones)
{
    bool has_liberties = false;
    array<array<int, 9>, 9> groups = { {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 0 for check, 1 for already checked
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0} };

    // destroy all stones with no liberties, add to points
    if (destroy_black_stones)
    {
        // check each black stone to see if it should be destroyed
        for (int x = 0; x < 9; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                
            }
        }
    }
    else
    {

    }
}