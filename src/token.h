#ifndef _TOKENS_H_
#define _TOKENS_H_

#include <array>
#include <iostream>
#include <string>

enum TokenState {
  Initial,
  Constant,
  Dice,
  Operator,
  Flag,
  Invalid,
};

std::ostream &operator<<(std::ostream &os, const TokenState &token_type);

class Token {
public:
  TokenState get_state() const { return state; }
  std::string get_value() const { return value; }

  bool update_value(const char &c);

  bool update_state_from_initial(const char &c);
  bool update_state_from_constant(const char &c);
  bool update_state_from_dice(const char &c);
  bool update_state_from_operator(const char &c);
  bool update_state_from_flag(const char &c);
  bool update_state_from_invalid(const char &c);

  Token() : state{Initial}, value{std::string()} {};

private:
  TokenState state;
  std::string value;
  static constexpr std::array<char, 4> operators = {'+', '-', '*', '/'};
  static constexpr std::array<char, 4> whitespace = {' ', '\n', '\r', '\t'};
};

#endif // !_TOKENS_H_
