# STLSoft - Install

There are three options for installing **STLSoft**, depending on how you obtain it.

## As downloaded archive, using environment variables

If you obtain the latest release as an archive, e.g. from the [STLSoft SourceForge project](https://sourceforge.net/projects/stlsoft/):

1. Download the latest distribution, e.g. **STLSoft-1.10.1.zip**;

2. Unzip it to a directory of your choice, as in:

```bash
$ mkdir -p ~/open-source
$ cd ~/open-source
$ unzip STLSoft-1.10.1.zip
```

3. Define an environment variable `STLSOFT`, whose value is the directory in which you unzipped it, e.g. `STLSOFT=~/open-source/STLSoft-1.10.1`, and then specify `$(STLSOFT)/include` (**UNIX**) or `%STLSOFT%\include` (**Windows**) in your project files and makefiles;


## Cloning project, using environment variables

If you clone the project from https://github.com/synesissoftware/STLSoft-1.10:

1. Clone, e.g. **STLSoft-1.10.1.zip**;

```bash
$ mkdir -p ~/open-source
$ cd ~/open-source
$ git clone -b master https://github.com/synesissoftware/STLSoft-1.10
```

2. Define an environment variable `STLSOFT`, whose value is the directory in which you cloned it, e.g. `STLSOFT=~/open-source/STLSoft-1.10`, and then specify `$(STLSOFT)/include` (**UNIX**) or `%STLSOFT%\include` (**Windows**) in your project files and makefiles;


## Cloning project, installing via CMake

1. Clone, e.g. **STLSoft-1.10.1.zip**;

```bash
$ mkdir -p ~/open-source
$ cd ~/open-source
$ git clone -b master https://github.com/synesissoftware/STLSoft-1.10
```

1. "Prepare" the **CMake** build context:

```bash
$ cd ~/open-source/STLSoft-1.10
$ ./prepare_cmake.sh -m -v
```

3. Install the **CMake** build artefacts such that they are available for use _and_ that **STLSoft** may be found by other **CMake**-based installations:

```bash
$ cd ~/open-source/STLSoft-1.10
$ sudo cmake --install ./_build --config Release
```

----

## Use of environment variables.

Unless you are certain that your projects, and all the projects upon which they depend, all use **STLSoft** via **CMake** then it is recommended that you define an `STLSOFT` environment variable.

For example, if you're using **UNIX** and you install to
**/usr/local/stlsoft/stlsoft-1.10.1**
then you should set the environment variable `STLSOFT` to
**/usr/local/stlsoft/stlsoft-1.10.1**
in which case the file `stlsoft/stlsoft.h`, for example, will be located in `$STLSOFT/include/stlsoft/stlsoft.h`.

Conversely, if you're using **Windows** and you intall to
**C:\3pty\STLSoft\stlsoft-1.10.1**
then you should set the environment variable `STLSoft` to
**C:\3pty\STLSoft\stlsoft-1.10.1**
in which case the file `stlsoft/stlsoft.h`, for example, will be located in `C:\3pty\STLSoft\stlsoft-1.10.1\stlsoft\stlsoft.h`.

The makefiles / project files of several other open-source projects expect this symbol, including:

| Project     | Project home                                  |
| ----------- | --------------------------------------------  |
| b64         | https://github.com/synesissoftware/b64        |
| CLASP       | https://github.com/synesissoftware/CLASP      |
| cstring     | https://github.com/synesissoftware/cstring    |
| FastFormat  | https://github.com/synesissoftware/FastFormat |
| libCLImate  | https://github.com/synesissoftware/libCLImate |
| Pantheios   | https://github.com/synesissoftware/Pantheios  |
| recls       | https://github.com/synesissoftware/recls      |
| shwild      | https://github.com/synesissoftware/shwild     |
| VOLE        | https://github.com/synesissoftware/VOLE       |
| xTests      | https://github.com/synesissoftware/xtests     |

**NOTE**: If you're using **STLSoft** on `UNIX`, you might want to apply `dos2unix` over all the files before using it. You *must* do this if you're using the **SunPro C compiler** - this action is carried out automatically, for example, by the **Pantheios** makefile(s).
