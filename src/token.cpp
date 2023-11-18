#include "token.h"
#include "token_utils.h"
#include <algorithm>

bool Token::update_value(const char &c) {
  // std::cout << state << "> " << c << std::endl;
  bool is_token_complete{};
  switch (state) {
  case Initial:
    is_token_complete = update_state_from_initial(c);
    break;
  case Constant:
    is_token_complete = update_state_from_constant(c);
    break;
  case Dice:
    is_token_complete = update_state_from_dice(c);
    break;
  case Operator:
    is_token_complete = update_state_from_operator(c);
    break;
  case Flag:
    is_token_complete = update_state_from_flag(c);
    break;
  case Invalid:
    is_token_complete = update_state_from_invalid(c);
    break;
  }
  return is_token_complete;
}

bool Token::update_state_from_initial(const char &c) {
  if (util::isdigit(c)) {
    state = Constant;
    value += c;
  } else if (c == 'd') {
    state = Dice;
    value += c;
  } else if (util::find(operators, c)) {
    state = Operator;
    value += c;
  } else if (util::find(whitespace, c)) {
  } else {
    // std::cout << "fallen through initial >> " << c << std::endl;
    state = Invalid;
    value += c;
  }
  return false;
}

bool Token::update_state_from_constant(const char &c) {
  if (util::isdigit(c)) {
    value += c;
  } else if (c == 'd') {
    state = Dice;
    value += c;
  } else
    return true;
  return false;
}

bool Token::update_state_from_dice(const char &c) {
  if (util::isdigit(c)) {
    value += c;
  } else
    return true;
  return false;
}

bool Token::update_state_from_operator(const char &c) {
  if (util::isalpha(c) and value == "-") {
    state = Flag;
    value += c;
  } else
    return true;
  return false;
}

bool Token::update_state_from_flag(const char &c) {
  if (util::isalpha(c)) {
    value += c;
  } else
    return true;
  return false;
}

bool Token::update_state_from_invalid(const char &c) { return true; }

std::ostream &operator<<(std::ostream &os, const TokenState &token_state) {
  std::string token_name{};
  switch (token_state) {
  case Initial:
    token_name = "Initial";
    break;
  case Constant:
    token_name = "Constant";
    break;
  case Dice:
    token_name = "Dice";
    break;
  case Operator:
    token_name = "Operator";
    break;
  case Flag:
    token_name = "Flag";
    break;
  case Invalid:
    token_name = "Invalid";
    break;
  }
  os << token_name;
  return os;
}
