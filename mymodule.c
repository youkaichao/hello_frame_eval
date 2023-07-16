#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <code.h>
#include <frameobject.h>
#define Py_BUILD_CORE
#include <internal/pycore_pystate.h>

#if PY_VERSION_HEX >= 0x03090000
static PyObject* new_frame_eval(PyThreadState *state, PyFrameObject *frame, int throwflag){
#else
static PyObject* new_frame_eval(PyFrameObject *frame, int throwflag){
#endif
    printf("hello, world!\n");
#if PY_VERSION_HEX >= 0x03090000
    return _PyEval_EvalFrameDefault(state, frame, throwflag);
#else
    return _PyEval_EvalFrameDefault(frame, throwflag);
#endif
}

static PyObject* modify_frame_eval() {
    PyThreadState *state = PyThreadState_Get();
#if PY_VERSION_HEX >= 0x03090000
    _PyInterpreterState_SetEvalFrameFunc(state->interp,
                                         &new_frame_eval);
#else
    state->interp->eval_frame = &new_frame_eval;
#endif
    Py_RETURN_NONE;
}

static PyMethodDef MyMethods[] = {
    {"modify_frame_eval",  modify_frame_eval, METH_NOARGS, 
     "Modify frame eval to print hello world before executing the code."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef hello_frame_eval = {
    PyModuleDef_HEAD_INIT,
    "hello_frame_eval",   /* name of module */
    NULL,         /* module documentation, may be NULL */
    -1,           /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    MyMethods
};

PyMODINIT_FUNC
PyInit_hello_frame_eval(void)
{
    return PyModule_Create(&hello_frame_eval);
}
