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

private:
    std::string _inputFilePath;
    std::string _outputFilePath;
};

#endif // COMMENTREMOVER_H
