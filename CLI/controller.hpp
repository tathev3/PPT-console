#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <iostream>
#include <memory>
#include "command.hpp" // not created yet
#include "parser.hpp"



class Controller {
public:
    using CommandPtr = std::unique_ptr<Command>; 
    Controller();
    void start(std::istream& stream);

private:
    std::unique_ptr<CLI::Parser> m_parser; 

    CommandPtr fetch(std::istream& stream);
    void execute(CommandPtr& command); 
    void initialize();
};

#endif // CONTROLLER_HPP
