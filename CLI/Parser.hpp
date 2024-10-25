// parser.hpp
#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <unordered_map>
#include <utility>

namespace cli {

    class Parser {
    public:
        enum class TokenType { Null = 0, Name, Option, Argument };
        enum class State { S_Start, S_Name, S_Opt, S_Arg, S_Dead, S_End };

        using Token = std::pair<std::string, TokenType>;
        using StateDiagram = std::unordered_map<State, std::unordered_map<TokenType, State>>;

        explicit Parser(const std::string& input);

    private:
        class Lexer {
        public:
            explicit Lexer(const std::string& input);
            Token getToken();

        private:
            std::string m_Input;
            size_t m_Position;

            std::string extractToken();
            TokenType determineType(const std::string& token);
            void validate(TokenType type, const std::string& token);
            void validateWord(const std::string& token);
            void validateOption(const std::string& token);
            void validateArgument(const std::string& token);
        };

        class SyntaxAnalyzer {
        public:
            SyntaxAnalyzer();
            bool isValid(const Token& validToken);
            State getCurrentState() const;

        private:
            State m_CurrentState;
            StateDiagram m_StateMap;

            State getNextState(TokenType tokenType);
        };

        Lexer m_Lexer;
        SyntaxAnalyzer m_SyntaxAnalyzer;

        void parse();
    };

} // namespace cli

#endif // PARSER_HPP

