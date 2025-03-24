# Owner: Caio Lauro de Lima

Command-line tools for Fedora/Linux.

## Installation
You can use `make` to create the binary file `cll-tools` or alternatively, use `make install` to install automatically the binary file into `/usr/local/bin/cll-tools` (requires super-user authentication). You may also execute `make install prefix=/PATH` to install `cll-tools` in `PATH/bin/cll-tools`.

## Usage
If not installed using `make install`, you can run the executable file using `./cll-tools [OPTIONS] COMMAND`. \
If installed, you may use `cll-tools [OPTIONS] COMMAND` as a CLI tool.

### Software Options and Commands:
```
--help, -h                          Provides help for the user
system-update, update-system        Updates the sytem when needed. (using dnf and flatpak update)
```

## Return codes
Any return code that differs from zero means a failure of some kind. The program has the following error return codes: 
1. Command not found.
2. Wrong Usage.\
Since commands such as `update-system` use other software, they may return the same results, but with other meanings, just check the output to know what happened.
