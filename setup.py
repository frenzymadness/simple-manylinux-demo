from distutils.core import setup, Extension

extension_module = Extension(
    'dummyextension.extension',
     sources=['dummyextension/extension.c'],
)

setup(
    name = 'simple-manylinux-demo',
    version = '3.0',
    author = "Lumír Balhar",
    author_email = "frenzy.madness@gmail.com",
    url = "https://github.com/frenzymadness/simple-manylinux-demo",
    license = "CC0 1.0",
    description = 'This is a simple package with a compiled C extension.',
    long_description = "See the project homepage for more info.",
    ext_modules = [extension_module],
    packages=['dummyextension', 'dummyextension.tests'],
)
