# arcdec
Modular multi-stage assembly to C decompiler

# Modules

ARCDEC Module is a set of files for supporting assembly architecture.
Modules are written in human-readable ARCDEC Module Source Format with JSON and directives.
ARCDEC Module Compiler translates Source Format to Output Format.
Output files are stored for later usage with ARCDEC Decompiler.

# Decompiler

ARCDEC Decompiler accepts an assembly source file and translates it to C source in context of one function.
Currently only simple x86 instructions are supported fully.
