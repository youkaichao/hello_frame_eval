# hello_frame_eval
A hello-world usage for frame eval api proposed in [PEP 523](https://peps.python.org/pep-0523/), the core functionality of pytorch 2.0.

Part of the code adapted from the [pytorch dynamo code](https://github.com/pytorch/pytorch/blob/main/torch/csrc/dynamo/eval_frame.c).

It hooks the evaluation of each function by printing a `hello, world!` message first, and then execute the original code.

# Installation

Just run `python setup.py install`.

It works for python 3.6 and above.

# Test

After installation, try the test code `python test.py`.

The test code is:
```python
def f():
    return 1
import hello_frame_eval
hello_frame_eval.modify_frame_eval()
f()
```

You will see that each function call results in printing a `hello, world!` message.

# :warning: Do not use this in ipython/jupyter!

In ipython or jupyter, each line of code you execute involves thousands of function calls! You will be swamped by the output message!
