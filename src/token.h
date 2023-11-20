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
  TokenState get_state() const { return m_state; }
  std::string get_value() const { return m_value; }
  bool is_invalid() const { return get_state() == Invalid; }

  bool update_value(const char &c);

  bool update_state_from_initial(const char &c);
  bool update_state_from_constant(const char &c);
  bool update_state_from_dice(const char &c);
  bool update_state_from_operator(const char &c);
  bool update_state_from_flag(const char &c);
  bool update_state_from_invalid(const char &c);

  bool isoperator(const char &c);

  Token() : m_state{Initial}, m_value{std::string()} {};

private:
  TokenState m_state;
  std::string m_value;
  static constexpr std::array<char, 4> c_operators = {'+', '-', '*', '/'};
};

#endif // !_TOKENS_H_
