#ifndef FILEREADER_H
#define FILEREADER_H

#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <list>

class FileReader
{
public:
  FileReader(const std::string &filename);
  ~FileReader();

  bool isOpen() const;
  bool readLine(std::string &line);
  void close();
  std::vector<char> readAllCharactersToVector();
  std::list<char> readAllCharactersToList();
  std::string readWholeFileToString();

private:
  std::ifstream fileStream;
};

#endif // FILEREADER_H