#include "./src/markov.h"
#include <ctime>

int main(int argc, char* argv[])
{
  srand(time(0));
  Markov markovChain;

  if (!markovChain.readFile("./Metamorphosis-Franz_Kafka.txt"))
  {
    std::cout << "ERROR: Could not read file!\n";

    std::cin.get();
    exit(1);
  }

  std::string sentence = markovChain.generateSentence(100);
  std::cout << sentence;

  system("pause");
  return 0;
}