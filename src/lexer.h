#ifndef _LEXER_H_
#define _LEXER_H_

#include "token.h"
#include <string>
#include <vector>

class Lexer {
public:
  std::vector<Token> generate_token_stream();

  Lexer(std::string input)
      : input{input}, current_token{Token()},
        token_stream{std::vector<Token>()} {
    current_position = this->input.begin();
  }

private:
  std::string input;
  std::string::iterator current_position;
  Token current_token;
  std::vector<Token> token_stream;
};

#endif // !_LEXER_H_
