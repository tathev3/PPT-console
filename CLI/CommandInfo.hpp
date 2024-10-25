#ifndef COMMANDINFO_H
#define COMMANDINFO_H

#include <string>
#include <set>
#include <vector>
#include <tuple>

namespace cli {

    class CommandInfo {
    public:
        using Info = std::tuple<std::string, std::set<std::string>, std::vector<std::string>>;

        CommandInfo(const std::string& name, const std::set<std::string>& options, const std::vector<std::string>& arguments)
            : m_name(name), m_options(options), m_arguments(arguments) {}

        Info getInfo() const;

    private:
        std::string m_name;
        std::set<std::string> m_options;
        std::vector<std::string> m_arguments;
    };

} // namespace cli

#endif // COMMANDINFO_H
