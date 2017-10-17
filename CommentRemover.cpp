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
    if(!inputFile)
    {
        return false;
    }
    // do not open/create output file is error open input file
    std::ofstream outputFile(_outputFilePath);
    if(!outputFile)
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
    // remove multiline comments: /* ... */
    // then remove single line comments: //
    return Execute(Execute(inputString, "/*", "*/", "\\\n"), "//", "\n", "\\\n");
}

std::string CommentRemover::Execute(std::string inputString,
                                    const std::string& commentStart,
                                    const std::string& commentEnd,
                                    const std::string& continueString)
{
    // while find any match delimeterStart
    while(inputString.find(commentStart) != std::string::npos)
    {
        size_t posCommentStart = inputString.find(commentStart);
        size_t posCommentEnd = inputString.find(commentEnd, posCommentStart);
        size_t posContinueStringStart = inputString.find(continueString, posCommentStart);
        // remove all continueString sequences in comment
        while(posContinueStringStart != std::string::npos &&
              posContinueStringStart < posCommentEnd)
        {
            inputString.erase(posContinueStringStart, continueString.length());
            posContinueStringStart = inputString.find(continueString, posCommentStart);
            posCommentEnd = inputString.find(commentEnd, posCommentStart);
        }
        // cut file to next entrance delimeterEnd
        inputString.erase(posCommentStart, (posCommentEnd - posCommentStart) + commentEnd.length());
    }
    return inputString;
}
