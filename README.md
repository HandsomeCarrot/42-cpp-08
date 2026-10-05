*This project has been created as part of the 42 curriculum by vpoka.*

# CPP08 — Templated containers, iterators, algorithms

A C++98 project from the 42 curriculum focused on templates and practical use of the Standard Template Library (STL): containers, iterators, and algorithms.

## Table of contents

- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [What this project demonstrates](#what-this-project-demonstrates)
- [Technical constraints](#technical-constraints)
- [Repository structure](#repository-structure)
- [Focus areas by exercise](#focus-areas-by-exercise)
- [Testing](#testing)
- [Status](#status)

## Description

CPP08 is the ninth module of the 42 C++ Common Core sequence and the first one where the Standard Template Library is not just allowed but expected. The module is a set of three short exercises that build confidence with function templates, class templates, STL containers, iterators, and the algorithms in `<algorithm>`, all under the usual C++98 rules.

Unlike earlier modules, where the STL was forbidden, this one wants you to reach for `std::vector`, `std::find`, `std::sort` and friends whenever they fit. Hand-rolling what the standard library already provides can cost points even when the code works.

This module is split into three exercises:

* **ex00 — Easy find**
  Write a function template `easyfind` that looks for the first occurrence of an integer in a container of integers.
* **ex01 — Span**
  A `Span` class that stores up to N integers and can report the shortest and longest distance between any two of them, including bulk filling through ranges.
* **ex02 — Mutated abomination**
  `MutantStack`, an iterable take on `std::stack` that adds iterators on top of the standard container.

| Exercise | Executable | STL used |
| --- | --- | --- |
| [ex00](ex00/) — Easy find | `ex00` | `std::find`, `std::vector<int>` |
| [ex01](ex01/) — Span | `ex01` | `std::vector`, `std::sort`, `std::distance` |
| [ex02](ex02/) — Mutated abomination | `ex02` | `std::stack` over `std::deque` |

## Instructions

### Prerequisites

- A C++ compiler available as `c++`, supporting `-std=c++98`.
- GNU Make and standard Unix shell utilities. The Makefiles use `-Wall -Wextra -Werror -std=c++98`; no external libraries are required.

### Build

Run these commands from the repository root. Each exercise has its own Makefile; there is no root Makefile.

```bash
make -C ex00
make -C ex01
make -C ex02
```

Each Makefile provides `all`, `clean` (remove the `build/` directory), `fclean` (also remove the executable), `re` (rebuild), `debug` (`-g -DDEBUG`), and `run` (rebuild and start the exercise). For example:

```bash
make -C ex00 run
make -C ex01 fclean
make -C ex02 re
```

`ex01` and `ex02` also provide `fsan` (debug info plus the address sanitizer; requires compiler support):

```bash
make -C ex01 fsan
make -C ex02 fsan
```

Each executable is named after its directory: `ex00/ex00`, `ex01/ex01`, and `ex02/ex02`. All three take **no command-line arguments** and no environment variables; they run their built-in test suites and exit.

### ex00 — Easy find

From the repository root:

```bash
make -C ex00 && ./ex00/ex00
```

`easyfind(T& container, int value)` in [ex00/easyfind.hpp](ex00/easyfind.hpp) searches with `std::find` and returns nothing: on success the call simply returns, on failure it throws `std::runtime_error`. The bundled `main.cpp` exercises a hit and a miss on `std::vector<int>`. Associative containers are not handled — the subject does not require it.

### ex01 — Span

From the repository root:

```bash
make -C ex01 && ./ex01/ex01
```

The main interface of `Span` ([ex01/include/Span.hpp](ex01/include/Span.hpp)):

- `Span(unsigned int N)` — a span holding at most N integers.
- `addNumber(int)` — adds one number; throws when the span is already full.
- `shortestSpan()` / `longestSpan()` — the smallest / largest distance between any two stored numbers; both throw when fewer than two numbers are stored.
- `append(Iter first, Iter last)` — appends a range of iterators in one call; throws on an empty range or one larger than the remaining capacity.
- `append_range(int start, int end)` — appends the values `[start, end)`; throws when `start >= end` or the range does not fit.

The bundled `main.cpp` runs twelve tests, including the subject example (numbers 6, 3, 17, 9, 11 give a shortest span of `2` and a longest span of `14`), overfill and undersized-span exceptions, and a span of 100,000 numbers.

### ex02 — Mutated abomination

From the repository root:

```bash
make -C ex02 && ./ex02/ex02
```

`MutantStack<T, Container = std::deque<T> >` ([ex02/MutantStack.hpp](ex02/MutantStack.hpp)) is implemented in terms of `std::stack` and inherits all its member functions, adding `iterator`, `begin()`, and `end()` over the underlying container. A `MutantStack` can also be copied into a plain `std::stack`, as in the subject example.

The bundled `main.cpp` runs the subject sequence on `MutantStack<int>`, the same sequence on `std::list<int>` (the two outputs match), and a deep-copy test.

## Resources

- **cppreference C++ standard-library reference:** entries for `std::find`, `std::sort`, `std::distance`, `std::vector`, `std::stack`, `std::deque`, and container iterators. Consult the C++98 behavior when reading modern documentation.
- **GNU Make manual:** targets, automatic variables, and dependency tracking.
- **ISO/IEC 14882:1998 (C++98)** — the language standard this module compiles against.

### AI usage

AI was used to help write and improve this README and project documentation, prepare commits, and, where output or data visualisation is more complex, tweak that output.

## What this project demonstrates

* Writing function templates and class templates in C++98
* Orthodox Canonical Form on both plain and template classes
* Practical use of STL containers (`std::vector`, `std::deque`, `std::stack`) and algorithms (`std::find`, `std::sort`)
* Iterator-based interfaces, including iterator-range bulk insertion
* Exception-based error handling with `std::runtime_error`
* Self-contained test programs covering success and failure paths
* Writing code that is explainable during peer evaluation and maintainable afterward

## Technical constraints

This project is developed under the 42 C++ module rules:

* Standard: **C++98**
* Compiler flags: **`-Wall -Wextra -Werror -std=c++98`**
* STL usage is mandatory in this module: containers and `<algorithm>` must be used wherever appropriate
* External libraries, Boost, and C++11 or later features are forbidden; `*printf()`, `*alloc()`, and `free()` are forbidden too
* `using namespace` and `friend` are forbidden unless an exercise states otherwise
* Classes follow the **Orthodox Canonical Form**
* Function implementations in headers are forbidden except function templates; `.tpp` files are optional extras
* Headers must be self-contained and protected against double inclusion
* Memory leaks are not allowed; Makefile rules follow the same rules as in the C modules
* ex00 does not need to handle associative containers

## Repository structure

```text
cpp08/
├── README.md
├── ex00/   # Easy find: main.cpp, easyfind.hpp, Makefile
├── ex01/   # Span: Makefile
│   ├── include/   # Span.hpp, Span.tpp, helpers/{colors.h, debug.hpp}
│   └── src/       # Span.cpp, main.cpp
└── ex02/   # Mutated abomination: main.cpp, MutantStack.hpp, MutantStack.tpp, Makefile
```

## Focus areas by exercise

### ex00 — Easy find

* function templates over sequence containers
* `std::find` as the search primitive
* signalling failure with exceptions
* covering the hit and miss paths in tests

### ex01 — Span

* class design in Orthodox Canonical Form
* capacity-checked insertion with `addNumber()`
* span computation through sorting (`std::sort`) and adjacent differences
* bulk insertion from iterators (`std::distance`, `std::vector::insert`) and from value ranges
* behavior with large data sets (100,000 numbers)

### ex02 — Mutated abomination

* implementing a class template in terms of `std::stack`
* exposing the underlying container's iterators (`begin()`, `end()`)
* keeping compatibility with `std::stack`, including copy-construction
* verifying identical behavior against `std::list`

## Testing

Each exercise ships its tests inside its own `main.cpp` (the subject asks for your own tests, and they are part of the submission). There are no separate test scripts; running the executable runs the tests.

### ex00

Two tests: a successful search and a search that throws `std::runtime_error` (caught and reported).

```bash
make -C ex00 && ./ex00/ex00
```

### ex01

Twelve tests: the subject example (spans `2` and `14`), filling and overfilling a span, valid and rejected `append_range()` calls, appends to partially filled spans, duplicate numbers, a 100,000-number span, the single-element error, and iterator-range appends (valid and too large).

```bash
make -C ex01 && ./ex01/ex01
```

### ex02

Three tests: the subject sequence on `MutantStack<int>`, the same sequence on `std::list<int>`, and a deep-copy test showing independence of a copied stack.

```bash
make -C ex02 && ./ex02/ex02
```

## Status

* **Status:** Completed
* **Final grade:** **100/100 points**
