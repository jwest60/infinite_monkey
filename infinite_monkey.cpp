#include <iostream>
#include <string>
#include <random>
#include <algorithm>

#define TW_KEYS 39

class Typewriter
{
public:

    Typewriter();

    bool type_word(const std::string& word);

    std::vector<unsigned char> c_set;

private:

    std::mt19937 gen;
    std::uniform_int_distribution<> dist;
};

Typewriter::Typewriter() : dist(0, TW_KEYS), c_set(TW_KEYS, '\0')
{
    std::random_device rd;
    this->gen.seed(rd());

    for (size_t i = 0; i < TW_KEYS; ++i)
    {
        if (i < 26) c_set[i] = 'a' + i;
        if (i >= 26 && i < 36) c_set[i] = '0' + (i - 26);
        if (i == 36) c_set[i] = '.';
        if (i == 37) c_set[i] = ',';
        if (i == 38) c_set[i] = ' ';
    }
}

bool Typewriter::type_word(const std::string& word)
{ 
    std::string r_word(word.length(), '0');

    for (size_t i = 0; i < word.length(); ++i)
    {
        unsigned int n = this->dist(this->gen);

        if (this->c_set[n] != word[i]) return false;
    }

    return true;
}

int main()
{
    std::string word;

    std::cout << "Give the monkey some text to type: ";
    getline(std::cin, word);

    unsigned long long count = 1;

    Typewriter tw;

    for (size_t i = 0; i < word.length(); ++i)
    {
        if (std::find(tw.c_set.begin(), tw.c_set.end(), word[i]) == tw.c_set.end())
        {
            std::cout << "The monkey is refusing to type that word (Invalid input).\n";
            return 0;
        }
    }

    while (!tw.type_word(word)) count++;

    std::cout << "The monkey typed \"" << word <<  "\" after " << count << " tries.\n";
}
