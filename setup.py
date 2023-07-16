from distutils.core import setup, Extension

module1 = Extension('hello_frame_eval',
                    sources = ['mymodule.c'])

setup (name = 'hello_frame_eval',
       version = '1.0',
       description = 'A hello-world usage for frame eval api.',
       ext_modules = [module1])
