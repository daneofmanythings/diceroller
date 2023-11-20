#include "lexer.h"
#include <string>

std::vector<Token> Lexer::generate_token_stream() {

  while (m_current_position != m_input.end()) {

    bool is_token_complete{m_current_token.update_value(*m_current_position)};

    if (is_token_complete) {
      if (m_current_token.is_invalid()) { // throws away invalid characters
        m_current_token = pop_last();
      } else {
        m_token_stream.push_back(m_current_token);
        m_current_token = Token();
      }
    } else {
      m_current_position++;
    }
  }
  if (m_current_token.get_state() != Initial)
    m_token_stream.push_back(m_current_token);
  return m_token_stream;
}

Token Lexer::pop_last() {
  auto it = m_token_stream.end();
  Token result{*--it};
  m_token_stream.pop_back();
  return result;
}
