#ifndef COMMENTREMOVER_H
#define COMMENTREMOVER_H

#include <string>

///
/// \brief The CommentRemover class
/// Parce input file for c/c++ comments style, remove any comments.
/// Write result comments to output file
///

class CommentRemover
{
public:
    explicit CommentRemover();
    explicit CommentRemover(const std::string& inputFilePath,
                            const std::string& outputFilePath);

    void SetInputFilePath(const std::string& value);
    std::string GetInputFilePath() const;

    void SetOutputFilePath(const std::string& value);
    std::string GetOutputFilePath() const;

    ///
    /// \brief Execute
    /// \return true - successful, false - can't open any file
    ///
    bool Execute();

    ///
    /// \brief Execute
    /// \param inputString
    /// \return modified result string without comments
    ///
    static std::string Execute(std::string inputString);

    ///
    /// \brief Execute
    /// \param inputString
    /// \param commentStart: delimeter begin comment section
    /// \param commentEnd : delimeter end comment section
    /// \param continueString : delimeter unite strings
    /// \return modified result string without comments
    ///
    static std::string Execute(std::string inputString,
                               const std::string& commentStart,
                               const std::string& commentEnd,
                               const std::string& continueString = "\\\n");
private:
    std::string _inputFilePath;
    std::string _outputFilePath;
};

#endif // COMMENTREMOVER_H
