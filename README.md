# Shows breakage involving `LD_PRELOAD` on linux

LD_PRELOAD is specified by [ld.so](http://man7.org/linux/man-pages/man8/ld.so.8.html)
as (my emphasis):

```
LD_PRELOAD
     A list of additional, user-specified, ELF shared objects to be
     loaded *BEFORE* all others.
```

Does this happen ? Let's find out with a simple program that links a shared
library and then we add another with LD_PRELOAD.


## Build

Build with [mulle-make](//github.com/mulle-sde/mulle-make) or alternatively :

```
(
   mkdir build &&
   cd build &&
   cmake .. &&
   make
)
```

## Run

```
LD_PRELOAD="${PWD}/build/libld-preload.so" ./build/main
```

## Output

```
load_linked
load_preload
```

LD_PRELOAD's constructor is certainly run *AFTER* all others.


## Addendum

Looking at it with `ldd` (See: [Issue #1](//github.com/mulle-nat/LD_PRELOAD-breakage-linux/issues/1)) one can see that `load_preload` is actually loaded ahead of `linked`, which is fine. According to the ELF spec, the initialization order
of non-related shared objects is non-defined (maybe to support parallel loading). So this could be technically OK on
the ELF side. But I still think, this violates `LD_PRELOAD`s purpose.
