# C++ In Flow State

Personal learning repo for C++ — small standalone `.cpp` files, each covering one concept, plus running notes.

## Structure

Each topic has a `<topic>.cpp` source file (some compile to a same-named binary):

| File | Topic |
|---|---|
| `main.cpp` | entry point / scratch |
| `assignment.cpp` | assignment operators |
| `arrays.cpp` | arrays |
| `strings.cpp` | strings |
| `pointer.cpp` | pointers |
| `function.cpp` / `valueReturningFunctions.cpp` | functions |
| `class.cpp` / `constructor.cpp` / `constructorMemberInitializarList.cpp` | classes & constructors |
| `inheritance.cpp` / `virtualFunction.cpp` / `super.h` | inheritance & polymorphism |
| `const.cpp` / `mutable.cpp` | const-correctness |
| `staticClass.cpp` | static members |
| `enums.cpp` | enums |
| `conversion.cpp` | type conversion |
| `ternaryOperators.cpp` | ternary operator |
| `maybe.cpp` / `log.cpp` / `PrintStandard.cpp` | misc exercises |

Notes:
- `Cpp_In_Flow_State.md` — notes from the start (machine/assembly language, low-level basics).
- `Back_To_Basics.md` — statements, functions, and other fundamentals.

## Build & run

Single-file examples, compile directly with g++:

```bash
g++ -std=c++17 -o ternaryOperators ternaryOperators.cpp
./ternaryOperators
```

Swap the filename for whichever topic you want to try.
