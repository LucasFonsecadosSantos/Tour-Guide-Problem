#ifndef PHARSER_OBJECT_H
#define PHARSER_OBJECT_H 1

#include <string>

class Pharser {
    private:
    public:
        Pharser();
        ~Pharser();
        std::string* getConectionsTokens(std::string);
        int tokensCounter(std::string);
};

#endif