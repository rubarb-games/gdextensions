#ifndef GD_TOML_PARSER
#define GD_TOML_PARSER

#include <godot_cpp/classes/object.hpp>
#include "../toml11/single_include/toml.hpp"

using namespace godot;

class TomlParser : public Object {
    GDCLASS(TomlParser, Object);

private:
    toml::value t;
    std::string to_str(const String &p_string);
    Dictionary to_dictionary(const toml::value &val);

protected:
    static void _bind_methods();

public:
    TomlParser();
    ~TomlParser();

    bool try_parse(const String &p_content);
    String get_str(const String &p_key);
    Array get_arr(const String &p_key);
    Dictionary get_section(const String &p_section_name);
};

#endif