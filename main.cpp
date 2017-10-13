#include <iostream>
#include <cstring>

#include "CommentRemover.h"

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        std::cerr << "You must specify:" << std::endl
                  << "Input file path as first cmd argument." << std::endl
                  << "Output file path as second cmd argument." << std::endl
                  << "Example: ./comment-remover ./in ./out" << std::endl;
        return -1;
    }
    else if(!std::strcmp(argv[1], argv[2]))
    {
        std::cerr << "Input and output file paths can't be equal" << std::endl;
        return -1;
    }
    CommentRemover remover(argv[1], argv[2]);
    if(!remover.Execute())
    {
        std::cerr << "Can't open file, check I/O file paths." << std::endl;
        return -1;
    }
    std::cout << "Done!" << std::endl;
    return 0;
}
