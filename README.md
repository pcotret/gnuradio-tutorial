# Gnuradio tutorial - How to create custom blocks ?

The basic behind this tutorial is to show the **complete** flow to creat custom blocks in Gnuradio in both C++ and Python. We'll go through several steps starting with the official tutorial given by GNURadio on their wiki (https://wiki.gnuradio.org/index.php/OutOfTreeModules)

This tutorial will present several custom blocks:

* square_in_cpp: 1-input, 1-output. Performing a simple square operation.
* multiply_sig_cpp: 2-input, 1-output. The output is the product of both inputs.
* add_sig_cpp: 3-input, 1-output. The output is the sum of inputs.
* *_python: same thing for those threee blocks in Python.

## Creation of an OTT (Out-Of-Tree) module
Basically, an OTT module is a component that doesn't exist in a default GNURadio installation. It can be your own blocks or blocks made by someone else, downloaded from the web. A GNURadio module is a king of library: it contains a list of blocks that can be used in a GRC schematic.

You won't be alone in this adventure. A tool called `gr_modtool` will help you with the most important operations needed to create a custom block. In order to create a custom block called `gnuradio-tutorial`, type the following command:

```bash
gr_modtool newmod tuto
```

It will create a folder called `gr-tuto` with several subfolders: apps, cmake, docs. Important ones are:

* lib: C++ code
* grc: GRC/XML files
* python: containing the... ...Python code

## Tutorial #1 - square_in_cpp

In this first exercise, taken from the official wiki, we will create a block performing `output=input*input`.

Disclaimers:

* It is assumed we are in the `gr-tuto` directory.
* Unlike the official wiki, we won't address test codes that can be added to each block.

First, create a block called `square_in_cpp`:

```bash
gr_modtool add square_in_cpp
```

We are asked for several things:

```bash
GNU Radio module name identified: tuto
('sink', 'source', 'sync', 'decimator', 'interpolator', 'general', 'tagged_stream', 'hier', 'noblock')
Enter block type: general
Language (python/cpp): cpp
Language: C++
Block/code identifier: square_in_cpp
Enter valid argument list, including default arguments: 
Add Python QA code? [Y/n] n
Add C++ QA code? [Y/n] n
```

* **Enter block type:** choose general.
* **Language (python/cpp):** the language used to implement the block. Choose C++.
* **Enter valid argument list, including default arguments:** no need for arguments at this step.
* **QA codes:** these are template codes needed for tests. We don't need it in this tutorial.

Several files are generated:
```bash
Adding file 'lib/square_in_cpp_impl.h'...
Adding file 'lib/square_in_cpp_impl.cc'...
Adding file 'include/tuto/square_in_cpp.h'...
Editing swig/tuto_swig.i...
Adding file 'grc/tuto_square_in_cpp.xml'...
Editing grc/CMakeLists.txt...
```

Modify `lib/square_in_cpp_impl.cc` with your favourite editor.

The private constructor:
```C++
square_in_cpp_impl::square_in_cpp_impl()
      : gr::block("square_in_cpp",
              gr::io_signature::make(1, 1, sizeof (float)), // Number and type of inputs
              gr::io_signature::make(1, 1, sizeof (float))) // Number and type of outputs
    {}
```

