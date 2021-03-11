#ifndef MARKOV_H_
#define MARKOV_H_

#include <iostream>
#include <vector>
#include <unordered_map>

class Markov {
public:
  bool readFile(const std::string&);
  std::string generateSentence(int);

private:
  std::vector<std::string> words_;
  std::unordered_map<std::string, std::vector<std::string>> markovChain_;
};

#endif // MARKOV_H_