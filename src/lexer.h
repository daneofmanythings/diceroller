#ifndef _LEXER_H_
#define _LEXER_H_

#include "token.h"
#include <string>
#include <vector>

class Lexer {
public:
  std::vector<Token> generate_token_stream();
  Token pop_last();

  Lexer(std::string input)
      : m_input{input}, m_current_token{Token()},
        m_token_stream{std::vector<Token>()} {
    m_current_position = m_input.begin();
  }

private:
  std::string m_input;
  std::string::iterator m_current_position;
  Token m_current_token;
  std::vector<Token> m_token_stream;
};

#endif // !_LEXER_H_
