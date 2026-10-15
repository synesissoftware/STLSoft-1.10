# STLSoft - Known Issues:


> **Semi-frozen / maintenance**
>
> **STLSoft-1.10** is a historical, maintenance-only line. It remains available for
> consumers that must stay on the 1.10 API (for example compatibility matrices),
> but all **new development** and **new consumers** MUST use
> **[synesissoftware/STLSoft](https://github.com/synesissoftware/STLSoft)** (tip).
> Feature work belongs on tip; this repository only receives recognition and
> packaging fixes required by historical consumers.

----


## Maintenance policy

* Feature work and new consumers belong on **[synesissoftware/STLSoft](https://github.com/synesissoftware/STLSoft)** (tip).
* This 1.10 line is **semi-frozen**: recognition / packaging / helper fixes for historical consumers only. No CI is maintained on this line.


## STLSoft 1.10 Known Issues:

* The documentation is still lacking. This will be addressed in the release of 1.11.

* Several `unixstl::system_traits` methods are declared but not defined, with the intention to flesh them out from Linux system calls (and have emulations/workarounds for other architectures). We're keen to see pull-requests on this.


<!-- ########################### end of file ########################### -->

