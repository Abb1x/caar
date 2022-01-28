#include <gen.h>
#include <lib/map.h>

Bytes _codegen(Ast ast, size_t *i, map_str_t labels)
{
    (void)ast;
    (void)i;
    (void)labels;

    Bytes ret = {};
    vec_init(&ret);

    return ret;
}

Bytes codegen(Ast ast)
{
    size_t i = 0;
    map_str_t labels;
    map_init(&labels);
    return _codegen(ast, &i, labels);
}