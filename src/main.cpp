#include "lexer.h"
#include <iostream>
#include <sstream>

static const std::string input{"1d20 + 2d4 - 1d6 + 12 -adv"};

void display_token_stream(const std::vector<Token> &token_stream);

int main() {
  // main work being done
  Lexer lexer{input};

  std::vector<Token> token_stream = lexer.generate_token_stream();
  display_token_stream(token_stream);

  std::cout << "Program completed" << std::endl;
  return 0;
}

void display_token_stream(const std::vector<Token> &token_stream) {
  std::ostringstream ss;
  for (const auto &token : token_stream) {
    ss << "[ " << token.get_state() << " : " << token.get_value() << " ]\n";
  }
  std::cout << ss.str();
}
