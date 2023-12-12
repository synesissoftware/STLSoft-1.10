# STLSoft - FAQ

The FAQ list is under (constant) development. If you post a question on the
Issues forum (https://github.com/synesissoftware/STLSoft-1.10/issues)
it will be used to create one.


* [Q1](#q1-how-do-i-build-stlsoft): "How do I build STLSoft?"
* [Q2](#q2-how-do-i-install-stlsoft): "How do I install STLSoft?"
* [Q3](#q3-how-do-i-use-stlsoft): "How do I use STLSoft?"
* [Q4](#q4-does-stlsoft-have-unit-tests): "Does STLSoft have unit-tests?"


# FAQs:

## Q1: "How do I build STLSoft?"

You don't!

STLSoft is 100% header-only, so all you have to do is `#include` it. We do recommend that you use an environment variable, e.g. `STLSOFT`, so that you can use new versions of the library from your projects without disruption.


## Q2: "How do I install STLSoft?"

Basically, there are three ways:

1. As downloaded archive, using environment variables;
2. Cloning project, using environment variables;
3. Cloning project, installing via CMake;

Option 3 is preferred.

See [INSTALL.md](./INSTALL.md) for details of these options.


## Q3: "How do I use STLSoft?"

Assuming you've installed it using environment variables (as per instructions in [Q2](#q2-how-do-i-install-stlsoft)), then:

* in your IDE settings, add the include directory `$(STLSOFT)/include`; or
* in your makefiles, add the include directory `-I$STLSOFT/include` (UNIX) or `-I%STLSOFT%/include` (Windows);


## Q4: "Does STLSoft have unit-tests?"

Yes, there are *many* such, but for various reasons they're not available with the STLSoft 1.10 distribution. When STLSoft 1.11 is released it will include unit-tests, which will likely be a mix of [**xTests**](https://github.com/synesissoftware/xTests) and [**Catch2**](https://github.com/catchorg/Catch2) unit-test libraries, both of which will be bundled with distributions.

