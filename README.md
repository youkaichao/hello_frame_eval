# hello_frame_eval
A hello-world usage for frame eval api proposed in [PEP 523](https://peps.python.org/pep-0523/), the core functionality of pytorch 2.0.

Part of the code adapted from the [pytorch dynamo code](https://github.com/pytorch/pytorch/blob/main/torch/csrc/dynamo/eval_frame.c).

It hooks the evaluation of each function by printing a `hello, world!` message first, followed by the function name, and then execute the original code.

# Installation

Just run `python setup.py develop`.

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

You will see that each function call results in printing a `hello, world! From this function: f` message.

Strangely, sometimes (in some machines) I see the following output:

```
hello, world! From this function: f
hello, world! From this function: _shutdown
hello, world! From this function: _stop
hello, world! From this function: daemon
```

Your mileage might vary!

# :warning: Do not use this in ipython/jupyter!

In ipython or jupyter, each line of code you execute involves thousands of function calls! You will be swamped by the output message!

Even if you enter nothing, the following lines might appear:

```
... (omitted)
hello, world! From this function: get_debug
hello, world! From this function: _run_once
hello, world! From this function: select
hello, world! From this function: _process_events
hello, world! From this function: time
hello, world! From this function: _run
hello, world! From this function: _poll_output_size
hello, world! From this function: sleep
hello, world! From this function: cancel
hello, world! From this function: _timer_handle_cancelled
hello, world! From this function: cancel
hello, world! From this function: get_debug
... (omitted)
```

This might be helpful for you to understand the working mechanism of ipython?

Enjoy yourself in hooking python function calls!
