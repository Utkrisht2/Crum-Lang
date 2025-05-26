## Welcome to Crum Lang

Crum Lang is an open-source interpreter written in C++. The goal of this project is to understand how interpreters work and to build one with a custom syntax.

## Getting Started

Clone the project:

```
git clone git@github.com:Utkrisht2/crum-lang.git
```

[Install Google test](https://code.google.com/p/googletest/)

## Usage

##### Compile

```
make
```

##### Run

```
make run
```

##### Docs

Generate doxygen docs

```
make docs
```

### Run in other language

Create tokens file (based on `tokens/` dir files and run your examples based on `examples/` dir)

```
make run FILE=examples/portugues.tl TOKENS=tokens/portugues.yml
```

##### Format code

```
make format
```

##### Install

```
make install
```

##### Clean

```
make clean
```

To run manually, open bin/run

## Contributing

I :heart: Open source!

Before sending a pull request: Please, format the source code

```
bin/format
```
## ✨ Features

- [x] Tokenization using custom YAML definitions
- [x] Multilingual syntax support
- [x] Doxygen documentation generation
- [x] Example-based execution
- [ ] REPL support (Coming Soon!)
- [ ] Error highlighting and debugging (Planned)

## ❓ FAQs

**Q: Can I add my own language?**  
A: Yes! Define token rules in a `.yml` file under `tokens/` and provide examples in `examples/`.

**Q: Why use C++ for an interpreter?**  
A: C++ gives more control over memory, performance, and understanding low-level parsing mechanisms.


