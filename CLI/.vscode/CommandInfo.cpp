#include "CommandInfo.h"

namespace cli {

    CommandInfo::Info CommandInfo::getInfo() const {
        return {m_name, m_options, m_arguments};
    }

} // namespace cli
