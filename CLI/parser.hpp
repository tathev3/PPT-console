#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <unordered_map>
#include <utility>
#include <variant>

namespace cli {

    class Parser {
    public:
        enum class TokenType { Null = 0, Name, Option, Argument };
        enum class State { S_Start, S_Name, S_Opt, S_Arg, S_Dead, S_End };

        using rawToken = std::string;
        using Token = std::pair<rawToken, TokenType>;
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

            rawToken extractToken();
            TokenType determineType(const rawToken& token);
            void validate(TokenType type, const rawToken& token);
            void validateWord(const rawToken& token);
            void validateOption(const rawToken& token);
            void validateArgument(const rawToken& token);
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

        void parse();
        Lexer m_Lexer;
        SyntaxAnalyzer m_SyntaxAnalyzer;
    };

} // namespace cli

#endif // PARSER_HPP
