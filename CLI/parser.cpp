#include "parser.hpp"
#include <iostream>
#include <stdexcept>
#include <cctype>

namespace cli {

    Parser::Lexer::Lexer(const std::string& input) : m_Input(input), m_Position(0) {}

    Parser::Token Parser::Lexer::getToken() {
        rawToken token = extractToken();
        TokenType type = determineType(token);
        validate(type, token);
        return { token, type };
    }

    Parser::rawToken Parser::Lexer::extractToken() {
        while (m_Position < m_Input.size() && m_Input[m_Position] == ' ') {
            ++m_Position;
        }

        if (m_Position >= m_Input.size()) return "";

        size_t start = m_Position;
        if (m_Input[start] == '"') {
            ++m_Position;
            while (m_Position < m_Input.size() && m_Input[m_Position] != '"') {
                ++m_Position;
            }
            ++m_Position;
            return m_Input.substr(start, m_Position - start);
        }

        while (m_Position < m_Input.size() && m_Input[m_Position] != ' ') {
            ++m_Position;
        }
        return m_Input.substr(start, m_Position - start);
    }

    Parser::TokenType Parser::Lexer::determineType(const rawToken& token) {
        if (token.empty()) {
            return TokenType::Null;
        } else if (token[0] == '-') {
            return TokenType::Option;
        } else if (token.front() == '"' && token.back() == '"') {
            return TokenType::Argument;
        } else {
            return TokenType::Name;
        }
    }

    void Parser::Lexer::validate(TokenType type, const rawToken& token) {
        switch (type) {
            case TokenType::Name:
                validateWord(token);
                break;
            case TokenType::Option:
                validateOption(token);
                break;
            case TokenType::Argument:
                validateArgument(token);
                break;
            default:
                throw std::runtime_error("Unknown token type");
        }
    }

    void Parser::Lexer::validateWord(const rawToken& token) {
        for (char c : token) {
            if (!isalpha(c)) {
                throw std::runtime_error("Word token must contain only letters");
            }
        }
    }

    void Parser::Lexer::validateOption(const rawToken& token) {
        if (token.size() < 2 || token[0] != '-') {
            throw std::runtime_error("Invalid option format");
        }
    }

    void Parser::Lexer::validateArgument(const rawToken& token) {
        if (token.front() != '"' || token.back() != '"') {
            throw std::runtime_error("Argument token must be enclosed in double quotes");
        }
    }

    Parser::SyntaxAnalyzer::SyntaxAnalyzer() : m_CurrentState(State::S_Start) {}

    bool Parser::SyntaxAnalyzer::isValid(const Token& validToken) {
        State nextState = getNextState(validToken.second);
        if (nextState != State::S_Dead) {
            m_CurrentState = nextState;
            return true;
        }
        return false;
    }

    Parser::State Parser::SyntaxAnalyzer::getCurrentState() const {
        return m_CurrentState;
    }

    Parser::State Parser::SyntaxAnalyzer::getNextState(TokenType tokenType) {
        auto stateTransitions = m_StateMap[m_CurrentState];
        auto it = stateTransitions.find(tokenType);
        if (it != stateTransitions.end()) {
            return it->second;
        }
        return State::S_Dead;
    }

    Parser::Parser(const std::string& input) : m_Lexer(input), m_SyntaxAnalyzer() {
        parse();
    }

    void Parser::parse() {
        try {
            Token validToken = m_Lexer.getToken();
            if (validToken.second != TokenType::Name) {
                throw std::runtime_error("Command must start with a Name token");
            }

            if (!m_SyntaxAnalyzer.isValid(validToken)) {
                std::cerr << "Invalid syntax: " << validToken.first << std::endl;
                return;
            }

            while (true) {
                validToken = m_Lexer.getToken();
                if (validToken.second == TokenType::Null) {
                    break; 
                }

                if (!m_SyntaxAnalyzer.isValid(validToken)) {
                    std::cerr << "Invalid syntax: " << validToken.first << std::endl;
                    break;
                }

                if (m_SyntaxAnalyzer.getCurrentState() == State::S_End) {
                    std::cout << "Parsing completed successfully." << std::endl;
                    break;
                }
            }
        } catch (const std::exception& e) {
            std::cerr << "Error during parsing: " << e.what() << std::endl;
        }
    }

} // namespace cli
