#include <boost/config.hpp>
#include <iostream>
#include "abstract_plugin.h"

namespace plugin_multiply {
class plugin_multiply : public plugins_demo::abstract_plugin {
public:
    plugin_multiply() {
        std::cout << "Constructing plugin_multiply\n";
    }

    const std::string &name() const override {
        static std::string name = "multiply";
        return name;
    }

    float calculate(float x, float y) override {
        return x * y;
    }

    ~plugin_multiply() {
        std::cout << "Destructing plugin_multiply\n";
    }
};

extern "C" BOOST_SYMBOL_EXPORT plugin_multiply plugin;
plugin_multiply plugin;
}  // namespace plugin_multiply