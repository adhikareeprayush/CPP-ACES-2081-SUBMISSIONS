#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

namespace file
{
    std::string source = "words.txt";
}

namespace utils
{
    long int value(char ch)
    {
        if (ch >= 65 && ch <= 90)
        {
            return ch - 64;
        }

        if (ch >= 97 && ch <= 122)
        {
            return ch - 96;
        }

        return 0;
    }

    double magnitude(std::string str)
    {
        long int square_m = 0;
        for (char ch : str)
        {
            square_m += utils::value(ch) * utils::value(ch);
        }

        return sqrt(square_m);
    }

    inline long long int vector_dot(std::string word, std::string str)
    {

        int size = (word.size() <= str.size() ? word.size() : str.size());

        long long int dot = 0;

        for (int i = 0; i < size; i++)
        {
            dot += value(word[i]) * value(str[i]);
        }

        return dot;
    }

    double semantic_probability(std::string word, std::string str)
    {

        int total = (word.size() <= str.size() ? word.size() : str.size());

        int matched = 0;
        for (int i = 0; i < total; i++)
        {
            if (word[i] == str[i])
                matched++;
        }

        return ((double)matched / total);
    }

    double pattern_match_prob(std::string user_word, std::string str)
    {

        int i = 0;
        int matched = 0;
        int total = user_word.size();
        for (char ch : str)
        {
            if (matched == total)
                break;
            if (ch == user_word[i])
            {
                matched++;
                i++;
            }
        }

        return ((double)matched / total);
    }

}

// master function
double get_probability(std::string word, std::string str)
{
    double cosine_theta = (utils::vector_dot(word, str) / (utils::magnitude(word) * utils::magnitude(str)));

    double semantic_prob = utils::semantic_probability(word, str);
    double pattern_match_prob = utils::pattern_match_prob(word, str);

    return cosine_theta * semantic_prob * pattern_match_prob;
}
