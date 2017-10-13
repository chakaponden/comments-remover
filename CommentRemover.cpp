#include "CommentRemover.h"

#include <fstream>

CommentRemover::CommentRemover()

{
}

CommentRemover::CommentRemover(const std::string& inputFilePath,
                               const std::string& outputFilePath) :
    _inputFilePath(inputFilePath),
    _outputFilePath(outputFilePath)
{
}


void CommentRemover::SetInputFilePath(const std::string& value)
{
    _inputFilePath = value;
}

std::string CommentRemover::GetInputFilePath() const
{
    return _inputFilePath;
}

void CommentRemover::SetOutputFilePath(const std::string& value)
{
    _outputFilePath = value;
}

std::string CommentRemover::GetOutputFilePath() const
{
    return _outputFilePath;
}

bool CommentRemover::Execute()
{
    std::ifstream inputFile(_inputFilePath);
    std::ofstream outputFile(_outputFilePath);
    if(!inputFile || !outputFile)
    {
        return false;
    }
    std::string inputFileData;
    // read all data from file
    std::getline(inputFile, inputFileData, '\0');
    outputFile << Execute(inputFileData);
    return true;
}

std::string CommentRemover::Execute(std::string inputString)
{
    // while find any match
    while(inputString.find("/*") != std::string::npos)
    {
        // position to first entrance in file
        size_t pos = inputString.find("/*");
        // cut file to next entrance "*/"
        inputString.erase(pos, (inputString.find("*/", pos) - pos) + 2);
    }
    // while find any match
    while(inputString.find("//") != std::string::npos)
    {
        // position to first entrance in file
        size_t pos = inputString.find("//");
        // cut file to EOF
        inputString.erase(pos, inputString.find("\n", pos) - pos);
    }
    return inputString;
}
