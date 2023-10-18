project('luj_ogluszacz', 'c')

static_libs = false

# cc = meson.get_compiler('c')
deps = [
    dependency('zlib', static: static_libs),
    # cc.find_library('m', required: false),
]
executable(
    'luj_ogluszacz',
    'src/luj_ogluszacz.c',
    dependencies: deps,
)
