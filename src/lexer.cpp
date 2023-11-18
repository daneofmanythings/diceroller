#include "lexer.h"
#include <string>

std::vector<Token> Lexer::generate_token_stream() {

  while (current_position != input.end()) {

    // sanity check
    // std::cout << *current_position << " <";

    bool is_token_complete{current_token.update_value(*current_position)};

    if (is_token_complete) {
      token_stream.push_back(current_token);
      current_token = Token();
    } else {
      current_position++;
    }
  }
  if (current_token.get_state() != Initial)
    token_stream.push_back(current_token);
  return token_stream;
}
