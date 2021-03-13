#include "./markov.h"
#include <fstream>
#include <cstdlib>

void Markov::createMarkovChain()
{
  for (size_t i = 0; i < this->words_.size() - 1; ++i)
    this->markovChain_[this->words_[i]].push_back(this->words_[i + 1]);
}

bool Markov::readFile(const std::string& fileName)
{
  std::ifstream readFile(fileName);
  if (!readFile) return false;

  std::string currentWord;

  while (readFile >> currentWord)
    this->words_.push_back(currentWord);

  readFile.close();
  
  this->createMarkovChain();

  return true;
}

std::string Markov::generateSentence(int numberOfWords)
{
  std::string randomWord = this->words_[rand() % this->words_.size()];
  std::string sentence = randomWord;

  for (int i = 0; i < numberOfWords; ++i)
  {
    randomWord = this->markovChain_[randomWord][rand() % this->markovChain_[randomWord].size()];
    sentence += " " + randomWord;
  }

  return sentence + '\n';
}