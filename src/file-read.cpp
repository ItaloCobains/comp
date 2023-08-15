#include "../include/file-read.hpp"

FileReader::FileReader(const std::string &filename)
{
  fileStream.open(filename);
}

FileReader::~FileReader()
{
  close();
}

bool FileReader::isOpen() const
{
  return fileStream.is_open();
}

bool FileReader::readLine(std::string &line)
{
  if (!fileStream.is_open() || fileStream.eof())
    return false;

  std::getline(fileStream, line);
  return true;
}

void FileReader::close()
{
  if (fileStream.is_open())
    fileStream.close();
}

std::vector<char> FileReader::readAllCharactersToVector()
{
  std::vector<char> characters;
  char c;

  while (fileStream.get(c))
  {
    characters.push_back(c);
  }

  return characters;
}

std::list<char> FileReader::readAllCharactersToList()
{
  std::list<char> characters;
  char c;

  while (fileStream.get(c))
  {
    characters.push_back(c);
  }

  return characters;
}

std::string FileReader::readWholeFileToString()
{
  std::string content;
  char c;

  while (fileStream.get(c))
  {
    content += c;
  }

  return content;
}