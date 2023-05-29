# Arena Allocator

Simple Arena Allocator made in C

_This is made for educational purposes. Use at your own risk._

The arena is made as a single header-only library [arena.h](/src/arena.h)

## Quick Start
```console
> premake5 vs2022
> msbuild -p:configuration\Debug build\arena.sln
> bin\Debug\arena.exe
```
Note: You can also open the VS solution file (.sln) directly and build with Visual Studio<s>(If you want to wait eternally for it to open)</s> and build it.
## Dependencies
- [premake5 (version 5.0.0-beta2 and up)](https://github.com/premake/premake-core/releases/download/v5.0.0-beta2/premake-5.0.0-beta2-windows.zip)
- [Visual Studio 17.4.4 (2022)](https://visualstudio.microsoft.com/vs/community/) with (Desktop development with C++ Workload Installed)

# References:
Arena Allocator: https://en.wikipedia.org/wiki/Region-based_memory_management
Header-only library: https://github.com/nothings/stb#how-do-i-use-these-libraries
