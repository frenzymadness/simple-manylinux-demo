#include "Python.h"


/* The wrapper to the underlying C function */
static PyObject *
py_hello(PyObject *self)
{
    return Py_BuildValue("s", "Hello from Python extension!");
}

static PyMethodDef module_functions[] = {
	{"hello",  (PyCFunction)py_hello, METH_NOARGS, NULL},
	{NULL, NULL}      /* sentinel */
};


#if PY_MAJOR_VERSION >= 3
    static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "extension",     /* m_name */
        "This is a module",  /* m_doc */
        -1,                  /* m_size */
        module_functions,    /* m_methods */
        NULL,                /* m_reload */
        NULL,                /* m_traverse */
        NULL,                /* m_clear */
        NULL,                /* m_free */
    };
#endif


static PyObject *
moduleinit(void)
{
    PyObject *m;

#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule3("extension",
                        module_functions, "This is a module");
#endif
  return m;
}

#if PY_MAJOR_VERSION < 3
    PyMODINIT_FUNC
    initextension(void)
    {
        moduleinit();
    }
#else
    PyMODINIT_FUNC
    PyInit_extension(void)
    {
        return moduleinit();
    }
#endif
