// Copyright Epic Games, Inc. All Rights Reserved.
#include "Pyblish.h"
#include "Python3/Win64/include/Python.h"
#include "Async/Async.h"
#include "Python3//Win64/include/pystate.h"

#define LOCTEXT_NAMESPACE "FPyblishModule"

static PyObject* ExecuteInMainThreadWithResult(PyObject* ModuleSelf, PyObject* InArgs, PyObject* InKwargs) //PyObject* Args, PyObject* Keywds)
{
	PyEval_InitThreads();
	PyThreadState* threadState;
	threadState = PyEval_SaveThread();
	PyObject* Result = nullptr;
	Py_XINCREF(InArgs);
	FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=, &Result]()
		{
			//PyEval_InitThreads();
			PyGILState_STATE State = PyGILState_Ensure();
			PyObject* Callable = nullptr;
			PyObject* Args = nullptr;
			Callable = PyTuple_GET_ITEM(InArgs, 0);
			if (PyTuple_Size(InArgs) > 1)
			{
				Args = PyTuple_GetSlice(InArgs, 1, PyTuple_Size(InArgs));
			}
			if (Args)
			{
				Result = PyObject_Call(Callable, Args, InKwargs);

			}
			else
			{
				Result = PyObject_Call(Callable, PyTuple_New(0), InKwargs);
			}
			PyGILState_Release(State);

		}, TStatId(), NULL, ENamedThreads::GameThread);

	FTaskGraphInterface::Get().WaitUntilTaskCompletes(Task);
	PyEval_RestoreThread(threadState);
	return Result;
}

PyMethodDef PyhonExtendsion[] = {
	{ "executeInMainThreadWithResult", (PyCFunction)(void*)(&ExecuteInMainThreadWithResult), METH_VARARGS | METH_KEYWORDS, ""},
	{ nullptr, nullptr, 0, nullptr }
};

void FPyblishModule::StartupModule()
{
	PyGILState_STATE State = PyGILState_Ensure();
	PyObject* Modules = PyImport_GetModuleDict();
	PyObject* UnrealModule = PyDict_GetItemString(Modules, "unreal");
	if (UnrealModule)
	{
		PyModule_AddFunctions(UnrealModule, PyhonExtendsion);
	}
	PyGILState_Release(State);
}

void FPyblishModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPyblishModule, Pyblish)